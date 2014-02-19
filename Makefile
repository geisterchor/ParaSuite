CC=g++
CFLAGS=-std=c++0x
LDFLAGS=-lplplotcxxd
SOURCES=src/geometry/airfoil.cpp src/geometry/spline.cpp
RELEASE_MAIN=src/main.cpp
TEST_MAIN=src/test/main.cpp
OBJECTS=$(SOURCES:.cpp=.o)
EXECUTABLE=ParaSuite

all: geomgen

geomgen:
	mkdir -p bin
	$(CC) $(CFLAGS) src/geomgen.cpp $(SOURCES) $(LDFLAGS) -o bin/PSGeomGen

clean:
	rm -rf bin test/bin
	
test:
	mkdir -p bin
	$(CC) $(CFLAGS) $(TEST_MAIN) $(SOURCES) $(LDFLAGS) -o bin/test
	bin/test
	
run-test:
	bin/test
