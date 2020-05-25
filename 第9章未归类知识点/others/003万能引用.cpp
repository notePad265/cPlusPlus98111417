#include<iostream>
#include<cstdlib>

using namespace std;

template <typename T>
void myFunction(const T&value)//value的类型是const T&
{
	return;
}

void myFunction02(int&& tem)//参数是右值引用类型
{
	cout << "右值引用函数" << endl;
	return;
}

/*修改函数模板后，tem既可以接受左值，又可以接受右值。
*tem的类型是T&&
*从编译未报错可以判断：T被推断出来不仅仅是int类型，（int&&tem,导致tem只能接受右值）
*传递左值，编译器推断为T&类型 int&
*传递右值，编译器推断为T&&类型 int&&
*/
template<typename T1>
//void myFunction03(const T1 &&tem)
void myFunction03(T1 &&tem)//&&属于tem类型的一部分，&&和T类型没有关系
{
	cout << "右值引用模板函数" << endl;
	return;
}

//类模板
template<typename T2>
class myTest
{
public:
	void testFunction(T&& tem)//这个是右值引用
	{
		
	}

	template<typename T3>
	void testFunction02(T3&& tem)//这个是万能引用
	{
		
	}
};

int main(void)
{
	myFunction(12);//T是什么类型，value是什么类型？  T和value的类型往往不同。
	/*
	 * T是int类型，value的类型是const int&类型
	 * 调用函数模板时候给的参数10会对T的类型产生影响。
	 * value的类型会对T的类型产生影响。--value的类型为万能引用，就会对T类型产生影响
	 */

	//(2)右值引用&&
	int&&number01 = 23;
	myFunction02(123);
	//myFunction02(number01);//error number01是一个左值

	myFunction03(123);
	myFunction03(number01);//函数模板时候可以传递左值
	
	int number02 = 12;
	myFunction03(number02);//int&&右值引用类型

	//其他万能引用 auto
	auto &&number03 = 234;


	//(5)
	myTest<int>mt;
	int i = 100;
	//mt.testFunction(i);//error，因为定义对象的时候已经指定类型为int，里面不存在类型模板参数。本身没有涉及到类型推断。
	//类模板实例化后，成员函数有具体类型，这里为void testFunction(int&& tem)。
	
	cout << "helloWorld" << endl;
	system("pause");
	return 0;
}

/*
 *(1)类型区别基本概念
 *类型是按照规定的规则读取内存块而划分的。
 *
 *(2)universal reference 万能引用，未定义引用 进本认识
 *	万能引用需要的语境：
 *		1.必须是函数模板
 *		2.必须发生了模板类型推断并且函数形参的的样子是 T&&（auto也存在万能引用）  T模板类型参数
 *	T&&就是万能引用类型
 *(3万能引用和右值引用的区别：
 *	1.右值引用，编译器需要传递右值，否则编译器报错
 *	2.万能引用作为函数形参时，我们可以给他传递左值，也可以传递右值
 *		如果我们传递进去左值，那么这个万能引用就变成了左值引用
 *		如果我们传递过去右值，这个万能引用就变成右值引用
 *	左值转换为右值std::move()
 *		
 *(4)判断下面是不是万能引用
 *		1.void func(int&&parm)//右值引用，因为没有模板
 *		2.template<typename T>
 *		  void func(T&&parm)
 *		  {}//是万能引用，有模板参数
 *
 *		3.template<typename T>
 *		  void func(std::vector<T>&& parm)
 *		  {}//右值引用，模板类型T，必须和&&挨着，是一个右值引用
 *
 *(5)万能引用资格的剥夺和辨认
 *	1.剥夺：const会剥夺成为右值引用的资格，使其成为右值引用  void myFunction03(const T1 &&tem)
 *	2.辨认：类的成员函数辨认
 *	2019年12月9日11点23分
 */