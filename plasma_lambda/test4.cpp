#include"test.hpp"

#if TEST_CODE == 4

#include<iostream>

template<class Func>void test_func(Func func)
{
	std::cout << func(3) << std::endl;
}

void test()
{
	using namespace plasma::lambda;
	test_func(+_<0>());
	test_func(-_<0>());
	test_func(~_<0>());
	test_func(!_<0>());
}

#endif