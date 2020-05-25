#include<iostream>
#include<cstdlib>
#include<string>
#include<vector>
using namespace std;

class  Human
{
public:
	int age;
	string name;
public:
	//构造函数
	Human();
	Human(int age, string name);
	//析构函数
	~Human()
	{
		cout << "Human析构函数" << endl;
	}
public:
	void myFunction();
	//virtual void eat() final;
	virtual void eat()//虚函数的实现	运行时动态识别
	{
		cout << "这是Human的eat函数" << endl;
	}
};

class Man:public Human
{
public:
	Man();
public:
	void myFunction();
	void eat() override;
	
};
void Man::eat()
{
	cout << "man中的eat（）函数执行" << endl;
}


class Woman:public Human
{
public:
	Woman();
public:
	void myFunction();
	void eat() override
	{
		cout << "woman中的eat()函数" << endl;
	}
};


void Human::myFunction()
{
	cout << "Human类中的函数执行" << endl;
}

void Man::myFunction()
{
	cout << "Man类中的myFunction函数执行" << endl;
}


Human::Human()
{
	cout << "Human默认构造函数" << endl;
}

Human::Human(int age, string name)
{
	this->age = age;
	this->name = name;
	
}

Woman::Woman()
{
	cout << "woman的构造函数" << endl;
}

void Woman::myFunction()
{
	cout << "Woman类中的myFunction函数" << endl;
}



Man::Man()
{
	cout << "Man类的默认构造函数" << endl;
}



int main(void)
{
	Human*p_human = new Human;
	Man *p_man = new Man;

	//子类是特殊的父类，父类指针可以new一个子类对象
	Human*p_human2 = new Man;	//ok，使用子类对象初始化父类指针
	Human*p_human3 = new Woman;
	
	p_human2->myFunction();	//这里调用父类中的函数
	//但是父类指针实际上是指向子类的对象，如果想调用子类的函数？--->新需求
	//---父类指针指向父类对象还是子类对象就调用对应的函数--->多态
	p_human->eat();	//调用父类eat()
	p_human2->eat();//调用Man类eat()
	p_human3->eat();//调用Woman中的函数eat()
	p_human3->Human::eat();//显式调用父类的eat()函数

	
	delete p_human;
	delete p_human2;
	delete p_human3;
	/*
	 *都是调用Human的析构函数,若果想调用各个子类的析构函数应该怎么办？
	 *
	 */
	system("pause");
	return 0;

}
/*(1)基类指针，派生类指针
 *	使用new创建对象都是返回指针
 *	父类指针使用子类对象初始化，但是只能调用父类中的同名函数---->如何调用子类同名函数--->新需求--->虚函数-->多态
 *
 *
 *实际中当函数的参数是父类指针，可以接受所有的子类对象作为实参传递过来，实现动态类型识别来调用父类和子类中的同名函数。
 *(2)虚函数--实现多态
 *	父类的同名函数前面增加virtual.来表示这是一个虚函数，可以实现多态。子类的同名函数可以不写virtual，自动为虚函数。
 *	父类函数和子类函数的名字，参数，参数类型，必须完全相同。才会有多态。
 *
 *	重载--在一个类内部函数名字相同，但是参数个数，参数类型，参数顺序不同，调用时候使用参数来区别。
 *	重写：虚函数实现多态，父类中的同名函数在子类中函数名字，参数都不能改变。
 *	重定义：继承中子类重新写了这个函数，改变了参数个数，类型，参数顺序等。
 *
 *为了避免你在子类中写错虚函数，在c++中，你可以在函数声明中增加一个override的关键字。这个关键字用在“子类”中，
 *	必须父类是虚函数，才可以加上override，否则会报错。当函数不能覆盖的时候也会报错。
 *	override就是用来说明派生类中的虚函数，编译器就会认为你这个eat()函数覆盖了父类中的同名函数，
 *	编译器就会在父类中找同名同参数的虚函数，如果没找到，就会报错。
 *
 *(3)final关键字
 *	是与overrode相对的，也是用在虚函数中，使用在“父类”中，如果我们在父类的函数中声明了“final”关键字，那么任何尝试
 *	覆盖该函数的操作都将引发错误。
 *
 *	动态绑定：动态表示的就是我们的程序运行的时候才知道父类指针指向哪个对象，调用对象的对应的函数。
 *	运行的时候才知道哪个对象绑定到eat()函数中。
 *(4)多态性
 *	多态性是针对虚函数来说的。
 *	体现在具有继承关系的父类和子类之间，子类重写了父类成员函数virtual，通过父类的指针，只有到了程序运行时期找到程序动态绑定到
 *	父类指针的函数，然后系统内部查询虚函数表执行对应的函数（父类和子类的虚函数）。
 *
 *
 *(6)
 * 
 */


