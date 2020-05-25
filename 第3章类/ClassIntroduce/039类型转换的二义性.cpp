
#include<iostream>
#include<cstdlib>
#include<string>
#include<vector>

using namespace std;

class TypeConversion	//功能：将一个数字转换为0-100存储下来
{
public:
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
	//类对象转换为double类型
	operator double()const
	{
		return 1.0*number01;
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

	TypeConversion tc03(1.00);
	//int m = tc03 + 4;//二义性--不知道转换为int类型还是doble类型


	system("pause");
	return 0;
}

/*
*
*(1)类型转换的二义性
*类类型--整形
*类类型--函数指针类型
*二义性：有两种或者多种方法，导致编译器不知道怎么做，所以编译器只能保存。
* Sunrise于东北电力大学第二教学楼1121实验室
* 2019年11月23日21:34:57
*
*/