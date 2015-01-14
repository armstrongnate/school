# CS 4550 - Compilers

* [Course Website](http://cit.dixie.edu/cs/4550/)
* 2:00pm - 3:40pm MW in Hazy 119

## Mon Jan 12

Notes for this day were lost due to my own stupidity. We reviewed c++ and how
it compared to c.

Highlights (that I can remember):

* c++ methods are non-virtual by default
* if you want an overriden method to be called it needs to be virtual. Consider
the following:

```c++
class Shape {
  virtual void Draw();
  virtual int NumSides() = 0; // purely virtual
}

class Circle {
  void Draw();
  int NumSides();
}

int main() {
  std::vector<Shape *> shapes;
  for (shape in shapes) {
    shape->Draw()
  }
  return 0;
}

// if one of the shapes is a Circle, the Circle's Draw method will
// only get called if the Draw method is declared as virtual
```

## Wed Jan 14

### C++ Initializations

```c++
class A {
public:
  A(int xx) : x(xx) {
    cout << "A constructor" << endl;
  }

  // 1
  virtual ~A() {
    cout << "A destructor" << endl;
  }

  virtual void Draw() {
    cout << "Drawing.." << endl;
  }
private:
  int x;
};

class B : public A {
public:
  B(int xx, int yy) : y(yy), A(xx) {
    cout << "B constructor" << endl;
  }
  ~B() {
    cout << "B destructor" << endl;
  }

  void Draw() {
    cout << "Also drawing.." << endl;
    A::Draw(); // 2
  }
private:
  int y;
}
```

1. base class destructors should almost always be virtual
2. this is how you call a parent's method

* constructors and destructors automatically call their parents
* **avoid dynamic memory unless you really need it**. If you know you're always
going to have 1 of something, don't store it as a pointer.

#### robust example

How to make a class with dynamic memory robust?

1. destructor
  * any `new` you have needs a corresponding `delete`
  * any _newables_ need to be set to `NULL` in the constructor
2. copy constructor (skipped in class)
3. assignment operator (skipped in class)

```c++
class robust {
public:
  robust() {
    x = NULL;
  }
  ~robust() {
    if (x) {
      delete []x;
    }
  }

  void SetSize(int num) {
    // release any old memory
    if (x) {
      delete []x;
      x = NULL;
    }

    if (num <= 0)
      return;

    // allocate any new memory
    x = new int[num];
  }

private:
  int *x; // 1
};

int main() {
  cout << "How many integers do you really need? ";
  int num;
  cin >> num;
  robust r;
  r.SetSize(num);

  return 0;
}
```

1. dynamically allocating memory because we don't know how many `x`s we are going
to have. This is opposed to doing `int x[n]` because we don't know `n`.

### Pointers

Size | Type
---- | ----
1 | char
2 | short int
4 | long int
4 | int
8 | int
4 | float
8 | double

* pointers to each type are their own types (`char *`, `int *`, etc)

![Pointers](images/pointers.JPG)

Before we could pass by reference there was this (which is what pass by reference
does behind the scenes):

```c++
void Foo(int *x) {
  *x = *x+1;
}

int x = 5;
Foo(x);
cout << "x = " << x; // x = 6
```

example | when to use
------  | ------
`void Foo(Student const &x)` | when you don't want it changed and it's a big type
`void Foo(int &x)` | you don't want to copy
`void Foo(int x)` | you don't mind copying (keep cost in mind)
