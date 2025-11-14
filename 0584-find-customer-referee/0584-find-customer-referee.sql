/* Write your T-SQL query statement below */
SELECT name 
from Customer
where referee_id is null or referee_id != 2;