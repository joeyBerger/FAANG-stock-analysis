#ifndef STOCK_H
#define STOCK_H

#include "data_importer.h"
#include "strategies.h"
#include "raw_data.h"
#include "data_anaylzer.h"
#include "strategy_types.h"

class Stock {
    public:

        //constructors
        Stock();
        Stock(string ticker);

        //methods
        void read_csv_data();
        void analyze_stock_data();
        void print_all_investment_strategies();
        void print_strongest_investment_strategies();
        void print_strongest_stock_given_various_tickers(std::vector<std::shared_ptr<Stock>> stocks);

    private:
    
        //member variables
        DataImporter _data_importer;
        string _ticker;
        string _filepath;
        std::vector<std::pair<std::string, std::vector<float>>> _stock_data;
        vector<vector<RawData>> _raw_data;
        DataAnalyzer _data_analyzer;
};

#endif
