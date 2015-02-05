#include"test.hpp"

#if TEST_CODE == 1
#include<typeinfo>
#include<iostream>

using namespace plasma::lambda;
template<class>struct test_sum;
template<index_t I, index_t... Is>struct test_sum < index_tuple<I, Is...> >
{
	static const int sum = I + test_sum<index_tuple<Is...>>::sum;
};
template<>struct test_sum <index_tuple<> >
{
	static const int sum = 0;
};
typedef class_tuple<int, double, float, unsigned int, char> test_class_tuple;

void test()
{
	std::cout << test_sum<index_count_t<10>>::sum << std::endl;

	std::cout << typeid(test_class_tuple).name() << std::endl;
	std::cout << class_tuple_size<test_class_tuple>::value << std::endl;
	std::cout << typeid(class_tuple_first_t<test_class_tuple, 3>).name() << std::endl;
	
}

#endif