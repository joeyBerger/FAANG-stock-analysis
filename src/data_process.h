#ifndef DATAPROCESS
#define DATAPROCESS

using namespace std;
#include <iostream>

class DataProcess {
    public:
        string report_strategy_findings(string ticker, string percent_gained,string days_selling_after_buying,string winning_picks,string losing_picks,string percentage_drop) {
            string s =
            "------------------------------------------------\n"
            "ANALYSIS FOR BUYING DIP WHEN MARKET CLOSES DOWN " + percentage_drop + "%\n"
            "AND SELLING TODAY, OVER THE COURSE OF 1 YEAR: " + "\n" +
            "------------------------------------------------\n" +
            "STOCK: " + ticker + "\n" +
            "PERCENT GAINED: " + percent_gained + "%\n" +
            "WINNING PICKS: " + winning_picks + "\n" +
            "LOSING PICKS: " + losing_picks + "\n" +
            "DAY IN MARKET STRATEGY: " + days_selling_after_buying + "\n" +
            // "AVERAGE TIME INVESTED: " + average_time_invested + " DAYS" + "\n" +
            "";
            return s;
        }

        string report_strategy_findings(string ticker, string percent_gained,string winning_picks,
                                        string losing_picks,string percentage_drop,string average_time_invested,
                                        string totalBuys, string allowed_market_orders, string unutilized_market_orders) {
            string s =
            "------------------------------------------------\n"
            "ANALYSIS FOR BUYING DIP WHEN MARKET CLOSES DOWN " + percentage_drop + "%\n"
            "AND SELLING TODAY, OVER THE COURSE OF 1 YEAR: " + "\n" +
            "------------------------------------------------\n" +
            "STOCK: " + ticker + "\n" +
            "PERCENT GAINED: " + percent_gained + "%\n" +
            "WINNING PICKS: " + winning_picks + "\n" +
            "LOSING PICKS: " + losing_picks + "\n" +
            "TOTAL MARKET ORDERS: " + totalBuys + "\n" +
            "ALLOWABLE MARKET ORDERS: " + allowed_market_orders + "\n" +
            "UNUTILIZED MARKET ORDERS: " + unutilized_market_orders + "\n" +
            "AVERAGE TIME INVESTED: " + average_time_invested + " DAYS" + "\n" +
            "";
            return s;
        }
};


#endif
