# Write your MySQL query statement below
select name as 'Employee'
from Employee E
where exists(select *from Employee where E.managerId = Employee.id and E.salary>Employee.salary)