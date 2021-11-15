# Write your MySQL query statement below
# select email as 'Email'
# from Person P
# where exists(select *from Person where P.id < Person.id and P.email = Person.email);

select email as 'Email'
from Person
group by email
having count(id)>1;