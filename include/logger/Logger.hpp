#ifndef LOGGER_HPP
#define LOGGER_HPP
#include "string"
#include <sstream>
#include <ctime>
#include <chrono>
#include <fstream>

//using namespace std;

class Logger{
public:
    Logger(std::string logfile);
    void logInput(std::string type, void* value);
private:
    std::string path;
    std::ofstream myfile;
    int number;
    std::string value_str;
    double value_double;
    int value_int;
    std::ostringstream strs;
    std::string line;
    int count;
    std::string count_str;
    
    std::chrono::milliseconds timestamp_ms;

//    std::string *sp;
//    std::string s;
};

#endif
