#include "../include/dbfunctions.h"
#include <stdio.h>
#include <stdlib.h>
#include <sqlite3.h>
#include <string.h>

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

int examStructCallBack(void *exam, int argc, char **argv, char **azColName) {
    

    //TODO: exam-array add-funktion?
    //TODO: Zuweisung der Felder zu exam

    /*
    for (int i = 0; i < argc; i++) {

        printf("%s = %s\n", azColName[i], argv[i] ? argv[i] : "NULL");
    }
    
    printf("\n");
    */
    
    return 0;
}

int insertInto(){
    
    sqlite3 *db;
    char *err_msg = 0;
    
    int rc = sqlite3_open("test.db", &db);
    
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

int selectAll(){

    sqlite3 *db;
    char *err_msg = 0;
    
    int rc = sqlite3_open("test.db", &db);
    
    if (rc != SQLITE_OK) {
        
        fprintf(stderr, "Cannot open database: %s\n", 
                sqlite3_errmsg(db));
        sqlite3_close(db);
        
        return 1;
    }
    
    char *sql = "SELECT * FROM Cars";
        
    rc = sqlite3_exec(db, sql, printCallback, 0, &err_msg);
    
    if (rc != SQLITE_OK ) {
        
        fprintf(stderr, "Failed to select data\n");
        fprintf(stderr, "SQL error: %s\n", err_msg);

        sqlite3_free(err_msg);
        sqlite3_close(db);
        
        return 1;
    } 
    
    sqlite3_close(db);
    
    return 0;
}

int lastInsertedId(){
    sqlite3 *db;
    char *err_msg = 0;
    
    int rc = sqlite3_open(":memory:", &db);
    
    if (rc != SQLITE_OK) {
        
        fprintf(stderr, "Cannot open database: %s\n", sqlite3_errmsg(db));
        sqlite3_close(db);
        
        return 1;
    }
    
    char *sql = "CREATE TABLE Friends(Id INTEGER PRIMARY KEY, Name TEXT);"
    "INSERT INTO Friends(Name) VALUES ('Tom');"
    "INSERT INTO Friends(Name) VALUES ('Rebecca');"
    "INSERT INTO Friends(Name) VALUES ('Jim');"
    "INSERT INTO Friends(Name) VALUES ('Roger');"
    "INSERT INTO Friends(Name) VALUES ('Robert');";
        
    
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

int parameterQuery(){

    sqlite3 *db;
    char *err_msg = 0;
    sqlite3_stmt *res;
    
    int rc = sqlite3_open("test.db", &db);
    
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

/**
 * \brief Returns all exams from the database.
 *
 * \param examArray The array to save the returned rows to.
 * \returns int Returns rowcount of query.
 */
struct exam * getAllExams(int *returnedRows){
    
    sqlite3 *db;
    sqlite3_stmt *stmt;
    char *err_msg = 0;
    
    int rc = sqlite3_open("/home/ingvar/Documents/projects/Test_DB/database/testdb.db", &db);
    
    if (rc != SQLITE_OK) {
        
        fprintf(stderr, "Cannot open database: %s\n", 
                sqlite3_errmsg(db));
        sqlite3_close(db);
        
        return NULL; //-1;
    }
    
    //count rows first
    char *sqlCountRows = "SELECT COUNT(e.id) FROM exam e";
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


    char *sql = "SELECT e.id, date(e.startDate) AS Date, time(e.startDate) AS Time, (l.firstname ||  ' ' || l.lastname) AS LecturerName, a.label, a.rows, a.columns, e.capacity \
                 FROM exam e \
                    JOIN lecturer l ON e.lecturerId = l.id \
                    JOIN auditorium a ON e.auditoriumId = a.id";
  

    //rc = sqlite3_exec(db, sql, printCallback, examArray, &err_msg);

    rc = sqlite3_prepare_v2(db, sql, -1, &stmt, 0);
    
    if (rc != SQLITE_OK ) {
        
        fprintf(stderr, "Failed to select data\n");
        fprintf(stderr, "SQL error: %s\n", err_msg);
        sqlite3_free(err_msg);
        sqlite3_close(db);
        
        return NULL; //-1;
    } 

    int counter = 0;
    struct exam * examArray = malloc(sizeof(*examArray) * (*returnedRows));
    //size_t newSize = sizeof(examArray);

    do{

        //struct exam *examEntry = &examArray[counter++];

        rc = sqlite3_step(stmt);

         if (rc == SQLITE_DONE) {
            //printf("No more rows ...\n");
            break;
        } else if (rc != SQLITE_ROW) {
            fprintf(stderr, "Problem: %s\n", sqlite3_errmsg(db)); 
            sqlite3_finalize(stmt);
            return NULL; //-1;
        }

        examArray[counter].id = sqlite3_column_int(stmt, 0);

        //char * entryDate = (char *) sqlite3_column_text(stmt, 1);
        examArray[counter].date = (char *)malloc(sizeof(char*) * strlen(sqlite3_column_text(stmt, 1)));
        strcpy(examArray[counter].date , sqlite3_column_text(stmt, 1));
        //examArray[counter].date = entryDate; // ? entryDate : (char*) "NULL";
        //strcpy(examEntry->date, sqlite3_column_text(stmt, 1));

        //char * entryTime = (char *) sqlite3_column_text(stmt, 2);
        examArray[counter].time = (char *)malloc(sizeof(char*) * strlen(sqlite3_column_text(stmt, 2)));
        strcpy(examArray[counter].time , sqlite3_column_text(stmt, 2));

        //char * entryTester = (char *) sqlite3_column_text(stmt, 3);
        examArray[counter].tester = (char *)malloc(sizeof(char*) * strlen(sqlite3_column_text(stmt, 3)));
        strcpy(examArray[counter].tester , sqlite3_column_text(stmt, 3));

        //char * entryRoom = (char *) sqlite3_column_text(stmt, 4);
        examArray[counter].room = (char *)malloc(sizeof(char*) * strlen(sqlite3_column_text(stmt, 4)));
        strcpy(examArray[counter].room , sqlite3_column_text(stmt, 4));

        examArray[counter].rows = sqlite3_column_int(stmt, 5);
        examArray[counter].columns = sqlite3_column_int(stmt, 6);
        examArray[counter].capacity = sqlite3_column_int(stmt, 7);

        /*
        newSize += sizeof(struct exam);
        examArray = realloc(examArray, newSize);
        */
       counter++;

    }while(rc == SQLITE_ROW);

    sqlite3_finalize(stmt);
    sqlite3_close(db);
    
    return examArray;
}