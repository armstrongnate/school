class Shape
  def __init__(self):
    self.color = None

  def draw(self):
    raise NotImplementedError("needs a draw method")

  def change_color(self, new_color):
    self.color = new_color

  def remove(self):
    pass

class Rectangle(Shape):
  def __init__(self):
    self.points = []

  def draw(self):
    pass

class Triangle(Shape):
  def __init(self):
    self.point = []

  def draw(self):
