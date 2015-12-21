variable usedcounter 0 usedcounter !
create used 100 cells allot 0 used !

variable candidatecounter 0 candidatecounter !
create candidate 100 cells allot 0 candidate !

variable crumbcounter 0 crumbcounter !
create crumb 100 cells allot 0 crumb !

variable multiplier 1 multiplier !


: 3dup ( x y z -- x y z x y z x y z )
    dup     ( x y z z )
    2over   ( x y z z x y )
    rot     ( x y z x y z )
  ;

: 3drop ( x y z -- ) drop drop drop ;

: pack ( near m c -- packedstate )
    swap
    10
    *
    rot
    100
    *
    +
    +
;

: unpack ( packedstate -- near m c )
    100
    /mod
    swap
    10
    /mod
    swap
;

: printstate ( side m c -- )
    ." c: " .
    ." m: " .
    ." near: " .
;

: isused ( n -- bool )
    \ assume false result
    0                                   ( n false )
    swap                                ( false n )
    \ loop through all set elements
    usedcounter                         ( false n &usedcounter )
    @                                   ( false n usedcounter )
    0                                   ( false n usedcounter 0 )
    do                                  ( false n )
        \ compare n with elt i
        dup                             ( false n n )
        used                            ( false n n &used )
        i                               ( false n n &used i )
        cells                           ( false n n &used i*8 )
        +                               ( false n n &used[i] )
        @                               ( false n n used[i] )
        =                               ( false n n==used[i] )
        if                              ( false n )
            nip                         ( n )
            -1                          ( n true )
            swap                        ( true n )
            leave                       ( true n )
        then
    loop                                ( bool n )
    drop                                ( bool )
;

: addused ( n -- )
  used usedcounter @ cells + !
  1 usedcounter +!
;

: pushcandidate ( n -- )
  candidate candidatecounter @ cells + !
  1 candidatecounter +!
;

: popcandidate ( -- n )
  -1 candidatecounter +!
  candidate candidatecounter @ cells +
;

: pushcrumb ( n -- )
  crumb crumbcounter @ cells + !
  1 crumbcounter +!
;

: popcrumb ( -- n )
  -1 crumbcounter +!
  crumb crumbcounter @ cells +
;

: printused ( -- )
  usedcounter
  @
  0
  do
    cr
    used
    i
    cells
    +
    @
    dup
    unpack
    printstate
    drop
  loop
;

: printcandidates ( -- )
  candidatecounter
  @
  0
  do
    cr
    candidate
    i
    cells
    +
    @
    dup
    unpack
    printstate
    drop
  loop
;

: printcrumbs ( -- )
  crumbcounter
  @
  0
  do
    cr
    crumb
    i
    cells
    +
    @
    dup
    unpack
    printstate
    drop
  loop
;

: startstate ( -- near m c ) 1 3 3 ;

: isgoal ( near m c -- bool )
  pack
  200
  =
  if
    -1
  else
    0
  then
;

: isvalid ( near m c -- bool )
  pack
  dup 133 = if -1 else
  dup 122 = if -1 else
  dup 111 = if -1 else
  dup 233 = if -1 else
  dup 222 = if -1 else
  dup 211 = if -1 else
  dup 232 = if -1 else
  dup 231 = if -1 else
  dup 132 = if -1 else
  dup 230 = if -1 else
  dup 131 = if -1 else
  dup 202 = if -1 else
  dup 103 = if -1 else
  dup 201 = if -1 else
  dup 102 = if -1 else
  0
  then then then then then then then then then then then then then then then swap drop
;

: addcandidate ( near m c -- )
  3dup
  isvalid
  false
  = if cr ." invalid " printstate else
  3dup
  pack
  isused
  if cr ." repeat  " printstate else
    3dup pack
    dup
    pushcandidate
    addused
    cr ." fresh   " printstate
  then then
 ;

: successors ( side m c -- )
  3dup cr ." candidates:" cr printstate
  swap rot      ( c m near )
  dup
  1 = if 1 +    ( c m far )
  swap rot      ( far m c )
  -1 multiplier !
  \ -1          ( far m c -1 )
  else 1 -      ( c m near )
  swap rot      ( near m c )
  1 multiplier !
  then
  \ move missionaries
  3dup
  swap          ( side m c side c m )
  multiplier @ + ( side m c side c m+multiplier )
  swap          ( side m c side m+multiplier c)
  addcandidate  ( side m c )
  3dup          ( side m c side m c )
  swap          ( side m c side c m )
  multiplier @  ( side m c side c m multiplier )
  2 *           ( side m c side c m multiplier*2 )
  +             ( side m c side c m+multiplier*2 )
  swap          ( side m c side m+multiplier*2 c )
  addcandidate  ( side m c )
  \ move cannibals
  3dup
  multiplier @ + ( side m c side m c+multiplier )
  addcandidate  ( side m c )
  3dup          ( side m c side m c )
  multiplier @  ( side m c side m c multiplier )
  2 *           ( side m c side m c multiplier*2 )
  +             ( side m c side m c+multiplier*2 )
  addcandidate  ( side m c )
  \ move both
  multiplier @ + ( side m c+multiplier )
  swap          ( side c+multiplier m )
  multiplier @ + ( side c+multiplier m+multiplier )
  swap          ( side m+multiplier c+multiplier )
  addcandidate
;

: search ( -- )
  \ pop a candidate state off
  \ the candidate stack
  popcandidate                  ( &candidate )
  \ push a copy on the
  \ bread-crumb trail stack
  dup                           ( &candidate &candidate )
  pushcrumb                     ( &candidate )
  \ check if it is the goal state
  @                             ( candidate )
  unpack                        ( side m c )
  3dup                          ( side m c )
  isgoal                        ( &candidate bool )
  if                            ( &candidate )
    ." solution found"
    \ if so, print out the contents of
    \ the bread-crumb trail in order.
    \ this is the solution to the puzzle.
    printcrumbs
  else
    \ otherwise:
    \ generate a list of successor states
    \ (there should be exactly 5)
    \ push the valid, legal, fresh successors
    \ on the candidate stack
    successors
    \ call search recursively
    recurse
  then
  popcrumb
;

: start ( -- )
  \ resets the stacks and the used set
  \ todo
  \ puts the start state on the candidate stack
  startstate pack dup pushcandidate
  \ adds it to the used set
  addused
  \ calls search
  search
;
