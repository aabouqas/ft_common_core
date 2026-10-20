#pragma once
#include <stack>
#include <iostream>

template <typename T>
class MutantStack : public std::stack<T> {
    public:
       typedef typename std::deque<T>::iterator iterator;

        MutantStack() {

        }

        ~MutantStack() {

        }

        MutantStack &operator=(const MutantStack &otherMutantStack) {
            if (this == &otherMutantStack)
                return *this;
            this->c = otherMutantStack.c;
            return *this;
        }

        MutantStack(const MutantStack &otherMutantStack) {
            this->c = otherMutantStack.c;
        }

        iterator begin() {
            return this->c.begin();
        }

        iterator end() {
            return this->c.end();
        }
};