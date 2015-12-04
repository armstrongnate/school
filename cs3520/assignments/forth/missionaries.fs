: 3dup ( x y z -- x y z x y z x y z )
    dup     ( x y z z )
    2over   ( x y z z x y )
    rot     ( x y z x y z )
  ;

: 3drop ( x y z -- ) drop drop drop ;
