-- SQLite

CREATE VIEW allExams 
AS 
SELECT 
    e.id, 
    date(e.startDate) AS Date, 
    time(e.startDate) AS Time, 
    (l.firstname ||  ' ' || l.lastname) AS LecturerName, 
    a.label, 
    a.rows,
    a.columns, 
    e.capacity
FROM exam e
    JOIN lecturer l ON e.lecturerId = l.id
    JOIN auditorium a ON e.auditoriumId = a.id

