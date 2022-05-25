#include "../include/dbfunctions.h"
#include <stdio.h>
#include <stdlib.h>
#include <sqlite3.h>

int getDatabaseVersionNumber(){
    sqlite3 *db;
    sqlite3_stmt *res;
    int rc;
    
    rc = sqlite3_open(":memory:", &db);

    if(rc != SQLITE_OK){

        fprintf(stderr, "Cannot open database: %s\n", sqlite3_errmsg(db));
        sqlite3_close(db);
    }

    rc = sqlite3_prepare_v2(db, "SELECT SQLITE_VERSION()", -1, &res, 0);

    if(rc != SQLITE_OK){

        fprintf(stderr, "Failed to fetch data: %s\n", sqlite3_errmsg(db));
        sqlite3_close(db);

        return 1;
    }

    rc = sqlite3_step(res);

    if(rc == SQLITE_ROW){
        printf("The database version number is: %s\n", sqlite3_column_text(res, 0));
    } 

    sqlite3_finalize(res);
    sqlite3_close(db);
}