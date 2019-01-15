#include "CSV.h"

CSV::CSV()
{
	data_ = new std::vector<CSVRow>;
}

CSV::~CSV()
{
	delete data_;
}

void CSV::push_back(CSVRow pushData)
{
	data_->push_back(pushData);
}

std::vector<CSVRow>* CSV::getDataPointer()
{
	return data_;
}
