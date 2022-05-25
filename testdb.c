#include <sqlite3.h> //"sqlite/sqlite3.h"
#include <stdio.h>
#include <stdlib.h>
#include "include/dbfunctions.h"


int main(void){

    //printf("%s\n", sqlite3_libversion());
    getDatabaseVersionNumber();

    return EXIT_SUCCESS;
}