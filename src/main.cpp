#include <iostream>
#include <string>
#include <fstream>
#include <vector>
#include <utility> // std::pair
#include <stdexcept> // std::runtime_error
#include <sstream> // std::stringstream

#include "stock.h"

using namespace std;

int main(int argc, const char * argv[]) {


    // Stock t0("AAPL");
    // Stock t1("AMZN");
    // Stock t2("FB");
    // Stock t3("GOOG");
    // Stock t4("NFLX");
    // auto thing = t4.fetchData();
    // for (auto t : thing) {
    //     cout << t.first << "\n";
    //     for (auto i : t.second) {
    //         cout << "\t" << i << "\n";
    //     }
    // }

    // t0.printStrongestInvestmentStrategies();


    // Vehicle v0;    // default constructor
    // Vehicle v1(1, "Vehicle 1"); // initializing constructor

    Stock s("AMZN");

    // launch a thread that modifies the Vehicle name
    // std::future<void> ftr = std::async([](Stock ) {
    //     v.read_csv_data();
    // },std::move(s));

    // std::cout << v0.getName() << std::endl;
    // ftr.wait();
    // std::cout << v0.getName() << std::endl;



    // vector<Stock> stocks = {
    //     Stock("AAPL"),
    //     Stock("AMZN"),
    //     Stock("FB"),
    //     Stock("GOOG"),
    //     Stock("NFLX")
    // };

    // for (auto stock : stocks) {
    //     // stock.printAllInvestmentStrategies();
    //     // stock.printStrongestInvestmentStrategies();
    // }

    // Stock *s;
    // s = new Stock();
    // s->printStrongestStockGivenVariousTickers(stocks);


    return 0;
}
