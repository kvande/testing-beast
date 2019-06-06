
add_executable(my-main main.cpp)

set(install-path ${CMAKE_SOURCE_DIR}/build_install)

target_link_libraries(my-main 
                      PUBLIC 
                      Boost::filesystem
                      Boost::date_time)                 


install(TARGETS my-main
        DESTINATION ${install-path}
)

