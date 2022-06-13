cmake_minimum_required(VERSION 3.22)
project(maara)

set(CMAKE_CXX_STANDARD 20)

add_executable(maara src/main.cpp src/marketdata.cpp src/marketdata.h src/ohlcdata.cpp src/ohlcdata.h src/price.h src/yahoofinancecsvreader.cpp src/yahoofinancecsvreader.h)
