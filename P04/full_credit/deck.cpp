#include "deck.h"

void Deck::add_card(std::string question, std::string answer)
{
	/*
	Deck() includes a vector of Cards(), which starts empty but is built by repeated calls
	to the add_card() method

	enables a new card to be constructed and pushed onto '_cards'
	*/
	_cards.push_back(Card{question, answer});
	_options.push_back(answer);
	_next_card = _cards.size();
}

void Deck::add_false_answer(std::string false_answer)
{
	/*
	vector '_options' lists the possible answers

	the add_card() method pushes its answer parameter to '_options'

	additional answers that have no match can be pushed to the '_options' vector
	(permits the list of answers to be longer than the list of questions)
	*/

	_options.push_back(false_answer);
}

std::vector<std::string> Deck::options()
{
	/*
	returns a copy of '_options'

	used to give the user a list of possible answers
	*/

	return _options;
}

Card& Deck::deal()
{
	/*
	returns the next Card object in the Deck (returns a reference to one Card)
	*/
	std::random_device rd;
	std::mt19937 rng(rd());
	std::uniform_int_distribution<int> uni(0, _cards.size() - 1);
	auto index = uni(rng);

	return _cards[index];
}
