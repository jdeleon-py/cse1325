# P02

## Summary
This program utilizes the concepts of basic OOP encapsulation such that a simple list can be instanced and modified 
with ease. Specifically, given info regarding a person's pets (age, name, type), each Pet object can be stored in a 
single vector such that the info of the Pet object can be printed out with a simple for loop.

## Full Credit
This implementation creates a basic structure of a class in C++, where the class itself is divided into its respective 
header file and source file, all wrapped up in a single Makefile.

### Class Diagram
![P02 Full Credit Class Diagram](/etc/fig_p02_full.png)

### Notes
* The enum Type will store all the pet types, such that when the Pet object's info is printed out, the type can easily 
be iterated over to choose the correct one.
* The method to_string() is overloaded from the std library's version of to_string(), which is why the "using namespace 
etc..." is confusing and cryptic. It is much more worthwhile to specify the namespace per use of method.
* The vector library is a more high-level means of creating lists of data.

## Bonus Credit
This implementation dives a little deeper into some in-class computations that could be performed. The methods act as 
functions that could be encapsulated within the class. The human_years() method is added, such that the Pet object's 
age can be translated into its "human-years" equivalent.

### Class Diagram
![P023 Bonus Credit Class Diagram](/etc/fig_p02_bonus.png)

### Notes
* The human-lifespan is hardcoded into the method (or header file if you're ambitious enough) and is assumed to be 80 
years.
* The mathematical formula computing the Pet object's "human-equivalent" age is as follows:
	* human_equivalent_age = (_age * human_lifespan) / type_lifespan;
* Note that the main function need not be modified. This proves the power and utility of OOP.

## Extreme Bonus Credit
This implementation focuses on the main function, such that some of the C++ internal sorting mechanisms are utilized to 
sort the Pet object vector by age in descending order (by the human-years metric).

### Notes
* A helper function is needed to move the sorting process along. So, outside of the Pet class exists a function 
compare_age(), which returns a boolean if pet1.human_years() > pet2.human_years().
* For the vector 'pets', the sorting function is organized as follows:
```cpp
std::sort(pets.begin(), pets.end(), compare_age);
```
