#include <iostream>
#include<bits/stdc++.h>
#include <string>
#include <unordered_map>
#include <vector>
#include <iomanip>
#include "../headers/api_handler.h"
#include "../headers/portfolio.h"
#include "../headers/strategy.h"
#include "../headers/utils.h"

int main() {
    std::string api_key = "eF7ztmmlvhxyr6GLw2ZRlMdvUUJTDegX";
    double usd_to_inr = 83.0;
    std::unordered_map<std::string, Holding> portfolio = load_portfolio_from_csv("portfolio.csv");


    while (true) {
        std::cout << "\n===== Stock Market Simulator =====\n";
        std::cout << "1. View stock\n2. Buy stock\n3. Sell stock\n4. View portfolio\n5. Export to CSV\n6. Exit\nEnter choice: ";
        int choice;
        std::cin >> choice;

        if (choice == 6) break;

        std::string symbol;
        nlohmann::json stock_data;

        switch (choice) {
            case 1:
                std::cout << "Enter stock symbol: ";
                std::cin >> symbol;
                stock_data = fetch_stock_data(symbol, api_key);
                if (!stock_data.empty()) {
                    display_stock_info(stock_data, usd_to_inr);
                    sma_strategy(stock_data);  // Optional: comment this out if not needed for now
                }
                break;
            case 2:
                std::cout << "Enter stock symbol to buy: ";
                std::cin >> symbol;
                stock_data = fetch_stock_data(symbol, api_key);
                if (!stock_data.empty()) {
                    double price = stock_data[0]["price"];
                    int qty;
                    std::cout << "Enter quantity: ";
                    std::cin >> qty;
                    portfolio[symbol].buy(qty, price);
                    export_portfolio_to_csv(portfolio, "portfolio.csv");
                }
                break;
            case 3:
                std::cout << "Enter stock symbol to sell: ";
                std::cin >> symbol;
                stock_data = fetch_stock_data(symbol, api_key);
                if (!stock_data.empty()) {
                    double price = stock_data[0]["price"];
                    int qty;
                    std::cout << "Enter quantity: ";
                    std::cin >> qty;
                    portfolio[symbol].sell(qty, price);
                    export_portfolio_to_csv(portfolio, "portfolio.csv");
                }

                break;
            case 4:
                display_portfolio(portfolio, usd_to_inr);
                break;
            case 5:
                export_portfolio_to_csv(portfolio, "portfolio.csv");
                std::cout << "Exported to portfolio.csv\n";
                break;
            default:
                std::cout << "Invalid choice!\n";
        }
    }

    return 0;
}
