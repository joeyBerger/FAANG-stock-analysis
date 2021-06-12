#include "strategies.h"

//setup key variables for use in run_strategies
Strategies::Strategies(string ticker, std::vector<std::pair<std::string, std::vector<float>>> data) : 
        _ticker(ticker),
        _data(data),
        percentage_drop_buy_points(init_percentage_drop_buy_points()),
        days_between(init_days_betweem()),
        buy_order_limits(init_buy_order_limits()),
        data_column_map(init_data_column_map()) {
}

//helper function that runs in constructor call
vector<float> Strategies::init_percentage_drop_buy_points() {
    vector<float> p { .01, .015, .02, .025, .03, .035, .04 };
    return p;
}

//helper function that runs in constructor call
vector<int> Strategies::init_days_betweem() {
    vector<int> days { 1, 2, 3, 4, 5 };
    return days;
}

//helper function that runs in constructor call
vector<int> Strategies::init_buy_order_limits() {
    vector<int> b { 5, 35, 50, 100, 250 };
    return b;
}

//helper function that runs in constructor call
map<string,int> Strategies::init_data_column_map() {
    map<string, int> map { 
        { "Date", 0}, 
        { "Open", 1 },
        { "High", 2}, 
        { "Low", 3 },
        { "Close", 4}, 
        { "Adj_Close", 5 },
        { "Volume", 6}
    };
    return map;
} 

//runs available sceanarios 
vector<vector<RawData>> Strategies::run_strategies() {
    vector<vector<RawData>> raw_data;
    raw_data.push_back(analyze_same_closing_day_market_dip(days_between,percentage_drop_buy_points,StrategyTypes::dip_at_market_close));
    raw_data.push_back(analyze_same_closing_day_market_dip(days_between,percentage_drop_buy_points,StrategyTypes::dip_at_market_adjusted_close));
    raw_data.push_back(analyze_market_dip_to_current_date(percentage_drop_buy_points, buy_order_limits));
    return raw_data;
}

//runs either the close or adjusted close for variable amount of days scenario, percentage drops
vector<RawData> Strategies::analyze_same_closing_day_market_dip(vector<int> days_between_collection, vector<float> percentage_drop_buy_points, StrategyTypes id) {
    auto open = _data.at(data_column_map["Open"]).second;
    
    string type = id == StrategyTypes::dip_at_market_close ? "Close" : "Adj_Close";
    auto close = _data.at(data_column_map[type]).second;
    vector<RawData> raw_data_collection;

    for (auto days_between : days_between_collection) {
        for (auto percentage_drop_point : percentage_drop_buy_points) {

            int hits = 0;
            int misses = 0;
            float hit_gain_total = 0;
            float miss_gain_total = 0;
            float dollar_buy_amount = 1.0;
            float total_dollar_invested = 0;

            for (int i = 0; i < open.size(); i++) {
                if (1 - close.at(i) / open.at(i) > percentage_drop_point) {
                    if (i + days_between < open.size()) {
                        int day_diff = i + days_between;
                        float buy_point = close.at(i);
                        float sell_point = close.at(day_diff);
                        if (buy_point < sell_point) {hits++;}
                        else {misses++;}
                        total_dollar_invested += dollar_buy_amount * (sell_point/buy_point);
                    }
                }
            }
            float percent_gained = (total_dollar_invested / (dollar_buy_amount * (hits + misses)) - 1) * 100;

            RawData rd(id,_ticker,percent_gained,percentage_drop_point*100,hits,misses,days_between);
            raw_data_collection.push_back(rd);
        }
    }
    return raw_data_collection;
}

//runs either the year to date scenario for variable amount of percentage drops
vector<RawData> Strategies::analyze_market_dip_to_current_date(vector<float> percentage_drop_buy_points, vector<int> buy_order_limits) {
    auto open = _data.at(data_column_map["Open"]).second;
    auto close = _data.at(data_column_map["Close"]).second;
    vector<RawData> raw_data_collection;

    for (auto percentage_drop_point : percentage_drop_buy_points) {
        vector<float> resulting_percetage_gain;
        for (auto buy_order_limit : buy_order_limits) {
            int hits = 0;
            int misses = 0;
            float dollar_buy_amount = 1.0;
            float total_dollar_invested = 0;
            float totalTimeInvested = 0.0;

            for (int i = 0; i < open.size(); i++) {
                if (misses + hits < buy_order_limit && 1 - close.at(i) / open.at(i) > percentage_drop_point) {
                    float buy_point = close.at(i);
                    float sell_point = close.back();
                    if (buy_point < sell_point) {hits++;} 
                    else {misses++;}
                    total_dollar_invested += dollar_buy_amount * (sell_point/buy_point);
                    totalTimeInvested += open.size() - i;
                }
            }

            float percent_gained = (total_dollar_invested / (dollar_buy_amount * (hits + misses)) - 1) * 100;
            if (resulting_percetage_gain.size() > 0 && resulting_percetage_gain.back() == percent_gained) continue;
            resulting_percetage_gain.push_back(percent_gained);
            
            RawData rd(StrategyTypes::yearly_analysis,_ticker,percent_gained,percentage_drop_point*100,buy_order_limit,hits,misses,int(totalTimeInvested / (hits + misses)));
            raw_data_collection.push_back(rd);
        }
    }
    return raw_data_collection;
}