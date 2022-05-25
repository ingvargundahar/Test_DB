-- SQLite

--get users by classname
--TODO: geht in sqlite nicht => temp table
--DECLARE @class = '2D';

SELECT personalIdentifier, username
FROM student s
    JOIN class c ON s.classId = c.id
WHERE classname LIKE '2D'

--get classes from lecturer
--TODO: geht in sqlite nicht => temp table
--DECLARE varchar @lastname  = '%Perry%';

SELECT classname
FROM lecturer l
    JOIN class_lecturer cl ON l.id = cl.lecturerId
    JOIN class c ON cl.classId = c.id
WHERE l.lastname LIKE '%Perry%'

--get lecturer & subject
SELECT (l.firstname ||  ' ' || l.lastname) AS LecturerName, s.subjectLabel, s.subject
FROM lecturer l
    JOIN subject s ON l.subjectId = s.id 
WHERE l.lastname LIKE '%Perry%'

