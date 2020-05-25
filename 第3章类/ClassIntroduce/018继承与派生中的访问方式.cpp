
#include<iostream>
#include<cstdlib>
#include<string>
#include<vector>
using namespace std;

class Human
{
private:
	
public:
	//构造函数
	Human();
	Human(int m_i,string str,int myProtected,int myPrivate);

	//析构函数
	~Human();
	
public:
	int age;	//年龄
	string str;	//名字
	void myPubFunction() { ; }

public:	//父类的同名函数构成函数重载
	void myFunction();
	void myFunction(int tem);
protected:	//只能在子类的成员函数中调用
	int myProtected;	//本类和子类的成员函数可以访问
	void myProFunction() { ; }
private://子类都不能访问
	int myPrivate;
	void myPriFunction() { ; }
};

//构造函数
Human::Human()
{
	cout << "执行了Human默认构造函数" << endl;
}

Human::Human(int age, string str,int myWeath,int myPrivete)
{
	this->age = age;
	this->str = str;
	this->myProtected = myWeath;
	this->myPrivate = myPrivete;
	
	cout << "执行了Human带参数的构造函数" << endl;
}

//析构函数
Human::~Human()
{
	cout << "执行了Human析构函数" << endl;
}

void Human::myFunction()
{
	cout << "myFunction" << endl;
}

void Human::myFunction(int tem)
{
	cout << "myFunction" << tem << endl;

}


class Man:public Human	//男人类继承自Human类
{
public:
	Man();
	void myFunction(int tem);
public:
	using Human::myFunction;	//vs2015对这个支持不太好
};

void Man::myFunction(int tem)
{
	Human::myFunction(3);
	Human::myFunction();
	cout << "myFunction man" << tem << endl;
}




Man::Man()
{
	cout << "执行了man类的默认构造函数" << endl;
}



int main(void)
{
	Man m1;	//先调用父类的构造函数，然后调用子类的构造函数
	m1.age = 12;
	m1.str = "白乾龙";

	m1.myPubFunction();	//子类可以调用父类的public成员函数,


	//如果子类和父类有同名函数，那么子类对象只能调用子类的函数，不能调用父类的重载的函数
	m1.myFunction(123);
	/*如果确实想调用父类的成员函数，1.在子类的成员函数中，可以使用 父类名字：：同名函数名 强制调用父类函数
	 *2.using using namespace
	 *c++11中，让父类同名函数在子类中可见
	 *通过using这个关键字，让父类的同名函数在子类中可见，说白了就是让父类同名函数在子类中以重载的方式实现。
	 *
	 */

	m1.myFunction();	//会调用父类的myFunction函数
	system("pause");
	return 0;

}



/*
 * (1)派生类的概念
 *	类之间有一种层次关系，有父类有孩子类
 *	车这个类叫父类（基类，超类），派生出卡车轿车（他们叫孩子类。子类，派生类）
 *	有父类和子类。构成了层次关系，叫继承。子类可以从父类那里继承很多东西。
 *	继承的概念是面向对象程序设计的核心思想之一。
 *
 *	实现继承：
 *		1.定义一个父类，定义一些公用的成员变量，成员函数
 *		2.通过继承父类来构造新的类：子类。写代码时候我们只需要写和子类相关的一些内容即可。
 *		3.子类继承自父类，子类是特殊的父类，可以用子类对象来初始化父类对象。子类一般比父类拥有更多的功能。
 * (2)继承方式，有public private protected,继承是 class 子类名字:public/private/protected 父类
 * 
 * (3)派生类调用构造函数的顺序
 *	先调用父类的构造函数，初始化父类的成员变量，然后调用子类的构造函数，初始化子类的成员变量。
 * (4)类成员函数和成员属性的3中访问权限 与 3中继承方式
 *	public：可以被任意实体访问
 *	private：只允许本类的成员函数访问
 *	protected：只允许本类或者子类的成员成员函数访问。
 *
 *	父类和子类使用public方式继承
 *	父类			子类			子类访问类型
 *	public		public		public
 *	protected	public		protected	//重要
 *	private		public		无访问权限
 *
 *	public		protected	protected
 *	protected	protected	protected
 *	private		protected	无访问权限
 *
 *
 *	public		private		private
 *	protected	private		private
 *	private		private		无访问权限
 *
 *注意：
 *	1.子类public继承不改变父类的访问权限
 *	2.protected继承将父类中的public成员改为子类的protected成员。
 *	3.private继承使的父类所有成员在子类中变为private
 *	4.父类的private成员不受继承方式的影响，子类永远无法访问
 *	5.对于父类来讲，尤其是父类的成员函数，如果你不想让外部访问，就设置为private，
 *		如果你想让子类访问，就设置为protected，
 *		如果想公开，就设置为public。
 *	
 *(5)函数遮蔽
 *	子类对象可以调用父类的public，protected函数，但是当有同名函数时候，子类函数对象就会屏蔽父类的同名函数
 *
 *	using Human::myFunction;
 *	方法只能制定函数名，则凡是基类中的public protected的所有同名函数（myFucntion）在子类中都可见。
 *		不能让一部分同名函数在子类中可见，只能全部可见。
 *	using引入的主要目的是用来实现在子类中调用父类的同名函数。当子类中的参数个数，类型顺序和父类中的同名函数可以
 *	构成函数重载的时候才能区分开。
 *	 Sunrise于东北电力大学第二教学楼1121实验室
 *	 2019年11月19日10:39:17
 *	 
 *	
 */