#include<iostream>
#include<cstdlib>
#include <functional>

using namespace std;

class CT
{
public:
	void myFunction(int x,int y)//普通成员函数
	{
		cout << "x=" << x << endl;
		cout << "y=" << y << endl;
		m_a = x;
	}
public:
	int m_a = 0;
};

int main(void)
{
	CT ct;
	auto bf1 = std::bind(&CT::myFunction, ct,std::placeholders::_1, std::placeholders::_2);
	bf1(1, 2);
	/*
	 * bind中使用第二个参数ct会导致调用CT的拷贝构造函数来生成一个CT的拷贝构造函数生成一个临时对象，做为std::bind()的
	 * 返回值（仿函数类型），后续的myFunction调用修改的是这个临时对象的m_a的值，并不影响ct兑现的值。
	 * 解决办法：ct使用引用，就不会生成临时对象，会修改真正ct的值
	 * 
	 */
	auto bf2 = std::bind(&CT::myFunction, &ct, std::placeholders::_1, std::placeholders::_2);
	bf2(1, 2);

	system("pause");
	return 0;
}
/*
* (1)std::bind绑定器_绑定成员函数_第二个参数是类对象
* 
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