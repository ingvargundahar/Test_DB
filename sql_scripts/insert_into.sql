-- SQLite

/*
DELETE FROM auditorium;
DELETE FROM subject;
DELETE FROM lecturer;
DELETE FROM class;
DELETE FROM class_lecturer;
DELETE FROM student;
*/

INSERT INTO auditorium (label, rows, columns)
VALUES  ('A6.09', 4, 9), 
        ('F2.01', 6, 10), 
        ('F2.02', 4, 12), 
        ('A3.15', 5, 10), 
        ('A1.06', 6, 8)

INSERT INTO subject (subjectLabel, subject)
VALUES  ('BSYS', 'Betriebssysteme'), 
        ('HWSE2', 'Hardwarenahe Softwareentwicklung 2'), 
        ('MACS2', 'Mathematik für Computer Science 2'), 
        ('PROLB', 'Objektorientierte Programmierung und Modellierung'), 
        ('TK', 'Telekommunikation')
        /*
        ,('KREKO', 'Kreativität und Komplexität'), 
        ('ENG2', 'Business English')
        */

INSERT INTO lecturer (firstname, lastname, subjectId)
VALUES  ('Kevin', 'Perry', 1) ,             -- 1
        ('Robert', 'Trausmuth', 2),         -- 2
        ('Joseph', 'Wenninger', 2),         -- 3
        ('Francoise', 'Porchet', 3),        -- 4
        ('Susanne', 'Teschl', 3),           -- 5
        ('Markus', 'Holzer', 4),            -- 6
        ('Markus', 'Demetz', 4),            -- 7
        ('Reinhard', 'Fleck', 5),           -- 8
        ('Thomas', 'Zeitlhofer', 5)         -- 9
        /*
        ,('Jutta', 'Durstberger', 6),        -- 10
        ('Christiane', 'Lauschitzky', 7)    -- 11
        */

INSERT INTO class (classname)
VALUES ('2A'), ('2B'), ('2C'), ('2D'), ('2E') --, ('2CD'), ('2ABE')

INSERT INTO class_lecturer (lecturerId, classId)
VALUES  (1, 3), (1, 4), (1, 5),     --BSYS: Perry, 2C/D/E
        (2, 3), (2, 4), (2, 5),     --HWSE2: Trausmuth, 2C/D/E
        (3, 1), (3, 2),             --HWSE2: Wenninger, 2A/B
        (4, 3), (4, 4),             --MACS2: Porchet, 2C/D
        (5, 1), (5, 2), (5, 5),     --MACS2: Teschl, 2A/B/E
        (6, 4),                     --PROLB: Holzer, 2D
        (7, 5),                     --PROLB: Demetz, 2E
        (8, 3), (8, 4),             --TK: Fleck, 2C/D
        (9, 2), (9, 5)              --TK: Zeitlhofer, 2B/E

INSERT INTO student (personalIdentifier, username, classId)
VALUES  --2A
        ('2110258001', 'ic21b001', 1), ('2110258012', 'ic21b012', 1), ('2110258003', 'ic21b003', 1), ('2110258110', 'ic21b110', 1),
        ('2110258010', 'ic21b010', 1), ('2110258013', 'ic21b013', 1), ('2110258086', 'ic21b086', 1), ('2110258113', 'ic21b113', 1),
        ('2110258053', 'ic21b053', 1), ('2110258041', 'ic21b041', 1), ('2010258038', 'ic20b038', 1), 
        --2B
        ('2110258036', 'ic21b036', 2), ('2110258002', 'ic21b002', 2), ('2110258048', 'ic21b048', 2), ('2110258007', 'ic21b007', 2), 
        ('2110258049', 'ic21b049', 2), ('2110258009', 'ic21b009', 2), ('2110258011', 'ic21b011', 2), ('2110258080', 'ic21b080', 2), 
        ('2110258111', 'ic21b111', 2), ('2010258100', 'ic20b100', 2), ('2110258071', 'ic21b071', 2), ('2110258117', 'ic21b117', 2),
        ('2110258014', 'ic21b014', 2), ('2110258064', 'ic21b064', 2), ('2110258102', 'ic21b102', 2), 
        --2C
        ('2110258015', 'ic21b015', 3), ('2110258078', 'ic21b078', 3), ('2110258006', 'ic21b006', 3), ('2010258082', 'ic20b082', 3), 
        ('2110258027', 'ic21b027', 3), ('2110258028', 'ic21b028', 3), ('2110258008', 'ic21b008', 3), ('2110258137', 'ic21b137', 3), 
        ('2110258096', 'ic21b096', 3), ('2110258093', 'ic21b093', 3), ('2110258035', 'ic21b035', 3), ('2110258112', 'ic21b112', 3),
        ('2010258044', 'ic20b044', 3), ('2110258124', 'ic21b124', 3), ('2110258124', 'ic21b124', 3), ('2110258062', 'ic21b062', 3),
        --2D
        ('2110258045', 'ic21b045', 4), ('2110258060', 'ic21b060', 4), ('2110258065', 'ic21b065', 4), ('2110258066', 'ic21b066', 4), 
        ('2110258040', 'ic21b040', 4), ('2110258029', 'ic21b029', 4), ('2110258073', 'ic21b073', 4), ('2010258023', 'ic20b023', 4), 
        ('2010258028', 'ic20b028', 4), ('2010258086', 'ic20b086', 4), ('2010258075', 'ic20b075', 4), ('2110258032', 'ic21b032', 4),
        --2E
        ('2110258026', 'ic21b026', 5), ('2110258128', 'ic21b128', 5), ('2110258070', 'ic21b070', 5), ('2010258008', 'ic20b008', 5), 
        ('2110258120', 'ic21b120', 5), ('2110258084', 'ic21b084', 5), ('2110258109', 'ic21b109', 5), ('2010258064', 'ic20b064', 5), 
        ('2110258004', 'ic21b004', 5), ('2110258031', 'ic21b031', 5), ('2110258133', 'ic21b133', 5), ('2110258074', 'ic21b074', 5),
        ('2010258052', 'ic20b052', 5), ('2110258106', 'ic21b106', 5), ('2110258005', 'ic21b005', 5), ('2110258107', 'ic21b107', 5)


INSERT INTO exam (auditoriumId, classId, lecturerId, startDate, endDate, capacity)
VALUES  (1, 1, 1, '2022-05-30 17:00:00', '2022-05-30 20:00:00', 50),
        (2, 2, 2, '2022-06-07 17:30:00', '2022-05-30 20:30:00', 100),
        (3, 3, 3, '2022-06-07 15:30:00', '2022-05-30 18:30:00', 25)

INSERT INTO student_exam (studentId, examId, seat_row, seat_column)
VALUES  -- exam 1
        ( 1, 1, 1, 1), ( 2, 1, 1, 3), (3, 1, 1, 5), (4, 1, 1, 7), (5, 1, 1, 9),         --1st row
        ( 6, 1, 2, 2), ( 7, 1, 2, 4), (8, 1, 2, 6), (9, 1, 2, 8),                       --2nd row
        (10, 1, 3, 1), (11, 1, 3, 3),                                                   --3rd row
        -- exam 2
        (12, 2, 1, 1), (13, 2, 1, 2), (14, 2, 1, 3), (15, 2, 1, 4), (16, 2, 1, 5),      --1st row
        (17, 2, 1, 6), (18, 2, 1, 7), (19, 2, 1, 8), (20, 2, 1, 9), (21, 2, 1, 10),     --1st row
        (22, 2, 2, 1), (23, 2, 2, 2), (24, 2, 2, 3), (25, 2, 2, 4), (26, 2, 2, 5),      --2nd row
        -- exam 3
        (27, 3, 1, 1), (28, 3, 1, 4), (29, 3, 1, 7), (30, 3, 1, 10),                    --1st row 
        (31, 3, 2, 3), (32, 3, 2, 6), (33, 3, 2, 9), (34, 3, 2, 12),                    --2nd row
        (35, 3, 3, 1), (36, 3, 3, 4), (37, 3, 3, 7), (38, 3, 3, 10),                    --3rd row
        (39, 3, 4, 3), (40, 3, 4, 6), (41, 3, 4, 9), (42, 3, 4, 12)                     --4th row                               
