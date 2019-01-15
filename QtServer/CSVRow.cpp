#include "CSVRow.h"
#include <boost/algorithm/string/split.hpp>
#include <boost/algorithm/string/classification.hpp>
#include <qlogging.h>

CSVRow::CSVRow(std::string str)
{
	data_=new std::vector<std::string>;
	split(*data_, str, boost::is_any_of(",£¬"));
	num = data_->size();
}

CSVRow::~CSVRow()
{
	//delete data_;
}

int CSVRow::getNum()
{
	return num;
}

void CSVRow::debug()
{
	auto p = data_->begin();
	for(;p!=data_->end();++p)
	{
		qDebug(p->c_str());
	}
}
