CREATE SEQUENCE IF NOT EXISTS seq_person_discounts START 1;
SELECT setval('seq_person_discounts', (SELECT max(id) FROM person_discounts) + 1, false);
ALTER TABLE person_discounts
ALTER COLUMN id SET DEFAULT nextval ('seq_person_discounts');
