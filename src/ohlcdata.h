//
// Created by Arne on 13.06.22.
//

#ifndef MAARA_OHLCDATA_H
#define MAARA_OHLCDATA_H

#include <string>

namespace maara {
    class OHLCData {
    public:
        explicit OHLCData();
        explicit OHLCData(std::string open_dt, double open, int volume);

        void setOpenDatetime(std::string value);
        std::string openDatetime();
        void setCloseDatetime(std::string value);
        std::string closeDatetime();
        void setOpen(std::string open_dt, double value);
        double open();
        void setHigh(double value);
        double high();
        void setLow(double value);
        double low();
        void setClose(std::string close_dt, double value);
        double close();
        void setAdjClose(double value);
        double adjClose();
        void setVolume(int value);
        int volume();


    private:
        std::string open_dt_;
        std::string close_dt_;
        double open_;
        double high_;
        double low_;
        double close_;
        double adjusted_close_;
        int volume_;
    };

} // maara

#endif //MAARA_OHLCDATA_H
