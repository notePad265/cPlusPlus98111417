#include<iostream>
#include<cstdlib>
#include<string>
#include<vector>

using namespace std;
//两个数字相加
int AddFunction(int a,int b)
{
	int Tem = a + b;
	return a + b;
}

int AddFunction(double a,double b)
{
	int tem = a + b;
	return tem;
}

//两个函数只有参数类型不同
template <typename T>//声明一个类型为T的模板函数
T FunctionTemplate (T a,T b)
{
	T tem = a + b;
	return tem;
}
/*
 * 1.函数模板以template开头，后边跟<>。<>里面叫模板参数列表，多个参数使用逗号,分开
 * 2.<>里面必须具有一个模板参数，模板参数前面有个typename关键字，也可以用class,表示是个类型名。
 * 3.如果模板参数列表里面有多个参数，那么就要使用多个typename,class template <typename T，typename Q>
 * 4.模板参数列表里面表示在函数定义中要用到的“类型”或者“值”，与函数参数列表类似。
 * 5.调用的时候使用指定模板实参，模板名字<模板实参>（函数参数）
 * 6.模板函数根据调用传递的实参，在编译的时候确定类型。
 */

int main(void)
{
	//编译器根据调用的实参去推断模板函数里面的参数类型。有时候需要提供，有时候推断。
	//有时候根据根据实参是推断不出模板的类型，需要使用<>提供出来。
	int Sum = FunctionTemplate<int>(32, 44);
	int Sum02 = FunctionTemplate(44.00, 34.454);//可以不提供模板类型参数,编译器推断是double类型
	//调用时候，编译器 推断出模板类型之后，就实例化一个特定版本类型的函数。
	
	
	system("pause");
	return 0;
}

/*
*(1)函数模板的定义
*
*(2)函数模板的使用
*
*(3)
*
*
*/