# Write your MySQL query statement below

# Solution - 1

# if (employee_id % 2) * (name not like 'M%') return 1 , then the bonus will e salary, if any of the two returns 0, then bonus will automatically become 0.
select employee_id , salary * (employee_id % 2) * (name not like 'M%') as bonus
from Employees
order by employee_id;





# Solution - 2

# select employee_id , 
# case when employee_id%2 <>0 and name not like 'M%' then salary 
# else 0
# end 
# as bonus
# from employees
# order by employee_id;