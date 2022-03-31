cmake_minimum_required(VERSION 3.5)

project(techchallenge LANGUAGES CXX)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

add_subdirectory(lib/googletest)

set(BIN_SOURCES main.cpp)
set(TEST_SOURCES test_detector.cpp test_vehicle.cpp)
set(LIB_SOURCES collisionDetector.cpp vehicle.cpp)

set(BIN_NAME ${CMAKE_PROJECT_NAME})
set(TEST_NAME ${BIN_NAME}_test)
set(LIB_NAME ${BIN_NAME}_lib)

add_library(${LIB_NAME} STATIC ${LIB_SOURCES})

add_executable(${BIN_NAME} ${BIN_SOURCES})
target_link_libraries(${BIN_NAME} PUBLIC ${LIB_NAME})


add_executable(${TEST_NAME} ${TEST_SOURCES})
target_link_libraries(${TEST_NAME} PUBLIC ${LIB_NAME} gtest_main)
add_test(NAME ${TEST_NAME} COMMAND ${TEST_NAME})

