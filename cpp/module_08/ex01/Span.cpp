#include "Span.hpp"

Span::Span() {
    this->N = 0;
    this->integers.resize(0);
}

Span::Span(unsigned int N) {
    this->N = N;
}

Span::~Span() {

}

Span::Span(const Span &otherSpan) {
    this->integers = otherSpan.integers;
    this->N = otherSpan.N;
}

Span &Span::operator=(const Span &otherSpan) {
    if (this == &otherSpan)
        return *this;
    this->integers = otherSpan.integers;
    this->N = otherSpan.N;
    return *this;
}

void    Span::addNumber(int N) {
    if (this->integers.size() >= this->N) {
        throw std::runtime_error("Reached max numbers");
    }
    this->integers.push_back(N);
}

unsigned int Span::shortestSpan() const {
    if (this->integers.size() <= 1) {
        throw std::runtime_error("Not enough numbers");
    }
    std::vector<int> vec = this->integers;
    std::sort(vec.begin(), vec.end());

    int shortest = std::numeric_limits<int>::max();
    for (std::vector<int>::iterator it = (vec.begin() + 1); it != vec.end(); it++) {
        int currentSpan = abs(*it - *(it - 1));
        if (currentSpan < shortest)
            shortest = currentSpan;
    }
    return shortest;
}

unsigned int Span::longestSpan() const {
    if (this->integers.size() <= 1) {
        throw std::runtime_error("Not enough numbers");
    }
    int max = *std::max_element(this->integers.begin(), this->integers.end());
    int min = *std::min_element(this->integers.begin(), this->integers.end());
    return max - min;
}

void Span::addNumber(std::vector<int>::iterator begin, std::vector<int>::iterator end) {
    while (begin != end) {
        addNumber(*begin);
        begin++;
    }
}