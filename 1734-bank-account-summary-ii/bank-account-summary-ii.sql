# Write your MySQL query statement below
select e.name ,sum(t.amount) as balance
from Users e
left join Transactions t
on e.account=t.account
group by t.account
having sum(t.amount)>10000