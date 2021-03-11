#include "sensor.h"


Sensor::Sensor(QString name,qint32 baudRate,SensorType sensorType):_nameUSB(name),_baudRate(baudRate),_sensorType(sensorType)
{
	sensorConnection();
}

Sensor::~Sensor()
{
	if(serial->isOpen()){
		serial->close();
	}
}

void Sensor::sensorConnection()
{
	serial =  new QSerialPort(this);

	serial->setPortName(_nameUSB);
	serial->setBaudRate(_baudRate);
	serial->setDataBits(QSerialPort::Data8);
	if (_sensorType == SensorType::LASER) {
		serial->setParity(QSerialPort::NoParity);
	}
	else {
		serial->setParity(QSerialPort::EvenParity);
	}

	serial->setStopBits(QSerialPort::OneStop);

	if(serial->open(QIODevice::ReadWrite)){
		if(_sensorType == SensorType::LASER) qDebug() <<"Laser Connected...";
		else if (_sensorType == SensorType::MOTOR) qDebug() << "Motor Connected...";
	}
	else{
		if (_sensorType == SensorType::LASER) qDebug() << "Laser Can't Connected...";
		else if (_sensorType == SensorType::MOTOR) qDebug() << "Motor Can't Connected...";
	}

	connect(serial,SIGNAL(readyRead()),this,SLOT(readData()));
}

void Sensor::writeData(const QString &str)
{
	if(_sensorType == SensorType::LASER){
		if(serial->isOpen()){
			// clear old data
			//
			laserData.clear();
			serial->write(str.toUtf8());
		}
	}
	else{
		QByteArray myhexarray = QByteArray::fromHex(str.toLatin1());
		if (myhexarray.size() >= 1) {
			if (myhexarray.at(1) == 0x03) this->numberofByteMotor = 9;

			else if (myhexarray.at(1) == 0x06) this->numberofByteMotor = 8;
		}

		// clear old motor data

		motorData.clear();
		serial->write(myhexarray);
		//serial->waitForReadyRead(40);
	}
}

void Sensor::readData()
{
	if(_sensorType == SensorType::LASER){
		laserData += serial->readAll();

		if(QString(laserData).contains("\n",Qt::CaseInsensitive)){
			emit resultReady("laser "+QString(laserData));
			laserData.clear();
		}
	}
	else{
		motorData += serial->readAll();
		if(motorData.size() == this->numberofByteMotor) {
			emit resultReady("motor " + motorData.toHex());
			motorData.clear();
		}

	}

}

