#ifndef STRATEGIES_H
#define STRATEGIES_H

#include <sstream> // std::stringstream
using namespace std;
#include <map>
#include <iomanip> 
#include <cmath> 
#include <math.h>
#include <vector>
#include "data_aggregator.h"
#include "raw_data.h"
#include "strategy_types.h"

class Strategies {
    public:
        Strategies(string ticker, std::vector<std::pair<std::string, std::vector<float>>> data);
        vector<vector<RawData>> run_strategies();

    private:
        map<string, int> data_column_map;
        string _ticker;
        std::vector<std::pair<std::string, std::vector<float>>> _data;
        DataAggregator data_aggregator;
        vector<int> days_between;
        vector<float> percentage_drop_buy_points;
        vector<int> buy_order_limits;

        vector<RawData> analyze_same_closing_day_market_dip(vector<int> days_between_collection, vector<float> percentage_drop_buy_points, StrategyTypes id);
        vector<RawData> analyze_market_dip_to_current_date(vector<float> percentage_drop_buy_points, vector<int> buy_order_limits);          
};

#endif