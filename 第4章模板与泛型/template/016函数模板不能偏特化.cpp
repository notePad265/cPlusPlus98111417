#include<iostream>
#include<cstdlib>
#include<string>
#include<vector>

using namespace std;


template<typename T, typename U>
void TestFunction(T &t, U&u)
{
	cout << "--这是函数泛化版本--" << endl;
}

//全特化版本 t=int，u=doubel
template<typename T>//这种写法是只有一个类型参数的新的模板，不是局部偏特化
void TestFunction(T&t, double&u)
{
	cout << "--这是局部偏特化的特化版本--" << endl;
}




int main(void)
{
	//函数模板全特化
	const char*p = "jisuanjiz";
	int i = 1200;
	TestFunction(p, i);//t=const char* &


	double d = 23.344;

	TestFunction(i, d);//重新调用了新的类型模板，而不是函数偏特化
	TestFunction(p, d);

	system("pause");
	return 0;
}

/*
*(1)函数模板偏特化--
*函数模板不能偏特化

*(2)模板特化版本 放置位置建议
*模板定义、实现一般放在.h文件中，模板的特化版本和泛化版本应该在同一文件中。
*
*返还版本在前，特化版本在后
*
*(3)
*
*
*/