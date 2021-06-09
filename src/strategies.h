#ifndef STRATEGIES_H
#define STRATEGIES_H

#include <sstream> // std::stringstream
using namespace std;
#include <map>
#include <iomanip> 
#include <cmath> 
#include <math.h>
#include "data_aggregator.h"
#include "raw_data.h"

class Strategies {
    public:
        Strategies() {
            // data_column_map.insert(pair<string, int>("Date", 0));
            // data_column_map.insert(pair<string, int>("Open", 1));
            // data_column_map.insert(pair<string, int>("High", 2));
            // data_column_map.insert(pair<string, int>("Low", 3));
            // data_column_map.insert(pair<string, int>("Close", 4));
            // data_column_map.insert(pair<string, int>("Adj_Close", 5));
            // data_column_map.insert(pair<string, int>("Volume", 6));            
        }

        vector<vector<RawData>> analyze(string ticker, std::vector<std::pair<std::string, std::vector<float>>> data) {
            //TODO: put in constructor..
            _data = data;
            _ticker = ticker;

            vector<vector<RawData>> raw_data;

            vector<int> days_between;
            for (int i = 0; i < 5; i++) days_between.push_back(i+1);
            vector<float> percentage_drop_buy_points { .01, .015, .02, .025, .03, .035, .04 };
            vector<int> buy_order_limits { 5, 35, 50, 100, 250 };

            raw_data.push_back(analyze_same_closing_day_market_dip(days_between,percentage_drop_buy_points,"dip_at_market_close"));
            raw_data.push_back(analyze_same_closing_day_market_dip(days_between,percentage_drop_buy_points,"dips_at_market_adjusted_close"));
            raw_data.push_back(analyze_market_dip_to_current_date(percentage_drop_buy_points, buy_order_limits));
            return raw_data;
        }

    private:
        float _buying_threshold;
        static map<string, int> data_column_map;
        string _ticker;
        std::vector<std::pair<std::string, std::vector<float>>> _data; //this shold get instantiated in constructor
        DataAggregator data_aggregator;

        vector<RawData> analyze_same_closing_day_market_dip(vector<int> days_between_collection, vector<float> percentage_drop_buy_points, string id) {
            //make this a static variable
            static map<string, int> column_map { 
                { "Date", 0}, 
                { "Open", 1 },
                { "High", 2}, 
                { "Low", 3 },
                { "Close", 4}, 
                { "Adj_Close", 5 },
                { "Volume", 6}
            };

            auto open = _data.at(column_map["Open"]).second;
            string type = id == "dip_at_market_close" ? "Close" : "Adj_Close";
            auto close = _data.at(column_map[type]).second;
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

        vector<RawData> analyze_market_dip_to_current_date(vector<float> percentage_drop_buy_points, vector<int> buy_order_limits) {
            //make this a static variable
            static map<string, int> column_map { 
                { "Date", 0}, 
                { "Open", 1 },
                { "High", 2}, 
                { "Low", 3 },
                { "Close", 4}, 
                { "Adj_Close", 5 },
                { "Volume", 6}
            };

            auto open = _data.at(column_map["Open"]).second;
            auto close = _data.at(column_map["Close"]).second;
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
                   
                    RawData rd("yearly_analysis",_ticker,percent_gained,percentage_drop_point*100,buy_order_limit,hits,misses,int(totalTimeInvested / (hits + misses)));
                    raw_data_collection.push_back(rd);
                }
            }
            return raw_data_collection;
        }
};

#endif