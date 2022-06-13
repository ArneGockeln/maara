

#include "marketdata.h"
#include "yahoofinancecsvreader.h"
#include <iostream>
#include <filesystem>

int main(int argc, char* argv[]) {
    if ( argc < 2 ) {
        std::cout << "Usage: " << argv[0] << " DATA_DIRECTORY" << std::endl;
        return EXIT_SUCCESS;
    }

    std::string path( argv[1] );
    std::vector<maara::MarketData> markets;
    if ( path.empty() ) {
        std::cerr << "Directory not found." << std::endl;
        return EXIT_FAILURE;
    }

    for ( const auto& entry : std::filesystem::directory_iterator( path ) ) {
        if ( entry.is_directory() ) {
            continue;
        }

        maara::MarketData marketData( entry.path().string() );
        maara::YahooFinanceCSVReader reader;
        bool ok = reader.read(entry.path().string(), [&](maara::OHLCData& bar) -> void {
            marketData.addBar( bar );
        });

        if ( ok ) {
            markets.push_back( marketData );
        }
    }

    for ( maara::MarketData& market : markets ) {
        std::cout << market.symbol() << " has " << market.count() << " Bars" << std::endl;
    }

    return EXIT_SUCCESS;
}
