# Write your MySQL query statement below

# Basically, what we are doing is we are selecting names of those customers from Customer table whose id is not present in Orders Table as customerId.

SELECT name as Customers FROM Customers
WHERE id NOT in (SELECT customerId FROM Orders);
