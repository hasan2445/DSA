# Write your MySQL query statement below
select e.employee_id,e.name,count(m.reports_to) as reports_count,round(avg(m.age)) as average_age
from Employees e
join Employees m
on m.reports_to=e.employee_id
group by e.employee_id
order by e.employee_id