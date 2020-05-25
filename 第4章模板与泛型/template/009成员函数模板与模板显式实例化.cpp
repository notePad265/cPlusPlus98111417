#include<iostream>
#include<cstdlib>
#include<string>
#include<vector>

using namespace std;


class A
{
public:
	template <typename T>
	void myFunction09(T tem)//成员变量函数模板
	{
		cout << tem << endl;
	}
	
};


//类本身具有模板参数C，成员函数具有模板参数T1，T2
template <typename T3>
class B
{
public:
	template <typename T>
	void myFunction09(T tem)//成员变量函数模板
	{
		cout << tem << endl;
	}


	//构造函数模板
	template <typename T2>
	B(T2 v1, T2 v2);
	
	void mytestFunction09()
	{
		cout << "这是B类的测试函数" << endl;
	}
	
public:
	T3 c1;
};

//构造函数
template <typename T3>//先写类的模板参数列表
template<typename  T2>//在写函数自己的模板参数列表
B<T3>::B(T2 v1, T2 v2)
{
	cout << v1 << endl;
	cout << v2 << endl;
}

//函数模板
template <typename T4>
void myFunction009(T4 t)
{

	cout << t << endl;
}



/*（3）
1.显式实例化  --实例化定义，只需要在一个.cpp只不过定义就可以，
编译器一遇到这个定义就实例化一个具体的类

2.在其他.cpp文件中“显式实例化声明”
extern template B<double>;		--模板实例化声明，不会在本文件中生成一个实例化代码，在其他cpp文件中已经有一个实例化版本了
但是其他版本的实例化可以存在其他cpp文件中，如int float double类型等
总结：一个cpp中定义，其他cpp中都是声明。
*
 */


//显式实例化类模板
template B<double>;

//显式实例化函数模板
template void myFunction009(int t);



int main(void)
{
	//(1)
	A a;
	//调用的时候，编译器才会实例化模板
	a.myFunction09(3);//编译器自动推断--int
	a.myFunction09<double>(3.2343);

	//(2)
	//类模板参数必须<>来指定，函数模板参数很多时候可以推断出来
	B<double> b1(2, 3);//构造函数模板类型自动推断int


	//(3)模板显式实例化
	

	system("pause");
	return 0;
}

/*
*(1)普通类的成员函数模板
*不管是普通类，还是类模板，它的成员函数都可以是一个函数模板，称为“成员函数模板”。不可以是虚函数。
*
*(2)类模板的成员函数
*类模板的函数（类模板函数+普通成员函数）只有被调用的时候才会实例化。如果函数从未使用，则不会实例化该成员函数。
*
*(3)模板显式实例化
*每个cpp都是独立编译的。
*同时为了防止多个.cpp中都实例化了相同的类模板，所以c++提供了一个解决办法。
*这时候就需要显式实例化。
*
*总结：
*1。这个特色编译器实现不不好，不建议使用，认识即可。
*
* Sunrise于东北电力大学第二教学楼1121实验室
* 2019年11月24日22:28:05
*
*/