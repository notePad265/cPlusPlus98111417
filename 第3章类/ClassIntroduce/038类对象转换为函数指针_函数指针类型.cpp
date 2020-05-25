
#include<iostream>
#include<cstdlib>
#include<string>
#include<vector>

using namespace std;

class TypeConversion	//功能：将一个数字转换为0-100存储下来
{
	//定义一个函数指针类型，代表函数带一个函数形参，没有返回类型
	typedef void(*myFunction)(int);
	//等价于
	//using myFunction = void(*)(int);
public:
	static void myfunc(int value)	//静态成员函数
	{
		int test;
		test = 11;
	}
	//新的类型转换运算符，将本类类型转换为一个函数指针类型
	operator myFunction()
	{
		//必须要返回一个函数指
		return myfunc;//函数名字（函数地址）返回即可
	}
	
public:
	//类型转换构造函数--将一个int类型数字转换为TypeConversion类型
	//explicit TypeConversion(int x = 0) :number01(x)
	TypeConversion(int x = 0) :number01(x)
	{
		if (x <= 0 && x>100)
		{
			x = 0;
		}
		else
		{
			number01 = x;
		}
	}
	//类型转换运算符--类--->>>>>>>其他数据类型
	//explicit operator int()const
	operator int()const
	{
		return number01;
	}
public:
	int Add()
	{
		number01 += 1;
	}
public:
	int number01;
};


int main(void)
{
	TypeConversion tc = 12;//隐式类型转换，将数字转换为类对象，调用类型转换构造函数，加上explict禁止隐式类型转换
						   //把12隐式类型转换为一个临时对象，然后构建在tc分配的内存空间中。

	TypeConversion tc02(22);//调用类型转换构造函数，但是没有隐式类型转换
	tc02(123);//看起来是个可调用对象的感觉
	/*这一行调用了两个函数-------------------------------------------------
	 * 调用operator myFunction()类型转换函数返回一个函数指针，然后调用对应的函数。  
	 */
	//显式调用
	tc02.operator TypeConversion::myFunction()(123);
	/*
	 * tc02.operator TypeConversion::myFunction()返回的是函数地址，然后调用函数地址
	 */

	

	system("pause");
	return 0;
}

/*
*
*(1)类对象转换为函数指针
*	
*
*
*/