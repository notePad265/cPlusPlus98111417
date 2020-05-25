#include<iostream>
#include<cstdlib>

using namespace std;

void myFunction(int a_i)
{
	cout << "这是我自定义的函数myFunction" << endl;
	return;
}

//类实现的功能：返回一个大于等于0的数字，如果小于0，返回0
class BiggerThanZero
{
public:
	//带一个参数的构造函数
	BiggerThanZero(int a):m_i(a)
	{
		m_i = a;
	}
	
public:
	//重载()函数调用运算符
	int operator()(int value)const
	{
		if (value<=0)
		{
			return 0;
		}
		else
		{
			return value;
		}
	}

	int operator()(int a,int b)const
	{
		return 1;
	}
private:
	int m_i;
};

int main(void)
{
	myFunction(3);//()--函数调用运算符

	//类中重载函数调用运算符
	BiggerThanZero b1(23);//重载了函数调用运算符的对象,这里是对象定义并初始化（因为前面有类名），所以调用的是构造函数
	int number01=b1(-34);
	//重载的函数，operator 运算符就是函数名字  operator ()
	int number02 = b1.operator()(-45);

	//重载函数调用运算符--两个参数
	int number03 = b1(12, 33);
	
	
	system("pause");
	return 0;
}
/*
 *(1)学习c++体会、总数
 *	1.对语言本身的学习--学习语法，不可或缺的阶段
 *	2.大量的练习--有条件尽量去实践
 *	3.开始阅读优秀的人写的优秀代码--每个人写的代码有不同的习惯,每个人都有自己的习惯和擅长。
 *		
 *(2)圆括号()就是函数调用的明显标记,()有一个称呼叫“函数调用运算符”;
 *	如果我们在类中重载了函数调用运算符()，那么我们就可以像使用函数一样使用该类的对象了。对象(实参)
 *	如何定义一个函数调用运算符？？
 *		1.定义一个该类的对象。
 *		2.像函数调用一样使用该对象，也就是在()中添加实参列表
 *(3)结论：
 *	只要这个对象所属的类重载了()"函数调用运算符"，那么这个类对象就变成可调用的了
 *	而且可以调用多个版本的()，只要在参数类型或者数量上构成函数重载即可。
 *(4)类重载了（），那该类就有一个新名字--"函数对象”,因为可以调用这种对象，或者说
 *	这些对象的行为像函数一样。
 *
 *
 *
*/