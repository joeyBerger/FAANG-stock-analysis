#include "stock.h"

int main(int argc, const char * argv[]) {
    
    const bool PRINT_ALL_MASS_DATA = true;
    const bool PRINT_TOP_PERFORMING_STRATEGIES = true;
    const bool PRINT_TOP_PERFOMRING_AMONG_ALL_FAANG_STOCKS = true;

    std::vector<std::shared_ptr<Stock>> stocks;

    const vector<std::string> tickers = {
        ("AAPL"),
        ("AMZN"),
        ("FB"),
        ("GOOG"),
        ("NFLX")
    };

    for (auto ticker : tickers) {
         auto base = std::make_shared<Stock>(ticker);
         stocks.push_back(base);
    }

    for (auto stock : stocks) {
        if (PRINT_ALL_MASS_DATA) stock->print_all_investment_strategies();
        if (PRINT_TOP_PERFORMING_STRATEGIES) stock->print_strongest_investment_strategies();
    }

    if (PRINT_TOP_PERFOMRING_AMONG_ALL_FAANG_STOCKS) {
        Stock *s;
        s = new Stock();
        s->print_strongest_stock_given_various_tickers(stocks);
    }
    
    return 0;
}
