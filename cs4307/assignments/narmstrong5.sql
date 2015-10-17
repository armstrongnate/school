/*

-- where
select title_id, title_name from titles where type="biography";

-- order by, desc is optional
select * from titles order by pages desc;

-- between
select * from authors where zip between "8000" and "9000";
select * from authors where zip> "8000" and zip< "9000";

-- tee output
rm narmstrong5.txt
tee narmstrong5.txt
source narmstrong5.sql

*/

-- #1
use books;
show tables;

-- #2
select * from authors;

-- #3
select emp_id, emp_name from employees;

-- #4
select distinct state from publishers;

-- #5
select title_id, title_name, price from titles order by price desc;

-- #6
select title_id, title_name from titles where type="children";

-- #7
select title_id, title_name from titles where (type != "history" or type != "biography");

-- #8
select au_id, au_fname, au_lname, phone from authors where phone like "%549%";

-- #9
select au_id, au_fname, au_lname, zip from authors where zip between "90000" and "99999";

-- #10
select au_id, au_fname, au_lname, state from authors where (state = "NY" or state = "CA");
