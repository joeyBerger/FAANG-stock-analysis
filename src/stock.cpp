#include "stock.h"

//constructors
Stock::Stock(){}

Stock::Stock(string ticker) {
    _ticker = ticker;
    _filepath = "../src/stock_data/" + ticker + ".csv";
    _stock_data = _data_importer.importData(_filepath);
    read_csv_data();
    analyze_stock_data();
}

//read get data from csv file
void Stock::read_csv_data() {
    Strategies strategies(_ticker,_stock_data);
    _raw_data = strategies.run_strategies();
}

//pass data to data analyzer
void Stock::analyze_stock_data() {
    _data_analyzer.init(_raw_data);
}

//prints all data gathered from csv file
void Stock::print_all_investment_strategies() {    
    _data_analyzer.output_buy_dip_with_days_trade_strategy(StrategyTypes::dip_at_market_close);
    _data_analyzer.output_buy_dip_with_days_trade_strategy(StrategyTypes::dip_at_market_adjusted_close);            
    _data_analyzer.output_year_to_date_buy_strategy();
}

//prints all strongest stock strategies, by percent and earnings
void Stock::print_strongest_investment_strategies() {
    _data_analyzer.output_best_buy_dip_with_days_trade_strategy_by_percent(StrategyTypes::dip_at_market_close);
    _data_analyzer.output_best_buy_dip_with_days_trade_strategy_by_earnings(StrategyTypes::dip_at_market_close);
    _data_analyzer.output_best_buy_dip_with_days_trade_strategy_by_percent(StrategyTypes::dip_at_market_adjusted_close);
    _data_analyzer.output_best_buy_dip_with_days_trade_strategy_by_earnings(StrategyTypes::dip_at_market_adjusted_close);
    _data_analyzer.output_best_year_to_date_buy_strategy_by_percent();
    _data_analyzer.output_best_year_to_date_buy_strategy_by_potential_earnings();
}

//prints strongest stock by earnings of stocks inputted
void Stock::print_strongest_stock_given_various_tickers(std::vector<std::shared_ptr<Stock>> stocks) {
    vector<vector<vector<RawData>>> raw_data_collection;
    for (auto stock : stocks) {raw_data_collection.push_back(stock->_raw_data);}
    _data_analyzer.compare_all_stock_strategy_data(raw_data_collection);
}