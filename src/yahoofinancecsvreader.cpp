//
// Created by Arne on 13.06.22.
//

#include "yahoofinancecsvreader.h"
#include <fstream>
#include <sstream>
#include <iostream>

maara::YahooFinanceCSVReader::YahooFinanceCSVReader() {

}

bool maara::YahooFinanceCSVReader::read(const std::string &filename, const std::function<void (OHLCData& bar)>& onBarCallable) {
    if ( filename.empty() ) {
        std::cerr << "File " << filename << " not found." << std::endl;
        return false;
    }
    if ( ! onBarCallable ) {
        std::cerr << "onBarCallable is not callable!" << std::endl;
        return false;
    }

    std::ifstream file( filename );

    if ( ! file.is_open() ) {
        std::cerr << "File " << filename << " is not readable." << std::endl;
        return false;
    }

    std::string row;
    std::string col;
    while ( getline( file, row ) ) {
        std::stringstream row_str( row );

        OHLCData bar;
        int i = 0;
        std::string open_dt;
        while ( getline( row_str, col, ',' ) ) {
            if ( col == "Date" || col == "date" ) {
                // skip first line.
                break;
            }

            switch( i ) {
                case 0:
                    open_dt = col; break;
                case 1:
                    bar.setOpen( open_dt, std::stod( col ) ); break;
                case 2:
                    bar.setHigh( std::stod( col ) ); break;
                case 3:
                    bar.setLow( std::stod( col ) ); break;
                case 4:
                    bar.setClose( open_dt, std::stod( col ) ); break;
                case 5:
                    bar.setAdjClose( std::stod( col ) ); break;
                case 6:
                    bar.setVolume( std::stoi( col ) ); break;
                default:
                    break;
            }
            i++;
        }

        onBarCallable( bar );
    }

    file.close();

    return true;
}

