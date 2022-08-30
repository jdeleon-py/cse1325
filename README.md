# UTA: CSE 1325 - Object-Oriented Programming

### Summary
This repository will detail my work and documentation for UTA's CSE 1325 (OOP) course using the C++ language.

The first three directories (P02, P03, P04, P10) will consist of stand-alone programs explaining key OOP concepts covered 
early on in the course, consisting (but not limited to):
* P02/ -> Encapsulation
* P03/ -> Operator Overloading
* P04/ -> Aggregate/Composite Classes
* P05/ -> Threading

The following directory, indexed as SMART, will be an accumulation of a single program, further covering some crucial 
lessons pertaining to OOP while also examining the gtkmm library for GUI development. This directory will consist of the 
following sub-directories, serving as benchmarks for the accumulating GUI product (as seen in SMART/P09/):
* P05/
* P06/
* P07/
* P08/
* P09/

### Notes
For each project directory, a series of notes and considerations for the accompanying program will be documented, along 
with UML class diagrams designed by the professor. UML class diagrams are followed for the majority of this repo; any 
changes that are made will be documented accordingly.

Each directory will have the original assignment describing the requirements and notes necessary to construct the 
program. Most assignment descriptions will cover a "full-credit", "bonus", and "extreme-bonus" implementation, each of 
which will be implemented as this repo is more developed.

## External Resources and References
### Resources
Link to prof's GitHub page: [Professor Rice's GitHub Page](https://github.com/prof-rice)

### Makefiles
A template for a standard Makefile used in this repo has the following layout:
```bash
CXXFLAGS = --std=c++20

all: exe1 exe2

exe1: main1.o class1.o *.h
	$(CXX) $(CXXFLAGS) main1.o class1.o -o exe1

exe2: main2.o class2.o *.h
	$(CXX) $(CXXFLAGS) main2.o class2.o -o exe2

main1.o: main1.cpp *.h
	$(CXX) $(CXXFLAGS) -c main1.cpp -o main1.o

class1.o: class1.cpp *.h
	$(CXX) $(CXXFLAGS) -c class1.cpp -o class1.o

main2.o: main2.cpp *.h
	$(CXX) $(CXXFLAGS) -c main2.cpp -o main2.o

class2.o: class2.cpp *.h
	$(CXX) $(CXXFLAGS) -c class2.cpp -o class2.o

clean:
	rm -f *.o *.gch *~ a.out exe1 exe2
``` 

Each project and implementation will be built using a Makefile. In order to build the project, run the following command 
inside the corresponding directory:
```bash
make #builds the project and produces an executable
```

In the scenario that the project can produce more than one executable, the executable must be specified at the end of the 
'make' command. To produce all executables at once, run the following command:
```bash
make all #builds the project and produces all corresponding executables
```

To clean the directory of any executables or object files (from compiling and linking), run the following command:
```bash
make clean #removes any extra files resulting from compilation or linkage of src files
```
