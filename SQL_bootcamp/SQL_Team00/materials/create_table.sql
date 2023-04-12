create table road
( point1 varchar not null,
  point2 varchar not null,
  cost integer not null
  );

alter table road add constraint ch_point check ( point1 in ('a','b','c','d') and point2 in ('a','b','c','d') and NOT point1=point2);

insert into road values ('a','b', 10);
insert into road values ('a','c', 15);
insert into road values ('a','d', 20);
insert into road values ('b','c', 35);
insert into road values ('b','d', 25);
insert into road values ('c','d', 30);

WITH CTE AS (
     SELECT point2, point1, cost FROM road
)
insert into road
SELECT * FROM CTE;
