#include<iostream>
#include<cstdlib>
#include<string>
#include<vector>
#include <memory>
#include <set>
#include <map>
#include <list>
#include <array>
#include<functional>
using namespace std;

class A
{
public:
	bool operator()(int i,int j)
	{
		return i > j;
	}
	
};

int main(void)
{
	plus<int>();//加()生成一个临时对象，就是一个可调用对象


	//(3)标准库中定义的函数对象范例
	vector<int>myVector = { 234,45,45,354,56,656,34,45645,654,7645,6,456,456 };
	A myA;
	sort(myVector.begin(), myVector.end(), myA);
	for (vector<int>::iterator iter=myVector.begin();iter!=myVector.end();iter++)
	{
		cout << *iter << endl;
	}

	//使用系统定义的函数对象
	sort(myVector.begin(), myVector.end(), greater<int>());//()产生临时对象
	sort(myVector.begin(), myVector.end(), less<int>());//()产生临时对象
	for (vector<int>::iterator iter = myVector.begin(); iter != myVector.end(); iter++)
	{
		cout << *iter << endl;
	}
	

	system("pause");
	return 0;
}

/*
*(1)函数对象function object（仿函数functors）
*在STL中，函数对象一般是和算法相结合实现特定的功能。也就是说函数对象主要用于服务于算符。
*可调用对象class A{public: void operator(){}}
*
*
*(2)标准库中定义的函数对象
*标准库中也为我们提供各类可以现成拿来使用的函数对象，使用它们之前，要包含一个头文件functional
*分类：
*	1.算数运算类
*	2.关系运算类
*	3.逻辑运算类
*	4.位运算类
*	
*(3)标准库中定义的函数对象范例
*
*
*
*
*/