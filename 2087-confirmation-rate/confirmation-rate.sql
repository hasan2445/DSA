# Write your MySQL query statement below
select e.user_id,round(ifnull(avg(c.action='confirmed'),0),2) as confirmation_rate
from signups as e
left join confirmations as c
on e.user_id=c.user_id
group by e.user_id;