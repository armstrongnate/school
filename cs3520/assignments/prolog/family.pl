/* Parents */

parent(loraine,barbie).
parent(loraine,diane).
parent(barbie,jake).
parent(diane,chad).
parent(chad,bell).
parent(stef,bell).
parent(jake,rylee).
parent(skylar,rylee).

male(ruwee).
male(vader).
male(luke).
male(han).
male(ben).
male(jacen).
male(anakin).

female(shmi).
female(jobal).
female(padme).
female(mara).
female(leia).
female(jaina).

mother(X,Y) :-
  female(X),
  parent(X,Y).

father(X,Y) :-
  male(X),
  parent(X,Y).

sister(X,Y) :-
  not(X=Y),
  female(X),
  parent(Parent,X),
  parent(Parent,Y).


grandson(X,Y) :-
  male(X),
  parent(Parent,X),
  parent(Y,Parent).

grandparent(X,Y) :-
  parent(Parent,Y),
  parent(X,Parent).

firstCousin(X,Y) :-
  not(X=Y),
  grandparent(GX,X),
  grandparent(GY,Y),
  (GX=GY).

child(X,Y) :- parent(Y,X).

descendent(X,Y) :- child(X,Y).
descendent(X,Y) :-
  child(Z,Y),
  descendent(X,Z).
