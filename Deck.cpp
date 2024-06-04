#include "Deck.h"
Deck::Deck() {
	size_t index{ 0 };
	for (auto suit : Card::allSuits) {
		for (auto rank : Card::allRanks) {
			m_deck[index] = Card{ rank, suit };
			++index;
		}
	}
}

Card Deck::dealCard() {
	assert(m_nextCard != 52 && "Deck::dealCard ran out of cards");
	return m_deck[m_nextCard++];
}

void Deck::shuffle() {
	std::shuffle(m_deck.begin(), m_deck.end(), Random::mt);
	m_nextCard = 0;
}