#include "PmergeMe.hpp"

#include <deque>
#include <iomanip>
#include <valarray>

int PmergeMe::unpair = -1;

PmergeMe::PmergeMe() {

}

PmergeMe::~PmergeMe() {

}

PmergeMe::PmergeMe(const PmergeMe &otherPmergeMe) {
    (void)otherPmergeMe;
}

PmergeMe&PmergeMe::operator=(const PmergeMe &otherPmergeMe) {
    (void)otherPmergeMe;
    return *this;
}

// int PmergeMe::binarySearch(std::vector<int> &vector, int target) {
//     int start = 0;
//     int end = vector.size() - 1;
//
//     while (start <= end) {
//         size_t middle = start + (end - start) / 2;
//
//         if (middle == 0) {
//             if (target < vector[0])
//                 return 0;
//             return 1;
//         }
//
//         if (middle > 0 && middle < vector.size() && target <= vector[middle]) {
//             end = middle - 1;
//         } else {
//             start = middle + 1;
//         }
//     }
//     return start;
// }


double PmergeMe::sort(std::vector<int> &input) {
    std::vector<std::pair<int, int> > pairs;
    static std::pair<std::vector<int>, std::vector<int> > chains;

    clock_t start, end;

    start = clock();
    {
        VectorIntConstIterator number = input.cbegin();

        // if the list is odd that means one number will remain so we will save it.
        if (input.size() % 2 != 0) {
            unpair = *number;
            number++;
        }

        // sort the pairs based on the first number (e,g [3, 9] become [9, 3])
        for (; number != input.end(); number += 2) {
            std::pair<int, int> pair(*number, *(number + 1));
            if (pair.first < pair.second) {
                const int temp = pair.first;
                pair.first = pair.second;
                pair.second = temp;
            }
            pairs.push_back(pair);
        }

        // insertion sort the pairs based on the first element on the pair (e,g [(9), 3])
        {
            VectorPairsIterator pair = pairs.begin();

            for (; pair != pairs.end(); pair++) {
                VectorPairsIterator iter = pair;
                std::pair<int, int> temp = *pair;
                // std::cout << "[" << pair->first << ", " << pair->second << "]" << std::endl;
                while (iter != pairs.begin() && (iter - 1)->first > temp.first) {
                    iter->first = (iter - 1)->first;
                    iter->second = (iter - 1)->second;
                    iter--;
                }
                *iter = temp;
            }
            // split the pairs to two chains, chain1 will hold the left number on the pair and chain2 holds the right number
            for (pair = pairs.begin(); pair != pairs.end(); pair++) {
                chains.first.push_back(pair->first);
                chains.second.push_back(pair->second);
            }
        }
    }

    const vector_t pend = chains.second;
    vector_t main = chains.first;

    vector_t jacobsthalNumbers;
    // Generate jacobsthal input [0, 1, 1, 3, 2, 5, 11, 21, 43, 85, 171]....
    {

        const size_t size = pend.size();
        jacobsthalNumbers.push_back(0);
        jacobsthalNumbers.push_back(1);

        size_t jacobsthalNumber = 0;
        for (size_t i = 2; i < size && jacobsthalNumber < size; i++) {
            jacobsthalNumber = jacobsthalNumbers[i - 1] + (2 * jacobsthalNumbers[i - 2]);
            jacobsthalNumbers.push_back(jacobsthalNumber);
        }

        // remove number at index 1 because it duplicated
        jacobsthalNumbers.erase(jacobsthalNumbers.cbegin() + 1);

        // add missed numbers to get all indexes we will need
        // [0, 1, 3, 2, 5, 11, 21, 43, 85, 171]
        for (size_t i = 0; i < size ; i++) {
            if (std::find(jacobsthalNumbers.begin(), jacobsthalNumbers.end(), i) == jacobsthalNumbers.end()) {
                for (VectorIntConstIterator it = jacobsthalNumbers.cbegin(); it != jacobsthalNumbers.end(); ++it) {
                    if (i < static_cast<size_t> (*it)) {
                        jacobsthalNumbers.insert(it + 1, i);
                        break;
                    }
                }
            }
        }
    }

    // merge the two chains
    {
        for (VectorIntConstIterator number = jacobsthalNumbers.cbegin(); number != jacobsthalNumbers.end(); number++) {
            if (*number < static_cast<int>(pend.size())) {
                int n = pend[*number];
                const int index = binarySearch(main, n);
                main.insert(main.cbegin() + index, n);
            }
        }
        if (unpair != -1) {
            const int index = binarySearch(main, unpair);
            std::cout << index << std::endl;
            main.insert(main.cbegin() + index, unpair);
        }
        input = main;
    }

    // calculating the time spent and return it !
    end = clock();
    return ((double)(end - start)) / CLOCKS_PER_SEC;
}


double PmergeMe::sort(std::deque<int> &input) {
    std::deque<std::pair<int, int> > pairs;
    static std::pair<std::deque<int>, std::deque<int> > chains;

    clock_t start, end;

    start = clock();
    {
        DequeIntIterator number = input.begin();

        // if the list is odd that means one number will remain so we will save it.
        if (input.size() % 2 != 0) {
            unpair = *number;
            ++number;
        }

        // sort the pairs based on the first number (e,g [3, 9] become [9, 3])
        for (; number != input.end(); number += 2) {
            std::pair<int, int> pair(*number, *(number + 1));
            if (pair.first < pair.second) {
                const int temp = pair.first;
                pair.first = pair.second;
                pair.second = temp;
            }
            pairs.push_back(pair);
        }

        // insertion sort the pairs based on the first element on the pair (e,g [(9), 3])
        {
            DequePairsIterator pair = pairs.begin();

            for (; pair != pairs.end(); pair++) {
                DequePairsIterator iter = pair;
                std::pair<int, int> temp = *pair;
                while (iter != pairs.begin() && (iter - 1)->first > temp.first) {
                    iter->first = (iter - 1)->first;
                    iter->second = (iter - 1)->second;
                    iter--;
                }
                *iter = temp;
            }
            // split the pairs to two chains, chain1 will hold the left number on the pair and chain2 holds the right number
            for (pair = pairs.begin(); pair != pairs.end(); pair++) {
                chains.first.push_back(pair->first);
                chains.second.push_back(pair->second);
            }
        }
    }

    const deque_t pend = chains.second;
    deque_t main = chains.first;

    deque_t jacobsthalNumbers;
    // Generate jacobsthal input [0, 1, 1, 3, 2, 5, 11, 21, 43, 85, 171]....
    {
        const size_t  size = pend.size();
        jacobsthalNumbers.push_back(0);
        jacobsthalNumbers.push_back(1);

        size_t jacobsthalNumber = 0;
        // n && static_cast<size_t> (jacobsthalNumber)
        for (size_t i = 2; i < size && jacobsthalNumber < size; i++) {
            jacobsthalNumber = jacobsthalNumbers[i - 1] + (2 * jacobsthalNumbers[i - 2]);
            jacobsthalNumbers.push_back(jacobsthalNumber);
        }

        // remove number at index 1 because it duplicated
        DequeIntConstIterator toRemove = jacobsthalNumbers.cbegin() + 1;
        jacobsthalNumbers.erase(toRemove);

        // add missed numbers to get all indexes we will need
        // [0, 1, 3, 2, 5, 11, 21, 43, 85, 171]
        for (size_t i = 0; i <= size ; i++) {
            if (std::find(jacobsthalNumbers.begin(), jacobsthalNumbers.end(), i) == jacobsthalNumbers.end()) {
                for (DequeIntIterator it = jacobsthalNumbers.begin(); it != jacobsthalNumbers.end(); ++it) {
                    if (i < static_cast<size_t> (*it)) {
                        jacobsthalNumbers.insert(it + 1, i);
                        break;
                    }
                }
            }
        }
    }

    // merge the two chains
    for (DequeIntIterator number = jacobsthalNumbers.begin(); number != jacobsthalNumbers.end(); ++number) {
        if (*number < static_cast<int>(pend.size())) {
            int n = pend[*number];
            const int index = binarySearch(main, n);
            main.insert(main.cbegin() + index, n);
        }
    }
    if (unpair != -1) {
        const int index = binarySearch(main, unpair);
        main.insert(main.cbegin() + index, unpair);
    }
    input = main;
    // calculating the time spent and return it !
    end = clock();
    return ((double) (end - start )) / CLOCKS_PER_SEC;
}
