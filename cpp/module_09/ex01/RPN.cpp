#include "RPN.hpp"

#include <valarray>

RPN::RPN() {

}

RPN::~RPN() {

}

RPN::RPN(const RPN & otherPN) {
    (void)otherPN;
}

RPN &RPN::operator=(const RPN & otherPN) {
    (void)otherPN;
    return *this;
}

void RPN::rpn(const std::string &input) {
    std::stack<double> stack;
    double             n1, n2, val;

    int n = 0;
    for (std::string::const_iterator it = input.begin(); it != input.end(); it++) {
        if (isdigit(*it)) {
            stack.push(*it - 48);
            n++;
        } else if (std::string("+-/*").find(*it) != std::string::npos) {
            if (stack.size() < 2) {
                throw std::runtime_error("Error: bad input");
            }
            n1 = popn(stack);
            n2 = popn(stack);
            if (*it == '+') {
                val = n2 + n1;
            } else if (*it == '-') {
                val = n2 - n1;
            } else if (*it == '*') {
                val = n2 * n1;
            } else if (*it == '/') {
                if (n1 == 0)
                    throw std::runtime_error("Error: Division by zero detected");
                val = n2 / n1;
            }
            stack.push(val);
            n++;
        }
        if ((strchr("+-/*", *it) == NULL && !isspace(*it) && !isdigit(*it)) || ((isdigit(*it) || strchr("+-/*", *it)) && *(it + 1) != '\0' && !isspace(*(it + 1))))
            throw std::runtime_error("Error: bad input");
    }
    if (stack.size() != 1) {
        throw std::runtime_error("Error: bad input");
    }
    if (stack.empty() == false)
        std::cout << stack.top() << std::endl;
}

double RPN::popn(std::stack<double> &stack) {
    if (stack.empty())
        return 0;
    const double n = stack.top();
    stack.pop();
    return n;
}

