-- SQLite

--[get users by classname]
--TODO: variable geht in sqlite nicht => temp table
--DECLARE @class = '2D';
SELECT s.id, personalIdentifier, username
FROM student s
    JOIN class c ON s.classId = c.id
WHERE classname LIKE '2C'

--[get classes from lecturer]
--TODO: variable geht in sqlite nicht => temp table
--DECLARE varchar @lastname  = '%Perry%';
SELECT classname
FROM lecturer l
    JOIN class_lecturer cl ON l.id = cl.lecturerId
    JOIN class c ON cl.classId = c.id
WHERE l.lastname LIKE '%Perry%'

--[get lecturer & subject]
SELECT (l.firstname ||  ' ' || l.lastname) AS LecturerName, s.subjectLabel, s.subject
FROM lecturer l
    JOIN subject s ON l.subjectId = s.id 
WHERE l.lastname LIKE '%Perry%'

--[get exam for examt_struct]
SELECT e.id, date(e.startDate) AS Date, time(e.startDate) AS Time, (l.firstname ||  ' ' || l.lastname) AS LecturerName, a.label, a.rows, a.columns, e.capacity
FROM exam e
    JOIN lecturer l ON e.lecturerId = l.id
    JOIN auditorium a ON e.auditoriumId = a.id

--[get students from exam]

--[get classId & lecturerId]
SELECT c.id, l.id
FROM lecturer l
    JOIN class_lecturer cl ON l.id = cl.lecturerId
    JOIN class c ON cl.classId = c.id
WHERE (l.firstname ||  ' ' || l.lastname) LIKE '%Holzer%'