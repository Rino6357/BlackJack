#ifndef CARD_H
#define CARD_H
#include <iostream>
#include <array>

struct Card {

	enum Rank {
		rAce, r2, r3, r4, r5, r6, r7, r8, r9,
		r10, rJack, rQueen, rKing, maxrank,
	};

	enum Suit {
		sClubs,
		sDiamonds,
		sHearts,
		sSpades,
		maxsuit,
	};

	Rank rank{};
	Suit suit{};

	static constexpr std::array allRanks{ rAce,r2,r3,r4,r5,r6,r7, r8, r9, r10,rJack,rQueen,rKing };
	static constexpr std::array allSuits{ sClubs, sDiamonds, sHearts, sSpades };

	friend std::ostream& operator<<(std::ostream& out, const Card& card);

	int value() const;
};
#endif
