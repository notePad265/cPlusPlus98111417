
#include<iostream>
#include<cstdlib>
#include<string>
#include<vector>
class A;

//class C;	//因为不仅仅用到了C的类声明，而且包含了里面的函数。甩下面的形式
class C
{
private:
	int number03;
public:
	void myFunctionC(int x, A&a);

public:
};

using namespace std;


class A
{
	friend class  B;	//这里还没有定义类B，但是没报错，如果有的编译器报错，可以在前面加一个类声明 class B;

	friend void C::myFunctionC(int x, A& a);
private:
	int number;
public:
	//构造函数
	A(int number)
	{
		this->number = number;
	}
	
};

class B
{
private:
	int number02 = 0;
public:

	void myFunction01(const A&temA);
};





void C::myFunctionC(int x, A& a)
{
	a.number = x;
	cout << a.number << endl;
	
}



void B::myFunction01(const A&temA)
{
	cout << "可以访问类A的私有成员" << endl;
	cout << temA.number << endl;

}


int main(void)
{
	A a(12);
	C c;
	c.myFunctionC(1, a);


	system("pause");
	return 0;

}
/*
*(1)友元成员函数--有的时候不需要让类中的所有成员函数都去访问另一个类的成员函数和成员变量。而只需要一个成员函数去访问
*
*总结：
*	(1)friend允许在特定情况下访问类的成员属性和成员函数。
*	(2)破坏了类的封装性，降低了类的可靠性与可维护性。
*	(3)要看具体的情况使用友元函数和友元类。
*
*
*2019年11月20日16:52:37
* Sunrise于东北电力大学第二教学楼1121实验室

*/



