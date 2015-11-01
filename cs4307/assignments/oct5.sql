-- Dates

-- date between, label column "year"
select title_id, title_name, pubdate, extract(year from pubdate) as "year"
  from titles
  where extract(year from pubdate) between 2001 and 2002;

-- date greater than
select title_id, title_name, pubdate
  from titles
  where pubdate>"2001-01-01";

-- only january, rename all column names
select title_id as "title",
       title_name as "name",
       pubdate as "publish date"
  from titles
  where extract(month from pubdate) = 01;

-- add 26 years to publisher date
select title_id, title_name, pubdate + interval 26 year as "Copyright"
  from titles;


-- current time
select CURRENT_TIMESTAMP;

-- null substitutes
select title_id, title_name, coalesce(price, "Priceless") from titles;

select title_id,
  title_name,
  case when price is NULL then "Priceless"
       when price>10 then "Expensive"
       when price<=10 then "Cheap"
  end as "Price"
  from titles;
