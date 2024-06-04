#ifndef PLAYER_H
#define PLAYER_H
#include "Deck.h"
#include "Card.h"
#include <iostream>
#include "InputHandling.h"

class Player {
private:
	int m_score{};

public:
	Player(int score) : m_score{ score } {
	}

	int score() const { return m_score; }

	void addScore(Card& card) {
		m_score += card.value();
		if (card.rank == Card::rAce && m_score > 21) {
			m_score -= 10;
		}
	}
};

namespace Settings {
	inline constexpr int bustValue{ 21 };
	inline int constexpr maxDealer{ 17 };

	enum Result {
		win,
		loss,
		tie,
	};
}

Settings::Result playBlackJack();

bool dealerTurn(Deck& deck, Player& dealer);

bool playerTurn(Deck& deck, Player& player);
#endif 
