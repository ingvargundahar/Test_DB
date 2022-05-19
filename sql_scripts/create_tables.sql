-- SQLite

/*
DROP TABLE lecture;
DROP TABLE class_students;
DROP TABLE class;
DROP TABLE students;
DROP TABLE auditorium;
DROP TABLE booking;
*/

CREATE TABLE auditorium(
    id int IDENTITY(1,1) PRIMARY KEY,
    label varchar(50),
    rows int,
    columns int
);

CREATE TABLE booking(
    id int IDENTITY(1,1) PRIMARY KEY,
    auditoriumId int,
    classId int,
    lectureId int,
    startDate datetime,
    endDate datetime,
    CONSTRAINT FK_AuditoriumBooking FOREIGN KEY (auditoriumId) REFERENCES auditorium(id),
    CONSTRAINT FK_ClassBooking FOREIGN KEY (classId) REFERENCES class(id),
    CONSTRAINT FK_LectureBooking FOREIGN KEY (lectureId) REFERENCES lecture(id)
);

CREATE TABLE class(
    id int IDENTITY(1,1) PRIMARY KEY,
    classname varchar(50)
);

CREATE TABLE lecture(
    id int IDENTITY(1,1) PRIMARY KEY,
    lecture varchar(50)
);

CREATE TABLE students(
    id int IDENTITY(1,1) PRIMARY KEY,
    studentId varchar(10) 
);

CREATE TABLE class_students(
    classId int,
    studentId int,
    CONSTRAINT FK_ClassClassStudents FOREIGN KEY (classId) REFERENCES class(id),
    CONSTRAINT FK_StudentClassStudents FOREIGN KEY (studentId) REFERENCES student(id)
);