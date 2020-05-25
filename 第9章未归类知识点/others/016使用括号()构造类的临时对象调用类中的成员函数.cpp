#include<iostream>
#include<cstdlib>

using namespace std;
class A
{
public:
	A()
	{
		cout << "执行A的构造函数" << endl;
	}
	~A()
	{
		cout << "执行A的析构函数" << endl;
	}
	int myFunction()
	{
		cout << "指向A的myFunction函数" << endl;
		return 0;
	}
};

int main(void)
{
	A().myFunction();//生成一个临时对象，调用临时对象的函数

	(const A()).myFunction();//ok,但是resharp会提示错误

	decltype(A().myFunction()) number01;//number01的类型是int类型
	//没有构造过临时对象，也没有真正调用过函数
	/*
	 * 执行A的构造函数
		指向A的myFunction函数
		执行A的析构函数
		执行A的构造函数
		指向A的myFunction函数
		执行A的析构函数
	 */
	system("pause");
	return 0;
}
/*
* (1)使用括号()构造类的临时对象调用类中的成员函数
* (2)
* (3)
* (4)
* (5)
* (6)(7)
*/