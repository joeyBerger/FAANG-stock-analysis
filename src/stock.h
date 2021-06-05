#ifndef STOCK_H
#define STOCK_H

#include <iostream>

#include <string>
#include <fstream>
#include <vector>
#include <utility> // std::pair
#include <stdexcept> // std::runtime_error
#include <sstream> // std::stringstream

#include "dataimporter.h"
using namespace std;

class Stock {
    public:
        Stock(string ticker) {
            std::cout << ticker << " constructor\n";
            _ticker = ticker;
            _filepath = "../src/stock_data/" + ticker + ".csv";
            _stock_data = _data_importer.importData(_filepath);
        };
        std::vector<std::pair<std::string, std::vector<string>>> fetchData() {
            string line;
            const int HEADER_SIZE = 7;
            string column_headers[HEADER_SIZE];
            for (int i = 0; i < HEADER_SIZE; i++) column_headers[i] = "";
            cout << _ticker << "\n";
            std::ifstream filestream(_ticker);    
            std::vector<std::pair<std::string, std::vector<string>>> result;
            if(!filestream.is_open()) throw std::runtime_error("Could not open file: " + _ticker);
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
    private:
        dataImporter _data_importer;
        string _ticker;
        string _filepath;
        std::vector<std::pair<std::string, std::vector<string>>> _stock_data;
};

#endif
