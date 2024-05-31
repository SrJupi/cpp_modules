#include "BitcoinExchange.hpp"

int main(int argc, char *argv[]){
    BitcoinExchange btc;
    try {
        if (argc == 1)
            btc.convertInput("");
        else
            btc.convertInput(argv[1]);
    }
    catch (std::exception &e) {
        std::cerr << e.what() << std::endl;
    }

    //btc.printDatabase();

    return 0;
}
