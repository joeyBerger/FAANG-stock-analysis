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

        Stock() {}

        Stock(string ticker) {
            _ticker = ticker;
            _filepath = "../src/stock_data/" + ticker + ".csv";
            _stock_data = _data_importer.importData(_filepath);
            read_csv_data();
            analyze_stock_data();
        };


        void read_csv_data() {
            _raw_data = strategies.analyze(_ticker,_stock_data);
            // analyze_stock_data();            
        }

        void analyze_stock_data() {
            // DataAnalyzer _data_analyzer(_raw_data);
            _data_analyzer.init(_raw_data);
        }

        void print_all_investment_strategies() {
            
            _data_analyzer.output_buy_dip_with_days_trade_strategy("dip_at_market_close");
            _data_analyzer.output_buy_dip_with_days_trade_strategy("dips_at_market_adjusted_close");            
            _data_analyzer.output_year_to_date_buy_strategy();
        }

        void print_strongest_investment_strategies() {
            _data_analyzer.output_best_buy_dip_with_days_trade_strategy_by_percent("dip_at_market_close");
            _data_analyzer.output_best_buy_dip_with_days_trade_strategy_by_earnings("dip_at_market_close");
            _data_analyzer.output_best_buy_dip_with_days_trade_strategy_by_percent("dips_at_market_adjusted_close");
            _data_analyzer.output_best_buy_dip_with_days_trade_strategy_by_earnings("dips_at_market_adjusted_close");
            _data_analyzer.output_best_year_to_date_buy_strategy_by_percent();
            // _data_analyzer.output_best_year_to_date_buy_strategy_by_potential_earnings();
        }

        void print_strongest_stock_given_various_tickers(vector<Stock> stocks) {
            vector<vector<vector<RawData>>> raw_data_collection;
            for (auto stock : stocks) {raw_data_collection.push_back(stock._raw_data);}
            _data_analyzer.compare_all_stock_strategy_data(raw_data_collection);
        }

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
