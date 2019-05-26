cmake_minimum_required(VERSION 3.13)

add_executable(my-main main.cpp)

set(install-path ${CMAKE_SOURCE_DIR}/install)

target_link_libraries(my-main 
                      PUBLIC 
                      Boost::filesystem
                      Boost::date_time)                 


install(TARGETS my-main
        DESTINATION ${install-path}
)

