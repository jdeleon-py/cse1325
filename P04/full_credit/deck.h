#ifndef __DECK_H
#define __DECK_H

#include <iostream>
#include <vector>
#include <algorithm>
#include <random>
#include "card.h"

class Deck
{
public:
	void add_card(std::string question, std::string answer);
	void add_false_answer(std::string false_answer);
	std::vector<std::string> options();
	Card& deal();
private:
	int _next_card;
	std::vector<Card> _cards;
	std::vector<std::string> _options;
};

#endif
