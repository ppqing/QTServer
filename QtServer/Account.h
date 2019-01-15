#pragma once
#include <qbytearray.h>

class Account
{
public:
	Account();
	~Account();
	static bool checkAccount(QByteArray str);
};
