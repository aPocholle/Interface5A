cmake_minimum_required(VERSION 3.13)  
project(TD1)               
set(CMAKE_CXX_STANDARD 11)            

set(SOURCE_FILES TD1.cpp)

add_executable(app ${SOURCE_FILES})


TARGET_LINK_LIBRARIES( app
    pthread
)