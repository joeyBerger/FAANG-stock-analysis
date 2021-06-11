#include "stock.h"
// #include <iostream>
#include "strategy_types.h"

int main(int argc, const char * argv[]) {
    
    //analysis output parameters
    const bool PRINT_ALL_MASS_DATA = true;
    const bool PRINT_TOP_PERFORMING_STRATEGIES = true;
    const bool PRINT_TOP_PERFOMRING_AMONG_ALL_FAANG_STOCKS = true;

    //output file name
    const char file_name [] = "analysis_output.txt";

    //create file
    bool ok = static_cast<bool>(std::ofstream(file_name)); 
    if (!ok) std::perror("Error creating output file\n");

    //delete file
    std::remove(file_name);  

    //hold stocks objects
    std::vector<std::shared_ptr<Stock>> stocks;

    const vector<std::string> tickers = {
        ("AAPL"),
        ("AMZN"),
        ("FB"),
        ("GOOG"),
        ("NFLX")
    };

    //instantiate new stock objects
    for (auto ticker : tickers) {
         auto stock = std::make_shared<Stock>(ticker);
         stocks.push_back(stock);
    }

    //output data
    for (auto stock : stocks) {
        if (PRINT_ALL_MASS_DATA) stock->print_all_investment_strategies();
        if (PRINT_TOP_PERFORMING_STRATEGIES) stock->print_strongest_investment_strategies();
    }

    //output top data
    if (PRINT_TOP_PERFOMRING_AMONG_ALL_FAANG_STOCKS) {
        Stock *s;
        s = new Stock();
        s->print_strongest_stock_given_various_tickers(stocks);
    }

    std::cout << "FAANG Analysis Complete. See analysis_output.txt in build directory.\n";
    
    return 0;
}
