#include "../headers/utils.h"
#include <iostream>
#include <iomanip>

void display_stock_info(const nlohmann::json& data, double usd_to_inr) {
    if (data.empty()) return;
    const auto& stock = data[0];

    double price_usd = stock["price"];
    double price_inr = price_usd * usd_to_inr;

    std::cout << "Symbol: " << stock["symbol"] << "\n";
    std::cout << "Price: $" << price_usd << " ( Rupees -> " << std::fixed << std::setprecision(2) << price_inr << ")\n";
    std::cout << "Change %: " << stock["changesPercentage"] << "%\n";
    std::cout << "Day High: $" << stock["dayHigh"] << " | Low: $" << stock["dayLow"] << "\n";
    std::cout << "52-Week High: $" << stock["yearHigh"] << " | Low: $" << stock["yearLow"] << "\n";
    std::cout << "Volume: " << stock["volume"] << "\n";
}
