#include "MyServer.h"



MyServer::MyServer(QObject *parent) :
        QTcpServer(parent)
{
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

void MyServer::incomingConnection(qintptr  socketDescriptor)
{
        qDebug() << socketDescriptor << " Connecting...";
        MyThread *thread = new MyThread(socketDescriptor, this);
        connect(thread, SIGNAL(finished()), thread, SLOT(deleteLater()));
        thread->start();
}

MyServer::~MyServer()
{
}
