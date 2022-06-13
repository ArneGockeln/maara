//
// Created by Arne on 13.06.22.
//

#include "ohlcdata.h"

namespace maara {
    OHLCData::OHLCData():
        open_dt_(""), close_dt_(""), open_(0), high_(0), low_(0), close_(0), adjusted_close_(0), volume_(0) {

    }

    OHLCData::OHLCData(std::string open_dt, double open, int volume) :
        open_dt_(std::move(open_dt)), open_(open), high_(open), low_(open), close_(0), adjusted_close_(0), volume_(volume) {

    }

    void OHLCData::setOpen(std::string open_dt, double value) {
        open_dt_ = std::move( open_dt );
        open_ = value;
    }

    double OHLCData::open() {
        return open_;
    }

    void OHLCData::setHigh(double value) {
        high_ = value;
    }

    double OHLCData::high() {
        return high_;
    }

    void OHLCData::setLow(double value) {
        low_ = value;
    }

    double OHLCData::low() {
        return low_;
    }

    void OHLCData::setClose(std::string close_dt, double value) {
        close_dt_ = std::move( close_dt );
        close_ = value;
    }

    double OHLCData::close() {
        return close_;
    }

    void OHLCData::setAdjClose(double value) {
        adjusted_close_ = value;
    }

    double OHLCData::adjClose() {
        return adjusted_close_;
    }

    void OHLCData::setVolume(int value) {
        volume_ = value;
    }

    int OHLCData::volume() {
        return volume_;
    }
} // maara