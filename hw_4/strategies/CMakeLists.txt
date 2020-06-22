project(strategies)

set(SOURCES
        comp_1.cpp
        comp_2.cpp
        computer_interface.cpp
        human.cpp)
set(HEADERS
        comp_1.h
        comp_2.h
        computer_interface.h
        human.h
        interface.h)

include_directories(../)

add_library(strategies ${SOURCES} ${HEADERS})
