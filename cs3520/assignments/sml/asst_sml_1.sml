exception ERROR of string option;
fun throwError msg = raise ERROR (SOME msg);
fun assert_equal a b = if a = b then 0 else throwError "not equal";

(* Write a function cube of type int -> int that returns the cube of
its parameter *)

fun cube x = x * x * x;
assert_equal 8 (cube 2);

(* Write a function cuber of type real -> real that returns the cube
of its parameter *)

fun cuber x:real = x * x * x;
assert_equal 8.0 (cuber 2.0);

(* Write a function fourth of type 'a list -> 'a that returns the
fourth element of a list. Your function need not behave well on
lists with less than four elements. *)

fun fourth (_::_::_::x::xs) = x;
assert_equal 4 (fourth [1, 2, 3, 4]);
assert_equal 4 (fourth [1, 2, 3, 4, 5]);

(* Write a function min3 of type int * int * int -> int that returns
the smallest of three integers *)

fun min3 (a:int, b:int, c:int) =
  if a < b andalso a < c then a
  else if b < a andalso b < c then b
  else c;
assert_equal 1 (min3 (1, 2, 3));
assert_equal 1 (min3 (1, 1, 1));
assert_equal 1 (min3 (3, 2, 1));
assert_equal 0 (min3 (0, 0, 0));

(* Write a function red3 of type 'a * 'b * 'c -> 'a * 'c that
converts a tuple with three elements into one with two by elminating
the second element *)

fun red3 (a, b, c) = (a, c);
assert_equal (1, 3) (red3 (1, 2, 3));

(* Write a function thirds of type string -> char that returns the
third character of a string. Your function need not behave well on
strings with lengths less than 3 *)

fun thirds s =
  let fun third (_::_::x::xs) = x
  in
    third (explode s)
  end;
assert_equal #"t" (thirds "cat");
assert_equal #"t" (thirds "nate");

(* Write a function cycle1 of type 'a list -> 'a list whose output
list is the same as the input list, but with the first element of
the list moved to the end. For example, cycle1 [1,2,3,4] shoudl
return [2,3,4,1] *)

fun cycle1 (x::xs) = xs @ [x]
  | cycle1 [] = [];
assert_equal [2, 3, 1] (cycle1 [1, 2, 3]);
assert_equal [2, 3, 4, 1] (cycle1 [1, 2, 3, 4]);

(* Write a function sort3 of type real * real * real -> real list
that returns a sorted list of three real numbers *)

fun sort3 (a:real, b:real, c:real) =
  let fun insertinorder n (lst as x::xs) =
      if n < x then n :: lst
      else x :: (insertinorder n xs)
    | insertinorder n _ = [n]
  in
    insertinorder a (insertinorder b (insertinorder c []))
  end;
assert_equal [1.0, 2.0, 3.0] (sort3 (2.0, 1.0, 3.0));
assert_equal [3.0, 30.0, 300.0] (sort3 (300.0, 30.0, 3.0));

(* Write a function del3 of type 'a list -> 'a list whose output
list is the same as the input list, but with the third element
deleted. Your function need not behave well on lists with lengths
less than 3 *)

fun del3 (a::b::_::xs) = a::b::xs;
assert_equal [1, 2] (del3 [1, 2, 3]);
assert_equal [1, 2, 4] (del3 [1, 2, 3, 4]);

(* Write a function sqsum of type int -> int that takes a
non-negative integer n and returns the sum of the squares of all the
integers 0 through n. Your function need not behave well on inputs
less than zero *)

fun sqsum 0 = 0
  | sqsum n = n * n + sqsum (n - 1);
assert_equal 14 (sqsum 3);
assert_equal 30 (sqsum 4);

(* Write a function cycle of type 'a list * int -> 'a list that
takes a list and an integer n as input and returns the same list,
but with the first element cycled to the end of the list n times.
(Make use of your cycle1 function from a previous exercise.) For
example, cycle ([1,2,3,4,5,6],2) should return the list
[3,4,5,6,1,2] *)

fun cycle (lst, 0) = lst
  | cycle (lst, n) = cycle ((cycle1 lst), (n - 1));
assert_equal [3,4,5,6,1,2] (cycle ([1,2,3,4,5,6], 2));

(* Write a function pow of type real * int -> real that raises a
real number to an integer power. Your function need not behave well
if the integer power is negative *)

fun pow (a:real, 1) = a
  | pow (a, 0) = 1.0
  | pow (a, b) = a * pow (a, b-1);
assert_equal 8.0 (pow (2.0, 3));
assert_equal 64.0 (pow (8.0, 2));
assert_equal 256.0 (pow (2.0, 8));
assert_equal 1.0 (pow (3.14, 0));

(* Write a function max of type int list -> int that returns the
largest element of a list of integers. Your function need not behave
well if the list is empty. Hint: Write a helper function maxhelper
that takes as a second parameter the largest element seen so far.
Then you can complete the exercise by defining

    fun max x = maxhelper (tl x, hd x)
*)

fun max [] = 0
  | max (lst as x::xs) =
  let fun help [] a = a
        | help (y::ys) m = if y > m then help ys y else help ys m
  in
    help lst x
  end;
assert_equal 3 (max [1,2,3]);
assert_equal 6 (max [6,5,4]);
assert_equal 400 (max [3,200,400,220,120]);

(* Write a function isPrime of type int -> bool that returns true
if and only if its integer parameter is a prime number. Your
function need not behave well if the parameter is negative *)

fun isPrime 0 = false
  | isPrime 1 = false
  | isPrime 2 = true
  | isPrime n =
  let fun inner _ 1 = true
        | inner x m = if x mod m = 0 then false else inner x (m - 1)
    in
      inner n (n - 1)
    end;
assert_equal true (isPrime 2);
assert_equal true (isPrime 3);
assert_equal true (isPrime 5);
assert_equal false (isPrime 6);
assert_equal true (isPrime 7);

(* Write a function select of type 'a list * ('a -> bool) -> 'a list
that takes a list and a function f as parameters. Your function
should apply f to each element of the list and should return a new
list containing only those elements of the original list for which f
returned true. (The elements of the new list may be given in any
order.) For example, evaluating select ([1,2,3,4,5,6,7,8,10],
isPrime) should result in a list like [7,5,3,2]. This is an example
of a higher-order function, since it takes another function as a
parameter *)

fun select (lst, f) =
  let fun inner _ a [] = a
        | inner f a (y::ys) = if f y then inner f (y::a) ys else inner f a ys
  in
    inner f [] lst
  end;
assert_equal [7,5,3,2] (select ([1,2,3,4,5,6,7,8,10], isPrime));
