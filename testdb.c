#include <sqlite3.h> //"sqlite/sqlite3.h"
#include <stdio.h>
#include <stdlib.h>
#include "include/dbfunctions.h"

int main(void){

    //getDatabaseVersionNumber();

    struct exam newExam = {0};
    newExam.date = "2022-06-01"; 
    newExam.time = "19:30:00";
    newExam.tester = "Holzer";
    newExam.room = "A1.06";
    newExam.capacity = 50;

    int insertedId = setExam(newExam);
    printf("Last inserted id: %d\n", insertedId);

    int rowCount;
    int *rowCountP = &rowCount;
    struct exam *examArray = getAllExams(rowCountP);

    for(int i = 0; i < rowCount; i++){
        printf("id: %d, date: %s, time: %s, tester: %s, room: %s,  rows: %d, columns: %d, capacity: %d\n", 
            examArray[i].id, examArray[i].date, examArray[i].time, examArray[i].tester, 
            examArray[i].room, examArray[i].rows, examArray[i].columns, examArray[i].capacity);
    }

    printf("Returned rows: %d\n", rowCount);

    free(examArray);

    return EXIT_SUCCESS;
}