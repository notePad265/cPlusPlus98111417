#include<iostream>
#include<cstdlib>
#include <boost/type_index.hpp>
using namespace std;

template<typename T>
void myFunction01(T &&tem)//T是类型模板参数，T是有类型的,tem是形参，tem也是有类型的
{
	using boost::typeindex::type_id_with_cvr;
	cout << "T type=" << type_id_with_cvr<T>().pretty_name() << endl;//显示T类型
	cout << "tem type=" << type_id_with_cvr<decltype(tem)>().pretty_name() << endl;//显示tem类型

}

int main(void)
{
	int i = 18;//i的类型是int类型，i是个左值。
	myFunction01(i);//实例化后,我们认为编译器推断后的结构为void myFunction(int& &&tem){}
	myFunction01(12);
	/*
	 *	T type=int &
		tem type=int &
		T type=int
		tem type=int &&
	 */
	//编译器真正实例化出来的myFunction是什么类型 void myFunction(int&tem){}--引用折叠


	//1.1引用的引用
	int number = 500;
	int &number_reference = number;//引用
	//int & &rr = b;//链接在一起叫右值引用，分开交引用的引用，是非法的。但是编译器内部可以出现，它自己推导，使用引用折叠处理。


	
	system("pause");
	return 0;
}
/*
 * (1)引用折叠规则
 * 引用折叠是c++s11新标准，是一条规则，是一条规则reference-collapsing rules 引用坍塌，&&&--->&
 * c++标准中有明确含义的引用只有两种：一种是&左值引用，一种是&&右值引用。
 *	void myFunction(int& &&tem)//两组 int&是左值引用，第二组&&tem是右值引用类型
 *	
 *	什么情况下出现引用折叠？？
 *	分成两组，第一组是左值引用/右值引用		第二组 左值引用/右值引用
 *			左值引用  左值引用	&		&
 *			左值引用	右值引用	&		&&	当前的情况
 *			右值引用	左值引用	&&		&
 *			右值引用	右值引用	&		&
 *		折叠规则：如果任何一个为左值引用，那么结果就是左值引用，否则就是右值引用。--左值具有传染性。
 *
 *		1.1引用的引用
 *		不可以显示写，但是编译器内部进行函数模板类型推断的时候可以出现，编译器使用引用折叠规则进行处理。
 *		编译器不允许程序开发者写出引用的引用的代码。
 *	需要引用折叠的场景有：
 *		1.函数模板实例化
 *		2.auto自动类型推断的时候
 *		
 * (2)
 * (3)
 * (4)
 * (5)
 * (6)
 */