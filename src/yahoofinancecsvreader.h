//
// Created by Arne on 13.06.22.
//

#ifndef MAARA_YAHOOFINANCECSVREADER_H
#define MAARA_YAHOOFINANCECSVREADER_H

#include "ohlcdata.h"
#include <string>
#include <functional>

namespace maara {

    class YahooFinanceCSVReader {
    public:
        explicit YahooFinanceCSVReader();
        bool read(const std::string& filename, const std::function<void (OHLCData& bar)>& onBarCallable);
    };

} // maara

#endif //MAARA_YAHOOFINANCECSVREADER_H
