#ifndef STRATEGIES_H
#define STRATEGIES_H

#include <sstream> // std::stringstream
using namespace std;
#include <map>
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
        void analyze(std::vector<std::pair<std::string, std::vector<float>>> data) {
            _data = data;
            // int ** days_between 

            //get rid of days_between_vec

            vector<int> days_between;
            for (int i = 0; i < 1; i++) days_between.push_back(1);
            // vector<float> percentage_drop_buy_points { .01, .015, .02, .025, .03, .035, .04 };
            vector<float> percentage_drop_buy_points { .03 };
            // analyze_same_closing_day_market_dip(days_between,percentage_drop_buy_points);
            analyze_market_dip_to_current_date(percentage_drop_buy_points);
        }

    private:
        float _buying_threshold;
        static map<string, int> data_column_map;
        std::vector<std::pair<std::string, std::vector<float>>> _data; //this shold get instantiated in constructor

        void analyze_same_closing_day_market_dip(vector<int> days_between_vec, vector<float> percentage_drop_buy_points) {
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



            // for (int day_between_idx = 0; day_between_idx < days_betwee_vec.size(); i++)

            for (auto days_between : days_between_vec) {
                for (auto percentage_drop_point : percentage_drop_buy_points) {

                    int hits = 0;
                    int misses = 0;
                    float hit_gain_total = 0;
                    float miss_gain_total = 0;
                    // int days_between = 1;

                    for (int i = 0; i < open.size(); i++) {
                        //closed more than a percent lower
                        if (1 - close.at(i) / open.at(i) > percentage_drop_point) {
                            if (i + days_between < open.size()) {
                                int day_diff = i + days_between;
                                float buy_point = close.at(i);
                                float sell_point = close.at(day_diff);
                                if (buy_point < sell_point) {
                                    hits++;
                                    hit_gain_total += sell_point/buy_point - 1;
                                } else {
                                    misses++;
                                    miss_gain_total += 1 - sell_point/buy_point;
                                }
                            }
                        }
                    }

                    cout << "hits " << hits << "\n";
                    cout << "misses " << misses << "\n";

                    cout << "hit_gain_total " << hit_gain_total << "\n";
                    cout << "miss_gain_total " << miss_gain_total << "\n";

                    cout << "hits avg.: " << hit_gain_total/hits * 100 << "%\n";
                    cout << "misses avg.: " << miss_gain_total/misses * 100 << "%\n";
                    
                    cout << "overall strategy gain/loss: " << (hit_gain_total - miss_gain_total) * 100 << "%\n";
                }
            }
        }


        void analyze_same_closing_day_market_dip_using_adjusted_close(vector<int> days_between_vec, vector<float> percentage_drop_buy_points) {
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



            // for (int day_between_idx = 0; day_between_idx < days_betwee_vec.size(); i++)

            for (auto days_between : days_between_vec) {
                for (auto percentage_drop_point : percentage_drop_buy_points) {

                    int hits = 0;
                    int misses = 0;
                    float hit_gain_total = 0;
                    float miss_gain_total = 0;
                    // int days_between = 1;

                    for (int i = 0; i < open.size(); i++) {
                        //closed more than a percent lower
                        if (1 - close.at(i) / open.at(i) > percentage_drop_point) {
                            if (i + days_between < open.size()) {
                                int day_diff = i + days_between;
                                float buy_point = close.at(i);
                                float sell_point = close.at(day_diff);
                                if (buy_point < sell_point) {
                                    hits++;
                                    hit_gain_total += sell_point/buy_point - 1;
                                } else {
                                    misses++;
                                    miss_gain_total += 1 - sell_point/buy_point;
                                }
                            }
                        }
                    }

                    cout << "hits " << hits << "\n";
                    cout << "misses " << misses << "\n";

                    cout << "hit_gain_total " << hit_gain_total << "\n";
                    cout << "miss_gain_total " << miss_gain_total << "\n";

                    cout << "hits avg.: " << hit_gain_total/hits * 100 << "%\n";
                    cout << "misses avg.: " << miss_gain_total/misses * 100 << "%\n";
                    
                    cout << "overall strategy gain/loss: " << (hit_gain_total - miss_gain_total) * 100 << "%\n";
                }
            }
        }

        void analyze_market_dip_to_current_date(vector<float> percentage_drop_buy_points) {
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

            // for (int day_between_idx = 0; day_between_idx < days_betwee_vec.size(); i++)

                for (auto percentage_drop_point : percentage_drop_buy_points) {
                    int hits = 0;
                    int misses = 0;
                    float hit_gain_total = 0;
                    float miss_gain_total = 0;
                    float dollar_buy_amount = 1.0;
                    float total_dollar_invested = 0;
                    float loss = 0;

                    for (int i = 0; i < open.size(); i++) {
                        if (1 - close.at(i) / open.at(i) > percentage_drop_point) {
                            float buy_point = close.at(i);
                            float sell_point = close.back();
                            if (buy_point < sell_point) {
                                hits++;
                                // total_dollar_invested += dollar_buy_amount * (sell_point/buy_point);
                                // cout << buy_point << "\n";
                                // cout << sell_point/buy_point - 1 << "\n";
                                hit_gain_total += sell_point/buy_point - 1;
                            } else {
                                misses++;
                                miss_gain_total += 1 - sell_point/buy_point;
                                cout << buy_point << "\n";
                                cout << 1 - sell_point/buy_point << "\n";

                                // loss += dollar_buy_amount * (sell_point/buy_point);
                            }
                            total_dollar_invested += dollar_buy_amount * (sell_point/buy_point);
                        }
                    }

                    cout << "hits " << hits << "\n";
                    cout << "misses " << misses << "\n";

                    cout << "hit_gain_total " << hit_gain_total << "\n";
                    cout << "miss_gain_total " << miss_gain_total << "\n";

                    cout << "hits avg.: " << hit_gain_total/hits * 100 << "%\n";
                    cout << "misses avg.: " << miss_gain_total/misses * 100 << "%\n";
                    
                    cout << "overall strategy gain/loss: " << (hit_gain_total - miss_gain_total) * 100 << "%\n";

                    cout << total_dollar_invested - (dollar_buy_amount * (hits + misses)) << "\n"; 
                    cout << "total spent: " <<  (dollar_buy_amount * (hits + misses)) << "\n";
                    cout << "percent earned: " <<  total_dollar_invested / (dollar_buy_amount * (hits + misses)) << "\n";
                }
        }
};

#endif