#include <iostream>
#include <string>
#include <fstream>
#include <vector>
#include <utility> // std::pair
#include <stdexcept> // std::runtime_error
#include <sstream> // std::stringstream

#include "stock.h"
#include "dataimporter.h"

using namespace std;

int main(int argc, const char * argv[]) {


    Stock t0("AAPL");
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
    return 0;
}
