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

using namespace std;

class Stock {
    public:
        Stock(string ticker) {
            std::cout << ticker << " constructor\n";
            _ticker = ticker;
            _filepath = "../src/stock_data/" + ticker + ".csv";
            _stock_data = _data_importer.importData(_filepath);
            _raw_data = strategies.analyze(_ticker,_stock_data);
            analyzeStockData();


            // fetchData();
        };

        void analyzeStockData() {
            // DataAnalyzer _data_analyzer(_raw_data);
            _data_analyzer.init(_raw_data);

        }

        void printAllInvestmentStrategies() {
            _data_analyzer.output_year_to_date_buy_strategy();
        }

        void printStrongestInvestmentStrategies() {
            _data_analyzer.output_best_year_to_date_buy_strategy_by_percent();
            _data_analyzer.output_best_year_to_date_buy_strategy_by_potential_earnings();
        }

        void fetchData();
        // Stock(string ticker);
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
