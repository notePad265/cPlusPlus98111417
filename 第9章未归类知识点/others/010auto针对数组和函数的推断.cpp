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

void myFunction(double a,int b)
{
	
}


int main(void)
{
	const char myStr[] = "jisuanjizuchengyaunli";//mystr=const char[长度]类型
	auto mystr02 = myStr;//const char*
	auto&mystr03 = myStr;//const char(&)[数组长度]类型

	int a[2] = { 1,2 };
	auto myIntarry = a;//auto =int* myIntArray=int*

	//函数类型
	auto myf = myFunction;//
	auto &myf02 = myFunction;//
	using boost::typeindex::type_id_with_cvr;
	cout << "myf type=" << type_id_with_cvr<decltype(myf)>().pretty_name() << endl;//显示类型
	cout << "myf02 type=" << type_id_with_cvr<decltype(myf02)>().pretty_name() << endl;
	/*
	    myf type=void (__cdecl*)(double,int)//函数指针
		myf02 type=void (__cdecl&)(double,int)//函数引用
	 */

	
	system("pause");
	return 0;
}
/*
* (1)auto针对数组和函数的推断
* (3)
* (4)
* (5)
* (6)(7)
*/