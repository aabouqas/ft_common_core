#include "Span.hpp"
#include <iostream>
#include <list>
int main() {
    Span sp = Span(10);

    std::vector<int> container;

    srand(time(NULL));

    for (int n = 0; n < 10; n++) {
        container.push_back(rand() % 100);
    }
//
//    std::vector<int>::iterator it;
//
//    for (it = container.begin(); it != container.end(); ) {
//        std::cout << *it;
//        it++;
//        if (it != container.end())
//            std::cout << ", ";
//    }
//    std::cout << std::endl;
    try {
        sp.addNumber(container.begin(), container.end());
        std::cout << sp.shortestSpan() << std::endl;
        std::cout << sp.longestSpan() << std::endl;
    } catch (std::exception &e) {
        std::cout << e.what() << std::endl;
    }
    return 0;
}