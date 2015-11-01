third([_,_,X|_],Y) :-
  X = Y.

del3([A,B,_|C], Y) :-
  [A,B|C] = Y.

isDuped([]).
isDuped([A,B|Tail]) :-
  A = B,
  isDuped(Tail).

evenSize([]).
evenSize([_|Tail]) :-
  Tail = [_|_],
  not(evenSize(Tail)).
