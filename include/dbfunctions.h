#ifndef DBFUNCTIONS_H
#define DBFUNCTIONS_H

#include <time.h>

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

extern const char* const connectionString;

int getDatabaseVersionNumber();
int printCallback(void *NotUsed, int argc, char **argv, char **azColName);
int lastInsertedId();
int parameterQuery();
int setExam(struct exam newExam);
struct exam * getAllExams(int *returnedRows);
time_t makeDateTimeFromStringAndAddTime(const char * const datetimestring, int hoursToAdd);

#endif