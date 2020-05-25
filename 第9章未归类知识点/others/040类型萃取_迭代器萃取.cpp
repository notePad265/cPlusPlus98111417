#include<iostream>
#include<iostream>
#include<cstdlib>
#include<functional>
#include <vector>
#include <algorithm>
#include <list>

using namespace std;

template <typename T>
void printTraitsInfo(const T& t)
{
	cout << "--------------begin-----------" << endl;

	cout << "我们要萃取的类型名字是：" << typeid(T).name() << endl;

	cout << "is_void = " << is_void<T>::value << endl;                                    //类型是否是void
	cout << "is_class = " << is_class<T>::value << endl;                                  //类型是否是一个class
	cout << "is_object = " << is_object<T>::value << endl;                                //类型是否是 一个对象类型
	cout << "is_pod = " << is_pod<T>::value << endl;                                      //是否普通类（只包含成员变量，不包含成员函数）；   POD(plain old data)
	cout << "is_default_constructible = " << is_default_constructible<T>::value << endl;  //是否有缺省构造函数
	cout << "is_copy_constructible = " << is_copy_constructible<T>::value << endl;        //是否有拷贝构造函数
	cout << "is_move_constructible = " << is_move_constructible<T>::value << endl;        //是否有移动构造函数
	cout << "is_destructible = " << is_destructible<T>::value << endl;                    //是否有析构函数
	cout << "is_polymorphic = " << is_polymorphic<T>::value << endl;                      //是否含有虚函数
	cout << "is_trivially_default_constructible = " << is_trivially_default_constructible<T>::value << endl;      //缺省拷贝构造函数是否是可有可无的(没有也行的),返回1表示确实可有可无

	cout << "has_virtual_destructor = " << has_virtual_destructor<T>::value << endl;      //是否有虚析构函数

	cout << "--------------end-------------" << endl;

}

class A
{
public:
	A() = default;
	A(A&& ta) = delete;           //移动构造：你要不写delete，系统一般就会认为你有这个成员函数；
	A(const A& ta) = delete;      //拷贝构造 
	virtual ~A() {}
};
class B
{
public:
	int m_i;
	int m_j;
};
class C
{
public:
	C(int t) {} //有自己的构造函数，编译器不会给你提供缺省构造函数
};

void func()
{
	printTraitsInfo(int());     //扔一个临时对象进去
	printTraitsInfo(string());
	printTraitsInfo(A());
	printTraitsInfo(B());
	printTraitsInfo(C(1));
	printTraitsInfo(list<int>());
}
int main(void)
{
	func();
	system("pause");
	return 0;
}
/*
* (1)类型萃取概述  type traits
* 属于泛型编程技术，在stl实现源码中，这种类型萃取技术使用比较多。萃取：提取一下信息出来。
* c++标准库中提出了很多类型萃取接口，这些接口其实都是一些类模板。。
* https://en/cppreference.com/w/cpp/types
* 
* (2)类型萃取范例
* 通过萃取接口中的value值为true或者false就能萃取一些有用的信息。
* 
* (3)迭代器萃取概述(iteratirs traits)
* 给定迭代器类型  对象 能够给出迭代器的种类
*
* (4)总结
* c++中，模板与泛型编程，模板元编程常用于开发标准库和接口库开发，如果做这个方向工作需要专门学习。
* 我们一般都是做和业务逻辑相关的工作。
* 
*/
