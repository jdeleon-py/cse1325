#include "card.h"

Card::Card(std::string question, std::string answer) : _question{question}, _answer{answer} {}

std::string attempt(std::string response) {}

std::ostream& operator<<(std::ostream& ost, Card& m) {}