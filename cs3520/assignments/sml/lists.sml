exception Undefined
exception ERROR of string option;
fun throwError msg = raise ERROR (SOME msg);
fun assert_equal a b = if a = b then 0 else throwError "not equal";

(* Define a function member of type ''a * ''a list -> bool so that member (e,L)
   is true if and only if e is an element of the list L *)

fun member (_, []) = false
  | member (e, (x::xs)) = if x = e then true else member (e, xs)

(* Define a function less of type int * int list -> int list so that less (e,L)
   is a list of all the integers in L that are less than e *)

fun less (e, lst) =
  let fun inner ([], a) = a
        | inner ((x::xs), a) =
    if x < e then inner (xs, (a @ [x])) else inner (xs, a)
  in
    inner (lst, [])
  end

(* Define a function repeats of type ''a list -> bool so that repeats L is true
   if and only if the list L has two equal elements next to each other *)

fun repeats [] = false
  | repeats (lst as x::xs) =
  let fun inner ([], _) = false
    | inner ((y::ys), last) = if last = y then true else inner (ys, y)
  in
    inner (xs, x)
  end

(* Represent a polynomial using a list of its (real) coefficients, starting with
   the constant coefficient and going only as high as necessary. For example,
   3x²+5x+1 would be represented as the list [1.0,5.0,3.0] and x³-2x as
   [0.0,~2.0,0.0,1.0]. Write a function eval of type real list * real -> real
   that takes a polynomial represented this way and a value for x and returns
   the value of that polynomial at the given x. For example,
   eval ([1.0,5.0,3.0],2.0) should evaluate to 23.0, because when x=2,
   3x²+5x+1=23 *)

fun eval (lst: real list, x) = foldr (fn (c, a) => x * a + c) 0.0 lst

(* Write a bubblesort function of type int list -> int list. Here is a review of
   the bubblesort algorithm. Compare the first two elements of the list. If they
   are out of order relative to each other, swap them. Then compare the second
   and third elements and swap them if they are out of order, etc. After
   completing the list, repeat until you make a complete pass over the list with
   no swaps. Note: write any helper functions as local functions using
   let..in..end *)

 fun bubble_select [] = []
   | bubble_select [a] = [a]
   | bubble_select (a::b::xs) =
       if b < a then b::(bubble_select(a::xs)) else a::(bubble_select(b::xs))

fun bubblesort [] = []
  | bubblesort (x::xs) = bubble_select (x::(bubblesort xs))

(* In the following exercises, implement sets as lists, where each element of a
   set appears exactly once in the list and the elements appear in no particular
   order. Do not assume you can sort the lists. Do assume that input lists have
   no duplicate elements, and do guarantee that output lists have no duplicate
   elements. *)

(* Write a function to construct the union of two sets. It should have type
   ''a list * ''a list -> ''a list. Note: you may use the member function you
   defined earlier. *)

fun union (lst1, []) = lst1
  | union (lst1, lst2) =
    if member (hd lst2, lst1) then
      union (lst1, tl lst2)
    else
      union (lst1 @ [hd lst2], tl lst2)

(* Write a function to construct the intersection of two sets. It should have
   type ''a list * ''a list -> ''a list. *)

fun append_uniq x lst = if member (x, lst) then lst else lst @ [x]
fun member_both x lst1 lst2 = member (x, lst1) andalso member (x, lst2)

fun intersection (lst1, lst2) =
  let fun inner [] a = a
        | inner (lst as x::xs) a =
          if member_both x lst1 lst2 then
            inner xs (append_uniq x a)
          else inner xs a
  in
    inner lst2 (inner lst1 [])
  end

(* Write a function to construct the powerset of any set. A set's powerset is
   the set of all of its subsets. Consider the set A={1,2,3}. It has various
   subsets: {1}, {1,2}, and so on. Of course the empty set, ∅, is a subset of
   every set. The powerset of A is the set of all subsets of A:

      {x: x ⊆ A}={∅, {1}, {2}, {3}, {1,2}, {1,3}, {2,3}, {1,2,3}}

   Your powerset function should take a list (representing the set) and return a
   list of lists (representing the set of all subsets of the original set).
   powerset [1,2] should return [[1,2], [1], [3], []] (in any order). Your
   powerset function need on work on the untyped empty list; it may give an
   error message when evaluating powerset nil. But it should work on a typed
   empty list, so powerset (nil : int list) should give the right answer ([[]]).
   *)

fun powerset xs = foldr (fn (x, rest) => rest @ map (fn ys => x::ys) rest) [[]] xs
