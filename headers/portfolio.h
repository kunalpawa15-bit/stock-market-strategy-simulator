#pragma once
#include <unordered_map>
#include <string>

struct Holding {
    int total_quantity = 0;
    double total_cost = 0.0;
    void buy(int qty, double price);
    void sell(int qty, double price);
};

void display_portfolio(const std::unordered_map<std::string, Holding>& portfolio, double usd_to_inr);
void export_portfolio_to_csv(const std::unordered_map<std::string, Holding>& portfolio, const std::string& filename);
std::unordered_map<std::string, Holding> load_portfolio_from_csv(const std::string& filename);
