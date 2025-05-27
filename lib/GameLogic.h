#pragma once
#include <string>

void initBoard();
void printBoard();
bool checkWin(char player);
bool isDraw();
bool isValidMove(int row, int col);
void playGame();
void configureGame();
void showHistory();

struct GameSettings {
    int boardSize;
    std::string player1;
    std::string player2;

    GameSettings();
    void save();
    void load();
};

extern GameSettings settings;