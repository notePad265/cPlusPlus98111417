#include<iostream>
#include<cstdlib>
#include <boost/type_index.hpp>

using namespace std;

//显示参数类型，这里不研究boost库
template<typename T>
//void myFunction01(T&tem)//T是类型模板参数，T是有类型的,tem是形参，tem也是有类型的
void myFunction01(const T &tem)
{
	using boost::typeindex::type_id_with_cvr;
	cout << "T type=" << type_id_with_cvr<T>().pretty_name() << endl;//显示T类型
	cout << "tem type=" << type_id_with_cvr<decltype(tem)>().pretty_name() << endl;//显示T类型

}

//2.1指针或者引用类型
template<typename T>
void myFunction02( T &tem)//tem是引用
{
	using boost::typeindex::type_id_with_cvr;
	cout << "T type=" << type_id_with_cvr<T>().pretty_name() << endl;//显示T类型
	cout << "tem type=" << type_id_with_cvr<decltype(tem)>().pretty_name() << endl;//显示T类型

}

template<typename T>
void myFunction03( const T &tem)//形参是常量引用
{
	using boost::typeindex::type_id_with_cvr;
	cout << "T type=" << type_id_with_cvr<T>().pretty_name() << endl;//显示T类型
	cout << "tem type=" << type_id_with_cvr<decltype(tem)>().pretty_name() << endl;//显示T类型

}

template<typename T>
void myFunction04( T *tem)//形参是指针类型
{
	using boost::typeindex::type_id_with_cvr;
	cout << "T type=" << type_id_with_cvr<T>().pretty_name() << endl;//显示T类型
	cout << "tem type=" << type_id_with_cvr<decltype(tem)>().pretty_name() << endl;//显示T类型

}

template<typename T>
void myFunction05(T &&tem)//形参是万能引用类型
{
	using boost::typeindex::type_id_with_cvr;
	cout << "T type=" << type_id_with_cvr<T>().pretty_name() << endl;//显示T类型
	cout << "tem type=" << type_id_with_cvr<decltype(tem)>().pretty_name() << endl;//显示T类型

}


template<typename T>
void myFunction06(T tem)//形参是万能引用类型
{
	using boost::typeindex::type_id_with_cvr;
	cout << "T type=" << type_id_with_cvr<T>().pretty_name() << endl;//显示T类型
	cout << "tem type=" << type_id_with_cvr<decltype(tem)>().pretty_name() << endl;//显示T类型

}

void tesFunction()
{
	;
}
int main(void)
{
	//(2)void myFunction01(const T&tem)
	myFunction01(100);
	/*
	 * T type=int
	 * tem type=int const &
	 */
	
	//2.1
	int i = 18;	//int
	const int j = i;	//const int
	const int&k = i;	//const int&类型
	cout << "-----" << endl;
	myFunction02(i);
	myFunction02(j);
	myFunction02(k);
	/*
	 *	T type=int
		tem type=int &
		T type=int const
		tem type=int const &
		T type=int const
		tem type=int const &
	1.如果实参是引用类型，则引用类型会被忽略掉，T不会被推到为引用类型。
	2.当我们向引用类型的形参tem传递const类型实参时，形参就会成为const&
		实参的const属性会成为类型模板参数的推导的类型的组成部分，
		也就是说，实参的const属性会传递。在函数中修改不了原来带const属性的实参。
	
	 */

	//形参是常量引用
	cout << "*******" << endl;
	myFunction03(i);
	myFunction03(j);
	myFunction03(k);
	/*
	 *  T type=int
		tem type=int const &
		T type=int
		tem type=int const &
		T type=int
		tem type=int const &

	1.如果实参是引用类型，则引用类型会被忽略掉，T不会被推到为引用类型。
	2.对于有const属性的实参，推导后T中的const属性没有了，因为模板函数myFunction03的形参tem出现了const。实参const替换掉形参const
	
	 */

	//指针类型
	const int*pi = &i;
	cout << "&&&&&&&&&" << endl;
	myFunction04(&i);
	myFunction04(pi);
	/*
	 *  T type=int
		tem type=int *
		T type=int const
		tem type=int const *
	结论：如果tem形参中没有const，则实参中的const就会传递到T类型中去。如果形参中有const，则T类型中不会带const。
	
	 */

	//*	2.2万能引用--形式参数tem是一个万能引用类型T&&
	cout << "2.2------------------------" << endl;
	myFunction05(i);//左值
	myFunction05(j);//左值
	myFunction05(k);
	myFunction05(100);//传递过去右值
	/*
	T type=int &
	tem type=int &	//这里有引用折叠
	T type=int const &
	tem type=int const &
	T type=int const &
	tem type=int const &
	T type=int
	tem type=int &&
	 */


	//2.3传值方式 如果形式参数tem是常规的传值方式传递
	cout << "2.3------------------------" << endl;
	myFunction06(i);
	myFunction06(j);
	myFunction06(k);
	/*
	 *  T type=int
		tem type=int
		T type=int
		tem type=int
		T type=int
		tem type=int
	const属性没有传递进去，因为形式参数是一个新副本。怎么传递进去const属性？？？-->传递指针进去
	 */
	char myStr[] = "jisuanjizuchengyhuanli";
	const char*const point = myStr;//第一个const修饰内存空间，第二个表示指针的指向不能改变
	cout << "jjjjjjjjjjjjjjjj" << endl;
	myFunction06(point);
	/*
	 T type=char const *
	 tem type=char const *
	传递const char*或者const char[]第一个const没有了，第二个const保留。
	 */

	//2.4数组做实参
	const char mystr02[] = "jisuanjizuchegnaun";
	cout << "22222222222222222222222" << endl;

	myFunction06(mystr02);
	myFunction02(mystr02);//调引用--推导成数组
	/*
	T type=char const *
	tem type=char const *
	T type=char const [19]
	tem type=char const (&)[19]//代表数组的引用
	*/

	//	2.5函数名做实参，函数名相当于函数首地址，可以赋值给一个函数指针
	cout << "6666666666666" << endl;
	myFunction06(tesFunction);

	myFunction02(tesFunction);//引用
	/*
	T type=void (__cdecl*)(void)//函数指针类型
	tem type=void (__cdecl*)(void)
	T type=void __cdecl(void)//函数指针引用
	tem type=void (__cdecl&)(void)
	 */

	
	cout << "helloWorld" << endl;
	system("pause");
	return 0;
}

/*
*(1)如何查看类型推断结果
*	推断有时候叫做推导，在现代c++中，经常涉及到推断，如auto等。这里主要讲解模板类型推断的知识。
*	模拟编译器来推断一个模板参数和普通参数的类型。
*	这里要验证我们推断出的类型和编译器推断出来的类型是否一致。--学习类型推断的原因？
*	我们为了学习类型推断相关知识，有必要知道编译器推断出来的“模板参数类型”以及“普通参数类型”的protype
*
*	通过“查看编译器类型推断的结果”这个手段来学习并掌握c++类型推断的规则。要求掌握C++类型推断结果，
*	而不是依赖什么手段去查看编译器个我们推断出来的结果。
*
*	使用boost库，把编译器给我们推断出来的类型信息打印出来。
*		1.访问官网https://www.boost.org/ 下载boost库
*		2.点击右侧Version History可以下载到1.68.0版本
*		3.将文件解压到一个文件夹中，本例中boost_1_68_0，
*		4.右键项目--“属性”--“vc++目录”--“包含目录”中将解压的路径添加上
*	这里使用nuget安装，右键项目 --“管理NuGet安装包”，搜索boost安装包
*	
*(2)理解模板类型推断
*	2.1指针或者引用类型
*			如果tem类型是个指针或者引用，但是不是万能引用
*	2.2万能引用--形式参数tem是一个万能引用类型T&&
*
*	2.3传值方式
*
*	2.4数组做实参
*		数组名代表数组的首地址
*	2.5函数名做实参，函数名相当于函数首地址，可以赋值给一个函数指针
*(3)总结：
*	1.推断中，引用类型实参的引用类型等于不存在
*	2.万能引用中，实参为右值和左值，推断出来的结果不同
*	3.按值传递的实参，传递给形参时const属性不起作用，则传递过去指针可能起作用。
*	4.数组或者函数类型在推断中被看作指针，除非函数模板的形参是个引用。
*(4)
*2019年12月9日
*20点48分
*
*/