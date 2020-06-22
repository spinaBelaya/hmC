project(game)

set(SOURCES
        field.cpp
        game.cpp
        step.cpp)
set(HEADERS
        field.h
        game.h
        step.h)

include_directories(../)

add_library(game ${SOURCES} ${HEADERS})
