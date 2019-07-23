#include <gtest/gtest.h>
#include <logger/Logger.hpp>
#include <fstream>

std::string logfile = "/home/stavrow/Logger/build/log_test.txt";

TEST(LoggerTest, IntegerCheck) {
    int value_int = 12;
    void* input = &value_int;

    // Check how many lines are already written
    std::string line;
    std::ifstream file(logfile.c_str());
    int count_before = 0;
    while (getline(file, line)){
        count_before++;
    }
    
    Logger Log(logfile);
    Log.logInput("integer", input);
    int count_after = 0;
    std::string last_line;
    std::ifstream file_new(logfile.c_str());
    while (getline(file_new, line)){
        last_line = line;
        count_after++;
    }
    ASSERT_EQ (count_before+1, count_after); //It should write only 1 line (not worth further testing if this is not true)
    
    std::string delimiter = ", ";
    last_line.erase(0, last_line.find(delimiter) + delimiter.length()); // remove event number
    std::string value = last_line.substr(0, last_line.find(delimiter)); // take out value (and leave out timestamp)
    EXPECT_EQ ("12", value);
    }
    
TEST(LoggerTest, BoolCheck) {
    bool value_bool = 1;
    void* input = &value_bool;

    // Check how many lines are already written
    std::string line;
    std::ifstream file(logfile.c_str());
    int count_before = 0;
    while (getline(file, line)){
        count_before++;
    }

    Logger Log(logfile);
    Log.logInput("bool", input);
    int count_after = 0;
    std::string last_line;
    std::ifstream file_new(logfile.c_str());
    while (getline(file_new, line)){
        last_line = line;
        count_after++;
    }
    ASSERT_EQ (count_before+1, count_after);
    
    std::string delimiter = ", ";
    std::cout<<last_line<<std::endl;
    last_line.erase(0, last_line.find(delimiter) + delimiter.length());
    std::string value = last_line.substr(0, last_line.find(delimiter));

    EXPECT_EQ ("True", value);
    }
    
TEST(LoggerTest, DoubleCheck) {
    double value_double = 12.3;
    void* input = &value_double;
    
    std::string line;
    std::ifstream file(logfile.c_str());
    int count_before = 0;
    while (getline(file, line)){
        count_before++;
    }

    Logger Log(logfile);
    Log.logInput("double", input);
    int count_after = 0;
    std::string last_line;
    std::ifstream file_new(logfile.c_str());
    while (getline(file_new, line)){
        last_line = line;
        count_after++;
    }
    ASSERT_EQ (count_before+1, count_after);
    
    std::string delimiter = ", ";
    last_line.erase(0, last_line.find(delimiter) + delimiter.length());
    std::string value = last_line.substr(0, last_line.find(delimiter));
    EXPECT_EQ ("12.3", value);
    }
    
TEST(LoggerTest, StringCheck) {
    std::string value_str = "Test123$%^";
    void* input = static_cast<void*>(new std::string(value_str));

    std::string line;
    std::ifstream file(logfile.c_str());
    int count_before = 0;
    while (getline(file, line)){
        count_before++;
    }

    Logger Log(logfile);
    Log.logInput("string", input);
    int count_after = 0;
    std::string last_line;
    std::ifstream file_new(logfile.c_str());
    while (getline(file_new, line)){
        last_line = line;
        count_after++;
    }
    ASSERT_EQ (count_before+1, count_after);
    
    std::string delimiter = ", ";
    last_line.erase(0, last_line.find(delimiter) + delimiter.length());
    std::string value = last_line.substr(0, last_line.find(delimiter));
    EXPECT_EQ ("Test123$%^", value);
    }
    
TEST(LoggerTest, WrongTypeCheck) {
    std::string value_str = "Test123$%^";
    void* input = static_cast<void*>(new std::string);
    
    std::string line;
    std::ifstream file(logfile.c_str());
    int count_before = 0;
    while (getline(file, line)){
        count_before++;
    }

    Logger Log(logfile);
    Log.logInput("Unknown", input);
    int count_after = 0;
    std::ifstream file_new(logfile.c_str());
    while (getline(file_new, line)){
        count_after++;
    }
    EXPECT_EQ (count_before, count_after); //It should not write anything
    }
    

int main(int argc, char **argv) {
    ::testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
    }
