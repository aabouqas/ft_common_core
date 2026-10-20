#include <iostream>
#include <vector>
#include <list>
#include "easyfind.hpp"

int main() {
    std::vector<int> v;
    v.push_back(10);
    v.push_back(11);
    v.push_back(154);
    v.push_back(1574);

    std::list<int> l;
    l.push_back(10);
    l.push_back(11);
    l.push_back(154);
    l.push_back(1574);

    std::cout << *easyfind(v, 11) << std::endl;

    try {
        std::cout << *easyfind(l, 100) << std::endl;
    } catch (std::exception &e) {
        std::cout << e.what() << std::endl;
    }

    return 0;
}