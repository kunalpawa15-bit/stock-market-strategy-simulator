#include "../headers/portfolio.h"
#include "../headers/api_handler.h" 
#include <iostream>
#include <iomanip>
#include <fstream>
#include<bits/stdc++.h>

void Holding::buy(int qty, double price) {
    total_quantity += qty;
    total_cost += qty * price;
    std::cout << "Bought " << qty << " units at $" << price << "\n";
}

void Holding::sell(int qty, double price) {
    if (qty > total_quantity) {
        std::cout << "Not enough shares to sell.\n";
        return;
    }
    total_quantity -= qty;
    total_cost -= (total_cost / (total_quantity + qty)) * qty;
    std::cout << "Sold " << qty << " units at $" << price << "\n";
}

void display_portfolio(const std::unordered_map<std::string, Holding>& portfolio, double usd_to_inr) {
    double total_value_usd = 0.0;

    std::cout << "\n--- Portfolio ---\n";
    for (const auto& [symbol, holding] : portfolio) {
        double avg_price = holding.total_quantity ? (holding.total_cost / holding.total_quantity) : 0;
        double market_price = fetch_stock_data(symbol, "eF7ztmmlvhxyr6GLw2ZRlMdvUUJTDegX")[0]["price"];
        double holding_value = market_price * holding.total_quantity;
        double profit = holding_value - holding.total_cost;

        total_value_usd += holding_value;

        std::cout << symbol << ": " << holding.total_quantity << " shares, Avg buy: $" << avg_price
                  << ", Current: $" << market_price << ", P/L: $" << profit
                  << ", Rs. INR Value: " << holding_value * usd_to_inr << "\n";
    }

    std::cout << "Total Portfolio Value: $" << total_value_usd
              << " (Rs." << total_value_usd * usd_to_inr << ")\n";
}

void export_portfolio_to_csv(const std::unordered_map<std::string, Holding>& portfolio, const std::string& filename) {
    std::ofstream file(filename);
    file << "Symbol,Quantity,AveragePrice,TotalCost\n";
    for (const auto& [symbol, holding] : portfolio) {
        file << symbol << "," << holding.total_quantity << ","
             << (holding.total_quantity ? (holding.total_cost / holding.total_quantity) : 0) << ","
             << holding.total_cost << "\n";
    }
}
std::unordered_map<std::string, Holding> load_portfolio_from_csv(const std::string& filename) {
    std::unordered_map<std::string, Holding> portfolio;
    std::ifstream file(filename);
    if (!file.is_open()) {
        std::cerr << "⚠️ Couldn't open portfolio file.\n";
        return portfolio;
    }

    std::string line;
    std::getline(file, line); // Skip header

    while (std::getline(file, line)) {
        std::stringstream ss(line);
        std::string symbol;
        int qty;
        double avg_price, total_cost;

        std::getline(ss, symbol, ',');
        ss >> qty;
        ss.ignore();  // skip comma
        ss >> avg_price;
        ss.ignore();
        ss >> total_cost;

        portfolio[symbol] = Holding{qty, total_cost};
    }

    return portfolio;
}
