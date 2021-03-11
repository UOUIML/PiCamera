#ifndef SENSOR_H
#define SENSOR_H

#include <QObject>
#include <QThread>
#include <QtSerialPort>
#include <QtSerialPort>
#include <QDebug>

enum SensorType {LASER=5,MOTOR=6};

class Sensor: public QObject
{
     Q_OBJECT

public:
    Sensor(QString _name,qint32 baudRate,SensorType sensorType);
    ~Sensor();

    void sensorConnection();

public slots:
    void writeData(const QString& str);
    void readData();
signals:
    void resultReady(QString str);
private:
    QSerialPort * serial;
    QByteArray laserData;
	QByteArray motorData;
	int numberofByteMotor;

    QString _nameUSB;
    qint32 _baudRate;
    SensorType _sensorType;
};

#endif // SENSOR_H

