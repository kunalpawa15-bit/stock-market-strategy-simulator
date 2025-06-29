#include "../headers/api_handler.h"
#include <cpr/cpr.h>
#include <iostream>

nlohmann::json fetch_stock_data(const std::string& symbol, const std::string& api_key) {
    std::string url = "https://financialmodelingprep.com/api/v3/quote/" + symbol + "?apikey=" + api_key;

    cpr::Response r = cpr::Get(cpr::Url{url});
    if (r.status_code != 200) {
        std::cerr << "Failed to fetch data: " << r.status_code << std::endl;
        return {};
    }

    try {
        return nlohmann::json::parse(r.text);
    } catch (const std::exception& e) {
        std::cerr << "JSON Parsing error: " << e.what() << std::endl;
        return {};
    }
}
