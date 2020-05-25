#include<iostream>
#include<cstdlib>
#include<string>
#include<vector>

using namespace std;

//可变参函数的简单例子
/*
 * 1.我么一般吧args称为一包或者一堆参数，而且这些参数类型是可以不同的。
 * 2.我们理解T这种类型，不要理解为一个类型，而是0到多个类型。
 * 3.一包参数中可以容纳0到多个模板参数，而且这些模板参数可以是任意类型。
 * 4.注意：
 *	T...   可变参类型，是一包类型
 *	args可变形参，一包形参
 *5.&的位置出现在类型名后面
 */
template<typename ... T>
void myFunction(T...args)
{
	cout << "args=" <<sizeof...(args) << endl;
	cout << sizeof...(T) << endl;
}


//例子2
template<typename T,typename ...U>
void myFunction02(const T&firstarg,const U&...otherargs)
{
	cout << sizeof...(otherargs) << endl;//sizeof...可变参的数量
}

void func()
{
	myFunction();
	myFunction(10, 20);
	myFunction(10, 20,23,4343.34);
	cout << "----------------------------------" << endl;

	myFunction02(1, 23, 43);//2,至少有一个参数
}

int main(void)
{
	func();
	system("pause");
	return 0;
}

/*
*(1)可变参函数模板 variadic templates
*允许模板中包含0个到任意个模板参数，在语法上和传统的模板不一样，使用  ...
*
*
*(3)
*
*
*/