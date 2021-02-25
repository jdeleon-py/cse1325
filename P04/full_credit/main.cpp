#include "card.h"
#include "deck.h"

int main(void)
{
	Deck deck;

	deck.add_card("Reuse and extension of fields and method implementations from another class", "Inheritance");
	deck.add_card("Bundling data and code into a restricted container", "Encapsulation");
	deck.add_card("Specifying a general interface while hiding implementation details", "Abstraction");
	deck.add_card("A style of programming focused on the use of classes and class hierarchies", "OOP");
	deck.add_card("A data type that can typically be handled directly by the underlying hardware", "Primitive Type");
	deck.add_card("A data type consisting of a fixed set of constant values called enumerators (C++ has both enum and enum class)", "Enumerated Type");
	deck.add_card("A template encapsulating data and code that manipulates it", "Class");
	deck.add_card("An encapsulated bundle of data and code", "Instance");
	deck.add_card("An instance of a class containing a set of encapsulated data and associated methods", "Object");
	deck.add_card("A block of memory associated with a symbolic name that contains an object instance or a primitive data value", "Variable");
	deck.add_card("A class member variable", "Attribute");
	deck.add_card("A special class member that creates and initializes an object from the class", "Constructor");
	deck.add_card("A function that manipulates data in a class", "Method");
	deck.add_card("A class or a function (NOT a method!) that is granted access to its friend class’ private members", "Friend");
	deck.add_card("Providing a user-defined meaning to a pre-defined operator", "Operator Overloading");
	deck.add_card("A method that returns the value of a private variable", "Getter");
	deck.add_card("A method that changes the value of a private variable", "Setter");
	deck.add_card("A derived class inheriting class members from two or more base classes", "Multiple Inheritance");
	deck.add_card("The class from which members are inherited", "Base Class");
	deck.add_card("The class inheriting members", "Derived Class");
	deck.add_card("A derived class replacing its base class’ implementation of a method", "Override");

	deck.add_false_answer("Polymorphism");
	deck.add_false_answer("Algorithm");
	deck.add_false_answer("Destructor");
	deck.add_false_answer("Operator");

	std::vector<std::string> choices = deck.options();

	int logic = 1;
	std::string guess;
	std::cout << "Select the number of the term for each definition (-1 to exit)" << std::endl << std::endl;
	while(logic)
	{
		//print out vector of options
		for(int i = 0; i < choices.size(); ++i)
		{
			std::cout << std::to_string(i) << ") " << choices[i] << std::endl;
		}
		std::cout << std::endl;

		Card& card = deck.deal();

		std::cout << card << "? ";
		std::getline(std::cin, guess);
		std::cout << std::endl;

		if(guess == "-1")
		{
			logic = 0;
		}
		else
		{
			std::string result = card.attempt(guess);
			std::cout << result << std::endl << std::endl;
		}
	}
}
