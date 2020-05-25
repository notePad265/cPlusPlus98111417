#include<iostream>
#include<cstdlib>
#include <vector>

using namespace std;

//2.1应付可变类型--一般应用于模板类型编程中
template<typename T>
class CT
{
public:
	//typename T::iterator iter;//迭代器类型
	decltype(T().begin())  iter;//如果T类型是const std::vector<int>，返回常量迭代器类型
	//const std::vector<int>()表示生成该类型的临时对象(加括号)，调用临时对象的begin()，得到一个常量迭代器
	void getBegin(T&tem)
	{
		iter = tem.begin();
	}
public:
	CT(){}
};

//类模板偏特化
//template<typename T>
//class CT<const T>
//{
//public:
//	typename T::const_iterator iter;//迭代器类型
//	void getBegin(T&tem)
//	{
//		iter = tem.begin();
//	}
//};

int main(void)
{
	//2.1应付可变类型--一般应用于模板类型编程中
	//using conttype =std::vector<int>;
	using conttype =const std::vector<int>;
	
	conttype myVector = { 12,23,34 };//定义该变量类型，myVector是个容器
	CT<conttype>ct;
	ct.getBegin(myVector);

	//常来容器遍历使用常量迭代器
	const std::vector<int> myvector02 = { 23,345,45 };
	vector<int>::const_iterator iter = myvector02.begin();
	
	system("pause");
	return 0;
}
/*
* (1)decltype的主要用途
*		2.1应付可变类型--一般应用于模板类型编程中
*			生成临时对象使用decltype获取类型
* (2)
* (3)
* (4)
* (5)
* (6)(7)
* 错误，vs2015没能编译通过，不知道vs2017能否编译通过
*	二进制“=”: 没有找到接受“std::_Vector_const_iterator<std::_Vector_val<std::_Simple_types<int>>>”类型的右操作数的运算符(或没有可接受的转换)	others	e:\projectcode\第9章未归类知识点\others\源15.cpp	17	

*/