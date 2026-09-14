# Write your MySQL query statement below
-- with cte subquety
select name
from Employee
where id in(
    (select managerId
    from Employee
    group by managerId 
    having count(*)>=5)
);