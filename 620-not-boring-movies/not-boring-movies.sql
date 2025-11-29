# Sol : 01
SELECT * 
FROM Cinema 
WHERE id % 2 != 0 AND description <> 'boring'
ORDER BY rating desc;


# Sol : 02
-- SELECT *
-- FROM Cinema
-- WHERE MOD(id, 2) = 1
--   AND description <> 'boring'
-- ORDER BY rating DESC;


# Sol : 03
-- SELECT *
-- FROM Cinema
-- WHERE id % 2 = 1
--   AND NOT(description = 'boring')
-- ORDER BY rating DESC;


# SOl : 04
-- SELECT *
-- FROM Cinema
-- WHERE RIGHT(id, 1) IN ('1','3','5','7','9')
--   AND description <> 'boring'
-- ORDER BY rating DESC;


# SOl : 05
-- SELECT *
-- FROM Cinema
-- WHERE 
--     CASE WHEN id % 2 = 1 THEN 1 ELSE 0 END = 1
--     AND description <> 'boring'
-- ORDER BY rating DESC;

# Sol : 06
-- SELECT *
-- FROM Cinema
-- WHERE id IN (SELECT id FROM Cinema WHERE id % 2 = 1)
--   AND description <> 'boring'
-- ORDER BY rating DESC;

# Write your MySQL query statement below
