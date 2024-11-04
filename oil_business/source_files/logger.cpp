#include <iostream>
#include <fstream>
#include <string>
#include <ctime>
#include "../header_files/logger.h"

using namespace std;


Logger::Logger(const std::string &file_name){
    this->logfile.open("logfiles/" + file_name);
    if (!this->logfile.is_open()){
        cout << "Error opening file!" << endl;
        return;
    }

    std::cerr.rdbuf(this->logfile.rdbuf());
}

Logger::~Logger(){
    if (this->logfile.is_open()){
        this->logfile.close();
    }
}
