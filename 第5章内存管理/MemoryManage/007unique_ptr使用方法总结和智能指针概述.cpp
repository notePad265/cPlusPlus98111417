#include<iostream>
#include<cstdlib>
#include<string>
#include<vector>
#include <memory>

using namespace std;


unique_ptr<string>myFunction()
{
	unique_ptr<string>pr(new string("dsfsdf"));
	return  pr;
	/*
	 * 从函数返回一个局部对象，系统给我们生成一个临时unique_ptr对象，调用unique_ptr的移动构造函数
	 * 
	 */
}

void myDelete(string *pdel)
{
	delete pdel;
	pdel = nullptr;
}
typedef void(*myf)(string *);
//定义函数指针类型 using myf=void(*)(string*)
//typedef decltype(myDelete)*myf;

//lambda表达式
auto mydel=[](string*del)
{
	delete del;
	del = nullptr;
};


int main(void)
{
	unique_ptr<string> p1;
	p1 = myFunction();//临时对象直接构造在p1中。不接受会释放掉临时对象及其所指向的内存空间。


	//指定删除器--取代系统默认的删除器
	unique_ptr<string, myf> p2(new string("jisuanj"), myDelete);

	//另一种写法
	unique_ptr<string, decltype(myDelete)*>p3(new string("jisann"), myDelete);
	//用lambda表达式来写，可以理解成带有operator()类型的类对象
	unique_ptr<string, decltype(mydel)>p4(new string("sdfdsf"), mydel);
	
	//unque_ptr和裸指针相同
	string *p = nullptr;
	cout << sizeof(p) << endl;//4
	unique_ptr<string>p5(new string("sdf"));
	cout << sizeof(p5) << endl;//4
	
	system("pause");
	return 0;
}

/*
*(1)返回unique_ptr智能指针
*是不能拷贝，要被销毁的时候，还是可以拷贝的，最常见的是从一个函数返回一个unique_ptr
*
*(2)指定删除器
*	1.缺省情况下，会用delete释放内存空间
*	unique_ptr<指定的对象类型，删除器>智能指针变量名。
*	删除器本质上是一个可调用对象。
*	shared_ptr删除器直接在参数里面加上函数名字即可。但是unique_ptr的删除器相对负载一点。
*	需要向类模板中传递具体类型和删除函数类型。
	unique_ptr<string, myf> p2(new string("jisuanj"), myDelete);
*
*	2.指定删除器额外说明
*		shared_ptr指定的删除器不同，但是指向的对象类型相同，两个shared_ptr就是同一种类型。
*		但是unique_ptr的类型包含删除器，也就说，删除器不同，unique_ptr不是同一个类型。
*
*(3)尺寸问题
*	shared_ptr是裸指针的2倍，但是unque_ptr和裸指针相同.但是删除器不同可能占用内存空间不同
*	lambda --4字节,
*	函数指针类型--8字节
*	增加字节对效率有影响，自定义删除器哟啊谨慎使用。
*	shared_ptr不管指定什么删除器都是裸指针的2倍。
*
*(4)智能指针总结
*	4.1智能指针背后的设计思想
*		主要目的：帮助我们释放内存，防止内存泄漏。
*	4.2auto_ptr为什么被废弃？	--设计问题，会默认转移所有权
*		c++98时代的智能指针，具有unique_ptr智能指针的一部分功能。
*		且不能在容器中保存，并不能从函数中返回。
*		虽然unique_ptr和auto_ptr都是独占式的，但是auto_ptr进行赋值操作=会默认转移所有权。
*	建议：使用unique_ptr取代auto_ptr
*	
*	4.3智能指针的选择
*		shared_ptr
*		unique_ptr
*		如果程序有多个指针指向同一个对象，使用shared_ptr
*		如果不需要多个指针指向同一个指针，使用unique_ptr指针
*	
*
*
*/