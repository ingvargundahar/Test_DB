cmake_minimum_required(VERSION 3.0.0)
project(testdb VERSION 0.1.0)

#include(CTest)
#enable_testing()

add_executable(testdb testdb.c)

#mit SQLite Library linken
target_link_libraries(testdb sqlite3)

#set(CPACK_PROJECT_NAME ${PROJECT_NAME})
#set(CPACK_PROJECT_VERSION ${PROJECT_VERSION})
#include(CPack)
