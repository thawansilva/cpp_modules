#include <iostream>
#include <ctime>
#include <cstdlib>
#include "Array.hpp"

#define MAX_VAL 750
int main(int, char**)
{
    Array<int> numbers(MAX_VAL);
    int* mirror = new int[MAX_VAL];
    srand(time(NULL));
	// Teste Copy constructor and assignment operator
    for (int i = 0; i < MAX_VAL; i++)
    {
        const int value = rand();
        numbers[i] = value;
        mirror[i] = value;
    }
    //SCOPE
    {
        Array<int> tmp = numbers;
        Array<int> test(tmp);
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
        std::cerr << e.what() << ": Out of range" << '\n';
    }
    try
    {
        numbers[MAX_VAL] = 0;
    }
    catch(const std::exception& e)
    {
        std::cerr << e.what() << ": Out of range" << '\n';
    }
	// Teste String
	Array<std::string> str_arr(3);
	const std::string src_arr[3] = { "Teste1", "Teste2", "Teste3"};
	for (int i = 0; i < 3; ++i)
		str_arr[i] = src_arr[i];
	for (int i = 0; i < 3; ++i)
		std::cout << str_arr[i] << std::endl;

    for (int i = 0; i < MAX_VAL; i++)
        numbers[i] = rand();
    delete [] mirror;
    return 0;
}
