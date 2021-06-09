
#ifndef RAWDATA_H
#define RAWDATA_H

#include <iostream>
using namespace std;

class RawData {
    public:
         
        RawData();
        RawData(string type, string ticker, float percent_gained, float percentage_drop_buy_siganl, int winning_picks, int losing_picks, int days_selling_after_buying);
        //TODO: replace string with enum
        RawData(string type, string ticker, float percent_gained, float percentage_drop_buy_siganl, int buy_order_limit, int winning_picks, int losing_picks, int average_time_invested);
        
        string getType();
        string getTicker();
        float getPercentGained();
        float getPercentageDropBuySignal(); 
        int getBuyOrderLimit();
        int getWinningPicks(); 
        int getLosingPicks();
        int getAverageTimeInvested();
        int getDaysAfterBuying();

    private:
        string _type;
        string _ticker;
        float _percent_gained;
        float _percentage_drop_buy_siganl;
        int _buy_order_limit;
        int _winning_picks;
        int _losing_picks;
        int _average_time_invested;
        int _days_selling_after_buying;
};

#endif
