@echo off
pushd build
echo Building
set var=%1
set name=%var:.cpp=%
echo the file name is %name%
g++ ..\src\%1.cpp -Wall -o %name%
echo Done
popd
