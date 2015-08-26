# ML

Not an imperative language.

Statement: do something

Expression: way of evaluating something

An `if` expression can be reused.

_Referencial transparency_ is kind of like caching the expression since it will
always have the same output given the same inputs.

_Value bindings_ are not variables because they can't change (but they can be rewritten).

**TODO** have a usable ML installation by next time.

## Functions

```
val square = fn x => x * x;
```

To specify the type of the input param:

```
val square = fn x:real => x * x;
```

Define a method on the fly (_lambda functions_):

```
(fn a => a mod 3) 13;
```

Use `fun` as a shortcut for defining a function:

```
fun makeodd x = 2 * (x div 2) + 1;

// same as
val makeodd = fn x => 2 * (x div 2) + 1;
```

Functions can return functions:

```
val f = fn x => fn y => x + y;

// invoke: (f 6) 7; => 13
```

### Partial evaluation

```
fun adder a b = a + b;
val add5 = adder 5; // notice only 1 input given so it returns a function
add5 7; // => val it = 12;
```

### Compose

```
fun compose f g x = f (g x);
```

You can use `o` to do just what `compose` does above.

### Lexical Closures

Consider the following:
```
(fn x => fn y => x + y) 1 5;
```

How does the function of `y` know about `x`? The function of `y` is not defined
until the function of `x` is called with the `1`.

Lexical Scoping is better than Dynamic Scoping. Dynamic scoping is dangerous
because of the way it resolves _free variables_.

## Numeric types

`int`, `real`

### char

* constants `#"A"` `#"y"

### string

* constants `"A"` `"y"
* concatenation s1^s2

### bool

* constants `false` `true`
* p `andalso` q // same as `&&`
* p `orelse` q // same as `||`
