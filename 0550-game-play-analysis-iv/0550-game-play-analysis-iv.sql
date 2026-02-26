# Write your MySQL query statement below
SELECT
  ROUND(
    COUNT(DISTINCT CASE
      WHEN a.event_date = DATE_ADD(f.first_date, INTERVAL 1 DAY) THEN a.player_id
    END) / COUNT(DISTINCT f.player_id),
  2) AS fraction
FROM (
  SELECT player_id, MIN(event_date) AS first_date
  FROM Activity
  GROUP BY player_id
) f
LEFT JOIN Activity a
  ON a.player_id = f.player_id;