#include<iostream>
#include<cstdlib>
using namespace std;

constexpr int functuonReturn()	//返回一个值的函数
{
	//这个函数定义的变量必须初始化
	return 5;
}


int main009(void)
{
	const int var = 7;	//	命名常量，表示这个变量的值，我不会去改变
	//var = 8;	//	error，编译错误
	//实际上可以通过方法来改变
	int&var2 = (int&)var;
	var2 = 100;
	cout << var << endl;	//=7
	cout << var2 << endl;	//=100

	cout << &var << endl;
	cout << &var2 << endl;	//地址相同
	//总结：加断点调试时候，var=var2=100,但是cout值不同，两个变量地址相同
	////--实际上，别名不是那么简单。编译器做了手脚


	//constexpr关键字
	constexpr int var3 = 100;
	int& var4 = (int&)var3;
	var4 = 200;
	cout << var3 << endl;
	cout << var4 << endl;
	//与上面现象相同，，内存中的值相同，但是cout中的值不同
	if (var3==var4)	//并不会执行这个语句。
	{
		cout << "两个数字相同" << endl;
	}
	
	//constexpr int var5 = functuonReturn();	//函数的原型必须加上constexpr关键字来实现
	//注意：va2013对这个关键字不支持编译，这样写应该可以调用成功
	//functuonReturn();	//可以像普通函数一样调用
	system("pause");
	return 0;
}
/*
* (1)常量就是不变的量
* const关键字表示不变的意思
* 
*（2） constexpr关键字(vs2013不支持这个关键字)
*	c++11才引入的关键字，也是一个常量的概念，在编译的时候求职，肯定能提升性能
* 
*/