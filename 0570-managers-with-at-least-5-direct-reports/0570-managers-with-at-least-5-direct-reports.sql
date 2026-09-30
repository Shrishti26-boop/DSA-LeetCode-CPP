# Write your MySQL query statement below
select m.name from 
employee e
join employee m
on e.managerId=m.id
group by m.id,m.name
having count(*)>=5;