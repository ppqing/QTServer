#pragma once
#include <string>
#include <vector>

class CSVRow
{

public:
	CSVRow(std::string str);
	~CSVRow();
	int getNum();
	void debug();
private:
	int num;
	std::vector<std::string>* data_;
};
