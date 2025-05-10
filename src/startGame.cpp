
#include "startGame.hpp"
#include <iostream>
#include <utility>

void printBoard(char board[3][3]) {
    for (int i = 0; i < 3; ++i) {
        for (int j = 0; j < 3; ++j) {
            std::cout << (board[i][j] == ' ' ? '.' : board[i][j]) << " ";
        }
        std::cout << std::endl;
    }
}

bool checkWin(char board[3][3], char player) {
    for (int i = 0; i < 3; ++i)
        if ((board[i][0] == player && board[i][1] == player && board[i][2] == player) ||
            (board[0][i] == player && board[1][i] == player && board[2][i] == player))
            return true;

    return (board[0][0] == player && board[1][1] == player && board[2][2] == player) ||
           (board[0][2] == player && board[1][1] == player && board[2][0] == player);
}

void startGame(const Settings& settings, std::vector<std::string>& history) {
    char board[3][3] = {{' ', ' ', ' '}, {' ', ' ', ' '}, {' ', ' ', ' '}};
    char currentSymbol = settings.firstPlayer == 1 ? 'X' : 'O';
    std::string currentPlayer = settings.firstPlayer == 1 ? settings.player1 : settings.player2;
    std::string otherPlayer = settings.firstPlayer == 1 ? settings.player2 : settings.player1;
    int moves = 0;
    std::string result;

    std::cout << "Game started between " << settings.player1 << " and " << settings.player2 << std::endl;

    while (true) {
        printBoard(board);
        std::cout << currentPlayer << "'s turn. Enter row and column (0-2): ";
        int row, col;
        std::cin >> row >> col;

        if (row < 0 || row > 2 || col < 0 || col > 2 || board[row][col] != ' ') {
            std::cout << "Invalid move, try again." << std::endl;
            continue;
        }

        board[row][col] = currentSymbol;
        moves++;

        if (checkWin(board, currentSymbol)) {
            printBoard(board);
            std::cout << currentPlayer << " wins!" << std::endl;
            result = settings.player1 + " vs " + settings.player2 + " | Winner: " + currentPlayer;
            break;
        }

        if (moves == 9) {
            printBoard(board);
            std::cout << "It's a draw!" << std::endl;
            result = settings.player1 + " vs " + settings.player2 + " | Draw";
            break;
        }

        currentSymbol = (currentSymbol == 'X') ? 'O' : 'X';
        std::swap(currentPlayer, otherPlayer);
    }

    history.push_back(result);
}
