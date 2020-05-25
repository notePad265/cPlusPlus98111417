#include<iostream>
#include<cstdlib>
#include<string>
#include<vector>

using namespace std;
class A
{
public:
	int a;
	A(int i):a(i)
	{
		cout << "A构造函数执行" << endl;

	}
	virtual ~A()
	{
		cout << "A析构函数" << endl;
	}
};
class B1:public A
{
public:
	int b1;
	B1(int i,int j):A(i),b1(j)
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


class C:public B1,public B2		//派生列表
{
public:
	int c;
	C(int i,int j, int k):B1(i,j),B2(i,j),c(k)
	{
		cout << "c构造函数执行" << endl;
	}
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

	C c1(1, 2, 3);
	c1.static_number = 12;
	C::static_number = 30;
	/*析构函数和构造函数调用顺序：
	A构造函数执行
	B1构造函数执行
	A构造函数执行
	B2构造函数执行
	c构造函数执行
	C析构函数
	B2析构函数
	A析构函数
	B1析构函数
	A析构函数
	请按任意键继续. . .

	 * 
	 */
}

int main(void)
{
	playObject();
	system("pause");
	return 0;
}

/*
*(1)静态成员变量 静态成员变量属于类，而不是属于对象
*
*(2)派生类构造函数与析构函数
*	1.构造一个派生类对象将同时构造并初始化所有的基类对象
*	2.派生类的构造函数初始化只初始化它的直接基类。每个类的构造函数都负责初始化它的直接基类。
*		一层一层传递下去。
*	3.派生类构造函数初始化列表将实参值分别传递给它的直接基类。
*		基类的构造顺序和“派生列表”中基类的出现顺序保持一致。
*	4.每个类的析构函数都负责释放自己类分配的内存，子类的析构函数释放子类分配的内存。父类析构函数负责释放父类分配的内存。
*	
*显式初始化基类：C(int i,int j, int k):B1(i,j),B2(i,j),c(k)
*隐式初始化基类：当一个基类包含一个不带参数的构造函数，那么初始化的时候可以不出现父类，
*	隐式的使用不带参数的构造函数来初始化。
*
*	
*(3)
*
*
*/