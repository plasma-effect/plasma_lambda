#include"test.hpp"

#if TEST_CODE == 2

#include<iostream>

void test()
{
	using namespace plasma::lambda;
	auto func = _<1>();
	std::cout << func(1, 2, 3) << std::endl;
}


#endif