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
            cout << "data_collection " << _raw_data_collection.size() << "\n";
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

        void output_best_year_to_date_buy_strategy_by_potential_earnings(RawData *data = nullptr, float dollars_earned = 0.0, float total_investment = 0.0) {
            // float dollars_earned = 0.0, total_investment = 0.0, individual_buy_dollar_amount = INDIVIDUAL_BUY_DOLLAR_AMOUNT;
            // auto data = find_top_performing_by_potential_earnings(dollars_earned,total_investment,individual_buy_dollar_amount,"yearly_analysis");

            // float dollars_earned = 0.0, total_investment = 0.0
            if (data == nullptr) {
                *data = find_top_performing_by_potential_earnings(dollars_earned,total_investment,INDIVIDUAL_BUY_DOLLAR_AMOUNT,"yearly_analysis");
                // *data = &r;
            } 

            _data_aggregator.report_best_year_to_date_buy_strategy_by_potential_earnings(
                data->getTicker(),
                data->getPercentGained(),
                data->getWinningPicks(),
                data->getLosingPicks(),
                data->getPercentageDropBuySignal(),
                data->getAverageTimeInvested(),
                data->getWinningPicks() + data->getLosingPicks(),
                data->getBuyOrderLimit(),
                data->getBuyOrderLimit() - (data->getWinningPicks() + data->getLosingPicks()),
                dollars_earned,
                total_investment,
                INDIVIDUAL_BUY_DOLLAR_AMOUNT
            );
        }

        void compare_all_stock_strategy_data(vector<vector<vector<RawData>>> raw_data_collection) {
            vector<RawData> best_yearly_strategy_by_dollar_earned;

            float dollars_earned [raw_data_collection.size()];
            float total_investment [raw_data_collection.size()];
            float individual_buy_dollar_amount = INDIVIDUAL_BUY_DOLLAR_AMOUNT;

            float highest_Price = 0;
            int winning_idx = 0;
            for (int i = 0; i < raw_data_collection.size(); i++) {
                dollars_earned[i] = 0.0;
                total_investment[i] = 0.0;
                _raw_data_collection = raw_data_collection[i];
                best_yearly_strategy_by_dollar_earned.push_back(find_top_performing_by_potential_earnings(dollars_earned[i],total_investment[i],individual_buy_dollar_amount,"yearly_analysis"));
                if (dollars_earned[i] > highest_Price) {
                    highest_Price = dollars_earned[i];
                    winning_idx = i;
                }
            }
            
            auto data = best_yearly_strategy_by_dollar_earned[winning_idx];
            output_best_year_to_date_buy_strategy_by_potential_earnings(&data,dollars_earned[winning_idx],total_investment[winning_idx]);
        }
        

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
