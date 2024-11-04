#pragma once
#include <fstream>
#include <string>


class Logger{
private:
    std::ofstream logfile;
public:
    Logger(const std::string &file_name);
    ~Logger();
};
