#define MAX_STR_SIZE 1000
#include "QtServer.h"
#include <qstring.h>
#include "Account.h"
#include <boost/filesystem/fstream.hpp>
#include <boost/filesystem/path.hpp>
#include <boost/filesystem/operations.hpp>
#include <boost/algorithm/string/split.hpp>
#include <boost/algorithm/string/classification.hpp>
#include <boost/lexical_cast.hpp>

QtServer::QtServer(QWidget *parent)
	: QMainWindow(parent)
{
	ui.setupUi(this);
	createUI();
	//for (int i = 0; i < 50; i++) {
	//	ui.textBrowser->append(QString::number(i, 10));
	//}
}

QtServer::~QtServer()
{
	if(tcpSocket_!=nullptr)
	{
		tcpSocket_->disconnectFromHost();
		tcpSocket_->close();
	}
	
}



void QtServer::createUI() {
	QRegExp regPort("([0-9]|[1-9]\\d{1,3}|[1-5]\\d{4}|6[0-5]{2}[0-3][0-5])");
	QRegExpValidator *latitudePort = new QRegExpValidator(regPort, this);
	ui.portText->setValidator(latitudePort);
	ui.portText->setText(QString::number(port, 10));
}

void QtServer::slotStartButtonClicked() {
	if (!listenFlag) {
		this->port = ui.portText->text().toInt();
		QString str = u8"设置端口";
		str += QString::number(port, 10);
		str += u8"成功";
		ui.textBrowser->append(str);
		ui.textBrowser->append(u8"开始监听成功!");
		init();
		ui.startButton->setText(u8"停止监听");
		listenFlag = true;
	}
	else {
		ui.textBrowser->append(u8"结束监听成功!");
		ui.startButton->setText(u8"开始监听");
		delete tcpServer_;
		listenFlag = false;
	}
}


void QtServer::init() {
	tcpServer_ = new QTcpServer(this);
	tcpServer_->listen(QHostAddress::AnyIPv4, port);
	connect(tcpServer_, &QTcpServer::newConnection,
		[=]() {
		//取出建立好连接的套接字，用于通信
		//取监听队列中下一个(第一个)连接
		tcpSocket_ = tcpServer_->nextPendingConnection();

		//获取对方的IP:port
		QString ipCli = tcpSocket_->peerAddress().toString();
		qint16 portCli = tcpSocket_->peerPort();
		QString temp = QString(u8"[%1:%2]:").arg(ipCli).arg(portCli);
		ui.textBrowser->append(temp+u8"连接成功");
											//进行通信套接字的读取
		connect(tcpSocket_, &QTcpSocket::readyRead,
			[=]() {
			//从通信套接字中取出内容
			QByteArray array = tcpSocket_->readAll();
			if (Account::checkAccount(array))
			{
				ui.textBrowser->append("login success");
				tcpSocket_->write("ok\n");
				readFile("data2000.csv", tcpSocket_);
				readFile("data3000.csv", tcpSocket_);
				readFile("data3001.csv", tcpSocket_);
			}
			else
			{
				tcpSocket_->write("denied\n");
			}
			ui.textBrowser->append(array);
		}
		);
		connect(tcpSocket_, &QTcpSocket::disconnected,
			[=]() {ui.textBrowser->append(temp+u8"连接断开"); });
	}
	);
}

void QtServer::sendData()
{
	
}

using namespace boost::filesystem;
using namespace std;

void QtServer::readFile(string filename, QTcpSocket* socket)
{	
	auto path_ = new path(current_path().string() + "\\"+filename);
	int num = 0;
	vector<string>data;
	//vector<char[MAX_STR_SIZE]>data;
	if (exists(*path_) &&
		is_regular_file(*path_))
	{
		boost::filesystem::fstream fs(*path_, std::ios_base::in);
		while (!fs.eof()) {
			char str[MAX_STR_SIZE];
			fs.getline(str, MAX_STR_SIZE);
			data.push_back(str);
			num++;
		}
		socket->write("sending\n");
		socket->write(filename.c_str());
		socket->write("\n");
		socket->write(to_string(num).c_str());
		socket->write("\n");
		auto p = data.begin();
		for(;p!=data.end();++p)
		{
			//qDebug(p->c_str());

			*p += "\n";
			socket->write(p->c_str());
			qDebug(p->c_str());
		}
		socket->write("complete\n");
		fs.close();
	}
	else
	{
		;
	}
}
