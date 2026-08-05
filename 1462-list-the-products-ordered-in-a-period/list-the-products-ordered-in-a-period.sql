# Write your MySQL query statement below
select e.product_name ,sum(p.unit) as unit
from Products e
left join Orders p
on e.product_id=p.product_id
where year(p.order_date)='2020' and month(p.order_date)='2'
group by p.product_id
having sum(p.unit)>=100