#include <iostream>
#include <fstream>
#include <typeinfo>
#include "logger/Logger.hpp"
#include <string>
#include <ctime>
#include <chrono>


Logger::Logger(std::string logfile){ 
    path = logfile;
}

void Logger::logInput(std::string type, void* value){
    //Get time stamp
    using namespace std::chrono;
    milliseconds timestamp_ms = duration_cast< milliseconds >(system_clock::now().time_since_epoch());

    //Change void* to string to write file
    if (type == "bool"){
        bool value_bool = *(bool *)value;
        if (value_bool){
            value_str = "True";
            value = &value_bool;
        }   
        else{
            value_str = "False";
        }
    }
    else if (type == "double"){
        value_double = *(double *)value;
        std::ostringstream strs;
        strs << value_double;
        value_str = strs.str();
    }
    else if (type == "integer"){
        int value_int = *((int *)value);
        std::stringstream ss;
        ss << value_int;
        value_str = ss.str();
    }
    else if (type == "string"){
        std::string *sp = static_cast<std::string*>(value);
        value_str = *sp;
        delete sp;
    }
    else {
        return; //Prevent writing when type is invalid
    }
    
    //Write file
    std::ofstream myfile;
    myfile.open (path.c_str(), std::ios_base::app);
    
    std::string line;
    std::ifstream file(path.c_str());
    count = 0;
    while (getline(file, line)){
        count++;
    }

    std::stringstream ss2;
    ss2 << count;
    count_str = ss2.str();
    
    myfile << count_str + ", " + value_str + ", " + std::to_string(timestamp_ms.count()) << std::endl;
    std::cout << "writing: " + count_str + ", " + value_str + ", " + std::to_string(timestamp_ms.count()) << std::endl;
    myfile.close();
}
