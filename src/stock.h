#ifndef STOCK_H
#define STOCK_H

#include <iostream>
#include <string>
#include <fstream>
#include <vector>
#include <utility> // std::pair
#include <sstream> // std::stringstream

#include "data_importer.h"
#include "strategies.h"
#include "raw_data.h"
#include "data_anaylzer.h"

// using namespace std;

class Stock {
    public:
        Stock();
        Stock(string ticker);

        void read_csv_data();
        void analyze_stock_data();
        void print_all_investment_strategies();
        void print_strongest_investment_strategies();
        void print_strongest_stock_given_various_tickers(std::vector<std::shared_ptr<Stock>> stocks);

        enum Strategy_Type {
            dip_at_market_close,
            dips_at_market_adjusted_close,
            best_yearly_strategy_by_dollar_earned
        };

    private:
        DataImporter _data_importer;
        // Strategies strategies;
        string _ticker;
        string _filepath;
        std::vector<std::pair<std::string, std::vector<float>>> _stock_data;
        vector<vector<RawData>> _raw_data;
        DataAnalyzer _data_analyzer;
};

#endif
