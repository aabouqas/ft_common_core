#pragma once
#include <string>
#include <vector>
#include <exception>
#include <iostream>
#include <utility>
#include <algorithm>
#include <deque>
#include <sys/time.h>

class PmergeMe {
private:
    // static  std::vector<int> numbers;
    // static  std::vector<std::pair<int, int> > pairs;
    static int unpair;
    // static std::pair<std::vector<int>, std::vector<int> > chains;
    PmergeMe();
    ~PmergeMe();
    PmergeMe(const PmergeMe &otherPmergeMe);
    PmergeMe&operator=(const PmergeMe &otherPmergeMe);
    static std::vector<int>     getJacobsthalNumbers();

    template <typename Container>
    error
    static int  binarySearch(Container &container, int target) {
        int start = 0;
        int end = container.size() - 1;

        while (start < end) {
            size_t middle = start + (end - start) / 2;

            if (middle == 0) {
                if (target < container[0])
                    return 0;
                std::cout << end << std::endl;
                return 1;
            }

            if (middle > 0 && middle < container.size() && target <= container[middle]) {
                end = middle - 1;
            } else {
                start = middle + 1;
            }
        }
        return start;
    }

    typedef                     std::vector<std::pair<int, int> >::iterator VectorPairsIterator;
    typedef                     std::deque<std::pair<int, int> >::iterator DequePairsIterator;
    // aliases for deque
    typedef                     std::vector<int>::const_iterator VectorIntConstIterator;
    typedef                     std::vector<int>::iterator VectorIntIterator;
    typedef                     std::vector<int> vector_t;
    // aliases for vector
    typedef                     std::deque<int>::const_iterator DequeIntConstIterator;
    typedef                     std::deque<int>::iterator DequeIntIterator;
    typedef                     std::deque<int> deque_t;

    // TODO remove this
    // static  void displayPairs();

    // template function can display any container (e,g vector, deque....)
public:
    template <typename T>
    static  void displayContainer(const char *msg, T container) {
        std::cout << msg;
        for (typename T::iterator it = container.begin(); it != container.end(); it++) {
            std::cout << *it << " ";
        }
        std::cout << std::endl;
    }
    static  double    sort(std::vector<int> &input);
    static  double    sort(std::deque<int> &input);
};
