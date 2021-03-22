CXXFLAGS += --std=c++17

all: smart cli

debug: CXXFLAGS += -g
debug: smart

smart: person.o student.o parent.o example.o *.h
	$(CXX) $(CXXFLAGS) person.o student.o parent.o example.o -o smart

cli: person.o student.o parent.o cli.o *.h
	$(CXX) $(CXXFLAGS) person.o student.o parent.o cli.o -o cli

person.o: person.cpp *.h
	$(CXX) $(CXXFLAGS) -c person.cpp -o person.o

student.o: student.cpp *.h
	$(CXX) $(CXXFLAGS) -c student.cpp -o student.o

parent.o: parent.cpp *.h
	$(CXX) $(CXXFLAGS) -c parent.cpp -o parent.o

example.o: example.cpp *.h
	$(CXX) $(CXXFLAGS) -c example.cpp -o example.o

cli.o: cli.cpp *.h
	$(CXX) $(CXXFLAGS) -c cli.cpp -o cli.o

#main.o: main.cpp *.h
#	$(CXX) $(CXXFLAGS) -c main.cpp -o main.o

clean:
	rm -f *.o *.gch *~ smart cli
