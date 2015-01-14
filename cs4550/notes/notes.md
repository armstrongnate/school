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
