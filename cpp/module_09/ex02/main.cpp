#include <iomanip>

#include "PmergeMe.hpp"

#include  <unistd.h>
int main(int argc, char *argv[]) {
    if (argc == 1) {
        std::cout << "Example: ./PmergeMe 2 3 1...." << std::endl;
        return 1;
    }
    try {
        int     number;
        char    *rem;
        std::vector<int>    n1;
        std::deque<int>     n2;

        std::cout << std::setprecision(5);
        std::cout << std::fixed;
        // Parsing input to check if is there any invalid input.
        if (argc == 2)
            throw std::runtime_error("Bad input");
        for (size_t n = 1; argv[n] != NULL ; n++) {
            number = strtol(argv[n], &rem, 10);

            if (number < 0 || (rem != NULL && *rem != '\0') || *argv[n] == '\0') {
                throw std::runtime_error("Bad input");
            }
            n1.push_back(number);
        }

        n2.insert(n2.begin(), n1.cbegin(), n1.cend());

        {
            PmergeMe::displayContainer("before : ", n1);
            double vectorTimeSpent = PmergeMe::sort(n1);
            PmergeMe::displayContainer("after : ", n1);

            std::cout << "Time to process a range of " << n1.size() << " elements with std::vector " << (vectorTimeSpent) << " s" << std::endl;
        }
        {
            double vectorTimeSpent = PmergeMe::sort(n2);
            std::cout << "Time to process a range of " << n1.size() << " elements with std::deque " << (vectorTimeSpent) << " s" << std::endl;
        }

        // std::cout << "Time to process a range of " << n2.size() << " elements with std::vector " << (diff) << " s" << std::endl;
    } catch (std::exception &e) {
        std::cerr << "Error: " << e.what() << std::endl;
    }
    return 0;
}