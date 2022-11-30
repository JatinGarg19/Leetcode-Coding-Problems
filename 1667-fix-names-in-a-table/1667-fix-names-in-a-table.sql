# Write your MySQL query statement below

# UPPER(A) where A is string
# LOWER(A) where A is string
# SUBSTR(A,index,length) where A is string index is starting index(1 index insead of 0 index) and length which is optional
# So to get first letter we can use SUBSTR(name,1,1)
# To get the remaining string we can use SUBSTR(name,2) // length is not required here
# CONCAT(A,B) where we concat two strings A+B

select user_id , concat(upper(substr(name,1,1)), lower(substr(name,2))) as name
from Users
order by user_id;
