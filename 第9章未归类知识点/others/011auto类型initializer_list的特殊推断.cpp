#include<iostream>
#include<cstdlib>

#include <boost/type_index.hpp>

using namespace std;

//显示参数类型，这里不研究boost库
template<typename T>
void myFunction01(T&tem)//T是类型模板参数，T是有类型的,tem是形参，tem也是有类型的
{
	using boost::typeindex::type_id_with_cvr;
	cout << "T type=" << type_id_with_cvr<T>().pretty_name() << endl;//显示T类型
	cout << "tem type=" << type_id_with_cvr<decltype(tem)>().pretty_name() << endl;//显示T类型

}



int main(void)
{
	//c++98支持的初始化方式
	int number01 = 10;
	int number02(23);
	//c++11支持的初始化方式
	int number03 = { 23 };
	int number04{ 234 };
	//替换为auto可以吗？？

	auto number05 = 23;//ok
	auto number06(23);
	auto number07 = { 23 };//class std::initializer_list<int>  auto遇见{}推导规则不一样
	auto number08{ 23 };
	using boost::typeindex::type_id_with_cvr;
	cout << "number07 type=" << type_id_with_cvr<decltype(number07)>().pretty_name() << endl;//显示T类型
	cout << "number08 type=" << type_id_with_cvr<decltype(number08)>().pretty_name() << endl;//显示T类型
	/*
	 *  number07 type=class std::initializer_list<int>一个类模板
		number08 type=int
	 */

	auto number09 = { 23,345 };//所有的类型要一致，需要进行二次推导，先推导auto=int,再推导出类模板类型
	
	
	system("pause");
	return 0;
}
/*
* (1)auto类型std::initializer_list的特殊推断
*	class std::initializer_list<int> c++中引入的类模板，表示某种特定的值的数组
* (2)auto还可以放在函数返回值类型，以后讲。
* (4)
* (5)
* (6)(7)
*/