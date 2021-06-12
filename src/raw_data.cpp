#include "raw_data.h"

RawData::RawData(StrategyTypes type, string ticker, float percent_gained, float percentage_drop_buy_siganl, 
                 int winning_picks, int losing_picks, int days_selling_after_buying) :
            _type(type),
            _ticker(ticker),
            _percent_gained(percent_gained),
            _percentage_drop_buy_siganl(percentage_drop_buy_siganl),
            _winning_picks(winning_picks),
            _losing_picks(losing_picks),
            _days_selling_after_buying(days_selling_after_buying)
        {}


RawData::RawData(StrategyTypes type, string ticker, float percent_gained, float percentage_drop_buy_siganl, 
                 int buy_order_limit, int winning_picks, int losing_picks, int average_time_invested) :
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

//helper functions for access to private variables
StrategyTypes RawData::getType() {return _type;}
string RawData::getTicker() {return _ticker;}
float RawData::getPercentGained() {return _percent_gained;}
float RawData::getPercentageDropBuySignal() {return _percentage_drop_buy_siganl;}
int RawData::getBuyOrderLimit() {return _buy_order_limit;}
int RawData::getWinningPicks() {return _winning_picks;}
int RawData::getLosingPicks() {return _losing_picks;}
int RawData::getAverageTimeInvested() {return _average_time_invested;}
int RawData::getDaysAfterBuying() {return _days_selling_after_buying;}