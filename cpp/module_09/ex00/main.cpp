#include <string>
#include <iostream>
#include "BitcoinExchange.hpp"

int main(int argc, char *argv[]) {
    if (argc == 1) {
        std::cerr << "Error: could not open file." << std::endl;
        return 1;
    }
    try {
        BitcoinExchange::exchange(std::string(argv[1]));
    } catch (std::exception &e) {
        std::cerr << e.what() << std::endl;
        return 1;
    }

    return 0;
}