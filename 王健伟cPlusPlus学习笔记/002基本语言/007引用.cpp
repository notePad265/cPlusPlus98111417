#include<iostream>
#include<cstdlib>
using namespace std;

void functionSwap(int&num1,int&num2)	//使用引用来交换两个值
{
	int temp;
	temp = num1;
	num1 = num2;
	num2 = temp;
}

int main007(void)
{
	int value = 10;
	int &refValue = value;	//value的别名就是refValue，这里&不是去地址运算符，不要使用c语言去解释c++
	refValue = 20;
	cout << value << endl;
	//定义引用并不额外占用空间，或者理解为占用同一块内存（实际并不占有同一块内存）
	//定义引用必须初始化，要不然给谁起别名？？

	//int &reference = 10;	//	错误，必须初始化一个变量
	//float &reference = value;	//错误，引用类型必须相同

	
	//引用的例子--通过引用把参数传递到函数内部，在函数内部就可以修改内部的值

	int number1 = 11;
	int number2 = 22;
	functionSwap(number1, number2);
	cout << "number1=" << number1 << endl;
	cout << "number2=" << number2 << endl;

	system("pause");
	return 0;
}
/*
* (1)引用
*	引用理解为为变量起了另外一个名字，一般使用&来表示，起别名之后，
*	别名和变量名字表示同一个变量。
*
*/