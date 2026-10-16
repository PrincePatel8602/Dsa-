SELECT d.name
FROM Employee d
WHERE (
    SELECT COUNT(*)
    FROM Employee e
    WHERE e.managerId = d.id
) >= 5;