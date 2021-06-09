#ifndef DATAAGGREGATOR
#define DATAAGGREGATOR

#include <iostream>
#include "raw_data.h"
#include <iomanip> 

using namespace std;

class DataAggregator {
    public:

        void report_strategy_findings(RawData raw_data);
        void report_strategy_findings(RawData raw_data, int totalBuys, int unutilized_market_orders);
        void report_buy_dip_with_days_trade_strategy_by_percent(RawData raw_data);
        void report_buy_dip_with_days_trade_strategy_by_earnings(RawData raw_data,float dollars_earned, float total_investment, float individual_buy_dollar_amount);
        void report_best_year_to_date_buy_strategy_by_percent(RawData raw_data,int totalBuys, int unutilized_market_orders);
        void report_best_year_to_date_buy_strategy_by_potential_earnings(RawData raw_data,int totalBuys, int unutilized_market_orders,float dollars_earned, float total_investment, float individual_buy_dollar_amount);
        void print_header();
        void print_daily_stock_info(string ticker, float percent_gained, int winning_picks, int losing_picks, int days_selling_after_buying);
        void print_yearly_stock_info(string ticker, float percent_gained,int winning_picks,int losing_picks,float percentage_drop,int average_time_invested,int totalBuys, int allowed_market_orders, int unutilized_market_orders);
        void print_large_data_seperater();
        string return_days_string(int days);
        string return_close_string(bool adjusted_market_close);
};



#endif
