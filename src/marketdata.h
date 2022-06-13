//
// Created by Arne on 13.06.22.
//

#ifndef MAARA_MARKETDATA_H
#define MAARA_MARKETDATA_H

#include "ohlcdata.h"
#include <vector>
#include <string>

namespace maara {

    class MarketData {
    public:
        explicit MarketData(std::string  symbol);

        std::string symbol();
        void setSymbol(const std::string& symbol);

        OHLCData& barAt(size_t index);
        void addBar(const OHLCData& bar);

        size_t count();

    private:
        std::string symbol_;
        std::vector<OHLCData> data_vec_;
    };

} // maara

#endif //MAARA_MARKETDATA_H
