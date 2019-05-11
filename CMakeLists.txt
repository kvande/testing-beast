cmake_minimum_required(VERSION 3.13)

project(TestingBeast)

set(BOOST_ROOT /usr/arnstein/boost_1_70_0)

find_package(Boost REQUIRED)
INCLUDE_DIRECTORIES( ${Boost_INCLUDE_DIR} )

add_executable(MyExe main.cpp)