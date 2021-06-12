#ifndef STRATEGIES_H
#define STRATEGIES_H

#include <map>
#include <vector>
#include "data_aggregator.h"
#include "raw_data.h"
#include "strategy_types.h"

class Strategies {
    public:
        Strategies(string ticker, std::vector<std::pair<std::string, std::vector<float>>> data);
        vector<vector<RawData>> run_strategies();        

    private:
        //constant members
        const string _ticker;
        const std::vector<std::pair<std::string, std::vector<float>>> _data;
        const vector<int> days_between;
        const vector<float> percentage_drop_buy_points;
        const vector<int> buy_order_limits;

         //variable members
        map<string, int> data_column_map;
        DataAggregator data_aggregator;

        //private methods
        vector<RawData> analyze_same_closing_day_market_dip(vector<int> days_between_collection, vector<float> percentage_drop_buy_points, StrategyTypes id);
        vector<RawData> analyze_market_dip_to_current_date(vector<float> percentage_drop_buy_points, vector<int> buy_order_limits);

        //static methods
        static vector<float> init_percentage_drop_buy_points();
        static vector<int> init_days_betweem();
        static vector<int> init_buy_order_limits();
        static map<string,int> init_data_column_map();
};

#endif