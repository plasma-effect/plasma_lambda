#include"test.hpp"

#include<iostream>

#if TEST_CODE==3

template<class Func>void test_func(Func func)
{
	std::cout << func(6, 3) << std::endl;
}

void test()
{
	test_func(_<0>() + _<1>());
	test_func(_<0>() - _<1>());
	test_func(_<0>() * _<1>());
	test_func(_<0>() / _<1>());
	test_func(_<0>() % _<1>());

	test_func(_<0>() << _<1>());
	test_func(_<0>() >> _<1>());

	test_func(_<0>() == _<1>());
	test_func(_<0>() != _<1>());
	test_func(_<0>() < _<1>());
	test_func(_<0>() > _<1>());
	test_func(_<0>() <= _<1>());
	test_func(_<0>() >= _<1>());

}


#endif