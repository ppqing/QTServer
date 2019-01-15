#include "FileReader.h"
#include "CSV.h"
#include <boost/filesystem/fstream.hpp>
#include <boost/filesystem/path.hpp>
#include <boost/filesystem/operations.hpp>
#include <boost/algorithm/string/split.hpp>
#include <boost/algorithm/string/classification.hpp>
#include <boost/lexical_cast.hpp>
#include <vector>
#include <string>

using namespace boost::filesystem;
using namespace std;

FileReader::FileReader()
{
}

FileReader::~FileReader()
{
}

CSV* FileReader::readFile(std::string& filename)
{
	path_ = new path(current_path().string() + "\\"+filename);
	if (exists(*path_) &&
		is_regular_file(*path_))
	{
		csv_=new CSV();
		boost::filesystem::fstream fs(*path_, std::ios_base::in);
		char str[MAX_STR_SIZE];
		while (!fs.eof()) {
			fs.getline(str, MAX_STR_SIZE);
			csv_->push_back(CSVRow(str));
		}
		fs.close();
		return csv_;
	}
	else
	{
		return nullptr;
	}
}
