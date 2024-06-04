#include "Player.h"
Settings::Result playBlackJack() {
	Deck deck{};
	deck.shuffle();

	Card card1{ deck.dealCard() };
	Card card2{ deck.dealCard() };
	Card card3{ deck.dealCard() };
	Player dealer{ card1.value() };
	Player player{ card2.value() + card3.value() };

	std::cout << "The dealer is showing: " << card1 << " (" << dealer.score() << ")\n";
	std::cout << "You have score: " << card2 << ' ' << card3 << " (" << player.score() << ")\n";

	if (playerTurn(deck, player))
		return Settings::loss;

	if (dealerTurn(deck, dealer))
		return Settings::win;

	if (player.score() > dealer.score()) {
		return Settings::win;
	}
	else if (player.score() < dealer.score()) {
		return Settings::loss;
	}
	else {
		return Settings::tie;
	}
}

bool dealerTurn(Deck& deck, Player& dealer) {
	while (dealer.score() < 17) {
		Card card{ deck.dealCard() };
		dealer.addScore(card);
		std::cout << "The dealer flips a " << card << ". They now have: (" << dealer.score() << ")\n";
	}
	if (dealer.score() > Settings::bustValue) {
		std::cout << "The dealer went bust!\n";
		return true;
	}
	return false;
}

bool playerTurn(Deck& deck, Player& player) {
	while (player.score() <= Settings::bustValue) {
		std::cout << "(h) to hit, or (s) to stand: ";
		char input{};
		std::cin >> input;
		if (!std::cin)
		{
			std::cin.clear(); // put us back in 'normal' operation mode
			ignoreLine(); // and remove the bad input
			continue;
		}

		// If there is extraneous input, treat as failure case
		if (!std::cin.eof() && std::cin.peek() != '\n')
		{
			std::cout << "Try again: \n";
			ignoreLine(); // ignore any extraneous input
			continue;
		}
		if (input == 'h') {
			Card card{ deck.dealCard() };
			player.addScore(card);
			std::cout << "You were dealt " << card << ". You now have (" << player.score() << ")\n";
		}
		if (input == 's') {
			break;
		}
	}
	if (player.score() > Settings::bustValue) {
		std::cout << "You went bust!\n";
		return true;
	}
	return false;
}