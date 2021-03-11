#include <QtCore/QCoreApplication>
#include "MyServer.h"

int main(int argc, char *argv[])
{
	QCoreApplication a(argc, argv);
	MyServer myServer;

	myServer.StartServer();

	return a.exec();
}

