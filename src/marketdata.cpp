//
// Created by Arne on 13.06.22.
//

#include "marketdata.h"

#include <utility>

maara::MarketData::MarketData(std::string symbol): symbol_(std::move(symbol)) {

}

std::string maara::MarketData::symbol() {
    return symbol_;
}

void maara::MarketData::setSymbol(const std::string &symbol) {
    symbol_ = symbol;
}

maara::OHLCData &maara::MarketData::barAt(size_t index) {
    return data_vec_.at( index );
}

void maara::MarketData::addBar(const maara::OHLCData& bar) {
    data_vec_.push_back( bar );
}

size_t maara::MarketData::count() {
    return data_vec_.size();
}
