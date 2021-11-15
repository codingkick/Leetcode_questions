# Write your MySQL query statement below
select Customers.name as Customers
# where customerId = null
from Customers
left join 
Orders on Customers.id=Orders.customerId
where Orders.customerId is null;