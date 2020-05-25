#include<iostream>
#include<cstdlib>
#include<string>
#include<vector>

using namespace std;

class A{};
class B:public A
{};

int main(void)
{
	//1隐式类型转换
	int number = 22;
	double number02 = 2.3333;
	double number03 = number + number02;
	int number04 = number + number02;
	cout << number03 << endl;
	cout << number04 << endl;
	//内存中的值和输出的值是不同的

	//2显式类型转换
	int number05 = 5 %(int) 3.2;
	int number06 = 5 % int(3.2);	//把类型或者数字()起来都可以--c语言风格的类型转换

	//static_cast
	double number07 = 100.4545;
	int number08 = (int)number07;	//c语言风格的类型转换
	int number09 = static_cast<int>(number07);//c++风格的类型转换

	//(2)子类和父类之间的类型转换
	B b;
	A a = static_cast<A>(b);	//把子类转换成父类对象   子类是特殊的父类对象


	//(3)void*(五类型指针)与其他类型指针之间的转换
	int number10 = 10;
	int*p = &number10;
	void*p2 = static_cast<void*>(p);
	int*p3 = static_cast<int*>(p2);
	cout << *p3 << endl;


	//const_cast()--只能修改指针和引用的const
	int number11 = 11;
	const int*p11 = &number11;
	int*p12 = const_cast<int*>(p11);
	*p12 = 100;	//正确--语法上没错，但是不建议修改const的变量的值，属于为定义的行为，可能行进去，也可能写不进去
	//--内存和打印出来的值不同
	
	const int& number12 = number11;
	int& number13 = const_cast<int&>(number12);



	//reinterpreter_cast类型转换
	int number14 = 14;
	int*p14 = &number14;
	char*p15 = reinterpret_cast<char*>(p14);
	double*p16 = reinterpret_cast<double*>(p14);
	cout << *p16 << endl;	//-9.25596e+61

	int number17 = 100;
	long long number18 = 8898899400;	//8个字节后面强制转换为4个字节的地址会丢失2==2 126A 6DC8
	int*p17 = (int*)number18;	//	c风格的转换
	int*p18 = reinterpret_cast<int*>(number18);	//4个字节，所以会丢失==126a 6dc8
	
	
	system("pause");
	return 0;
}

/*
* (1)隐式类型转换--系统自动进行，不需要程序开发人员介入
*
* （2）显式类型转换
*
* c++强制类型转换分为4种--我们要尽量使用c++风格的类型转换
* 这4中强制类型转换，分别用于不同的目的，提供4中轻质类型转换的目的：提供更加丰富的含义和功能，更好的类型检测机制
*	1.static_cast
*		静态转换理解为“正常转换”，变异的时候进行类型转换的检查。代码中要保证转换的安全性，如“asdf”字符串转换为int是错误的
*		与c语言的强制类型转换差不多。
*		c风格的强制类型转换以及编译器能够进行的隐式类型转换，都可以使用static_cast显式类型转换。
*		可用于：
*			（1）相关类型转换  整形---浮点型
*			（2）后续学习类中的子类转换成父类
*			(3)void*(五类型指针)与其他类型指针之间的转换
*		不可用于：
*			（1）一般不可以用于指针类型之间的转换 float*--int*--double*等之间的转换
*	2.dynamic_cast
*		主要应用于运行时类型识别和检查
*		应用于父类型和子类型之间转换---父类型指针指向子类对象（父类指针用子类对象初始化）,然后用dynamic_cast把父类指针转换为子类
*	3.const_cast
*		去除指针或者引用的const属性，也是属于编译时的转换。
*		不能去掉普通变量的。
*	4.reinterpret_cast
*		重新解释转换，将操作数重新解释为另一种类型--把操作数类型都转换了
*		处理无关类型的转换--两个转换之间没有关系。自由转换，非常随意。
*			1.将一个整形转换成一个指针类型 。一种指针类型重新转换成另一种指针类型int*---float*类型--按照转换后的内容重新解释内存中的内容。
*			2.也可以将一个指针类型转换为整形类型
*		这种自由转换安全性太差，都不建议使用。强制类型转换跳过编译器的类型检查。
*		资料上说：reinterpret危险，使用const_cast意味着设计缺陷。
*		使用c++风格的类型转换，尽量不要使用c语言风格的类型转换。
*	这4种类被称为“命名的强制类型转换”--都有一个名字并且不同名字
*
*	通用形式：
*	强制类型转换名字 <type>(express)
*		--type转换的目标类型
*		--express  需要转换的变量或者表达式
*	
*/ 