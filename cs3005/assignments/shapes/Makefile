PROGRAM := graphics1
OBJECTS := graphics1.o shape.o rectangle.o button.o shapes.o circle.o triangle.o
CXXFLAGS := -Wall
LDFLAGS := -lglut -lGLU

all: $(OBJECTS) $(PROGRAM)

$(PROGRAM): $(OBJECTS)
	$(CXX) $(CXXFLAGS) -o $@ $^ $(LDFLAGS)

graphics1.o: graphics1.cpp shape.h rectangle.h button.h shapes.h
shape.o: shape.cpp shape.h
rectangle.o: rectangle.cpp rectangle.h shape.h
button.o: button.cpp button.h rectangle.h shape.h
shapes.o: shapes.cpp shapes.h button.h circle.h
circle.o: circle.cpp circle.h shape.h
triangle.o: triangle.cpp triangle.h shape.h

clean:
	-rm -f *.o *~ $(PROGRAM) $(OBJECTS)


