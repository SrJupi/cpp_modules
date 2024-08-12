#include "BitcoinExchange.hpp"

int main(int argc, char *argv[]){
    BitcoinExchange btc;
    try {
        if (argc != 2)
            std::cerr << "Usage: ./btc <input_file>\n";
        else
            btc.convertInput(argv[1]);
    }
    catch (std::exception &e) {
        std::cerr << e.what() << std::endl;
    }
    return 0;
}
