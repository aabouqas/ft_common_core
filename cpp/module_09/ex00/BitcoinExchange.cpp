#include "BitcoinExchange.hpp"

BitcoinExchange::BitcoinExchange() {
}

BitcoinExchange::~BitcoinExchange() {
}

BitcoinExchange::BitcoinExchange(const BitcoinExchange &otherBitcoinExchange) {
    (void) otherBitcoinExchange;
}

BitcoinExchange &BitcoinExchange::operator=(const BitcoinExchange &otherBitcoinExchange) {
    (void) otherBitcoinExchange;
    return *this;
}

bool BitcoinExchange::isValidDateFormat(const std::string &date) {
    if (date.length() != 10)
        return false;

    if (date.at(4) != '-' || date.at(7) != '-')
        return false;

    for (size_t n = 0; date[n] != '\0'; n++) {
        if (n != 4 && n != 7 && !isdigit(date[n]))
            return false;
    }

    std::stringstream year, month, day;
    int yy, mm, dd;

    // 2010-01-02
    year << date.substr(0, 4);
    month << date.substr(5, 2);
    day << date.substr(8);

    year >> yy;
    month >> mm;
    day >> dd;

    if ((yy < 1) || (mm < 1 || mm > 12) || (dd < 1 || dd > 31))
        return false;

    if ((yy % 4 == 0 && yy % 100 != 0) || (yy % 400 == 0)) {
        if (mm == 2 && dd > 29)
            return false;
    } else {
        if (mm == 2 && dd > 28)
            return false;
    }

    if (mm == 4 || mm == 6 || mm == 9 || mm == 11) {
        if (dd > 30)
            return false;
    }
    return true;
}

bool BitcoinExchange::checkValue(const std::string &line, const std::string &val) {
    std::stringstream ss(val);
    double d;
    ss >> d;

    if (ss.fail()) {
        std::cout << "Error: bad input => " << line << std::endl;
        return false;
    }

    if (d < 0) {
        std::cout << "Error: not a positive number." << std::endl;
        return false;
    }

    if (d > 1000) {
        std::cout << "Error: too large a number." << std::endl;
        return false;
    }
    return true;
}

std::map<std::string, double> BitcoinExchange::getDB() {
    std::map<std::string, double> db;
    std::ifstream file("data.csv");
    std::string line;
    bool firstLine = true;

    if (file.is_open() == false)
        throw std::runtime_error("Error: could not open file.");

    while (getline(file, line)) {
        size_t pos = line.find(',');
        if (pos != std::string::npos) {
            if (firstLine == false) {
                std::string key = line.substr(0, pos);
                double value;
                std::stringstream ss(line.substr(pos + 1));
                ss >> value;
                db.insert(std::make_pair(key, value));
            }
            firstLine = false;
        } else {
            std::cout << "Error: bad input => " << line << std::endl;
        }
    }
    file.close();
    return db;
}

double BitcoinExchange::getValue(const std::string &str) {
    double val;
    std::stringstream ss(str);

    ss >> val;
    return val;
}

void BitcoinExchange::exchange(const std::string &fileName) {
    std::ifstream file(fileName);
    std::string line;

    if (file.is_open() == false)
        throw std::runtime_error("Error: could not open file.");

    bool firstLine = true;
    std::map<std::string, double> db = getDB();

    if (file.peek() == EOF)
        throw std::runtime_error("Error: The given file is empty");

    while (getline(file, line)) {
        if (firstLine) {
            if (line != "date | value") {
                file.close();
                throw std::runtime_error("Error: invalid header");
            }
            firstLine = false;
        } else {
            size_t pos = line.find(" | ");

            if (pos == std::string::npos || std::isspace(line[pos + 3]) || !isValidDateFormat(line.substr(0, pos))) {
                std::cout << "Error: bad input => " << line << std::endl;
            } else if (line.length() >= line.substr(pos + 3).length() && checkValue(line, line.substr(pos + 3))) {
                char *s = NULL;

                std::string date = line.substr(0, pos);
                std::string value_s = line.substr(pos + 3);
                double value = strtod(value_s.c_str(), &s);

                if (*s != '\0') {
                    std::cout << "Error: bad input => " << line << std::endl;
                    continue;
                }

                if (date < "2009-01-02") {
                    std::cout << "Error: invalid date" << std::endl;
                } else {
                    std::map<std::string, double>::iterator it = db.lower_bound(date);
                    if (it == db.end() || it != db.begin())
                        it--;
                    std::cout << date << " => " << value << " = " << (it->second * value) << std::endl;
                }
            }
        }
    }
    file.close();
}
