CC=g++
CFLAGS=
LDFLAGS=
SOURCES=src/geometry/airfoil.cpp
RELEASE_MAIN=src/main.cpp
TEST_MAIN=src/test/main.cpp
OBJECTS=$(SOURCES:.cpp=.o)
EXECUTABLE=ParaSuite

all:
	mkdir -p bin
	$(CC) $(CFLAGS) $(RELEASE_MAIN) $(SOURCES) -o bin/$(EXECUTABLE)

clean:
	rm -rf bin test/bin
	
test:
	mkdir -p bin
	$(CC) $(CFLAGS) $(TEST_MAIN) $(SOURCES) -o bin/test
	bin/test
	
run-test:
	bin/test