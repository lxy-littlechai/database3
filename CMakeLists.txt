cmake_minimum_required(VERSION 3.21)
project(database3)

set(CMAKE_CXX_STANDARD 20)

set(INC_DIR D:\\mysql-8.0.30-winx64\\include) ##本机MySQL下的include路径
set(LINK_DIR D:\\mysql-8.0.30-winx64\\lib) ##本机MySQL下的lib路径
include_directories(${INC_DIR})
link_directories(${LINK_DIR})
link_libraries(libmysql)

add_executable(database3 main.cpp DatabaseManager.cpp DatabaseManager.h FlightsManager.cpp FlightsManager.h BusManager.cpp BusManager.h HotelManager.cpp HotelManager.h CustomerManager.cpp CustomerManager.h)

target_link_libraries(database3 libmysql) ##Clion改为自己的工程文件