#ifndef DECK_H
#define DECK_H
#include <array>
#include <cassert>
#include <algorithm>
#include "Card.h"
#include "Random.h"

class Deck
{
public:
	Deck();

	Card dealCard();

	void shuffle();

private:
	std::array<Card, 52> m_deck{};
	size_t m_nextCard{ 0 };
};
#endif
