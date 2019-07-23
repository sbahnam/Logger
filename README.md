# Logger

In order to run the code create a directory build.
'mkdir build'
'cd build'

Run CMakeLists.txt followed by make to create the executable file "run_code" and "LoggerTest". The first time it will run all the tests automatically.
'cmake ..'
'make'

In order to be able to rune 'cmake ..' GTest is required.
To get GTest do the following:
Install cmake
'sudo apt-get install libgtest-dev'
'sudo apt-get install cmake'
'cd /usr/src/gtest'
'sudo cmake CMakeLists.txt'
'sudo make'

copy libgtest.a and libgtest_main.a to your /usr/lib folder
'sudo cp *.a /usr/lib'

Run the code:
Run the main code: './run_code' in build directory. Make sure your path input ends with "/" when running the code.
Run the GTest: './LoggerTest'.

In order to delete the builded files, simply delete the build folder (in Logger directory).
'rm -r build'
