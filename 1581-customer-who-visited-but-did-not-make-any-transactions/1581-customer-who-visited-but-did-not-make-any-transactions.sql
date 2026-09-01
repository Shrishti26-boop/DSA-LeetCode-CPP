# Write your MySQL query statement below
-- 1) find those visit_id who had made the transcations
-- 2) get those cust who haven't make trans
-- 3) groupby customer id then count
-- select customer_id 
--    , count(visit_id) as count_no_trans
-- from
-- (select * 
-- from Visits
-- where visit_id not in 
-- (select distinct visit_id 
-- from Transactions)) as cust_as_trans
-- group by customer_id;


-- optimal 
select customer_id 
   , count(visit_id) as count_no_trans
from Visits
where visit_id not in 
(select distinct visit_id 
from Transactions)
group by customer_id;