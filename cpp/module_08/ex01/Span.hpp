#pragma once
#include <stdlib.h>
#include <exception>
#include <iostream>
#include <vector>

class Span {
    private:
        std::vector<int> integers;
        unsigned int            N;
    public:
        Span();
        Span(unsigned int N);
        ~Span();
        Span(const Span &otherSpan);
        Span            &operator=(const Span &otherSpan);
        void            addNumber(int N);
        unsigned int    shortestSpan() const;
        unsigned int    longestSpan() const;
        void            addNumber(std::vector<int>::iterator begin, std::vector<int>::iterator end) ;
};
