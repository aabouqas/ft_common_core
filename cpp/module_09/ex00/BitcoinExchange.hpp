#pragma once

#include <iostream>
#include <exception>
#include <fstream>
#include <sstream>
#include <map>
#include <vector>
#include <limits>


class BitcoinExchange {
        private:
            static bool    isValidDateFormat(const std::string &date);
            static bool    checkValue(const std::string &line, const std::string &val);
            static std::map<std::string, double>       getDB();
            static double  getValue(const std::string &str);

            BitcoinExchange();
            BitcoinExchange(const BitcoinExchange &otherBitcoinExchange);
            BitcoinExchange &operator=(const BitcoinExchange &otherBitcoinExchange);
            ~BitcoinExchange();
    public:
            static void exchange(const std::string &fileName);
};
