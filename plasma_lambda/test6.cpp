#include"test.hpp"

#if TEST_CODE == 6
#include<iostream>

void test()
{
	using namespace plasma::lambda;

	auto func = constant(10);
	std::cout << func() << std::endl;
	std::cout << func(1) << std::endl;
	std::cout << func(1,2) << std::endl;
	std::cout << func(1,2,3) << std::endl;
}

#endif