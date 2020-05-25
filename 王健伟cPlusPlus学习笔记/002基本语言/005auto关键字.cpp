#include<iostream>
#include<cstdlib>
using namespace std;

int main005(void)
{

	auto bValue = true;
	auto ch = 'a';
	auto doubleValue = 12.1;
	auto intVlaue = 12;
	//使用auto可以避免写很长的类型名
	
	system("pause");
	return 0;
}
/*
* (1)auto自动类型推断
*	auto可以在变量声明的时根据变量的初始值类型自动为此变量选择匹配的类型，、
*	（声明的时候必须赋初值）
*	auto自动类型推断发生在编译期间，所以使用auto避讳造成程序效率低。
*	c++编译器内部的初始化器来实现
*	
*/