#include <iostream>
#include "Array.hpp"

#define MAX_VAL 750

class s {
    int *ptr;
public:
    s() {
        ptr = new int();
        *ptr = 10;
    }
    int get () {
        if (ptr != 0)
            return *ptr;
        return 0;
    }
};


int main(int, char**)
{

    s ss;
    memset(&ss, 0, sizeof(s));
    std::cout << ss.get() << std::endl;

    return 0;
    Array<std::string> arr(10);
    arr[0] = "hello";
    Array<int> numbers(MAX_VAL);
    int* mirror = new int[MAX_VAL];
    srand(time(NULL));
    for (int i = 0; i < MAX_VAL; i++)
    {
        const int value = rand();
        numbers[i] = value;
        mirror[i] = value;
    }
    //SCOPE
    {
        Array<int> tmp = numbers;
        const Array<int> test(tmp);
        (void)test.size();
    }

    for (int i = 0; i < MAX_VAL; i++)
    {
        if (mirror[i] != numbers[i])
        {
            std::cerr << "didn't save the same value!!" << std::endl;
            return 1;
        }
    }
    try
    {
        numbers[-2] = 0;
    }
    catch(const std::exception& e)
    {
        std::cerr << e.what() << '\n';
    }
    try
    {
        numbers[MAX_VAL] = 0;
    }
    catch(const std::exception& e)
    {
        std::cerr << e.what() << '\n';
    }

    for (int i = 0; i < MAX_VAL; i++)
    {
        numbers[i] = rand();
    }
    delete [] mirror; //
    return 0;
}
