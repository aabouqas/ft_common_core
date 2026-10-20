#pragma once

#include <stack>
#include <iostream>

class RPN {
    private:
        RPN();
        ~RPN();
        RPN(const RPN & otherPN);
        RPN &operator=(const RPN & otherPN);
        static double popn(std::stack<double> &stack);
    public:
        static void rpn(const std::string &input);
};
