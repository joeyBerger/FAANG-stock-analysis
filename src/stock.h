#ifndef STOCK_H
#define STOCK_H

#include <iostream>

#include <string>
#include <fstream>
#include <vector>
#include <utility> // std::pair
#include <stdexcept> // std::runtime_error
#include <sstream> // std::stringstream

#include "data_importer.h"
#include "strategies.h"
using namespace std;

class Stock {
    public:
        Stock(string ticker) {
            std::cout << ticker << " constructor\n";
            _ticker = ticker;
            _filepath = "../src/stock_data/" + ticker + ".csv";
            _stock_data = _data_importer.importData(_filepath);
            strategies.analyze(_ticker,_stock_data);
            // fetchData();
        };
        void fetchData();
        // Stock(string ticker);
    private:
        DataImporter _data_importer;
        Strategies strategies;
        string _ticker;
        string _filepath;
        std::vector<std::pair<std::string, std::vector<float>>> _stock_data;
};

#endif
