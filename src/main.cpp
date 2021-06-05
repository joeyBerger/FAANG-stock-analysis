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

std::vector<std::pair<std::string, std::vector<string>>> custom(string file) {
    string line;
    const int HEADER_SIZE = 7;
    string column_headers[HEADER_SIZE];
    for (int i = 0; i < HEADER_SIZE; i++) column_headers[i] = "";
    cout << file << "\n";
    std::ifstream filestream(file);    
    std::vector<std::pair<std::string, std::vector<string>>> result;
    if(!filestream.is_open()) throw std::runtime_error("Could not open file: " + file);
    else {
        bool pairCreated = false;
        while (std::getline(filestream, line)) {
            std::replace(line.begin(), line.end(), ' ', '_');
            std::replace(line.begin(), line.end(), ',', ' ');
            std::istringstream linestream(line);
            while (linestream >> column_headers[0] >> column_headers[1] >> column_headers[2] >> column_headers[3] >> column_headers[4] >> column_headers[5] >> column_headers[6]) {
                if (!pairCreated) {
                    for (int i = 0; i < HEADER_SIZE; i ++) result.push_back({column_headers[i], std::vector<string> {}});
                    pairCreated = true;
                } else for (int i = 0; i < HEADER_SIZE; i ++) result.at(i).second.push_back(column_headers[i]);
            }
        }
    }
    return result;
}

int main(int argc, const char * argv[]) {

    // auto thing = custom("../src/stock_data/AMZN.csv");
    // for (auto t : thing) {
    //     cout << t.first << "\n";
    //     for (auto i : t.second) {
    //         cout << "\t" << i << "\n";
    //     }
    // }

    // Stock stock;
    // stock.fetchData();



    Stock t0("AAPL");
    Stock t1("AMZN");
    Stock t2("FB");
    Stock t3("GOOG");
    Stock t4("NFLX");
    // auto thing = t4.fetchData();
    // for (auto t : thing) {
    //     cout << t.first << "\n";
    //     for (auto i : t.second) {
    //         cout << "\t" << i << "\n";
    //     }
    // }
    return 0;
}
