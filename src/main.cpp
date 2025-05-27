#include "GameLogic.h"
#include <iostream>
using namespace std;

void showMenu() {
    while (true) {
        cout << "\n=== TIC-TAC-TOE GAME ===\n";
        cout << "1. Start Game\n";
        cout << "2. Settings\n";
        cout << "3. Game History\n";
        cout << "4. Exit\n";
        cout << "Choose an option: ";
        int choice;
        cin >> choice;

        switch (choice) {
            case 1:
                playGame();
                break;
            case 2:
                configureGame();
                break;
            case 3:
                showHistory();
                break;
            case 4:
                cout << "Exiting game...\n";
                return;
            default:
                cout << "Unknown option! Try again.\n";
        }
    }
}
//111

int main() {
    settings.load();
    showMenu();
    return 0;
}