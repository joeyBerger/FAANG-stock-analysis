
#ifndef RAWDATA_H
#define RAWDATA_H

#include <iostream>
using namespace std;

class RawData {
    public:

        RawData() {}

        RawData(string type, string ticker, float percent_gained, float percentage_drop_buy_siganl, int winning_picks, int losing_picks, int days_selling_after_buying) :
            _type(type),
            _ticker(ticker),
            _percent_gained(percent_gained),
            _percentage_drop_buy_siganl(percentage_drop_buy_siganl),
            _winning_picks(winning_picks),
            _losing_picks(losing_picks),
            _days_selling_after_buying(days_selling_after_buying)
        {}

        //TODO: replace string with enum
        RawData(string type, string ticker, float percent_gained, float percentage_drop_buy_siganl, int buy_order_limit, int winning_picks, int losing_picks, int average_time_invested) :
            _type(type),
            _ticker(ticker),
            _percent_gained(percent_gained),
            _percentage_drop_buy_siganl(percentage_drop_buy_siganl),
            _buy_order_limit(buy_order_limit),
            _winning_picks(winning_picks),
            _losing_picks(losing_picks),
            _average_time_invested(average_time_invested),
            _days_selling_after_buying(0)

        {}

        RawData(string type) :
            _type(type)
        {cout << "got type " << type;}

        string getType() {return _type;}
        string getTicker() {return _ticker;}
        float getPercentGained() {return _percent_gained;}
        float getPercentageDropBuySignal() {return _percentage_drop_buy_siganl;}
        int getBuyOrderLimit() {return _buy_order_limit;}
        int getWinningPicks() {return _winning_picks;}
        int getLosingPicks() {return _losing_picks;}
        int getAverageTimeInvested() {return _average_time_invested;}
        int getDaysAfterBuying() {return _days_selling_after_buying;}

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
