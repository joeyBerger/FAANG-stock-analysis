#include "data_anaylzer.h"

DataAnalyzer::DataAnalyzer(vector<vector<RawData>> raw_data_collection) : _raw_data_collection(raw_data_collection) {}
DataAnalyzer::DataAnalyzer() {}

void DataAnalyzer::init(vector<vector<RawData>> raw_data_collection) {_raw_data_collection = raw_data_collection;}

//for all raw data of type, out put day(s) trading strategy findings
void DataAnalyzer::output_buy_dip_with_days_trade_strategy(string type) {
    auto data_collection = return_raw_data_collection(type);
    for (auto data : data_collection) {
        _data_aggregator.report_strategy_findings(data);
    }
    _data_aggregator.print_large_data_seperater();
}

//for all raw data of type, out put day(s) trading strategy findings
void DataAnalyzer::output_year_to_date_buy_strategy() {
    auto data_collection = return_raw_data_collection("yearly_analysis");
    for (auto data : data_collection) {
        _data_aggregator.report_strategy_findings(data,data.getWinningPicks() + data.getLosingPicks(),data.getBuyOrderLimit() - (data.getWinningPicks() + data.getLosingPicks()));
    }
}

void DataAnalyzer::output_best_buy_dip_with_days_trade_strategy_by_percent(string type) {
    auto data = find_top_performing_by_percent(type);
    _data_aggregator.report_buy_dip_with_days_trade_strategy_by_percent(data);
    _data_aggregator.print_large_data_seperater();
}

void DataAnalyzer::output_best_buy_dip_with_days_trade_strategy_by_earnings(string type) {
    float dollars_earned = 0.0, total_investment = 0.0, individual_buy_dollar_amount = INDIVIDUAL_BUY_DOLLAR_AMOUNT;
    auto data = find_top_performing_by_potential_earnings(dollars_earned,total_investment,individual_buy_dollar_amount,type);
    _data_aggregator.report_buy_dip_with_days_trade_strategy_by_earnings(
        data,
        dollars_earned,
        total_investment,
        individual_buy_dollar_amount
    );
    _data_aggregator.print_large_data_seperater();
}

void DataAnalyzer::output_best_year_to_date_buy_strategy_by_percent() {
    auto data = find_top_performing_by_percent("yearly_analysis");
    _data_aggregator.report_best_year_to_date_buy_strategy_by_percent(
        data,
        data.getWinningPicks() + data.getLosingPicks(),
        data.getBuyOrderLimit() - (data.getWinningPicks() + data.getLosingPicks())
    );
}

void DataAnalyzer::output_best_year_to_date_buy_strategy_by_potential_earnings() {
    float dollars_earned = 0.0, total_investment = 0.0;
    auto data = find_top_performing_by_potential_earnings(dollars_earned,total_investment,INDIVIDUAL_BUY_DOLLAR_AMOUNT,"yearly_analysis");
    _data_aggregator.report_best_year_to_date_buy_strategy_by_potential_earnings(
        data,
        data.getWinningPicks() + data.getLosingPicks(),
        data.getBuyOrderLimit() - (data.getWinningPicks() + data.getLosingPicks()),
        dollars_earned,
        total_investment,
        INDIVIDUAL_BUY_DOLLAR_AMOUNT
    );
}

void DataAnalyzer::compare_all_stock_strategy_data(vector<vector<vector<RawData>>> raw_data_collection) {
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
    _data_aggregator.report_best_year_to_date_buy_strategy_by_potential_earnings(
        data,
        data.getWinningPicks() + data.getLosingPicks(),
        data.getBuyOrderLimit() - (data.getWinningPicks() + data.getLosingPicks()),
        dollars_earned[winning_idx],
        total_investment[winning_idx],
        INDIVIDUAL_BUY_DOLLAR_AMOUNT
    );
}

vector<RawData> DataAnalyzer::return_raw_data_collection(string id) {
    for (auto data : _raw_data_collection) {
        if (data.front().getType() == id) return data;
    }
    vector<RawData> rd;
    return rd;
}

RawData DataAnalyzer::find_top_performing_by_percent(string id) {
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

RawData DataAnalyzer::find_top_performing_by_potential_earnings(float &dollars_earned, float &total_investment, float individual_buy_dollar_amount, string id) {
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