#include<iostream>
#include<cstdlib>
#include<string>
#include<vector>

using namespace std;

class TypeConversion	//功能：将一个数字转换为0-100存储下来
{
public:
	//类型转换构造函数--将一个int类型数字转换为TypeConversion类型
	//explicit TypeConversion(int x = 0) :number01(x)
	TypeConversion(int x=0):number01(x)
	{
		if (x<=0&&x>100)
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
	TypeConversion tc03 = TypeConversion(123);

	cout << "<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<" << endl;
	//类型转换运算符
	int i = tc02+5;//隐式调用类型转换运算符将tc02转换为22，然后做加法  27
	cout << "i=" << i << endl;
	//显式调用
	int k = tc02.operator int() + 5;
	cout << "k="<<k << endl;	//27

	int j = static_cast<int>(tc02) + 5;//同样调用operator int()const
	
	system("pause");
	return 0;
}

/*
*(1)类型转换构造函数
*	对于类类型也可以转换为整形等转换，需要使用类型转换构造函数和类型转换运算符等实现。
*	类-->整形
*	构造函数特点：
*		1.以类名作为函数名
*		2.没有返回值，连void也没有
*	构造函数种类：
*		默认构造函数
*		带参数的构造函数
*		拷贝构造函数&
*		移动构造函数--&&
*		类型转换构造函数：将其他的数据类型转换为该类型的对象
*			1.只有一个参数，该参数又不是本类的const引用。该参数就是待转换的数据类型。
*				只带一个参数的构造函数
*			2.在类型转换构造函数中，我们要指定转换的方法。函数的功能。
*
*(2)类型转换运算符--也叫类型转换函数
*功能：和类型转换构造函数能力相反，是特殊的成员函数。
*	将一个类对象转换成其他数据类型
*格式:operator type()const;
*	1.const是可选项，表示一般不应该改变待转换的内容。
*	2.type：表示待转换的某种类型，只要是能作为函数返回的类型。
*	3.类型转换构造函数没有形参。形参列表为什么为空？类型转换运算符一般是隐式转换，没有办法传递参数。
*		同事也不能指定返回类型，但是，他却能返回一个type类型的值。
*	4.必须定义为成员函数。
*显式的类型转换运算符--在类型转换运算符前面加上explicit
int j = static_cast<int>(tc02) + 5;//同样调用operator int()const
*
*(3)
*
*
*/