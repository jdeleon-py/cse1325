CXXFLAGS = --std=c++17

test: fraction.o test.o *.h
	$(CXX) $(CXXFLAGS) fraction.o test.o -o test

fraction.o: fraction.cpp *.h
	$(CXX) $(CXXFLAGS) -c fraction.cpp -o fraction.o

test.o: test.cpp *.h
	$(CXX) $(CXXFLAGS) -c test.cpp -o test.o

clean:
	rm -f *.o *.gch *~ a.out test
