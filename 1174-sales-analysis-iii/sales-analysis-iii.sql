# Write your MySQL query statement below
select e.product_id,e.product_name
from Product e
left join Sales s
on e.product_id=s.product_id
group by s.product_id
having min(sale_date)>='2019-01-01' and max(sale_date)<='2019-04-30'
