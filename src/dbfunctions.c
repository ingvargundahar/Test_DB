#include "../include/dbfunctions.h"
#include <stdio.h>
#include <stdlib.h>
#include <sqlite3.h>
#include <string.h>

const char* const connectionString = "../database/contacttracing.db";

int getDatabaseVersionNumber(){
    sqlite3 *db;
    sqlite3_stmt *res;
    int rc;
    
    rc = sqlite3_open(":memory:", &db);

    if(rc != SQLITE_OK){

        fprintf(stderr, "Cannot open database: %s\n", sqlite3_errmsg(db));
        sqlite3_close(db);

        return 1;
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

int printCallback(void *NotUsed, int argc, char **argv, char **azColName) {
    
    NotUsed = 0;
    
    for (int i = 0; i < argc; i++) {

        printf("%s = %s\n", azColName[i], argv[i] ? argv[i] : "NULL");
    }
    
    printf("\n");
    
    return 0;
}

int insertInto(){
    
    sqlite3 *db;
    char *err_msg = 0;
    
    int rc = sqlite3_open((char*)connectionString, &db);
    
    if (rc != SQLITE_OK) {
        
        fprintf(stderr, "Cannot open database: %s\n", sqlite3_errmsg(db));
        sqlite3_close(db);
        
        return 1;
    }
    
    char *sql = "DROP TABLE IF EXISTS Cars;" 
                "CREATE TABLE Cars(Id INT, Name TEXT, Price INT);" 
                "INSERT INTO Cars VALUES(1, 'Audi', 52642);" 
                "INSERT INTO Cars VALUES(2, 'Mercedes', 57127);" 
                "INSERT INTO Cars VALUES(3, 'Skoda', 9000);" 
                "INSERT INTO Cars VALUES(4, 'Volvo', 29000);" 
                "INSERT INTO Cars VALUES(5, 'Bentley', 350000);" 
                "INSERT INTO Cars VALUES(6, 'Citroen', 21000);" 
                "INSERT INTO Cars VALUES(7, 'Hummer', 41400);" 
                "INSERT INTO Cars VALUES(8, 'Volkswagen', 21600);";

    rc = sqlite3_exec(db, sql, 0, 0, &err_msg);
    
    if (rc != SQLITE_OK ) {
        
        fprintf(stderr, "SQL error: %s\n", err_msg);
        
        sqlite3_free(err_msg);        
        sqlite3_close(db);
        
        return 1;
    } 
    
    sqlite3_close(db);
    
    return 0;
}

int parameterQuery(){

    sqlite3 *db;
    char *err_msg = 0;
    sqlite3_stmt *res;
    
    int rc = sqlite3_open((char*)connectionString, &db);
    
    if (rc != SQLITE_OK) {
        
        fprintf(stderr, "Cannot open database: %s\n", sqlite3_errmsg(db));
        sqlite3_close(db);
        
        return 1;
    }
    
    char *sql = "SELECT Id, Name FROM Cars WHERE Id = @id";
        
    rc = sqlite3_prepare_v2(db, sql, -1, &res, 0);
    
    if (rc == SQLITE_OK) {
        
        int idx = sqlite3_bind_parameter_index(res, "@id");
        int value = 4;
        sqlite3_bind_int(res, idx, value);
        
    } else {
        
        fprintf(stderr, "Failed to execute statement: %s\n", sqlite3_errmsg(db));
    }
    
    int step = sqlite3_step(res);
    
    if (step == SQLITE_ROW) {
        
        printf("%s: ", sqlite3_column_text(res, 0));
        printf("%s\n", sqlite3_column_text(res, 1));
        
    } 

    sqlite3_finalize(res);
    sqlite3_close(db);
    
    return 0;
}

int setExam(struct exam newExam){
    
    sqlite3 *db;
    sqlite3_stmt *stmt;
    char *err_msg = 0;
    int insertedId = -1;
    
    int rc = sqlite3_open((char*)connectionString, &db);
    
    if (rc != SQLITE_OK) {
        
        fprintf(stderr, "Cannot open database: %s\n", sqlite3_errmsg(db));
        sqlite3_close(db);
        
        return 1;
    }

    /*
        STEPS
        1. get auditoriumId from name
        2. get classId from name
        3. get lecturerId from name
        4. insert into exam
    */

    //AUDITORIUM-ID
    int auditoriumId;
    char *sql = "SELECT auditoriumId FROM auditorium WHERE label = ?";
    rc = sqlite3_prepare_v2(db, sql, -1, &stmt, 0);
    if (rc == SQLITE_OK) {
        sqlite3_bind_text(stmt, 1, newExam.room, -1, SQLITE_STATIC);
    } else {
        fprintf(stderr, "Failed to execute statement: %s\n", sqlite3_errmsg(db));
    }
    
    rc = sqlite3_step(stmt);
    
    if (rc == SQLITE_ROW) {
        auditoriumId = sqlite3_column_int(stmt, 0);
        printf("%d ", auditoriumId);
    } 
    
    //CLASS-ID
    int classId;
    sql = "SELECT classId FROM class WHERE lecturername = ?";
    rc = sqlite3_prepare_v2(db, sql, -1, &stmt, 0);
    if (rc == SQLITE_OK) {
        sqlite3_bind_text(stmt, 1, newExam.tester, -1, SQLITE_STATIC);
    } else {
        fprintf(stderr, "Failed to execute statement: %s\n", sqlite3_errmsg(db));
    }
    
    rc = sqlite3_step(stmt);
    
    if (rc == SQLITE_ROW) {
        auditoriumId = sqlite3_column_int(stmt, 0);
        printf("%d ", auditoriumId);
    } 



    sql = "INSERT INTO exam (auditoriumId, classId, lecturerId, startDate, endDate, capacity) \
                    VALUES (?, ?, ?, ?, ?, ?); ";
        
    
    rc = sqlite3_exec(db, sql, 0, 0, &err_msg);
    
    if (rc != SQLITE_OK ) {
        
        fprintf(stderr, "Failed to create table\n");
        fprintf(stderr, "SQL error: %s\n", err_msg);
        sqlite3_free(err_msg);
        
    } else {
        
        fprintf(stdout, "Table Friends created successfully\n");
    }
    
    int last_id = sqlite3_last_insert_rowid(db);
    printf("The last Id of the inserted row is %d\n", last_id);

    sqlite3_close(db);
    
    return 0;
}

/**
 * \brief Returns all exams from the database.
 *
 * \param examArray Saves the returned rows to int pointer.
 * \returns struct exam* Returns array of struct exams to be used in main.
 */
struct exam * getAllExams(int *returnedRows){
    
    sqlite3 *db;
    sqlite3_stmt *stmt;
    char *err_msg = 0;
    
    int rc = sqlite3_open((char*)connectionString, &db);
    
    if (rc != SQLITE_OK) {
        
        fprintf(stderr, "Cannot open database: %s\n", 
                sqlite3_errmsg(db));
        sqlite3_close(db);
        
        return NULL;
    }
    
    //count rows first
    char *sqlCountRows = "SELECT COUNT(e.id) FROM exam e;";
    rc = sqlite3_prepare_v2(db, sqlCountRows, -1, &stmt, 0);
    if (rc != SQLITE_OK ) {
        
        fprintf(stderr, "Failed to select data\n");
        fprintf(stderr, "SQL error: %s\n", err_msg);
        sqlite3_free(err_msg);
        sqlite3_close(db);
        
        return NULL; //-1;
    }
    rc = sqlite3_step(stmt); 
    *returnedRows = sqlite3_column_int(stmt, 0);
    sqlite3_finalize(stmt);
    //----

    //get allExams data
    char *sql = "SELECT * FROM allExams;";

    rc = sqlite3_prepare_v2(db, sql, -1, &stmt, 0);
    
    if (rc != SQLITE_OK ) {
        
        fprintf(stderr, "Failed to select data\n");
        fprintf(stderr, "SQL error: %s\n", err_msg);
        sqlite3_free(err_msg);
        sqlite3_close(db);
        
        return NULL;
    } 

    int counter = 0;
    struct exam * examArray = malloc(sizeof(*examArray) * (*returnedRows));

    do{
        rc = sqlite3_step(stmt);

         if (rc == SQLITE_DONE) {
            //printf("No more rows ...\n");
            break;
        } else if (rc != SQLITE_ROW) {
            fprintf(stderr, "Problem: %s\n", sqlite3_errmsg(db)); 
            sqlite3_finalize(stmt);
            return NULL;
        }

        examArray[counter].id = sqlite3_column_int(stmt, 0);

        examArray[counter].date = (char *)malloc(sizeof(char*) * strlen(sqlite3_column_text(stmt, 1)));
        strcpy(examArray[counter].date , sqlite3_column_text(stmt, 1));

        examArray[counter].time = (char *)malloc(sizeof(char*) * strlen(sqlite3_column_text(stmt, 2)));
        strcpy(examArray[counter].time , sqlite3_column_text(stmt, 2));

        examArray[counter].tester = (char *)malloc(sizeof(char*) * strlen(sqlite3_column_text(stmt, 3)));
        strcpy(examArray[counter].tester , sqlite3_column_text(stmt, 3));

        examArray[counter].room = (char *)malloc(sizeof(char*) * strlen(sqlite3_column_text(stmt, 4)));
        strcpy(examArray[counter].room , sqlite3_column_text(stmt, 4));

        examArray[counter].rows = sqlite3_column_int(stmt, 5);
        examArray[counter].columns = sqlite3_column_int(stmt, 6);
        examArray[counter].capacity = sqlite3_column_int(stmt, 7);

       counter++;

    }while(rc == SQLITE_ROW);

    sqlite3_finalize(stmt);
    sqlite3_close(db);
    
    return examArray;
}