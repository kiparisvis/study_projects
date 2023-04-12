CREATE INDEX idx_person_name ON person (UPPER(name));

SET enable_indexscan = ON;
SET enable_seqscan = FALSE;
EXPLAIN ANALYZE 
SELECT * FROM person WHERE UPPER(name) = 'ANNA';
