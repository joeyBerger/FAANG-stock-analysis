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
#include "raw_data.h"
#include "data_anaylzer.h"


#include <thread>
using namespace std;

class Stock {
    public:
        Stock();
        Stock(string ticker);

        void read_csv_data();
        void analyze_stock_data();
        void print_all_investment_strategies();
        void print_strongest_investment_strategies();
        void print_strongest_stock_given_various_tickers(vector<Stock> stocks);

        void operator()() {
            cout << "operator\n";
            read_csv_data();
            analyze_stock_data();
        }

    private:
        DataImporter _data_importer;
        Strategies strategies;
        string _ticker;
        string _filepath;
        std::vector<std::pair<std::string, std::vector<float>>> _stock_data;
        vector<vector<RawData>> _raw_data;
        DataAnalyzer _data_analyzer;
};

#endif
