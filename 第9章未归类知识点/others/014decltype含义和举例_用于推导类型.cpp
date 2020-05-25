#include<iostream>
#include<cstdlib>
#include <functional>
using namespace std;

class CT
{
public:
	int i;
	int  j;
};


int testFunction()
{
	return 10;
}

const int&&myfunctionTest(void)
{
	return 0;
}
int main(void)
{
	//1.1decltype后的圆括号是个变量
	const int i = 0;
	const int&reference01 = i;
	auto number01 = i;//number01=int 传值方式推断，引用属性和const属性都会被抛弃
	decltype(i) number02 = 23;//number02=const int类型。。i是什么类型，number02就是什么类型
	//如果decltype是个变量，则变量中的const属性会返回。
	decltype(reference01) number03 = number02;//const属性和引用属性都会保留   int const&类型
	//用于类
	decltype(CT::i) number04;//number04=int
	CT temCT;
	decltype(temCT) temCT02;//temCT02=CT类型
	decltype(temCT02.j)number05;//number05=int

	auto &&number06 = i;//万能引用  --auto =int,number06=int&
	decltype(number06) && number07 = i;//这里用到引用折叠，折叠成了左值， int &number07=i;
	
	//1.2decltype后的圆括号是个不是个变量，表达式。返回表达式结果对应类型
	decltype(34)number08 = 5;//number08=5;

	int j = 0;
	int*p1 = &j;
	int&reference02 = j;
	decltype(reference02 + 1)number09 = 454;//j=int ()内是整形表达式
	decltype(p1)p2=&j;//p2=int*类型
	*p2 = 43;
	decltype(*p2) number10 = j;
	/*
	 *number10=int&类型
	 **p2指针p2所指向的内存空间，而且能够给内存空间赋值，所以是个左值
	 **p2是个表达式，不是个变量，如果表达式的结果能作为赋值语句左边的值，那么decltype后返回的就是个引用。
	 *专门记：
	 *decltype后边是个非变量表达式，并且表达式能够作为等号左边的内容，返回的就是一个类似int&的引用。
	 */
	//在变量名字外面多加一层括号，编译器会把变量当作一个表达式
	decltype((i))reference03 = j;//最终结果是个引用
	//结论：decltype((变量))的结果永远是个引用

	//1.3decltype后的圆括号是个函数
	decltype(testFunction())temv = 14;//temv是函数的返回值类型，但是不会真正调用函数
	decltype(testFunction)temv2;//不加()返回的是int(void),是一个可调用函数对象。

	function<decltype(testFunction)> func01 = testFunction;//声明一个function（）函数类型，代表一个可调用对象  int(void)
	cout << func01() << endl;//10

	decltype(myfunctionTest()) myreturn = 0;//const int&&类型 函数返回值

	


	
	system("pause");
	return 0;
}
/*
* (1)decltype含义和举例：用于推导类型
*	1 decltype对于给定的变量名或者表达式，decltype能够告诉你该名字或者表达式的类型
*		从表达式的类型推断出要定义的变量类型，并且不想初始化变量--使用decltype
*		decltype说明符：主要作用：返回操作数的数据类型
*
*		decltype的特点：
*			1.decltype的自动类型推断会发生在编译期间
*			2.decltype不会真正计算表达式的值
*	1.1decltype后的圆括号是个变量
*	1.2decltype后的圆括号是个不是个变量，表达式。返回表达式结果对应类型
*	1.3decltype后的圆括号是个函数--返回值是函数返回值类型
* declare声明
* (2)
* (3)
* (4)
* (5)
* (6)(7)
*/