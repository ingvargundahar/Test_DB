-- SQLite

/*
DROP TABLE student_exam;
DROP TABLE exam;
DROP TABLE student;
DROP TABLE class_lecturer;
DROP TABLE lecturer;
DROP TABLE subject;
DROP TABLE class;
DROP TABLE auditorium;
*/

/* --- old tables ---
DROP TABLE class_student;
*/

CREATE TABLE auditorium(
    id INTEGER PRIMARY KEY NOT NULL,
    label varchar(50),
    rows int,
    columns int
);

CREATE TABLE class(
    id INTEGER PRIMARY KEY NOT NULL,
    classname varchar(50)
);


CREATE TABLE subject(
    id INTEGER PRIMARY KEY NOT NULL,
    subjectLabel varchar(10),
    subject varchar(100)
);

CREATE TABLE lecturer(
    id INTEGER PRIMARY KEY NOT NULL,
    firstname varchar(50),
    lastname varchar(50),
    subjectId int,
    CONSTRAINT FK_SubjectLecturer FOREIGN KEY (subjectId) REFERENCES subject(id)
);

CREATE TABLE class_lecturer(
    lecturerId int,
    classId int,
    CONSTRAINT FK_LecturerClassLecturer FOREIGN KEY (lecturerId) REFERENCES lecturer(id),
    CONSTRAINT FK_ClassClassLecturer FOREIGN KEY (classId) REFERENCES class(id),
    CONSTRAINT PK_ClassId_LecturerId PRIMARY KEY (lecturerId, classId)
);

CREATE TABLE student(
    id INTEGER PRIMARY KEY NOT NULL,
    personalIdentifier int, -- 10-stellige Nummer, FH-Ausweis (Personenkennzeichen)
    username varchar(10), -- laut CIS "username", Schema "ic21bxxx"
    classId int, --2A, 2B, 2C, 2D, 2E
    CONSTRAINT FK_ClassStudent FOREIGN KEY (classId) REFERENCES class(id)
);

CREATE TABLE exam(
    id INTEGER PRIMARY KEY NOT NULL,
    auditoriumId int,
    classId int,
    lecturerId int,
    startDate datetime,
    endDate datetime,
    capacity int, --25, 50, 100
    CONSTRAINT FK_AuditoriumExam FOREIGN KEY (auditoriumId) REFERENCES auditorium(id),
    CONSTRAINT FK_ClassExam FOREIGN KEY (classId) REFERENCES class(id),
    CONSTRAINT FK_LecturerExam FOREIGN KEY (lecturerId) REFERENCES lecturer(id)
);

/*
-- nicht mehr benötigt - Studenten sind immer nur Teil einer Klasse
CREATE TABLE class_student(
    classId int,
    studentId int,
    CONSTRAINT FK_ClassClassStudent FOREIGN KEY (classId) REFERENCES class(id),
    CONSTRAINT FK_StudentClassStudent FOREIGN KEY (studentId) REFERENCES student(id),
    CONSTRAINT PK_ClassId_StudentId PRIMARY KEY (classId, studentId)
);
*/

CREATE TABLE student_exam(
    id INTEGER PRIMARY KEY NOT NULL,
    studentId int,
    examId int,
    seat_row int,
    seat_column int,
    CONSTRAINT FK_StudentStudentExam FOREIGN KEY (studentId) REFERENCES student(id),
    CONSTRAINT FK_ExamStudentExam FOREIGN KEY (examId) REFERENCES exam(id)
);