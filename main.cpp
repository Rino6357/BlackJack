#include <iostream>
#include "Deck.h"
#include "Card.h"
#include "Player.h"

int main()
{
    auto game{ playBlackJack() };

    if (game == Settings::win) {
        std::cout << "You win!\n";
    }
    if (game == Settings::loss){
        std::cout << "You lose!\n";
    }
    if (game == Settings::tie) {
        std::cout << "It's a tie.\n";
    }

	return 0;
}