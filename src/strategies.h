#ifndef STRATEGIES_H
#define STRATEGIES_H

#include <sstream> // std::stringstream
using namespace std;
#include <map>
class Strategies {
    public:
        void analyze(std::vector<std::pair<std::string, std::vector<float>>> data) {
            static map<string, int> column_map { 
                { "Date", 0}, 
                { "Open", 1 },
                { "High", 2}, 
                { "Low", 3 },
                { "Close", 4}, 
                { "Adj_Close", 5 },
                { "Volume", 6}
            };

            auto open = data.at(column_map["Open"]).second;
            auto close = data.at(column_map["Close"]).second;

            int hits = 0;
            int misses = 0;
            float hit_gain_total = 1;
            float miss_gain_total = 1;
            int days_between = 1;

            for (int i = 0; i < open.size(); i++) {
                //closed more than a percent lower
                if (1 - close.at(i) / open.at(i) > .01) {
                    if (i + days_between < open.size()) {
                        int day_diff = i + days_between;
                        //buy time = close.at(i)
                        //sell time = close.at(day_diff)
                        if (close.at(i) < close.at(day_diff)) {
                            hits++;
                            hit_gain_total += close.at(day_diff)/close.at(i) - 1;
                        } else {
                            misses++;
                            miss_gain_total -= 1 - close.at(day_diff)/close.at(i);
                        }
                    }
                }
            }

            cout << "hits " << hits << "\n";
            cout << "misses " << misses << "\n";

            cout << "hit_gain_total " << hit_gain_total << "\n";
            cout << "miss_gain_total " << miss_gain_total << "\n";

            cout << "hits avg." << hit_gain_total/hits << "\n";
            cout << "misses avg." << miss_gain_total/misses << "\n";
            
            cout << "overall strategy gain/loss: " << ((hit_gain_total - 1) - (1 - miss_gain_total)) * 100 << "%\n";
        }
    private:
        float _buying_threshold;
};

#endif