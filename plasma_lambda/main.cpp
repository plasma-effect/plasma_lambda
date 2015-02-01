#include<p_lambda/utility.hpp>
#include"test.hpp"

#include<iostream>
int main()
{
	test();
	std::cout << "プログラムを終了するにはEnterを押してください" << std::endl << "テストコード：" << TEST_CODE << std::endl;
	std::cin.get();
}