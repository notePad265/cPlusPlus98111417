#include<iostream>
#include<cstdlib>
#include <vector>

using namespace std;

template<typename T>
T& DoubleMyself(T&value)
{
	value *= 2;
	return value;
}


template<typename T>
decltype(auto) DoubleMyself02(T&value)//使用auto推断返回值结果
{//把auto理解成要推导的类型，推导过程理解为我们采用decltype推导
	value *= 2;
	return value;
}

int main(void)
{
	//2.4 decltype的主要用途_decltype(auto)用法
	//1.用于函数返回类型
	int number01 = 100;
	DoubleMyself(number01) = 20;//返回的是左值引用，所以可以赋值
	cout << "number01=" << number01 << endl;//20
	//使用auto推断返回值结果,DoubleMyself02的返回值结果是int，是一个右值，不能给右值赋值。加上decltype ok
	DoubleMyself02(number01) = 43;
	cout << number01 << endl;//43

	decltype(DoubleMyself02(number01))number02 = number01;
	cout << "number02=" << number02 << endl;//43
	
	system("pause");
	return 0;
}
/*
*2.4 decltype的主要用途_decltype(auto)用法
*c++14中存在这种语法，编译器要支持c++14语法
*	1.用于函数返回类型
* (3)
* (4)
* (5)
* (6)(7)
*/