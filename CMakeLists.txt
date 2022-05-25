#CMAKE - Allgemein
cmake_minimum_required(VERSION 3.10.0)
project(testdb VERSION 0.1.0)

#CMAKE - include folder + static library sqlite folder
include_directories(include /usr/include)
link_directories(/usr/lib)     

#CMAKE executable
add_executable(testdb ../testdb.c src/dbfunctions.c)

#CMAKE - link SQLite3
target_link_libraries (testdb sqlite3)


#[[
add_library(include ${PROJECT_SOURCE_DIR}/dbfunctions.c)
add_subdirectory(include)

add_executable(testdb testdb.c)

link_directories(/usr/lib)

target_link_libraries(testdb dbfunctions sqlite3)

target_include_directories(testdb PUBLIC
                          "${PROJECT_BINARY_DIR}"
                          "${PROJECT_SOURCE_DIR}/include"
                          "/usr/include"
                          )
]]

#mit SQLite Library linken

#set(CPACK_PROJECT_NAME ${PROJECT_NAME})
#set(CPACK_PROJECT_VERSION ${PROJECT_VERSION})
#include(CPack)

#[[
add_library(
    ${PROJECT_NAME}_library SHARED
    dbfunctions.c
)


add_executable(
    testdb    
    dbfunctions.c
    testdb.c
)


target_include_directories(
    testdb
    PUBLIC include
)

target_link_libraries(
    testdb
    ${SQLITE3_LINK_LIBRARIES} 
)
]]
#include_directories(${CMAKE_SOURCE_DIR}/include)