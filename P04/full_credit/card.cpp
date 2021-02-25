#include "card.h"

Card::Card(std::string question, std::string answer) : _question{question}, _answer{answer} {}

std::string Card::attempt(std::string response)
{
	//response = toupper(response);
	if(response == _answer)
	{
		return "Correct!";
	}
	else
	{
		return "X - Correct answer was " + _answer;
	}
}

std::ostream& operator<<(std::ostream& ost, const Card& card)
{
	ost << card._question;
	return ost;
}
