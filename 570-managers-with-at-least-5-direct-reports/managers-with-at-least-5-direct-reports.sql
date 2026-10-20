# Write your MySQL query statement below
select e.name
from Employee e
left join Employee m
on e.id=m.managerId
group by e.id
having count(e.id)>=5