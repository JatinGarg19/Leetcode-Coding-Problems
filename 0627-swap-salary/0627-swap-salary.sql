# Write your MySQL query statement below

# Use case - when sex = 'f', set sex as 'm', else set sex as 'f'.
update Salary set sex = (case when sex = 'f' then 'm' else 'f' end);