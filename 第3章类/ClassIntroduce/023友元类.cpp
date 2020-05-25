
#include<iostream>
#include<cstdlib>
#include<string>
#include<vector>
using namespace std;

class A
{
private:
	int number;
public:
	//构造函数
	A(int number)
	{
		this->number = number;
	}
	friend class  B;	//这里还没有定义类B，但是没报错，如果有的编译器报错，可以在前面加一个类声明 class B;
	
};

class B
{
private:
	int number02=0;
public:
	
	void myFunction01(const A&temA);
};



void B::myFunction01(const A&temA)
{
	cout << "可以访问类A的私有成员" << endl;
	cout << temA.number << endl;
	
}


int main(void)
{
	A a(12);
	B b;
	b.myFunction01(a);


	system("pause");
	return 0;

}
/*
*(1)友元类
*	声明一个类B是类A的友元类（在类A里面声明friend class B;），
*		则类B的成员函数可以访问类A的所有成员函数和成员属性
*
*	1.每个类都负责控制自己的友元函数和友元函数。（自己类的友元函数，友元函数在自己类声明）
*	2.友元关系不能被继承
*	3.友元关系是单向的。类A是类B的友元类，但是类B是类A的友元类
*	4.友元关系没有传递性。A-->B-->C
*	
*
*2019年11月20日16:52:37
* Sunrise于东北电力大学第二教学楼1121实验室

*/



