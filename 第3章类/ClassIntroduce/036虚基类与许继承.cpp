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
	A(){}
	virtual ~A()
	{
		cout << "A析构函数" << endl;
	}
};
class B1 :virtual public A
{
public:
	int b1;
	B1(int j) : b1(j)
	//B1(int i,int j) :A(i),b1(j)

	{
		cout << "B1构造函数执行" << endl;

	}
	virtual ~B1()
	{
		cout << "B1析构函数" << endl;
	}
};

class B2 :virtual public A
{
public:
	int b2;
	//B2(int i,int j) :A(i),b1(j)
	B2(int j) : b2(j)
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
	//特别注意：这里会调用A类的构造函数，要传递参数
	//C(int i, int j, int k) :B1(i, j), B2(i, j), c(k)//自己的版本--不是虚继承
	C(int i, int j, int k) : A(i), B1(j), B2(j), c(k)
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
	B1*b_point1 = new C(1,2,3);	//父类指向子类对象
	//A *a_point2 = new C(1, 2, 3);//不能使用爷爷类
	
	//c对象中包含A类的两个副本，解决办法就是使用虚继承
	C c2(11, 22, 33);
	//c2.a = 12;//C::a不明确
	//B1，B2虚继承后
	c2.c = 55;
	cout << c2.c << endl;
	
	

}

int main(void)
{
	playObject();
	system("pause");
	return 0;
}

/*
*(1)类型转换
*	基类指针可以使用子类对象初始化，编译器帮助我们执行隐式的类型转换。因为每个派生类都包含一个基类对象部分。
*	基类引用或者指针可以绑定到基类对象这部分上来的。
*(2)派生列表中，同一个基类只能出现一次，但是以下两种情况除外：
*	1.派生类可以通过它的两个直接基类分别继承同一个简介基类（爷爷类是一个）
*	2.直接继承一个基类，然后通过另一个基类间接继承该类
*(3)虚基类 virtual base class 虚继承
*	虚基类的特点：无论这个类在继承中出现多次，派生类只会包含一个共享的虚基类内容。
*
*	虚继承只影响从父类中派生出来的孙子类，对本身父类没有印象。
*	每个父类都要虚继承爷爷类。
*	爷爷类A-->父类B1，B2（这里进行虚继承），--->孙子类 --virtual和public的位置可以互换
*（4）	C(int i, int j, int k) : A(i), B1(j), B2(j), c(k)
*	1.当不进行虚继承的时候，B1，B2都会初始化爷爷A类，更改为虚继承之后，孙子C类就需要单独来初始化爷爷类
*	因为父类B不确定哪一个类进行初始化。
*	相应的父类构造函数也不需要初始化爷爷类对象。
*	2.初始化顺序发生改变。先初始化虚基类部分（A），然后按照派生列表的顺序来初始化其他类。
*	3.多个虚基类，哪个先初始化？
*		按照派生列表中虚基类出现的顺序构造
*总结
*	1.小心虚继承的二义性问题
*	2.在简单情况下，并且不容易出现二义性，实在必要才使用多继承。不建议使用多继承。
*
*	
*	2019年11月23日19:52:23
*	 Sunrise于东北电力大学第二教学楼1121实验室
*
*/