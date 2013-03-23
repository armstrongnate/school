PROGRAM := graphics1
OBJECTS := graphics1.o
CXXFLAGS := -Wall
LDFLAGS := -lglut -lGLU

all: $(OBJECTS) $(PROGRAM)

$(PROGRAM): $(OBJECTS)
	$(CXX) $(CXXFLAGS) -o $@ $^ $(LDFLAGS)

graphics1.o: graphics1.cpp

clean:
	-rm -f *.o *~ $(PROGRAM) $(OBJECTS)


