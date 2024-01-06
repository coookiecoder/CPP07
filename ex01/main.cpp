#include "iter.hpp"
#include <iostream>

void show_element_int(int element)
{
	std::cout << element;
}

void show_element_char(char element)
{
	std::cout << element;
}

template<typename type_element> void show_element(type_element element)
{
	std::cout << element;
}

int main(void) {
	char buffer1[10] = "abcdefijk";
	int buffer2[10] = {1,2,3,4,5,6,7,8,9,10};

	::iter(buffer1, 9, &show_element_char);
	std::cout << std::endl;

	::iter(buffer2, 10, &show_element_int);
	std::cout << std::endl;

	::iter(buffer1, 9, show_element);
	std::cout << std::endl;

	::iter(buffer2, 10, show_element);
	std::cout << std::endl;
}
