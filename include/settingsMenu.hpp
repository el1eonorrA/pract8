#pragma once
#include <string>
struct Settings {
    std::string player1;
    std::string player2;
    int firstPlayer; // 1 or 2
};
void settingsMenu(Settings &settings);
