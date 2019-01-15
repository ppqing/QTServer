#include "QtServer.h"
#include <QtWidgets/QApplication>
#include "FileReader.h"

#include <string>

int main(int argc, char *argv[])
{
	QApplication a(argc, argv);
	QtServer w;
	w.show();
	/*FileReader fr;
	std::string path = "data.csv";
	auto p = fr.readFile(path);
	auto p1 = p->getDataPointer();
	auto p2= p1->begin();
	++p2;
	p2->debug();*/
	return a.exec();
}
