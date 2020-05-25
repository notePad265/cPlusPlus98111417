#include<iostream>
#include<cstdlib>
#include <functional>

using namespace std;

//普通函数可调用对象
void myFunciton(int value)
{
	cout << "myFunciton函数执行了" << endl;
}

class TC
{
public:
	void operator()(int value)
	{
		cout << "这是类中重载了()运算符的函数执行了" << endl;
	}
	void myfunction02(int value)
	{
		cout << "testclass 类中的myfunction02函数执行了" << endl;
	}

	static int stcfunc(int t)
	{
		cout << "类tc中的静态函数执行" << endl;
		return t;
	}
public:
	int m_a=0;
};

//1.3可被转换为函数指针的类对象_仿函数_函数对象
class testclass02
{
public:
	using tfpoint = void(*)(int);
	static void myStaticFunction(int value)//静态成员函数执行了
	{
		cout << "testclass02静态成员函数执行了" << endl;
	}
	operator tfpoint()//类型转换函数
	{
		return myStaticFunction;//返回的是一个静态函数指针名字
	}
};
int main(void)
{
	//1.1绑定普通函数
	std::function<void(int)> f1 = myFunciton;
	f1(123);
	
	//1.2绑定类中的静态成员函数
	std::function<int(int)>f2 = TC::stcfunc;
	cout << f2(234) << endl;

	//1.3绑定仿函数
	TC tc03;
	std::function<void(int)>f3 = tc03;//类中的成员属性要初始化
	f3(23);


	testclass02 tc02;
	std::function<void(int)>f4 = tc02;
	f4(23);
	system("pause");
	return 0;
}
/*
* (1)function()可调用对象包装器
*如何能把各种可调用对象统一一下，使用同一种方法调用？？？
*std::function()可调用对象包装器
*c++11中引入的新标准，std::function是一个类模板，用来装各种可调用对象(不能装类成员函数指针，因为需要类对象参与)
*
*std::function类模板的特点：就是通过给它指定模板参数，他就能够用统一的方式来处理函数。
*	1.绑定普通函数
*	1.2绑定类的静态成员函数
*	1.3绑定仿函数
*
*
*/