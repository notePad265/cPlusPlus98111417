#include<iostream>
#include<cstdlib>

using namespace std;

int main(void)
{
	int x = 10;
	auto f1 = [=]()mutable //加上mutable可以更改x的值，虽然是按值捕获的x
	{
		x = 234;
	};
	
	
	system("pause");
	return 0;
}
/*
* (1)ambda表达式中的mutable
* mutable容易改变的，易变的
* 不管是不是一个const属性的变量，加上mutable就可以修改它的值。
* (2)
* (3)
* (4)
* (5)
* (6)(7)
*/