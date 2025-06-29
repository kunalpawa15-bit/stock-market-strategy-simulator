#include "../headers/strategy.h"
#include <iostream>

void sma_strategy(const nlohmann::json& data) {
    if (data.empty()) return;

    double price = data[0]["price"];
    double sma = price * 0.98;  // Mock value

    if (price > sma) {
        std::cout << "Strategy: Price is above SMA. Consider holding.\n";
    } else {
        std::cout << " Strategy: Price is below SMA. Consider buying.\n";
    }
}
