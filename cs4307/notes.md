## Table forms

### ONF

"Zero Normal Form" identified by tables in a table.

Problems:

- insert
- delete
- update 

### 1NF

"First Normal Form" is no tables within tables.

Keeps everything in the same table. You have the customer
info and the transaction amount in the same table. So if you delete the customer
you also delete the transaction which might not be what you want.

### 2NF

"Second Normal Form" fixes key problems. Has a customers table and a transactions
table. The transaction has a foreign key for its customer. The problem with the
example is that the `city`, `state`, and `zip` should be their own table in order
to be 3NF.

### 3NF (BCNF)

"Third Normal Form" fixes other problems like moving zip, city, and state into their
own table so if a city changes its name it is changed on all records referencing it.

A lot of people would not go to third normal form in this case but cities do not
typically change their names.

BCNF is in reference to the dude that invented it. His initials are 'BC'.

### 4NF

"Fourth Normal Form" is way too complicated so we are not going to worry about it.

## BOB Diagram

```
CUSTOMER
--------
cust, C, 7
name, V, 30
zip, C, 9, -> ZIP.zip
```

```
ZIP
---
zip, C, 9
city, V, 30
state, C, 2
```

```
TRANS
----
tid, C, 10
cust, C, 7, -> CUSTOMER.cust
date, D
code, C, 1
amount, N, 10, 2
```

### Legend

| Key | Name | Requirements |
| :--: | ---- | ------------ |
| N | number | digits, decimals |
| C | character | length |
| D | date | _none_ |
| V | variable | max size |
