CXXFLAGS = --std=c++17

all: main test

test: fraction.o test.o *.h
	$(CXX) $(CXXFLAGS) fraction.o test.o -o test

main: fraction.o main.o *.h
	$(CXX) $(CXXFLAGS) fraction.o main.o -o main

fraction.o: fraction.cpp *.h
	$(CXX) $(CXXFLAGS) -c fraction.cpp -o fraction.o

test.o: test.cpp *.h
	$(CXX) $(CXXFLAGS) -c test.cpp -o test.o

main.o: main.cpp *.h
	$(CXX) $(CXXFLAGS) -c main.cpp -o main.o

clean:
	rm -f *.o *.gch *~ a.out test main
