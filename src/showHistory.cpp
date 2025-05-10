#include "showHistory.hpp"
#include <iostream>
void showHistory(const std::vector<std::string>& history) {
    std::cout << "Game history:" << std::endl;
    if (history.empty()) std::cout << "No games played yet." << std::endl;
    for (size_t i = 0; i < history.size(); ++i)
        std::cout << i + 1 << ". " << history[i] << std::endl;
}
