#include<iostream>
#include<cstdlib>

using namespace std;
decltype(auto) myFunction()
{
	int i = 1;
	return i;
}

decltype(auto)myFunciton02()
{
	int i = 1;
	return(i);//加了()就会变成导致返回一个引用 int&,但是i是局部变量，使用会导致不可预料的结果。
	
}

int main(void)
{
	//用于变量的声明中
	int number01 = 12;
	const int &reference = 23;
	auto number02 = reference;//const属性和引用都没有传递
	decltype(auto)number03 = reference;//number03=const int& .auto丢掉的东西（const和引用），能够通过decltype(auto)捡回来

	//1.3再说(x)
	int number04 = 234;
	decltype((number04))rere = number04;//rere=int&类型

	decltype(myFunction()) number05 = 23;//int类型
	int a = 1;
	decltype(myFunciton02())number06 = a;//这里调用函数返回的是int&类型，但是i是局部变量
	myFunciton02() = 234;//语法上没问题，但是局部量i已经被系统回收了，会导致未预料的结果
	
	system("pause");
	return 0;
}
/*
* (1)decltype的主要用途_decltype(auto)用法
*	1.2用于变量的声明中_保存const和引用属性
*	1.3再说(x) 使用不当decltype会导致返回局部引用
* (2)decltype总结
*	
* (3)
* (4)
* (5)
* (6)(7)
*/