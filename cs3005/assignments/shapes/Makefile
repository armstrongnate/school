PROGRAM := graphics1
OBJECTS := graphics1.o shape.o rectangle.o button.o
CXXFLAGS := -Wall
LDFLAGS := -lglut -lGLU

all: $(OBJECTS) $(PROGRAM)

$(PROGRAM): $(OBJECTS)
	$(CXX) $(CXXFLAGS) -o $@ $^ $(LDFLAGS)

graphics1.o: graphics1.cpp shape.h rectangle.h button.h
shape.o: shape.cpp shape.h
rectangle.o: rectangle.cpp rectangle.h shape.h
button.o: button.cpp button.h rectangle.h shape.h
# circle.o: circle.cpp shape.h shape.h
# triangle.o: triangle.o triangle.h shape.h

clean:
	-rm -f *.o *~ $(PROGRAM) $(OBJECTS)


