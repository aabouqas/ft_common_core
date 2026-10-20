#pragma once
#include <iostream>

template <typename T1, typename T2>
void iter(T1 *a, size_t length, T2 function) {
	for (size_t n = 0; a != NULL && (n < length); n++) {
        (function)(a[n]);
	}
}

template <typename Type>
void display(Type p) {
    std::cout << p << std::endl;
}
