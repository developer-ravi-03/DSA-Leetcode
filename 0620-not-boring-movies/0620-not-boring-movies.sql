# Write your MySQL query statement below
SELECT * FROM Cinema WHERE ID%2=1 AND description!='boring' order by rating desc;