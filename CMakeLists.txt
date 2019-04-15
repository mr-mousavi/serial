cmake_minimum_required(VERSION 2.8)
project(serial)

## system defined variables
set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} --std=c++98")

if (CMAKE_BUILD_TYPE STREQUAL Debug)
	message("++ MAKE IN DEBUG MODE")
elseif (CMAKE_BUILD_TYPE STREQUAL Release)
	message("++ MAKE IN RELEASE MODE")
endif (CMAKE_BUILD_TYPE STREQUAL Debug)


#source
set (SRC_DIR source/src)
file (GLOB SOURCES ${SRC_DIR}/*.c*)

include_directories(
    ${PROJECT_BINARY_DIR}
    ${PROJECT_SOURCE_DIR}/source/include
)

## Target
add_executable(${PROJECT_NAME} 
    ${SOURCES}
)
target_link_libraries(${PROJECT_NAME} 
)

