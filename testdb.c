#include <sqlite3.h> //"sqlite/sqlite3.h"
#include <stdio.h>
#include <stdlib.h>
#include "include/dbfunctions.h"


int main(void){

    //printf("%s\n", sqlite3_libversion());
    //getDatabaseVersionNumber();

    //struct exam * examArray = (struct exam *)malloc(sizeof(struct exam *));

    int *rowCount;
    struct exam * examArray = getAllExams(&rowCount);

    for(int i = 0; i < rowCount; i++){
        printf("id: %d, date: %s, time: %s, tester: %s, room: %s,  rows: %d, columns: %d, capacity: %d\n", 
            examArray[i].id, examArray[i].date, examArray[i].time, examArray[i].tester, 
            examArray[i].room, examArray[i].rows, examArray[i].columns, examArray[i].capacity);
    }

    printf("Returned rows: %d\n", rowCount);

    free(examArray);

    return EXIT_SUCCESS;
}