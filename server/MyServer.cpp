#include "MyServer.h"

#define SENSOR
//#define CAMERA

MyServer::MyServer(QObject *parent) :
	QTcpServer(parent)
{ 
   connect(this, &MyServer::getcommand, this, &MyServer::runcommand, Qt::DirectConnection);

   qDebug() << "Scanning Port";
   ScanPortInfor();
}

void MyServer::StartServer()
{
	if (!this->listen(QHostAddress::Any, 8585))
	{
		qDebug() << "Could not start server";
	}
	else
	{
		qDebug() << "Listening...";
	}
}

std::vector<std::vector<QString>> MyServer::ScanPortInfor()
{
	const auto infos = QSerialPortInfo::availablePorts();
	QString serialNumber;
	QString portName;
	std::vector<std::vector<QString>> portVecs;
	for (const QSerialPortInfo &info : infos) {
		std::vector<QString> curPortInfo;
		serialNumber = info.serialNumber();
		portName = info.portName();

		curPortInfo.push_back(serialNumber);
		curPortInfo.push_back(portName);
		portVecs.push_back(curPortInfo);

		//
		qDebug() <<serialNumber;
		qDebug() << portName;
	}

	return portVecs;
}

void MyServer::InitialSensorCamera()
{
#ifdef CAMERA
	// camera
	int deviceID = 0;
	int apiID = cv::CAP_ANY;      // 0 = autodetect default API
								  // check if we succeeded
	_cap.open(deviceID, apiID);
	// Doing some setting for webcam
	_cap.set(3, 1920);
	_cap.set(4, 1080);
	_cap.set(cv::CAP_PROP_AUTOFOCUS, 0);
	_cap.set(cv::CAP_PROP_FOCUS, 240);
	_cap.set(cv::CAP_PROP_AUTO_EXPOSURE, 1);
	_cap.set(cv::CAP_PROP_EXPOSURE, 300);
	std::cout << _cap.get(cv::CAP_PROP_EXPOSURE) << std::endl;

	if (!_cap.isOpened()) {
		std::cout << "ERROR! Unable to open camera\n";
	}
#endif

#ifdef SENSOR
	// Scann port
	qDebug()<<"thocao";
	std::vector<std::vector<QString>> portVecs;
	portVecs = ScanPortInfor();
	if (portVecs.size() >= 1) {
		for (auto &p : portVecs) {
			// laser
			if (p[0] != "A107FQ43" && p[1] != "ttyAMA0" && p[1] !="ttyS0") {
				qDebug() << "this is laser";
				laserWorker = new Sensor(p[1], 19200, SensorType::LASER);
				laserWorker->moveToThread(&laserThread);
				connect(&laserThread, &QThread::finished, laserWorker, &QObject::deleteLater);
				connect(this, &MyServer::operateLaser, laserWorker, &Sensor::writeData);
				connect(laserWorker, &Sensor::resultReady, this, &MyServer::handleResultsLaser);
				laserThread.start();
			}
			// motor
			else if (p[0] == "A107FQ43" && !p[0].isEmpty() && !p[1].isEmpty()) {
				qDebug() << "this is motor";
				motorWorker = new Sensor(p[1], 115200, SensorType::MOTOR);
				motorWorker->moveToThread(&motorThread);
				connect(&motorThread, &QThread::finished, motorWorker, &QObject::deleteLater);
				connect(this, &MyServer::operateMotor, motorWorker, &Sensor::writeData);
				connect(motorWorker, &Sensor::resultReady, this, &MyServer::handleResultsMotor);
				motorThread.start();
			}
		}
	}
#endif 
}

void MyServer::readyRead()
{
	QByteArray data = socket->readAll();
	emit getcommand(data);

}

void MyServer::disconnected()
{
	qDebug() << "close all thread";
#ifdef SENSOR
	// close laser
	emit operateLaser(QString("C"));
	for (int i = 0; i<1000; i++) {

	}
	// stop motor
	emit operateMotor(QString("0106007d0020180a"));

	for (int i = 0; i<1000; i++) {

	}
	emit operateMotor(QString("0206007d00201839"));

	for (int i = 0; i<1000; i++) {

	}
	qDebug() << socketDescriptor << " Disconnected";

        laserThread.quit();
	laserThread.wait();

	motorThread.quit();
	motorThread.wait();
#endif

#ifdef CAMERA

	if (_cap.isOpened()) {
                _cap.release();
        }

#endif

	_flagConnected = false;
	socket->deleteLater();
}

void MyServer::handleResultsLaser(QString str)
{
	_sensorLaserData = str;

	socket->write(_sensorLaserData.toUtf8());
	_sensorLaserData.clear();
	qDebug() << str;
}

void MyServer::handleResultsMotor(QString str)
{
	_sensorMotorData = str;
	
	socket->write(_sensorMotorData.toUtf8());
	_sensorMotorData.clear();
	qDebug() << str;
}

void MyServer::runcommand(QByteArray data)
{
	QStringList commandSeries = QString(data).split(" ");
	if (commandSeries.size() <= 1) {
		socket->write("Wrong Command!");
		return;
	}

	QString IdCode = commandSeries[0];

	if (IdCode.contains("image", Qt::CaseInsensitive)) {// send image
														// send size
		if (_cap.isOpened()) {
			int count = 0;
			while (count != 5) {
				_cap.read(_img);
				count += 1;
			}

		}
		else {
			_img = cv::Mat::zeros(cv::Size(200, 200), CV_64FC1);
		}
		this->_buf.clear();

		if(!_img.empty()){
			cv::imencode(".jpg", _img, _buf);
		}
		else{
			_img = cv::Mat::zeros(cv::Size(200, 200), CV_64FC1);
			cv::imencode(".jpg", _img, _buf);
		}

		QString codeimg = "image " + QString::number(_buf.size());
		socket->write(codeimg.toUtf8());
	}
	else if (IdCode.contains("senddata", Qt::CaseInsensitive)) {
		socket->write((char*)_buf.data(), _buf.size());
	}
	else if (IdCode.contains("laser", Qt::CaseInsensitive)) {
		emit operateLaser(commandSeries[1]);
	    _flagLaserSensor = false;
	}
	else if (IdCode.contains("motor", Qt::CaseInsensitive)) {
		emit operateMotor(commandSeries[1]);
	}
	else if (IdCode.contains("exposure", Qt::CaseInsensitive)) {


		int exposure_value = commandSeries[1].toInt();
		qDebug()<<exposure_value;

		_cap.set(cv::CAP_PROP_EXPOSURE, exposure_value);

		socket->write("exposure okay");
	}

	else if (IdCode.contains("focuslen", Qt::CaseInsensitive)) {
		int focus_value = commandSeries[1].toInt();
		_cap.set(cv::CAP_PROP_FOCUS, focus_value);
		socket->write("focus len okay");
	}
	else {
		socket->write("Wrong Command!");
	}

	qDebug() << IdCode;
}

void MyServer::incomingConnection(qintptr  ID)
{
	if (_flagConnected == true) return;
	qDebug() << ID << " Connecting...";
	this->socketDescriptor = ID;

	socket = new QTcpSocket();
	if (!socket->setSocketDescriptor(this->socketDescriptor))
	{
		emit error(socket->error());
		return;
	}
	else {
		qDebug() << "new socket connected";
	}
	// Initial Sensor Camera


	connect(socket, SIGNAL(readyRead()), this, SLOT(readyRead()), Qt::DirectConnection);
	connect(socket, SIGNAL(disconnected()), this, SLOT(disconnected()), Qt::DirectConnection);
         InitialSensorCamera();
	_flagConnected = true;
}

MyServer::~MyServer()
{
	//if (_cap.isOpened()) {
          //      _cap.release();
        //}

        //laserThread.quit();
        //laserThread.wait();

       // motorThread.quit();
       // motorThread.wait();
}
