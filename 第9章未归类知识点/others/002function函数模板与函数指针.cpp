#include<iostream>
#include<cstdlib>
#include <map>
#include <string>
#include <functional>

using namespace std;
typedef int (*myfunction)(int);//定义一个函数指针类型，这种指针可以指向返回值是int类型，且只有一个int类型参数的函数

//类实现的功能：返回一个大于等于0的数字，如果小于0，返回0
class BiggerThanZero
{
public:
	//带一个参数的构造函数
	BiggerThanZero(int a) :m_i(a)
	{
		m_i = a;
	}

public:
	//重载()函数调用运算符
	int operator()(int value)const
	{
		if (value <= 0)
		{
			return 0;
		}
		else
		{
			return value;
		}
	}


private:
	int m_i;
};

//普通函数,打印value值，并原样返回.--调用参数和返回值与类型中重载()相同
int echoValue(int value)
{
	cout << value << endl;
	return value;
}

int main(void)
{
	//通过函数指针调用函数
	myfunction myfucntionP1 = echoValue;//这里可以不加&
	int number01 = myfucntionP1(-23);
	int number02 = (*myfucntionP1)(234);//这里也可以不加*

	//通过map保存可调用对象的指针
	map<string, int(*)(int)>myMap;//这个map只能装函数指针类型
	myMap.insert({ "aa", echoValue });//插入一个函数指针

	BiggerThanZero b1(123);//含有函数调用运算符的对象
	//myMap.insert({ "bb",b1.operator() });//error,语法错误
	//通过function来声明一个可调用对象
	//function<int(int)>//声明了一个function()类型，用来代表一个可调用对象，代表的是返回值是int类型，接受一个int类型参数
	function<int(int)>f1 = echoValue;//函数指针，这里echoValue有函数重载，就会找不到地址，报错
	function<int(int)>f2 = b1;//放类对象也ok，类中有运算符重载
	function<int(int)>f3 = BiggerThanZero(12);//创建一个匿名对象来初始化一个函数模板对象
	f1(43);
	f2(-23);
	f3(-23);


	map<string, function<int(int)>>myMap02 = { {"aa",echoValue},{"bb",b1},{"cc",BiggerThanZero(23)}};
	myMap02["aa"](12);//容器名["键"]==值
	myMap02["bb"](234);
	myMap02["cc"](-213);
	
	system("pause");
	return 0;
}
/*
*(1)不同调用对象的相同调用形式--function模板
*int echoValue(int value)和类中的int operator()(int value)const，参数和返回值相同，就叫做“调用形式相同”
*一种调用形式对应一个函数类型（函数类型--返回值和参数）
*
*(2)可调用对象
*	eachValue()函数叫可调用对象
*	重载了函数调用运算符类对象
*	我们可以把这些可调用对象的指针保存起来，目的是方便我们随时调用这些可调用对象，类似于我们c语言中的函数指针
*	通过map键值对来保存，用字符串做键，用函数指针做值。
*
*(3)标准库functional类型介绍
*	function 类模板，要提供模板参数来表示该function类型能表示的调用形式
*
*注意：
*	如果函数有重载，就无法通过function来调用，解决办法是使用函数指针来解决。
*	2019年12月8日22点03分
*
*
*/