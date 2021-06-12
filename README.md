# FAANG Stock Analysis

Evaluates historical yearly data for FAANG stocks (Facebook, Apple, Amazon, Netflix, Google).

Runs 3 basic strategies:
* Buying at market close after a variable dip of price and selling at market close after a variable amount of days.
* Buying at adjusted market close after a variable dip of price and selling at market close after a variable amount of days.
* Buying at market close after a variable dip of price and at market close of most recent date contained in CSV file.

## Program Structure
Upon running this program, various stocks are instantiated in main.cpp. The constructor of class Stock (stock.cpp) invokes a funciton (importData in data_importer.cpp) to import data stored in csv files. Once all stock data is imported, buy/sell strategies are run and its ensuing data is stored (strategies.cpp and data_analyzer.cpp). Next, based on the configuration of output in main.cpp, stock data is analyzed and written to a file in the build folder (data_aggregator.cpp). 

## Dependencies for Running Locally
* cmake >= 3.7
  * All OSes: [click here for installation instructions](https://cmake.org/install/)
* make >= 4.1 (Linux, Mac), 3.81 (Windows)
  * Linux: make is installed by default on most Linux distros
  * Mac: [install Xcode command line tools to get make](https://developer.apple.com/xcode/features/)
  * Windows: [Click here for installation instructions](http://gnuwin32.sourceforge.net/packages/make.htm)
* gcc/g++ >= 5.4
  * Linux: gcc / g++ is installed by default on most Linux distros
  * Mac: same deal as make - [install Xcode command line tools](https://developer.apple.com/xcode/features/)
  * Windows: recommend using [MinGW](http://www.mingw.org/)

## Basic Build Instructions

1. Clone this repo.
2. Make a build directory in the top level directory: `mkdir build && cd build`
3. Compile: `cmake .. && make`
4. Run it: `./FAANG-stock-analysis`.