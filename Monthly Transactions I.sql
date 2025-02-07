# Write your MySQL query statement below
select DATE_FORMAT(trans_date, "%Y-%m") as month, country, COUNT(state) as trans_count, SUM(case when state = "approved" then 1 else 0 end) as approved_count, 
SUM(amount) as trans_total_amount, SUM(case when state = "approved" then amount else 0 end) as approved_total_amount 
from Transactions 
group by month, country

/* Learned to use the case when statements combined with SUM query function */

/* Important docs related to DATE_FORMAT() FUNCTION IN SQL :- https://devdocs.io/mariadb/date_format/index */
