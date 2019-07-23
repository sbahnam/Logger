#include <iostream>
#include <typeinfo>
#include <fstream>
#include <string>
#include <chrono>
#include <sstream>
#include "logger/Logger.hpp"


int main () {
//    std::string path;
//    cout << "Enther the directory for the logfile (/home/user/example/"  << endl;
//    cin >> path;
    std::string path = "/home/stavrow/Logger/build/";
    std::string logfile = path+ "log.txt";
    Logger Log(logfile);
    
    // Check if the file is empty
    std::string line;
    std::ifstream file(logfile.c_str());
    int count = 0;
    while (getline(file, line)){
        count++;
    }
    std::cout<<count<<std::endl;
    if (count == 0){
        //write headers
        std::ofstream myfile;
        myfile.open (logfile.c_str(), std::ios_base::app);
        myfile << "event number, value, time" << std::endl;
        myfile.close();    
    }
    

    
    int i = 0;
    std::string value_str;
    std::string type;
    bool valid_input = true;
    void *value;

    while (true) {
        i++;
        std::cout << "Input variable" + std::to_string(i) + "('quit' to end program)"  << std::endl;
        std::cin >> value_str;
        if (value_str == "quit"){
            break;
        }
        std::cout << "variable type (string, integer, double, bool)"<< std::endl;
        std::cin >> type;
        
        // Convert string to bool
        if (type == "bool"){
            if (value_str == "true" || value_str == "1"){
                bool value_bool = true;
                value = &value_bool;
            }   
            else if (value_str == "false" || value_str == "0"){
                bool value_bool = false;
                value = &value_bool;
            }
            else {
                valid_input = false;
            }
        }
        
        // Convert string to double
        else if (type == "double"){
            double value_double =atof(value_str.c_str());
            value = &value_double;
        }
        
        // Convert string to integer
        else if (type == "integer"){
            int value_int;
            std::istringstream iss (value_str);
            iss >> value_int;
            value = &value_int;
        }
        
        //String (void pointer)
        else if (type == "string"){
            value = static_cast<void*>(new std::string(value_str));
        }
        else{
            std::cout<<"invalid type"<<std::endl;
            valid_input = false;
        }



        if (valid_input){
        
            Log.log(type, value); // Inputs: type (std::string) and value (void*)
        }

    }

    return 0;
}
