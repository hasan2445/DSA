# Write your MySQL query statement below
select p.product_name,e.year,e.price
from Sales e
left join Product p
on p.product_id=e.product_id