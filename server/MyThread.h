#pragma once
#include <QThread>
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
#include <iostream>
#include <stdio.h>
#include "sensor.h"


class MyThread: public QThread
{
	Q_OBJECT
		QThread laserThread;
	    QThread motorThread;
public:
	explicit MyThread(qintptr ID, QObject *parent = 0);
	std::vector<std::vector<QString>> ScanPortInfor();
	void run();

signals:
	void getcommand(QByteArray data);
	void error(QTcpSocket::SocketError socketerror);

	void operateLaser(const QString &);
	void operateMotor(const QString &);
		
	public slots:
	void readyRead();
	void disconnected();

	void handleResultsLaser(QString str);
	void handleResultsMotor(QString str);

	void runcommand(QByteArray data);
	
	public slots:

private:
	QTcpSocket *socket;
	qintptr socketDescriptor;
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


