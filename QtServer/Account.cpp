#include "Account.h"
#include <qstring.h>
#include <qstringlist.h>
#include <map>
Account::Account()
{
}

Account::~Account()
{
}

bool Account::checkAccount(QByteArray cstr)
{
	std::map<QString,QString>accounts;
	accounts["abc"] = "123";
	
	
	
	QString qstr;
	qstr.prepend(cstr);
	QStringList list = qstr.split(":");
	if(list.size()==2)
	{
		auto p = list.begin();
		QString id = *p;
		++p;
		QString passwd = *p;
		if(accounts.find(id)!=accounts.end())
		{
			//�����˺�����֤����
			if(accounts[id]==passwd)
			{
				return true;
			}
		}
	}
	return false;
}
