#include<iostream>
#include<cstdlib>

using namespace std;

void myFunciton(int value)
{
	cout << "myFunciton函数执行了" << endl;
}

class TESTCLASS
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
public:
	int m_a;
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
	//1.1函数指针
	void(*pMyFunc)(int) = myFunciton;//定义一个函数指针并给初值
	pMyFunc(23);//使用函数指针调用函数  这就是一个可调用对象

	//1.2operator()
	TESTCLASS ts;
	ts.operator()(3);
	//等价于下面的调用
	ts(23);

	//1.3可被转换为函数指针的类对象_仿函数
	testclass02 tc2;
	tc2(40);//先调用operator tfpoint,然后调用返回的函数
	//等价于
	tc2.operator testclass02::tfpoint()(40);

	//1.4类成员函数指针
	TESTCLASS tc03;
	void (TESTCLASS::*myfPoint)(int) = &TESTCLASS::myfunction02;//类成员函数指针定义变量并初始化
	//成员函数指针本身是有地址的，不依赖于类对象
	(tc03.*myfPoint)(234);//这里必须有*  ----也是一个可调用对象
	


	
	system("pause");
	return 0;
}
/*
* (1)可调用对象
*	函数和重载了()运算符的类对象
*	1.1函数指针
*	1.2具有operator()成员函数的类对象--重载了()运算符的类对象
*		仿函数的定义：仿函数funtor，他的行为类似于函数的东西(something that performs a function)
*		c++中仿函数是通过在类中重载()运算符实现的。仿函数又被称为函数对象（function obeject），能行使函数功能的类。
*	1.3可被转换为函数指针的类对象_仿函数_函数对象
*	1.4类成员函数指针
*总结：
*	1.所有可调用对象看成一个对象
*	2.我们对其使用()调用运算符，如果a是可调用对象，那么我们可以使用a(para,para...)调用
*	
*/