#pragma once
#include <QTcpServer>
#include <QDebug>
#include "MyThread.h"

class MyServer: public QTcpServer
{
        Q_OBJECT
public:
        explicit MyServer(QObject *parent = 0);
        ~MyServer();
        void StartServer();
signals:

        public slots :

protected:
        void incomingConnection(qintptr  socketDescriptor);
};
