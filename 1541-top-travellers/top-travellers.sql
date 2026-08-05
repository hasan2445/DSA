# Write your MySQL query statement below
select e.name ,sum(case when p.distance is null then 0 else p.distance end) as travelled_distance
from Users e
left join Rides p
on e.id=p.user_id
group by p.user_id
order by travelled_distance desc,name asc