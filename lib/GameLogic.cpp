#include "GameLogic.h"
#include <iostream>
#include <fstream>
#include <vector>
#include <limits>

using namespace std;

const string SETTINGS_FILE = "settings.txt";
const string HISTORY_FILE = "history.txt";

vector<vector<char>> board;
GameSettings settings;

GameSettings::GameSettings() : boardSize(3), player1("Player1"), player2("Player2") {}

void GameSettings::save() {
    ofstream file(SETTINGS_FILE);
    if (file) {
        file << boardSize << endl;
        file << player1 << endl;
        file << player2 << endl;
    }
}

void GameSettings::load() {
    ifstream file(SETTINGS_FILE);
    if (file) {
        file >> boardSize;
        file.ignore();
        getline(file, player1);
        getline(file, player2);
    }
}

void initBoard() {
    board.assign(settings.boardSize, vector<char>(settings.boardSize, '.'));
}

void printBoard() {
    cout << "  ";
    for (int j = 0; j < settings.boardSize; ++j) cout << j << " ";
    cout << endl;
    for (int i = 0; i < settings.boardSize; ++i) {
        cout << i << " ";
        for (int j = 0; j < settings.boardSize; ++j) {
            cout << board[i][j] << " ";
        }
        cout << endl;
    }
}

bool checkWin(char player) {
    int n = settings.boardSize;
    int winLength = 3;

    for (int i = 0; i < n; ++i) {
        for (int j = 0; j <= n - winLength; ++j) {
            bool rowWin = true;
            for (int k = 0; k < winLength; ++k) {
                if (board[i][j + k] != player) {
                    rowWin = false;
                    break;
                }
            }
            if (rowWin) return true;

            bool colWin = true;
            for (int k = 0; k < winLength; ++k) {
                if (board[j + k][i] != player) {
                    colWin = false;
                    break;
                }
            }
            if (colWin) return true;
        }
    }

    for (int i = 0; i <= n - winLength; ++i) {
        for (int j = 0; j <= n - winLength; ++j) {
            bool diag1 = true, diag2 = true;
            for (int k = 0; k < winLength; ++k) {
                if (board[i + k][j + k] != player) diag1 = false;
                if (board[i + k][j + (winLength - 1 - k)] != player) diag2 = false;
            }
            if (diag1 || diag2) return true;
        }
    }

    return false;
}

bool isDraw() {
    for (const auto& row : board)
        for (char cell : row)
            if (cell == '.') return false;
    return true;
}

bool isValidMove(int row, int col) {
    return row >= 0 && row < settings.boardSize && col >= 0 && col < settings.boardSize && board[row][col] == '.';
}

void saveGameResult(const string& winner) {
    ofstream file(HISTORY_FILE, ios::app);
    if (file) {
        file << settings.player1 << " vs " << settings.player2 << ", ";
        file << "Board " << settings.boardSize << "x" << settings.boardSize << ", ";
        file << "Winner: " << winner << endl;
    }
}

void playGame() {
    char player1 = 'X', player2 = 'O';
    char currentPlayer = player1;
    initBoard();
    printBoard();

    while (true) {
        int row, col;
        cout << "Player " << ((currentPlayer == 'X') ? settings.player1 : settings.player2) << " (" << currentPlayer << "), enter row and column: ";

        while (true) {
            if (!(cin >> row >> col)) {
                cout << "Invalid input! Please enter numeric values for row and column: ";
                cin.clear();
                cin.ignore(numeric_limits<streamsize>::max(), '\n');
                continue;
            }

            if (!isValidMove(row, col)) {
                cout << "Invalid move! Please enter valid coordinates within the board: ";
                continue;
            }
            break;
        }
        board[row][col] = currentPlayer;
        printBoard();
        if (checkWin(currentPlayer)) {
            cout << "Player " << ((currentPlayer == 'X') ? settings.player1 : settings.player2) << " (" << currentPlayer << ") wins!\n";
            saveGameResult((currentPlayer == 'X') ? settings.player1 : settings.player2);
            break;
        }

        if (isDraw()) {
            cout << "It's a draw!\n";
            saveGameResult("Draw");
            break;
        }

        currentPlayer = (currentPlayer == 'X') ? 'O' : 'X';
    }

    int choice;
    cout << "\n1. Play again\n2. Return to main menu\nChoose an option: ";
    cin >> choice;

    switch (choice) {
        case 1:
            playGame();
            break;
        case 2:
            return;
        default:
            cout << "Invalid choice, returning to menu.\n";
            return;
    }
}

void configureGame() {
    cout << "\n=== Game Settings ===\n";
    cout << "Enter board size (minimum 3): ";
    cin >> settings.boardSize;
    while (settings.boardSize < 3) {
        cout << "Error! Minimum size is 3. Try again: ";
        cin >> settings.boardSize;
    }
    cout << "Enter first player's name: ";
    cin.ignore();
    getline(cin, settings.player1);

    cout << "Enter second player's name: ";
    getline(cin, settings.player2);

    settings.save();
    cout << "Settings saved!\n";
}

void showHistory() {
    cout << "\n=== Game History ===\n";
    ifstream file(HISTORY_FILE);
    if (!file) {
        cout << "No history available.\n";
        return;
    }
    string line;
    while (getline(file, line)) {
        cout << line << endl;
    }
}