#pragma once

#include <QtWidgets/QMainWindow>
#include "ui_QtServer.h"
#include <qtcpserver.h>
#include <qtcpsocket.h>

class QtServer : public QMainWindow
{
	Q_OBJECT

public:
	QtServer(QWidget *parent = Q_NULLPTR);
	~QtServer();
	void init();

private:
	Ui::QtServerClass ui;
	QTcpServer* tcpServer_=nullptr;
	QTcpSocket* tcpSocket_= nullptr;
	int port = 9925;
	void createUI();
	bool listenFlag=false;
	void sendData();
	void readFile(std::string path, QTcpSocket* socket);
private slots:
	void slotStartButtonClicked();
};
