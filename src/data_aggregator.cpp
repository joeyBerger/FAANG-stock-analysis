#include "data_aggregator.h"
#include <fstream>
#include <sstream> 

void DataAggregator::report_strategy_findings(RawData raw_data) {

    string ticker = raw_data.getTicker();
    int days_selling_after_buying = raw_data.getDaysAfterBuying(), winning_picks = raw_data.getWinningPicks(), losing_picks = raw_data.getLosingPicks(); 
    float percent_gained = raw_data.getPercentGained(), percentage_drop = raw_data.getPercentageDropBuySignal();
    bool adjusted_market_close = raw_data.getType() != "dip_at_market_close";

    auto fout = return_ofstream();

    fout << print_header();
    fout << "ANALYSIS FOR BUYING DIP WHEN MARKET CLOSES DOWN ";
    fout << setprecision(3) << percentage_drop << "%\n";
    fout << "AND SELLING AT MARKET " << return_close_string(adjusted_market_close) << " IN " << days_selling_after_buying << " " << return_days_string(days_selling_after_buying) << ": " << "\n";
    fout << print_header();
    fout << print_daily_stock_info(ticker,percent_gained,winning_picks,losing_picks,days_selling_after_buying).str();
}

void DataAggregator::report_strategy_findings(RawData raw_data, int totalBuys, int unutilized_market_orders) {

    string ticker = raw_data.getTicker();
    int days_selling_after_buying = raw_data.getDaysAfterBuying(), winning_picks = raw_data.getWinningPicks(), 
        losing_picks = raw_data.getLosingPicks(), average_time_invested = raw_data.getAverageTimeInvested(), allowed_market_orders = raw_data.getBuyOrderLimit();
    float percent_gained = raw_data.getPercentGained(), percentage_drop = raw_data.getPercentageDropBuySignal();

    auto fout = return_ofstream();

    fout << print_header();
    fout << "ANALYSIS FOR BUYING DIP WHEN MARKET CLOSES DOWN ";
    fout << setprecision(3) << percentage_drop << "%\n";
    fout << "AND SELLING TODAY, OVER THE COURSE OF 1 YEAR:\n";
    fout << print_header();
    fout << print_yearly_stock_info(ticker, percent_gained,winning_picks,losing_picks,percentage_drop,average_time_invested,totalBuys, allowed_market_orders, unutilized_market_orders).str();
}

void DataAggregator::report_buy_dip_with_days_trade_strategy_by_percent(RawData raw_data) {
    string ticker = raw_data.getTicker();
    int days_selling_after_buying = raw_data.getDaysAfterBuying(), winning_picks = raw_data.getWinningPicks(), losing_picks = raw_data.getLosingPicks(); 
    float percent_gained = raw_data.getPercentGained(), percentage_drop = raw_data.getPercentageDropBuySignal();
    bool adjusted_market_close = raw_data.getType() != "dip_at_market_close";

    auto fout = return_ofstream();

    fout << print_header();
    fout << "BEST PERFORMING STRATEGY WHEN BUYING DIPS, BY PERCENTAGE, WHEN STOCK DIPS AT LEAST ";
    fout << setprecision(3) << percentage_drop << "%,\n";
    fout << "AND SELLING IN " << days_selling_after_buying << " " << return_days_string(days_selling_after_buying) << " AT " << return_close_string(adjusted_market_close) << ":\n";
    fout << print_header();
    fout << print_daily_stock_info(ticker,percent_gained,winning_picks,losing_picks,days_selling_after_buying).str();
}

void DataAggregator::report_buy_dip_with_days_trade_strategy_by_earnings(RawData raw_data,float dollars_earned, float total_investment, float individual_buy_dollar_amount) {
    string ticker = raw_data.getTicker();
    int days_selling_after_buying = raw_data.getDaysAfterBuying(), winning_picks = raw_data.getWinningPicks(), losing_picks = raw_data.getLosingPicks(); 
    float percent_gained = raw_data.getPercentGained(), percentage_drop = raw_data.getPercentageDropBuySignal();
    bool adjusted_market_close = raw_data.getType() != "dip_at_market_close";    

    auto fout = return_ofstream();

    fout << print_header();

    fout << "BEST PERFORMING STRATEGY WHEN BUYING DIPS, BY DOLLAR AMOUNT EARNED,\n";
    fout << "WHEN INVESTING $"  << (int)individual_buy_dollar_amount << " PER TRADE, WHEN STOCK DIPS AT LEAST ";
    fout << setprecision(3) << percentage_drop << "%,\n";
    fout << "AND SELLING IN " << days_selling_after_buying << " " << return_days_string(days_selling_after_buying) << " AT " << return_close_string(adjusted_market_close) << ":\n";
    fout << print_header();
    fout << "DOLLARS INVESTED: " << (int)total_investment << "\n";
    fout << "PROFIT: " << (int)dollars_earned << "\n";
    fout << print_daily_stock_info(ticker,percent_gained,winning_picks,losing_picks,days_selling_after_buying).str();
}

void DataAggregator::report_best_year_to_date_buy_strategy_by_percent(RawData raw_data,int totalBuys, int unutilized_market_orders) {
    string ticker = raw_data.getTicker();
    int days_selling_after_buying = raw_data.getDaysAfterBuying(), winning_picks = raw_data.getWinningPicks(), losing_picks = raw_data.getLosingPicks(), average_time_invested = raw_data.getAverageTimeInvested(), allowed_market_orders = raw_data.getBuyOrderLimit();; 
    float percent_gained = raw_data.getPercentGained(), percentage_drop = raw_data.getPercentageDropBuySignal();
    
    auto fout = return_ofstream();

    fout << print_header();
    fout << "BEST YEARLY PERFORMING STRATEGY, BY PERCENTAGE, WHEN STOCK DIPS AT LEAST ";
    fout << setprecision(3) << percentage_drop << "%,\n";
    fout << "AND SELLING TODAY, OVER THE COURSE OF 1 YEAR:\n";
    fout << print_header();
    fout << print_yearly_stock_info(ticker, percent_gained,winning_picks,losing_picks,percentage_drop,average_time_invested,totalBuys, allowed_market_orders, unutilized_market_orders).str();
}

void DataAggregator::report_best_year_to_date_buy_strategy_by_potential_earnings(RawData raw_data,                     
                        int totalBuys, int unutilized_market_orders,
                        float dollars_earned, float total_investment, float individual_buy_dollar_amount) {

    string ticker = raw_data.getTicker();
    int days_selling_after_buying = raw_data.getDaysAfterBuying(), winning_picks = raw_data.getWinningPicks(), losing_picks = raw_data.getLosingPicks(), average_time_invested = raw_data.getAverageTimeInvested(), allowed_market_orders = raw_data.getBuyOrderLimit();; 
    float percent_gained = raw_data.getPercentGained(), percentage_drop = raw_data.getPercentageDropBuySignal();      

    auto fout = return_ofstream();

    fout << print_header();
    fout << "BEST YEARLY PERFORMING STRATEGY, BY DOLLAR AMOUNT EARNED,\n";
    fout << "WHEN INVESTING $"  << (int)individual_buy_dollar_amount << " PER TRADE, WHEN STOCK DIPS AT LEAST ";
    fout << setprecision(3) << percentage_drop << "%,\n";
    fout << "AND SELLING TODAY, OVER THE COURSE OF 1 YEAR:\n";
    fout << print_header();
    fout << "DOLLARS INVESTED: " << (int)total_investment << "\n";
    fout << "PROFIT: " << (int)dollars_earned << "\n";
    fout << print_yearly_stock_info(ticker, percent_gained,winning_picks,losing_picks,percentage_drop,average_time_invested,totalBuys, allowed_market_orders, unutilized_market_orders).str();

}

string DataAggregator::print_header() {
    return "------------------------------------------------\n";
}


std::stringstream DataAggregator::print_daily_stock_info(string ticker, float percent_gained, int winning_picks, int losing_picks, int days_selling_after_buying) {
    std::stringstream buffer;
    buffer << "STOCK: " << ticker << "\n";
    buffer << "PERCENT GAINED: " << percent_gained << "%\n";
    buffer << "WINNING PICKS: " << winning_picks <<"\n";
    buffer << "LOSING PICKS: " << losing_picks << "\n";
    buffer << "DAY IN MARKET STRATEGY: " << days_selling_after_buying << "\n\n";
    return buffer;
}

std::stringstream DataAggregator::print_yearly_stock_info(string ticker, float percent_gained,int winning_picks,
                                int losing_picks,float percentage_drop,int average_time_invested,
                                int totalBuys, int allowed_market_orders, int unutilized_market_orders) {
    std::stringstream buffer;
    buffer << "STOCK: " << ticker << "\n";
    buffer << "PERCENT GAINED: " << setprecision(3) << percent_gained << "%\n";
    buffer << "WINNING PICKS: " << winning_picks << "\n";
    buffer << "LOSING PICKS: " << losing_picks << "\n";
    buffer << "TOTAL MARKET ORDERS: " << totalBuys << "\n";
    buffer << "ALLOWABLE MARKET ORDERS: " << allowed_market_orders << "\n";
    buffer << "UNUTILIZED MARKET ORDERS: " << unutilized_market_orders << "\n";
    buffer << "AVERAGE TIME INVESTED: " << average_time_invested << " DAYS" << "\n\n";
    return buffer;
}

void DataAggregator::print_large_data_seperater() {
    auto fout = return_ofstream();

    fout << print_header();
    fout << print_header();
    fout << print_header();
    fout << print_header();
}

string DataAggregator::return_days_string(int days) {
    return days > 1 ? "DAYS" : "DAY";
}

string DataAggregator::return_close_string(bool adjusted_market_close) {
    return adjusted_market_close ? "ADJUSTED CLOSE" : "CLOSE";
}

std::ofstream DataAggregator::return_ofstream() {

    std::ofstream fout;
    fout.open("analysis_output.txt", std::ios_base::app);
    return fout;

}