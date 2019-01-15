#pragma once

#define MAX_STR_SIZE 1000

#include <QObject>
#include <boost/filesystem/path.hpp>
#include <string>
#include "CSV.h"

class FileReader
{
public:
	FileReader();
	~FileReader();
	CSV* readFile(std::string& filename);
private:
	boost::filesystem::path *path_;
	CSV* csv_;
};
