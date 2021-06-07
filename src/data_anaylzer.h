#ifndef DATAANALYZER
#define DATAANALYZER
#include<iostream>
#include "data_aggregator.h"

using namespace std;

class RawData;

class DataAnalyzer {

    public:
        // DataAnalyzer(vector<vector<RawData>> raw_data_collection) : _raw_data_collection(raw_data_collection)  {}
        DataAnalyzer(vector<vector<RawData>> raw_data_collection) : _raw_data_collection(raw_data_collection) {}
        DataAnalyzer() {}
        void init(vector<vector<RawData>> raw_data_collection) {_raw_data_collection = raw_data_collection;}

        void output_buy_dip_with_days_trade_strategy(string type) {
            auto data_collection = return_raw_data_collection(type);
            cout << data_collection.back().getType() << "\n";
            for (auto data : data_collection) {
                _data_aggregator.report_strategy_findings(
                    data.getTicker(),
                    data.getPercentGained(),
                    data.getDaysAfterBuying(),
                    data.getWinningPicks(),
                    data.getLosingPicks(),
                    data.getPercentageDropBuySignal(),
                    type != "dip_at_market_close" 
                );
            }
            _data_aggregator.print_large_data_seperater();
        }
        
        void output_year_to_date_buy_strategy() {
            auto data_collection = return_raw_data_collection("yearly_analysis");
            for (auto data : data_collection) {
                _data_aggregator.report_strategy_findings(
                    data.getTicker(),
                    data.getPercentGained(),
                    data.getWinningPicks(),
                    data.getLosingPicks(),
                    data.getPercentageDropBuySignal(),
                    data.getAverageTimeInvested(),
                    data.getWinningPicks() + data.getLosingPicks(),
                    data.getBuyOrderLimit(),
                    data.getBuyOrderLimit() - (data.getWinningPicks() + data.getLosingPicks())
                );
            }
        }

        void output_best_buy_dip_with_days_trade_strategy_by_percent(string type) {
            auto data = find_top_performing_by_percent(type);
            _data_aggregator.report_buy_dip_with_days_trade_strategy_by_percent(
                data.getTicker(),
                data.getPercentGained(),
                data.getDaysAfterBuying(),
                data.getWinningPicks(),
                data.getLosingPicks(),
                data.getPercentageDropBuySignal(),
                type != "dip_at_market_close" 
            );
            _data_aggregator.print_large_data_seperater();
        }

        void output_best_buy_dip_with_days_trade_strategy_by_earnings(string type) {
            float dollars_earned = 0.0, total_investment = 0.0, individual_buy_dollar_amount = INDIVIDUAL_BUY_DOLLAR_AMOUNT;
            auto data = find_top_performing_by_potential_earnings(dollars_earned,total_investment,individual_buy_dollar_amount,type);

            _data_aggregator.report_buy_dip_with_days_trade_strategy_by_earnings(
                data.getTicker(),
                data.getPercentGained(),
                data.getDaysAfterBuying(),
                data.getWinningPicks(),
                data.getLosingPicks(),
                data.getPercentageDropBuySignal(),
                dollars_earned,
                total_investment,
                individual_buy_dollar_amount,
                type != "dip_at_market_close"
            );
            _data_aggregator.print_large_data_seperater();
        }
        
        void output_best_year_to_date_buy_strategy_by_percent() {
            auto data = find_top_performing_by_percent("yearly_analysis");
            _data_aggregator.report_best_year_to_date_buy_strategy_by_percent(
                data.getTicker(),
                data.getPercentGained(),
                data.getWinningPicks(),
                data.getLosingPicks(),
                data.getPercentageDropBuySignal(),
                data.getAverageTimeInvested(),
                data.getWinningPicks() + data.getLosingPicks(),
                data.getBuyOrderLimit(),
                data.getBuyOrderLimit() - (data.getWinningPicks() + data.getLosingPicks())
            );
        }

        void output_best_year_to_date_buy_strategy_by_potential_earnings() {
            float dollars_earned = 0.0, total_investment = 0.0, individual_buy_dollar_amount = INDIVIDUAL_BUY_DOLLAR_AMOUNT;
            auto data = find_top_performing_by_potential_earnings(dollars_earned,total_investment,individual_buy_dollar_amount,"yearly_analysis");
            _data_aggregator.report_best_year_to_date_buy_strategy_by_potential_earnings(
                data.getTicker(),
                data.getPercentGained(),
                data.getWinningPicks(),
                data.getLosingPicks(),
                data.getPercentageDropBuySignal(),
                data.getAverageTimeInvested(),
                data.getWinningPicks() + data.getLosingPicks(),
                data.getBuyOrderLimit(),
                data.getBuyOrderLimit() - (data.getWinningPicks() + data.getLosingPicks()),
                dollars_earned,
                total_investment,
                individual_buy_dollar_amount
            );
        }

        void compare_all_stock_strategy_data() {}
        

    private:
        //member constants
        const int INDIVIDUAL_BUY_DOLLAR_AMOUNT = 1000.0;

        //member variables
        vector<vector<RawData>> _raw_data_collection;
        DataAggregator _data_aggregator;

        //member methods
        vector<RawData> return_raw_data_collection(string id) {
            for (auto data : _raw_data_collection) {
                if (data.front().getType() == id) return data;
            }
            vector<RawData> rd;
            return rd;
        }

        RawData find_top_performing_by_percent(string id) {
            auto data_collection = return_raw_data_collection(id);
            int raw_data_idx = 0, i = 0;
            float highest_percent_gainer = 0.0;
            for (auto data : data_collection) {
                if (data.getPercentGained() > highest_percent_gainer) {
                    highest_percent_gainer = data.getPercentGained();
                    raw_data_idx = i;
                }
                i++;
            }
            return data_collection.at(raw_data_idx);
        }

        RawData find_top_performing_by_potential_earnings(float &dollars_earned, float &total_investment, float individual_buy_dollar_amount, string id) {
            auto data_collection = return_raw_data_collection(id);
            int raw_data_idx = 0, i = 0;
            for (auto data : data_collection) {
                int investment = (data.getWinningPicks() + data.getLosingPicks()) * individual_buy_dollar_amount;
                float total_gain = investment * data.getPercentGained() - investment;
                if (total_gain > dollars_earned) {
                    dollars_earned = total_gain;
                    total_investment = investment;
                    raw_data_idx = i;
                }
                i++;
            }
            return data_collection.at(raw_data_idx);
        }
};

#endif
