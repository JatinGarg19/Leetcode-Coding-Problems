# Please write a DELETE statement and DO NOT write a SELECT statement.
# Write your MySQL query statement below

delete p1
from Person as p1, Person as p2
where p1.email = p2.email and p1.id > p2.id;


# delete p.*
# from Person as p, (
#     select email, min(id) as minId
#     from Person
#     group by email
#     having count(*) > 1
# ) as q
# where p.email = q.email and id > q.minId;
