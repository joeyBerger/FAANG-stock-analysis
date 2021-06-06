#ifndef STRATEGIES_H
#define STRATEGIES_H

#include <sstream> // std::stringstream
using namespace std;
#include <map>
#include <iomanip> 
#include <cmath> 
#include <math.h>
#include "data_aggregator.h"

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
        void analyze(string ticker, std::vector<std::pair<std::string, std::vector<float>>> data) {
            _data = data;
            _ticker = ticker;
            vector<int> days_between;
            for (int i = 0; i < 5; i++) days_between.push_back(i+1);
            vector<float> percentage_drop_buy_points { .01, .015, .02, .025, .03, .035, .04 };
            vector<int> buy_order_limits { 5, 35, 50, 100, 250 };

            // analyze_same_closing_day_market_dip(days_between,percentage_drop_buy_points);
            analyze_same_closing_day_market_dip_using_adjusted_close(days_between,percentage_drop_buy_points);
            // analyze_market_dip_to_current_date(percentage_drop_buy_points, buy_order_limits);
        }

    private:
        float _buying_threshold;
        static map<string, int> data_column_map;
        string _ticker;
        std::vector<std::pair<std::string, std::vector<float>>> _data; //this shold get instantiated in constructor
        DataAggregator data_aggregator;

        float round(float var) {
            // 37.66666 * 100 =3766.66
            // 3766.66 + .5 =3767.16    for rounding off value
            // then type cast to int so value is 3767
            // then divided by 100 so the value converted into 37.67
            float value = (int)(var * 100 + .5);
            return (float)value / 100;
        }

        float round(float x, int n){ 
            int d = 0; 
            if((x * pow(10, n + 1)) - (floor(x * pow(10, n))) > 4) d = 1; 
            x = (floor(x * pow(10, n)) + d) / pow(10, n); 
            return x; 
        }

        void analyze_same_closing_day_market_dip(vector<int> days_between_collection, vector<float> percentage_drop_buy_points) {
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

                    cout << data_aggregator.report_strategy_findings(
                        _ticker,
                        to_string((total_dollar_invested / (dollar_buy_amount * (hits + misses)) - 1) * 100),
                        to_string(days_between),
                        to_string(hits),
                        to_string(misses),
                        to_string(percentage_drop_point*100)
                    ) << "\n";
                }
            }
        }

        void analyze_same_closing_day_market_dip_using_adjusted_close(vector<int> days_between_collection, vector<float> percentage_drop_buy_points) {
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
            auto close = _data.at(column_map["Adj_Close"]).second;

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

                    cout << data_aggregator.report_strategy_findings(
                        _ticker,
                        to_string((total_dollar_invested / (dollar_buy_amount * (hits + misses)) - 1) * 100),
                        to_string(days_between),
                        to_string(hits),
                        to_string(misses),
                        to_string(percentage_drop_point*100),
                        true
                    ) << "\n";
                }
            }
        }

        void analyze_market_dip_to_current_date(vector<float> percentage_drop_buy_points, vector<int> buy_order_limits) {
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
                    cout << data_aggregator.report_strategy_findings(
                        _ticker,
                        to_string(percent_gained),
                        to_string(hits),
                        to_string(misses),
                        to_string(percentage_drop_point*100),
                        to_string(int(totalTimeInvested / (hits + misses))),
                        to_string(hits + misses),
                        to_string(buy_order_limit),
                        to_string(buy_order_limit - (hits + misses))
                    ) << "\n";
                }
            }
        }
};

#endif