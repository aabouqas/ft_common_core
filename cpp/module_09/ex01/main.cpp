#include <iostream>

#include "RPN.hpp"

int main(int argc, char *argv[]) {
    if (argc == 1) {
        std::cout << "Usage: ./RPN \"numbers to calculate\"" << std::endl;
        return 0;
    }
    try {
        RPN::rpn(std::string(argv[1]));
    } catch (std::exception &e) {
        std::cerr << e.what() << std::endl;
        return 1;
    }
    return 0;
}
