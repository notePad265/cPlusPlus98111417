
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
	//拷贝构造函数
	Human(const Human&TemHuman)
	{
		cout << "这是拷贝构造函数执行" << endl;
		this->age = TemHuman.age;
		this->name = TemHuman.name;
	}
	Human&operator=(const Human&TemHuman)
	{
		this->age = TemHuman.age;
		this->name = TemHuman.name;
		
		return *this;
	}
};

class Man :public Human
{
public:
	Man();
	~Man()
	{
		cout << "man的析构函数执行" << endl;
	}
public:

};

class Woman :public Human
{
public:
	Woman();
public:
	~Woman()
	{
		cout << "Woman析构函数执行" << endl;
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


class A
{
public:
	A(int value,string myStr):valueA(value),str(myStr)
	{
		;
	}
	private:
		int valueA;
		string str;
};

class B:public A
{
public:
	B(int i,string myStr,int j):A(i,myStr),valueB(j)//子类向父类传递参数
	{
		;
	}
private:
	int valueB;
};



//3
class grandFather{};
class Father:public grandFather{};
class Son:public Father{};
//一些概念，直接基类，间接基类


class Base final	//表示类Base不能做其他类的基类
{
	
};

int main(void)
{
	Man myMan1;
	/*这个对象包含多个组成部分，
	*(1)派生类自己定义的成员函数，成员变量的子对象
	*(2)一个派生类所继承的基类的子对象，（基类中的成员变量，成员函数（派生类对象包含有基类的成员函数，属性））
	 */
	Human *p_human = new Man;//	为什么基类指针可以使用子类对象初始化？？-->派生类对象含有基类对象部分。
	//子类是特殊的父类，子类和父类转换编译器帮助我们做了隐式类型转换。--->函数参数用基类，但是可以传递子类对象当实参。
	
	//2
	B b(12,"jisuanji" ,34);//基类的构造函数先执行，然后执行子类的构造函数

	cout << sizeof(grandFather) << endl;	//1字节
	cout << sizeof(Father) << endl;//1字节
	cout << sizeof(Son) << endl;//1字节



	Human *p_human02 = new Man;
	Human&Human_reference = *p_human02;//基类引用绑定到派生类对象上
	/*p_human02静态类型是Human，动态类型是Man
	 * 
	 */

	Man man03;
	Human human03(man03);//用子类对象来初始化父类对象，调用拷贝构造函数。

	human03 = man03;//直接调用重载的赋值运算符
	
	system("pause");
	return 0;

}
/*
*(1)派生类对象模型简介
*子类是特殊父类。函数形式参数用父类对象的指针或者引用
*(2)派生类的构造函数
*	派生类实际是使用基类的构造函数来初始化子类对象的基类部分。
*	子类构造函数只初始化自己本身的数据成员，从父类继承的数据成员调用父类的构造函数。
*
*	怎么传递参数给基类构造函数？
*		构造函数初始化成员列表的形式。
*		子类构造函数(形参列表):父类名字(, , , ),子类特有成员()
*(3)既可以当父类，又可以当子类
*继承关系一直传递，构成一个继承链，grandFather，Father，Son。
*
*(4)不想当基类的类
*	存在一些类不需要当其他类的父类，c++11中有final关键字，加在类名后表示类不能做基类。
*	final用在虚函数后面表示不能被重载。
*(5)静态类型与动态类型
*静态类型：变量声明定义时的类型，静态编译的时候已知的。
*动态类型：只的是指针、引用所表示（指向）的内存中的对象类型。
*动态类型是在运行的时候才能知道。
*动态类型，静态类型这种概念，只有基类指针，引用，才存在这种静态类型和动态类型不一致的情况。
*如果不是基类的指针，引用，就不存在静态类型和动态类型不一致的情况。
*
*(6)派生类向基类的隐式类型转换
*	编译器隐式的执行派生类（子类）向父类的隐式类型转换。
*	这种转换之所以能够成功，是因为每个派生类都包含一个基类对象部分，
*	所以基类的引用或者指针是可以使用子类对象初始化。
*
*	基类对象能独立存在也能作为派生类一部分存在，也能作为派生类对象的一部分存在。
*	不存在从基类到派生类的自动类型转换。
*(7)父类和子类之间的拷贝赋值
*	用派生类对象为一个基类对象初始化或者赋值时，只有该派生类对象的基类部分被拷贝或者赋值。
*	派生类特有的部分不会赋值。
*	也就是说：基类只干基类自己的事情。多余的事情不会去做。问题：(1)为什么空类是1个字节？
*
*/



