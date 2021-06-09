// #include <iostream>
// #include <string>
// #include <vector>
// #include <utility> // std::pair
// #include <stdexcept> // std::runtime_error
// #include <sstream> // std::stringstream
#include "stock.h"

// using namespace std;

int main(int argc, const char * argv[]) {
    
    const bool PRINT_ALL_MASS_DATA = false;
    const bool PRINT_TOP_PERFORMING_STRATEGIES = false;
    const bool PRINT_TOP_PERFOMRING_AMONG_ALL_FAANG_STOCKS = true;

    vector<Stock> stocks = {
        Stock("AAPL"),
        Stock("AMZN"),
        Stock("FB"),
        Stock("GOOG"),
        Stock("NFLX")
    };

    for (auto stock : stocks) {
        if (PRINT_ALL_MASS_DATA) stock.print_all_investment_strategies();
        if (PRINT_TOP_PERFORMING_STRATEGIES) stock.print_strongest_investment_strategies();
    }

    if (PRINT_TOP_PERFOMRING_AMONG_ALL_FAANG_STOCKS) {
        Stock *s;
        s = new Stock();
        s->print_strongest_stock_given_various_tickers(stocks);
    }
    
    return 0;
}
