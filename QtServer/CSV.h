#pragma once
#include <string>
#include "CSVRow.h"
#include <vector>

class CSV
{
public:
	CSV();
	~CSV();
	void push_back(CSVRow push);
	std::vector<CSVRow>* getDataPointer();
private:
	std::vector<CSVRow>* data_;
};
