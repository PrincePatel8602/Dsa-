SELECT e.id FROM Weather e
WHERE e.temperature >(SELECT d.temperature FROM Weather d
WHERE d.recordDate = DATE_SUB(e.recordDate, INTERVAL 1 DAY));