-- SQLite

/*
DROP TABLE auditorium;
DROP TABLE class;
DROP TABLE subject;
DROP TABLE lecturer;
DROP TABLE student;
DROP TABLE exam;
DROP TABLE class_student;
DROP TABLE student_auditorium;
*/

CREATE TABLE auditorium(
    id int IDENTITY(1,1) PRIMARY KEY,
    label varchar(50),
    rows int,
    columns int
);

CREATE TABLE class(
    id int IDENTITY(1,1) PRIMARY KEY,
    classname varchar(50)
);

CREATE TABLE subject(
    id int IDENTITY(1,1) PRIMARY KEY,
    subject varchar(100)
);

CREATE TABLE lecturer(
    id int IDENTITY(1,1) PRIMARY KEY,
    lecturer_firstname varchar(50),
    lecturer_lastname varchar(50),
    subjectId int,
    CONSTRAINT FK_SubjectLecturer FOREIGN KEY (subjectId) REFERENCES subject(id)
);

CREATE TABLE student(
    id int IDENTITY(1,1) PRIMARY KEY,
    studentId varchar(10) 
);

CREATE TABLE exam(
    id int IDENTITY(1,1) PRIMARY KEY,
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

CREATE TABLE class_student(
    classId int,
    studentId int,
    CONSTRAINT FK_ClassClassStudent FOREIGN KEY (classId) REFERENCES class(id),
    CONSTRAINT FK_StudentClassStudent FOREIGN KEY (studentId) REFERENCES student(id)
);

CREATE TABLE student_auditorium(
    id int IDENTITY(1,1) PRIMARY KEY,
    studentId int,
    auditoriumId int,
    CONSTRAINT FK_StudentStudentAuditorium FOREIGN KEY (studentId) REFERENCES student(id),
    CONSTRAINT FK_AuditoriumStudentAuditorium FOREIGN KEY (auditoriumId) REFERENCES auditorium(id)
);