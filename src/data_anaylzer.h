#ifndef DATAANALYZER
#define DATAANALYZER
#include<iostream>
#include<vector>
#include "data_aggregator.h"
#include "strategy_types.h"

using namespace std;

class RawData;

class DataAnalyzer {

    public:
    
        DataAnalyzer(vector<vector<RawData>> raw_data_collection);
        DataAnalyzer();

        void init(vector<vector<RawData>> raw_data_collection);
        void output_buy_dip_with_days_trade_strategy(StrategyTypes type);        
        void output_year_to_date_buy_strategy();
        void output_best_buy_dip_with_days_trade_strategy_by_percent(StrategyTypes type);
        void output_best_buy_dip_with_days_trade_strategy_by_earnings(StrategyTypes type);        
        void output_best_year_to_date_buy_strategy_by_percent();
        void output_best_year_to_date_buy_strategy_by_potential_earnings();
        void compare_all_stock_strategy_data(vector<vector<vector<RawData>>> raw_data_collection);

    private:
        //member constants
        const int INDIVIDUAL_BUY_DOLLAR_AMOUNT = 1000.0;

        //member variables
        vector<vector<RawData>> _raw_data_collection;
        DataAggregator _data_aggregator;

        //private methods
        vector<RawData> return_raw_data_collection(StrategyTypes id);
        RawData find_top_performing_by_percent(StrategyTypes id);
        RawData find_top_performing_by_potential_earnings(float &dollars_earned, float &total_investment, float individual_buy_dollar_amount, StrategyTypes id);
};

#endif
