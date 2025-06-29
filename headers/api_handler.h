#pragma once
#include <string>
#include <nlohmann/json.hpp>

nlohmann::json fetch_stock_data(const std::string& symbol, const std::string& api_key);
