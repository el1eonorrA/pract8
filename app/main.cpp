#include "settingsMenu.hpp"
#include "startGame.hpp"
#include "showHistory.hpp"
#include <iostream>
#include <vector>
#include <string>

std::vector<std::string> history;
Settings settings;

int main() {
    settings.player1 = "Player1";
    settings.player2 = "Player2";
    settings.firstPlayer = 1;

    while (true) {
        std::cout << " Menu " << std::endl;
        std::cout << "1. Start Game" << std::endl;
        std::cout << "2. Settings" << std::endl;
        std::cout << "3. Game History" << std::endl;
        std::cout << "4. Exit" << std::endl;
        std::cout << "Your choice: ";

        int choice;
        std::cin >> choice;

        switch (choice) {
            case 1: startGame(settings, history); break;
            case 2: settingsMenu(settings); break;
            case 3: showHistory(history); break;
            case 4: return 0;
            default: std::cout << "Invalid choice. Please try again." << std::endl; break;
        }
    }

    return 0;
}
