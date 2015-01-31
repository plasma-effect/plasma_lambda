#include"test.hpp"
#include<iostream>

#if TEST_CODE == 2

void test()
{
	auto func = _<1>();
	std::cout << func(1, 2, 3) << std::endl;
}


#endif