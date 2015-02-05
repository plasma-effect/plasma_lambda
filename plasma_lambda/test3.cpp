#include"test.hpp"

#if TEST_CODE==3

#include<iostream>

template<class Func>void test_func(Func func)
{
	std::cout << func(6, 3) << std::endl;
}

void test()
{
	using namespace plasma::lambda;
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

	test_func(_<0>() | _<1>());
	test_func(_<0>()&_<1>());
	test_func(_<0>() || _<1>());
	test_func(_<0>() && _<1>());
}


#endif