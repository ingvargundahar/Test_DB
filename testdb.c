#include <sqlite3.h> //"sqlite/sqlite3.h"
#include <stdio.h>
#include <stdlib.h>
#include "include/dbfunctions.h"

int main(void){

    //getDatabaseVersionNumber();

    struct exam newExam = {0};
    newExam.date = "2022-06-01"; 
    newExam.time = "19:30:00";
    newExam.name = "Holzer";
    newExam.rows = 5;
    newExam.columns = 10;
    newExam.capacity = 50;

    int insertedId = addExamInDb(newExam);
    printf("Last inserted id: %d\n", insertedId);

    int rowCount;
    int *rowCountP = &rowCount;
    struct exam *examArray = getListOfExams(rowCountP);

    for(int i = 0; i < rowCount; i++){
        printf("id: %d, date: %s, time: %s, lecturer name: %s, rows: %d, columns: %d, capacity: %d\n", 
            examArray[i].id, examArray[i].date, examArray[i].time, examArray[i].name, 
             examArray[i].rows, examArray[i].columns, examArray[i].capacity);
    }

    printf("Returned rows: %d\n", rowCount);

    free(examArray);

    return EXIT_SUCCESS;
}