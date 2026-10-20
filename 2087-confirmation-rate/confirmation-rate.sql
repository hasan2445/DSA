# Write your MySQL query statement below
select e.user_id,round(avg(case when c.action='confirmed' then 1 else 0 end),2) as confirmation_rate
from Signups e
left join Confirmations c
on e.user_id= c.user_id
group by e.user_id