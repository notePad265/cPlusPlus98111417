#include<iostream>
#include<cstdlib>
#include <functional>

using namespace std;

void myFunction(int x,int y,int z)
{
	cout << "x=" << x << endl;
	cout << "y=" << y << endl;
	cout << "z=" << z << endl;
}

void myFunction02(int x, int y, int z)
{
	cout << "x=" << x << endl;
	cout << "y=" << y << endl;
	cout << "z=" << z << endl;
}

void myFunction03(int&x,int&y)
{
	x++;
	y++;
}

int main(void)
{
	auto bf1 = std::bind(myFunction, 1, 2, 3);//auto表示不关心返回的类型，其实bind返回的是一个仿函数类型对象
	bf1();//1  2  3
	//placeholders::_2是占位符
	auto bf2 = std::bind(myFunction02, placeholders::_1, placeholders::_2, 34);
	//表示第一，第二个参数分别由调用者提供，这里只制定了第三个参数
	bf2(1, 2);// 1  2  34
	//直接调用
	std::bind(myFunction02, placeholders::_1, placeholders::_2, 34)(12, 23);


	auto bf3 = std::bind(myFunction02, placeholders::_2, placeholders::_1, 300);
	bf3(1, 2);//2	1	300 按照标号位置传递

	int a = 1;
	int b = 2;
	auto bf4 = std::bind(myFunction03, a, placeholders::_1);
	bf4(b);
	cout << "a=" <<a<< endl;//1不是2
	cout << "b=" <<b<< endl;//3
	/*
	 * 这说明，bind对于预先绑定的函数参数是通过值传递的，所以这里的a实际上是值传递
	 * 对于不预先绑定的参数，通过std::placeholde传递的参数，是通过引用传递的，b实际上是引用传递的。
	 */



	
	system("pause");
	return 0;
}
/*
* (1)std::bind绑定器
* 也是个类模板，是c++11中新特性
* std::bind能够将对象及其相关的参数绑定到一起，绑定完毕后可以直接调用，也可以使用std::function保存，在需要的时候调用
* 格式：
* std::bind(待绑定的函数对象/函数指针/成员函数指针，绑定参数值1，参数绑定值2，参数绑定....)
* 总结：
*	1.将可调用对象可参数绑定在一起，构成一个仿函数，可以直接调用
*	2.如果函数有多个参数，可以只绑定一部分，其他参数在调用时候指定
* (2)
* (3)
* (4)
* (5)
* (6)(7)
*/