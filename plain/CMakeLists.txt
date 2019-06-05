cmake_minimum_required(VERSION 3.14.3)
project(the-project-name LANGUAGES CXX)

set(BOOST_ROOT D:/libs/boost_1_70_0)
set(BOOST_NO_SYSTEM_PATHS TRUE)
set(CMAKE_CXX_STANDARD 17)
set(Boost_USE_STATIC_LIBS TRUE)
add_definitions(-D BOOST_ALL_NO_LIB) 

find_package(Boost 1.70 REQUIRED COMPONENTS filesystem date_time)

# message(WAS BOOST FOUND::::: ${Boost_FOUND})
# message(Boost_INCLUDE_DIRS::::: ${Boost_INCLUDE_DIRS})
# message(Boost_LIBRARY_DIRS::::: ${Boost_LIBRARY_DIRS})

add_subdirectory(./src)
