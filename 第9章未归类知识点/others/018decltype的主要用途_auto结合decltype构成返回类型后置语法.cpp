#include<iostream>
#include<cstdlib>
#include <vector>

using namespace std;

//后置语法
auto func(int a,int b)->int
{
	return 0;
}

auto add(int i,int k)->decltype(i+k)
{
	return i + k;
}

int&myfunction01(int&i)
{
	return i;
}
double myfunction01(double&i)
{
	return i;
}

//函数模板
template<typename T>
auto myFunTemplate(T&tv)->decltype(myfunction01(tv))//返回类型后置，要现有tv，才能用tv，这里必须用返回类型后置这种用法
{
	return myfunction01(tv);
}

int main(void)
{
	//2.3decltype的主要用途_decltype(auto)用法
	int i = 12;
	double d = 23.34;
	cout << myFunTemplate(i) << endl;//12
	cout << myFunTemplate(d) << endl;//23.34

	
	system("pause");
	return 0;
}
/*
* (2)2.3decltype的主要用途_auto结合decltype构成返回类型后置语法
*auto这里没有自动类型推断的意思，只是返回类型后置语法的组成部分
* 
*/