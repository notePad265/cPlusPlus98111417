#include<iostream>
#include<cstdlib>

#include <boost/type_index.hpp>

using namespace std;

//显示参数类型，这里不研究boost库
template<typename T>
void myFunction01(T&tem)//T是类型模板参数，T是有类型的,tem是形参，tem也是有类型的
{
	using boost::typeindex::type_id_with_cvr;
	cout << "T type=" << type_id_with_cvr<T>().pretty_name() << endl;//显示T类型
	cout << "tem type=" << type_id_with_cvr<decltype(tem)>().pretty_name() << endl;//显示T类型

}

int main(void)
{
	int number01 = 18;
	const int number02 = number01;
	const int&number03 = number01;
	myFunction01(number01);//T=int  tem=int&类型
	myFunction01(number02);//T=int const tem=const int&
	myFunction01(number03);//T=int const tem=const int& 引用会被忽略，传递不过去
	/*
	T type=int
	tem type=int &
	T type=int const
	tem type=int const &
	T type=int const
	tem type=int const &
	 */

	// (1)auto类型常规推断
	auto number04 = 23;//number04是int类型，auto是int类型占位符
	
	//1.指针或者引用类型，但不是万能引用
	const auto&number07 = number01;  //auto =int,number07=const int&
	auto number08 = number07;//传值方式，引用和const属性会被抛弃，把对方当作新副本， number08=int ,auto =int
	auto &number09 = number07;//auto =const int		number09=const int&  引用属性被丢弃，const属性被保留
	const auto*p1 = &number01;//auto =int		p1=const int*
	auto*p2 = &number01;//auto=int	p2=int*
	auto p3 = &number01;//auto=int*		p3=int*
	


	
	//2.万能引用类型  --函数模板万能引用是T&&   auto万能引用是auto&&
	auto&&number11 = number01;//number11是左值，auto =int&,number11=int&,这里产生引用折叠
	const auto number12 = 234;
	auto&&number13 = number12;//autu=int&，number13=const int&
	auto&&number14 = 234;//赋值给处置是右值  --auto=int,number14=int&&
	

	
	//3.传值方式，非指针，非引用--
	auto number05 = 234;
	const auto number06 = number05;//auto =int number06=const int


	//auto可以使用new操作符
	auto number10 = new auto(2343);//auto=int
	
	system("pause");
	return 0;
}
/*
* (1)auto类型常规推断
* c++11中，auto英语变量的自动类型推断，在声明变量的时候根据变量的初值的类型自动为此变量选择匹配的类型，
*	而不需要我们显示指定类型
*特点：
*1.自动类型推断发生在编译期间，不会影响程序执行期间的性能。
*2.auto定义的变量必须立即初始化，这样编译器才能自动推断它的类型。确定auto的类型和它所定义变量的类型。
*	然后在编译期间使用真正的类型替换掉auto这个类型占位符。
*3.auto使用灵活，可以和指针，引用，const等限定符结合使用。
*4.auto类型推断和函数模板推断非常类似。autu推导后代表一个具体类型。
*	auto实际上是一个类型，实际上相当于函数模板推导中的类型模板参数T。auto也是类型声明中的一部分。
*	可以把auto当作类型占位符
*
*
* (2)auto类型推断分类
*		1.指针或者引用类型，但不是万能引用--不会抛弃const属性，但是会抛弃引用等限定符
*		2.万能引用类型
*		3.传值方式，非指针，非引用--传值方式会抛弃引用和const属性。
* (3)
* (4)
* (5)
* (6)(7)
*/