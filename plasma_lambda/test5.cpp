#include"test.hpp"

#if TEST_CODE == 5
#include<iostream>

void test()
{
	using namespace plasma::lambda;
	auto func = if_(_<0>() == _<1>())[_<0>()][_<0>() + _<1>()];
	std::cout << func(1, 2) << std::endl;
	std::cout << func(2, 2) << std::endl;
}


#endif