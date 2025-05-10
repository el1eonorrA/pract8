#include "settingsMenu.hpp"
#include <iostream>

void settingsMenu(Settings &settings) {
    std::cout << "Enter name for Player 1: ";
    std::cin >> settings.player1;
    std::cout << "Enter name for Player 2: ";
    std::cin >> settings.player2;
    std::cout << "Who goes first? (1 or 2): ";
    std::cin >> settings.firstPlayer;
    if (settings.firstPlayer != 1 && settings.firstPlayer != 2) {
        settings.firstPlayer = 1;
        std::cout << "Invalid input. Defaulting to Player 1." << std::endl;
    }
}
