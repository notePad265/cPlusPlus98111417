#include<iostream>
#include<cstdlib>
#include<string>
#include<vector>

using namespace std;

class A
{
public:
	A(int i,int j,int k=7):number01(i),number02(j),number03(k)
	{
		;
	}
	A()
	{}
public:
	int number01;
	int number02;
	int number03;
};

class B:public A
{
public:
	//B(int i,int j, int k):A(i,j,k)
	//{
	//	;
	//}
	using A::A;
	//继承A的构造函数，using就是让某个名字在当前作用域内可见。遇见这个代码，
	//会把基类的每个构造函数都生成一个在子类中。
	/*B(构造函数形参列表)：A（父类的构造函数形参列表）{}
	 *B(int i,int j, int k):A(i,j,k){}
	 *如果基类A的构造函数有默认参数的话，那么编译器遇到使用using A::A的时候，
	 *	就会帮助我们在派生类B中构造出多个构造函数出来
	 *
	 *如果基类包含多个构造函数，则在多数情况下，派生类会继承所有这些构造函数，但下面这些情况例外：
	 *	1.如果派生类中定义的构造函数和基类的构造函数具有相同的参数列表，那么从基类中继承来的构造函数被派生类中定义的覆盖掉。
	 *		（相当于只继承了一部分基类中的构造函数）
	 *	2.默认构造函数，拷贝构造函数，移动构造函数不会被继承。
	 *	3.如果类B，只含有using A::A从A继承来的构造函数的话，那么编译器是会合成默认的构造函数。
	 */
};



int main(void)
{

	B  b1(3, 4, 5);	//先调用父类的构造函数，再调用子类的构造函数。

	B b2;
	system("pause");
	return 0;
}

/*
*(1)继承的构造函数
*	一个类只调用其直接基类的构造函数。默认构造函数，拷贝构造函数，和移动构造函数是不能被继承。
*
*
*
*/