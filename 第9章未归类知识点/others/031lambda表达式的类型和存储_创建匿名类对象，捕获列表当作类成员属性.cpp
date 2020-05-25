#include<iostream>
#include<cstdlib>
#include<functional>


using namespace std;

int main(void)
{
	auto f1 = [] {};//f1就相当于一个未命名的类 类型对象

	int x = 5;
	auto f2 = [=]()
	{
		return x;
	};//f2要生成一个类类型变量，这些捕获的外部变量要在类内部作为成员变量存在。

	//lambda和function结合使用例子
	std::function<int(int)>f3 = [](int value)->int
	{
		value++;
		return value;
	};
	cout << f3(15) << endl;//16

	std::function<int(int)>f4 = std::bind(
		[](int value)
	{
		return value + 1;
		
	},placeholders::_1
	);
	//bind第一个参数是可调用对象或者函数指针，第二个参数是函数参数
	cout << f4(23) << endl;//24

	//捕获列表为空的lambda表达式，可以转换成一个普通的函数指针。
	using funcpType = int(*)(int);//定义一个函数指针类型
	funcpType fp = [](int value) {return value + 1; };
	cout << fp(123) << endl;//124
	
	system("pause");
	return 0;
}
/*
* (1)lambda表达式的类型和存储
* c++11中lambda表达式的类型被成为“闭包类型（closure type）”。
* 闭包--函数内部的函数（可调用对象），本质上就是lambda表达式创建的运行时期的对象。
* lambda表达式是一种比较特殊的，匿名的，类 类型（闭包类）的对象。
* 我们也可以认为他是一个带有operator()类型的对象。也就是仿函数（函数对象）
*
* 所以我们可以使用std::function  std::bind来保存和调用lambda表达式，每个lambda都会
* 触发编译器生成一个独一无二的类类型。
* 
* lambda表达式这种语法我们可以就地定义匿名函数，就地封装短小的功能闭包。
* 
* (2)语法糖的概念
*	就是一种便捷写法
*	int a[4];
*	a[0]=5;//编译器内部的写法*(a+0)=5;
*	语法糖的目的就是让我们写的代码更加简单，容易理解，减少代码出错的机率。
*	语法糖是基于语言现有的特性，构建出一个东西，使用起来更简单，但是没有增加语言的原有功能。
*	lambda表达式可以堪称定义仿函数闭包（函数中函数）的语法糖。
* (3)
* (4)
* (5)
* (6)(7)
*/