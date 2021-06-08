#include <iostream>
#include <string>
#include <fstream>
#include <vector>
#include <utility> // std::pair
#include <stdexcept> // std::runtime_error
#include <sstream> // std::stringstream
#include <future>
#include "stock.h"

using namespace std;

int main(int argc, const char * argv[]) {

    vector<Stock> stocks = {
        Stock("AAPL"),
        Stock("AMZN"),
        Stock("FB"),
        Stock("GOOG"),
        Stock("NFLX")
    };

    // vector<thread> threads;

    // for (int i = 0; i < stocks.size(); i++) {
    //     thread th(stocks[i]);
    //     threads.push_back(std::move(th));
    // }

    // for (thread & th : threads) {
    //     if (th.joinable()) {
    //         cout << "joined\n";
    //         th.join();
    //     }
    // }

    for (auto stock : stocks) {
        stock.print_all_investment_strategies();
        // stock.print_strongest_investment_strategies();
    }

    Stock *s;
    s = new Stock();
    s->print_strongest_stock_given_various_tickers(stocks);

    return 0;
}
