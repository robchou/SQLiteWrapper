PROJECT(SQLiteWrapper)

cmake_minimum_required(VERSION 2.8)

add_library(sqlitewrapper SQLiteWrapper.cpp)

add_executable(test_1 test_1.cpp)
add_executable(test_2 test_2.cpp)
add_executable(test_3 test_3.cpp)
add_executable(test_4 test_4.cpp)

target_link_libraries(test_1 sqlitewrapper sqlite3)
target_link_libraries(test_2 sqlitewrapper sqlite3)
target_link_libraries(test_3 sqlitewrapper sqlite3)
target_link_libraries(test_4 sqlitewrapper sqlite3)
