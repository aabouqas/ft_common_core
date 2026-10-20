#pragma once
#include <iterator>

template <typename T>
typename T::iterator easyfind(T &container, int b) {
    typename T::iterator number = std::find(container.begin(), container.end(), b);
    if (number != container.end())
        return number;
    throw std::runtime_error("not found");
}
