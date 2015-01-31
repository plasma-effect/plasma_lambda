#include<p_lambda/utility.hpp>
#include"test.hpp"

#include<iostream>
int main()
{
	test();
	std::cout << "テストを終了しました、プログラムを終了するにはエンターを押してください テストコード：" << TEST_CODE << std::endl;
	std::cin.get();
}