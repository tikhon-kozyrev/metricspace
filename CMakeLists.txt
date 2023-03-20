cmake_minimum_required(VERSION 3.2)

set(NAME metricspace)
PROJECT (${NAME})
set(PROJECT ${NAME} )

set (CMAKE_CXX_STANDARD 11)

set( HEADERS ${PROJECT_SOURCE_DIR})

file(GLOB_RECURSE SOURCES ${PROJECT_SOURCE_DIR} "*.cpp")

include_directories( ${PROJECT_SOURCE_DIR} )

set( REQUIRED_LIBRARIES )

add_executable(${NAME} ${SOURCES})
target_link_libraries(${NAME} ${REQUIRED_LIBRARIES} )

