#include<iostream>
#include<iostream>
#include<cstdlib>
#include<functional>
#include <vector>
#include <algorithm>
using namespace std;
std::vector<void(*)(int)>gv2;//用于存放一个int类型参数，返回值是void类型的lambda表达式

int main(void)
{
	static int temvalue = 4;
	gv2.push_back([](int value)//静态局部变量可以直接使用
	{
		cout << temvalue << endl;
		temvalue++;
	});
	
	gv2[0](12);//4
	gv2[0](123);//5
	gv2[0](123);//6
	
	system("pause");
	
	return 0;
}
/*
* (1)lambda中不捕获静态局部变量
*	捕获时间是不包括静态局部变量，也就是说静态局部变量是不能被捕获的。
*	但是可以在lambda表达式中使用静态局部变量，静态局部变量是保存在静态存储区，它的有效期是程序的运行期间。
*
*	静态变量不需要捕获，也捕获不到。但是这种对静态变量与按引用捕获效果类似。
*
*	将lambda匿名表达式存放在vector容器中，可以使用下表调用
*
*2019年12月11日19点30分
* (2)
* (3)
* (4)
* (5)
* (6)(7)
*/