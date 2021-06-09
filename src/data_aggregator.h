#ifndef DATAAGGREGATOR
#define DATAAGGREGATOR

using namespace std;
#include <iostream>
#include "raw_data.h"

class DataAggregator {
    public:
        void report_strategy_findings(RawData raw_data) {

            string ticker = raw_data.getTicker();
            int days_selling_after_buying = raw_data.getDaysAfterBuying(), winning_picks = raw_data.getWinningPicks(), losing_picks = raw_data.getLosingPicks(); 
            float percent_gained = raw_data.getPercentGained(), percentage_drop = raw_data.getPercentageDropBuySignal();
            bool adjusted_market_close = raw_data.getType() != "dip_at_market_close";

            print_header();
            cout << "ANALYSIS FOR BUYING DIP WHEN MARKET CLOSES DOWN ";
            cout << setprecision(3) << percentage_drop << "%\n";
            cout << "AND SELLING AT MARKET " << return_close_string(adjusted_market_close) << " IN " << days_selling_after_buying << " " << return_days_string(days_selling_after_buying) << ": " << "\n";
            print_header();
            print_daily_stock_info(ticker,percent_gained,winning_picks,losing_picks,days_selling_after_buying);
        }

        void report_strategy_findings(RawData raw_data, int totalBuys, int unutilized_market_orders) {

            string ticker = raw_data.getTicker();
            int days_selling_after_buying = raw_data.getDaysAfterBuying(), winning_picks = raw_data.getWinningPicks(), 
                losing_picks = raw_data.getLosingPicks(), average_time_invested = raw_data.getAverageTimeInvested(), allowed_market_orders = raw_data.getBuyOrderLimit();
            float percent_gained = raw_data.getPercentGained(), percentage_drop = raw_data.getPercentageDropBuySignal();

            print_header();
            cout << "ANALYSIS FOR BUYING DIP WHEN MARKET CLOSES DOWN ";
            cout << setprecision(3) << percentage_drop << "%\n";
            cout << "AND SELLING TODAY, OVER THE COURSE OF 1 YEAR:\n";
            print_header();
            print_yearly_stock_info(ticker, percent_gained,winning_picks,losing_picks,percentage_drop,average_time_invested,totalBuys, allowed_market_orders, unutilized_market_orders);
        }


        void report_buy_dip_with_days_trade_strategy_by_percent(RawData raw_data) {
            string ticker = raw_data.getTicker();
            int days_selling_after_buying = raw_data.getDaysAfterBuying(), winning_picks = raw_data.getWinningPicks(), losing_picks = raw_data.getLosingPicks(); 
            float percent_gained = raw_data.getPercentGained(), percentage_drop = raw_data.getPercentageDropBuySignal();
            bool adjusted_market_close = raw_data.getType() != "dip_at_market_close";

            print_header();
            cout << "BEST PERFORMING STRATEGY WHEN BUYING DIPS, BY PERCENTAGE, WHEN STOCK DIPS AT LEAST ";
            cout << setprecision(3) << percentage_drop << "%,\n";
            cout << "AND SELLING IN " << days_selling_after_buying << " " << return_days_string(days_selling_after_buying) << " AT " << return_close_string(adjusted_market_close) << ":\n";
            print_header();
            print_daily_stock_info(ticker,percent_gained,winning_picks,losing_picks,days_selling_after_buying);
        }

        void report_buy_dip_with_days_trade_strategy_by_earnings(RawData raw_data,float dollars_earned, float total_investment, float individual_buy_dollar_amount) {
            string ticker = raw_data.getTicker();
            int days_selling_after_buying = raw_data.getDaysAfterBuying(), winning_picks = raw_data.getWinningPicks(), losing_picks = raw_data.getLosingPicks(); 
            float percent_gained = raw_data.getPercentGained(), percentage_drop = raw_data.getPercentageDropBuySignal();
            bool adjusted_market_close = raw_data.getType() != "dip_at_market_close";    

            print_header();

            cout << "BEST PERFORMING STRATEGY WHEN BUYING DIPS, BY DOLLAR AMOUNT EARNED,\n";
            cout << "WHEN INVESTING $"  << (int)individual_buy_dollar_amount << " PER TRADE, WHEN STOCK DIPS AT LEAST ";
            cout << setprecision(3) << percentage_drop << "%,\n";
            cout << "AND SELLING IN " << days_selling_after_buying << " " << return_days_string(days_selling_after_buying) << " AT " << return_close_string(adjusted_market_close) << ":\n";
            print_header();
            cout << "DOLLARS INVESTED: " << (int)total_investment << "\n";
            cout << "PROFIT: " << (int)dollars_earned << "\n";
            print_daily_stock_info(ticker,percent_gained,winning_picks,losing_picks,days_selling_after_buying);
        }

        void report_best_year_to_date_buy_strategy_by_percent(RawData raw_data,int totalBuys, int unutilized_market_orders) {
            string ticker = raw_data.getTicker();
            int days_selling_after_buying = raw_data.getDaysAfterBuying(), winning_picks = raw_data.getWinningPicks(), losing_picks = raw_data.getLosingPicks(), average_time_invested = raw_data.getAverageTimeInvested(), allowed_market_orders = raw_data.getBuyOrderLimit();; 
            float percent_gained = raw_data.getPercentGained(), percentage_drop = raw_data.getPercentageDropBuySignal();
            
            print_header();
            cout << "BEST YEARLY PERFORMING STRATEGY, BY PERCENTAGE, WHEN STOCK DIPS AT LEAST ";
            cout << setprecision(3) << percentage_drop << "%,\n";
            cout << "AND SELLING TODAY, OVER THE COURSE OF 1 YEAR:\n";
            print_header();
            print_yearly_stock_info(ticker, percent_gained,winning_picks,losing_picks,percentage_drop,average_time_invested,totalBuys, allowed_market_orders, unutilized_market_orders);
        }

        void report_best_year_to_date_buy_strategy_by_potential_earnings(RawData raw_data,                     
                                int totalBuys, int unutilized_market_orders,
                                float dollars_earned, float total_investment, float individual_buy_dollar_amount) {

            string ticker = raw_data.getTicker();
            int days_selling_after_buying = raw_data.getDaysAfterBuying(), winning_picks = raw_data.getWinningPicks(), losing_picks = raw_data.getLosingPicks(), average_time_invested = raw_data.getAverageTimeInvested(), allowed_market_orders = raw_data.getBuyOrderLimit();; 
            float percent_gained = raw_data.getPercentGained(), percentage_drop = raw_data.getPercentageDropBuySignal();                      

            print_header();
            cout << "BEST YEARLY PERFORMING STRATEGY, BY DOLLAR AMOUNT EARNED,\n";
            cout << "WHEN INVESTING $"  << (int)individual_buy_dollar_amount << " PER TRADE, WHEN STOCK DIPS AT LEAST ";
            cout << setprecision(3) << percentage_drop << "%,\n";
            cout << "AND SELLING TODAY, OVER THE COURSE OF 1 YEAR:\n";
            print_header();
            cout << "DOLLARS INVESTED: " << (int)total_investment << "\n";
            cout << "PROFIT: " << (int)dollars_earned << "\n";
            print_yearly_stock_info(ticker, percent_gained,winning_picks,losing_picks,percentage_drop,average_time_invested,totalBuys, allowed_market_orders, unutilized_market_orders);

        }

        void print_header() {
            cout << "------------------------------------------------\n";
        }

        void print_daily_stock_info(string ticker, float percent_gained, int winning_picks, int losing_picks, int days_selling_after_buying) {
            cout << "STOCK: " << ticker << "\n";
            cout << "PERCENT GAINED: " << percent_gained << "%\n";
            cout << "WINNING PICKS: " << winning_picks <<"\n";
            cout << "LOSING PICKS: " << losing_picks << "\n";
            cout << "DAY IN MARKET STRATEGY: " << days_selling_after_buying << "\n\n";
        }

        void print_yearly_stock_info(string ticker, float percent_gained,int winning_picks,
                                        int losing_picks,float percentage_drop,int average_time_invested,
                                        int totalBuys, int allowed_market_orders, int unutilized_market_orders) {
            cout << "STOCK: " << ticker << "\n";
            cout << "PERCENT GAINED: " << setprecision(3) << percent_gained << "%\n";
            cout << "WINNING PICKS: " << winning_picks << "\n";
            cout << "LOSING PICKS: " << losing_picks << "\n";
            cout << "TOTAL MARKET ORDERS: " << totalBuys << "\n";
            cout << "ALLOWABLE MARKET ORDERS: " << allowed_market_orders << "\n";
            cout << "UNUTILIZED MARKET ORDERS: " << unutilized_market_orders << "\n";
            cout << "AVERAGE TIME INVESTED: " << average_time_invested << " DAYS" << "\n\n";
        }

        void print_large_data_seperater() {
            print_header();
            print_header();
            print_header();
            print_header();
        }

        string return_days_string(int days) {
            return days > 1 ? "DAYS" : "DAY";
        }

        string return_close_string(bool adjusted_market_close) {
            return adjusted_market_close ? "ADJUSTED CLOSE" : "CLOSE";
        }
};



#endif
