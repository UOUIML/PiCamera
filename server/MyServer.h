#pragma once
#include <QTcpServer>
#include <QTcpSocket>
#include <QDebug>
#include <QtGui/QImage>
#include <QBuffer>
#include <QtGui/QImageWriter>
#include <QFile>
#include <opencv2/opencv.hpp>
#include <opencv2/core.hpp>
#include <opencv2/videoio.hpp>
#include <opencv2/highgui.hpp>
#include "sensor.h"

class MyServer: public QTcpServer
{
	Q_OBJECT
		QThread laserThread;
	    QThread motorThread;
public:
	explicit MyServer(QObject *parent = 0);
	~MyServer();
	void StartServer();
	std::vector<std::vector<QString>> ScanPortInfor();
	void InitialSensorCamera();
signals:
	void error(QTcpSocket::SocketError socketerror);
	void getcommand(QByteArray data);
	void operateLaser(const QString &);
	void operateMotor(const QString &);

	public slots :
	void readyRead();
	void disconnected();

	void handleResultsLaser(QString str);
	void handleResultsMotor(QString str);

	void runcommand(QByteArray data);

private:
	QTcpSocket *socket;
	qintptr socketDescriptor;
	bool _flagConnected = false;

protected:
	void incomingConnection(qintptr  socketDescriptor);

	// laser and motor
private:
	Sensor *laserWorker;
	Sensor *motorWorker;

	cv::VideoCapture _cap;
	cv::Mat _img;
	std::vector<uchar> _buf;

	bool _flagLaserSensor = false;
	QString _sensorLaserData;

	bool _flagMotorSensor = false;
	QString _sensorMotorData;

	int waitTimerSensor = 1000000000;

};
