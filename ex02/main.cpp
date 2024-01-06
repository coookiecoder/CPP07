#include <iostream>
#include <cstdlib>
#include "Array.hpp"

#define MAX_VAL 100

int main(void)
{
	// init class and the copy
    Array<int> numbers(MAX_VAL);
    int* mirror = new int[MAX_VAL];

	// set value in the class and the copy
    srand(time(NULL));
    for (int i = 0; i < MAX_VAL; i++)
    {
        const int value = rand();
        numbers[i] = value;
        mirror[i] = value;
    }

    // contructor test
    {
        Array<int> tmp = numbers;
        Array<int> test(tmp);
    }

	// compare to check no information where lost
    for (int i = 0; i < MAX_VAL; i++)
    {
        if (mirror[i] != numbers[i])
        {
            std::cerr << "didn't save the same value!!" << std::endl;
            return 1;
        }
    }

	// out of bound in negative
    try
    {
        numbers[-2] = 0;
    }
    catch(const std::exception& e)
    {
        std::cerr << e.what() << '\n';
    }

	// out of bound in positive
    try
    {
        numbers[MAX_VAL] = 0;
    }
    catch(const std::exception& e)
    {
        std::cerr << e.what() << '\n';
    }

	// set every number in the class again
    for (int i = 0; i < MAX_VAL; i++)
    {
        numbers[i] = rand();
    }

	// free memory
    delete [] mirror;
    return 0;
}
