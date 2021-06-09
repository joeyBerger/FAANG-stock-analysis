#include "stock.h"

Stock::Stock(){}

Stock::Stock(string ticker) {
    _ticker = ticker;
    _filepath = "../src/stock_data/" + ticker + ".csv";
    _stock_data = _data_importer.importData(_filepath);
    read_csv_data();
    analyze_stock_data();
}

void Stock::read_csv_data() {
    _raw_data = strategies.run_strategies(_ticker,_stock_data);
}

void Stock::analyze_stock_data() {
    _data_analyzer.init(_raw_data);
}

void Stock::print_all_investment_strategies() {
    
    _data_analyzer.output_buy_dip_with_days_trade_strategy("dip_at_market_close");
    _data_analyzer.output_buy_dip_with_days_trade_strategy("dips_at_market_adjusted_close");            
    _data_analyzer.output_year_to_date_buy_strategy();
}

void Stock::print_strongest_investment_strategies() {
    _data_analyzer.output_best_buy_dip_with_days_trade_strategy_by_percent("dip_at_market_close");
    _data_analyzer.output_best_buy_dip_with_days_trade_strategy_by_earnings("dip_at_market_close");
    _data_analyzer.output_best_buy_dip_with_days_trade_strategy_by_percent("dips_at_market_adjusted_close");
    _data_analyzer.output_best_buy_dip_with_days_trade_strategy_by_earnings("dips_at_market_adjusted_close");
    _data_analyzer.output_best_year_to_date_buy_strategy_by_percent();
    _data_analyzer.output_best_year_to_date_buy_strategy_by_potential_earnings();
}

void Stock::print_strongest_stock_given_various_tickers(vector<Stock> stocks) {
    vector<vector<vector<RawData>>> raw_data_collection;
    for (auto stock : stocks) {raw_data_collection.push_back(stock._raw_data);}
    _data_analyzer.compare_all_stock_strategy_data(raw_data_collection);
}