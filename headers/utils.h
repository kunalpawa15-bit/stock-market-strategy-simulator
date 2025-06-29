#pragma once
#include <nlohmann/json.hpp>

void display_stock_info(const nlohmann::json& data, double usd_to_inr);
