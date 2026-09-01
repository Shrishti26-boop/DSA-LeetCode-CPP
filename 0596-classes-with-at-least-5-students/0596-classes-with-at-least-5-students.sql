# Write your MySQL query statement below
-- 1) find the number of students for each class
-- 2) find classes having atleast 5 students

SELECT class
FROM Courses
GROUP BY class
HAVING COUNT(student) >= 5;

-- select class
-- from (select class
--      , count(student) as cnt
--      from courses
--      group by class) as class_wise_strength
--      where cnt>=5;