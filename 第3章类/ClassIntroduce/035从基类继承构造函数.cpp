#include<iostream>
#include<cstdlib>
#include<string>
#include<vector>

using namespace std;
class A
{
public:
	int a;
	A(int i) :a(i)
	{
		cout << "A构造函数执行" << endl;

	}
	virtual ~A()
	{
		cout << "A析构函数" << endl;
	}
};
class B1 :public A
{
public:
	int b1;
	B1(int i, int j) :A(i), b1(j)
	{
		cout << "B1构造函数执行" << endl;

	}
	virtual ~B1()
	{
		cout << "B1析构函数" << endl;
	}
};

class B2 :public A
{
public:
	int b2;
	B2(int i, int j) :A(i), b2(j)
	{
		cout << "B2构造函数执行" << endl;

	}
	virtual ~B2()
	{
		cout << "B2析构函数" << endl;
	}
};


class C :public B1, public B2		//派生列表
{
public:
	int c;
	C(int i, int j, int k) :B1(i, j), B2(i, j), c(k)//自己的版本
	{
		cout << "c构造函数执行" << endl;
	}
	//using B1::B1;
	//using B2::B2;
public:
	static  int static_number;//声明静态变量
public:
	virtual ~C()
	{
		cout << "C析构函数" << endl;
	}
};

int C::static_number = 10;//定义变量，分配内存空间，赋予初值

void playObject()
{
	;

}

int main(void)
{
	playObject();
	system("pause");
	return 0;
}

/*
*(1)从多个父类继承构造函数
*	如果一个类从它的基类中继承了相同的构造函数，这个类必须为该构造函数定义自己的版本。
*
*/