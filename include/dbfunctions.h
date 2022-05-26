#ifndef DBFUNCTIONS_H
#define DBFUNCTIONS_H


/**
 * @brief Struct <c> exam </c>
 * 
 * @param id Unique ID
 * @param date Date of exam
 * @param time Time of exam
 * @param tester Person who schedules test
 * @param name Room
 * @param rows no of rows in room
 * @param cols no of columns in room
 */
struct exam {
    int id;
    char* date;
    char* time;
    char* tester;  //lecturer
    char* room; //name of room
    int capacity; //Belegungsmuster
    int rows;
    int columns;
};


int getDatabaseVersionNumber();
int callback(void *NotUsed, int argc, char **argv, char **azColName);
int insertInto();
int selectAll();
int lastInsertedId();
int parameterQuery();
int getAllExams();

#endif