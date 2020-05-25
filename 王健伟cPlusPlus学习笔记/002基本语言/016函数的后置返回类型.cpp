#include<iostream>
#include<cstdlib>
using namespace std;

void funcionTest(int , int);	//函数声明
//void funcionTest(int a, int b);	//函数声明--建议写法


//从语法上说，可以传递过来一个参数用于测试等操作，但是不使用，
void functionTest(int a,int)	//函数定义
{
	return;
}

//更改为后置返回类型
/*
 * 前面写auto，表示函数返回类型放置在函数参数列表后面，而放置在参数列表后的返回类型是以->开始的
 */
auto functionTest02(int a, int b)->void;	//	函数声明
auto functionTest02(int a,int b)->void	//	函数实现
{
	return;
}


int main(void)
{
	functionTest(1, 2);
	
	system("pause");
	return 0;
}

/*
* (1)函数回顾与后置返回类型
*	在函数定义中，形参如果在函数内部用不到，则可以不给形参变量名字，只给类型
*	函数声明中，可以只有形参类型，没有形参名字，但是建议写上。声明一般在头文件中。
*
*	把函数返回值类型写在函数名字前面，这种写法叫前置返回类型。
*	在c++11中引入一种新的语法，后置返回类型。
*		--在函数声明和定义中，把返回类型写在参数列表后面。
*		
*		为什么需要后置返回类型？？
*		主要是一个类或者函数的返回值非常复杂，写在后面清晰。
*
*	question：
*	（1）前置返回类型与后置返回类型
*		为什么需要后置返回类型？？
*		怎么改为后置返回类型？？auto  ->
* 
*/