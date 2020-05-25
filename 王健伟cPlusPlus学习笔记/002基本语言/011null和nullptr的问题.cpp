#include<iostream>
#include<cstdlib>
using namespace std;

int main011(void)
{
	char*p = NULL;
	char*q = nullptr;

	int number1 = NULL;//可以
	//int number2 = nullptr;//error
	if (p==q)	//成立，可以执行
	{
		cout << "p和q都是null" << endl;
	}
	//结论：引入nullptr主要是为了避免0和null之间的混淆。nullptr就是一个指针

	cout << typeid(NULL).name() << endl;
	cout << typeid(nullptr).name() << endl;
	/*int
	 *std::nullptr_t
	 */
	//结论：null和nullptr实际上是不同的类型，在进行重载函数的时候用到。
	//最终结论：对于指针的初始化，大家遇见的和指针有关的NULL场合，都用nullptr取代NULL
	
	system("pause");
	return 0;
}
/*
* (1)nullptr是c++11中的新关键字  nullptr也是空指针
* 为什么引入nullptr？
* 最终结论：指针初始化用NULL的地方使用nullptr初始化
*/