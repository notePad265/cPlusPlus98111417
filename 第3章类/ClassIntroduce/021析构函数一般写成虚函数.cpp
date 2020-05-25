
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
	virtual ~Human()
	{
		cout << "Human析构函数" << endl;
	}
public:
	virtual  void eat() = 0;
};

class Man :public Human
{
public:
	Man();
	virtual void eat() override;
public:
	~Man()
	{
		cout << "执行了Man的析构函数" << endl;
	}

};

class Woman :public Human
{
public:
	Woman();
	virtual void eat() override;
public:
	~Woman()
	{
		cout << "执行了Woman的析构函数" << endl;
	}

};

Woman::Woman()
{
	cout << "这是woman的构造函数" << endl;
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

Man::Man()
{
	cout << "Man类的默认构造函数" << endl;
}



void Woman::eat()
{
	cout << "Woman类的eat()执行" << endl;
}
void Man::eat()
{
	cout << "Man类的eat()执行" << endl;
}


void playObject()
{
	Human *p_human01 = new Woman;
	p_human01->eat();//调用Woman的eat()函数

	Human*p_human02 = new Man;
	p_human02->eat();//调用Man的eat()函数

	//执行正确，会执行父类构造和子类构造 ，父类析构，子类析构
	Woman *p_woman = new Woman;
	delete p_woman;
	
	//都是只执行父类的析构函数，没有执行子类的析构函数
	cout << "-------------------------------------" << endl;
	delete p_human01;
	delete p_human02;
	/*
	执行了Woman的析构函数
	Human析构函数
	执行了Man的析构函数
	Human析构函数
	 */
}

int main(void)
{
	playObject();


	system("pause");
	return 0;

}
/*(1)用基类指针指向子类的对象，当delete只调用父类的析构函数，不会执行子类的析构函数
 *解决办法：
 *	把父类中的析构函数写成虚函数。
 *
 *	总结：
 *		1.一般子类都是public继承。在public继承中，基类对派生类机器对象的操作，只能影响到从基类继承下来的成员。
 *			如果想要用派生类对基类非继承成员函数进行操作，怎要把这个成员函数定义为虚函数。析构函数也是如此。
 *		2.基类中析构函数的虚函数特性也会继承给子类，这样子类的析构函数自然也是虚函数。虽然子类的析构函数和父类的
 *			析构函数名字不同，但是他们都是继承的虚函数。
 *		3.delete删除一个指向子类对象的父类指针的时候，肯定要调用父类的析构函数，在子类的析构函数中调用父类的析构函数。
 *			所以父类的析构函数就要声明为虚函数，也就是说，c++为了获得运行时的多态，所调用的成员函数必须是Virtual类型的。
 *
 *		4.结论：如果一个类如果想做基类，务必把类的析构函数写成virtual类型，只要基类的析构函数是虚函数，就能保证我们delete
 *		基类指针的时候调用正确的析构函数版本（先调用子类，再调用父类）
 *
 *		虚函数会增加内存开销，类里面定义虚函数，编译器就会给这个类增加虚函数表，这个表里面存放虚函数的指针。
 *
 *
 *调试信息：
 *	当我们把析构或者构造函数的写在类内部实现，可能更改为内联函数，不能f11进入函数内部执行。可以在函数体设置一个断点。
 *	（前面说的没有执行我们自己的写的构造或者析构是错误的）
 *	2019年11月19日17:44:50
 *	 Sunrise于东北电力大学第二教学楼1121实验室
*
*/



