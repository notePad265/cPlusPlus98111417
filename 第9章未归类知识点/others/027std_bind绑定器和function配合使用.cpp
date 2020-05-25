#include<iostream>
#include<cstdlib>
#include <functional>

using namespace std;

class CT
{
public:
	void myFunction(int x, int y)//普通成员函数
	{
		cout << "x=" << x << endl;
		cout << "y=" << y << endl;
		m_a = x;
	}
	void operator()()
	{
		cout << "operator()函数被调用" << endl;
	}
public:
	int m_a = 0;
	
};

void myCallBack(int cs,const std::function<void(int)>&f)
{
	f(cs);
}

void runFunc(int x)
{
	cout << "runFunc函数执行了" <<x<< endl;
}

int main(void)
{
	//(1)std::bind绑定器和function配合使用
	CT ct;
	std::function<void(int, int)> bf1 = std::bind(&CT::myFunction, &ct, std::placeholders::_1, std::placeholders::_2);
	bf1(10, 20);

	//(2)把成员变量地址当函数一样绑定
	std::function<int&()>bf2 = std::bind(&CT::m_a, &ct);//如果第二个参数不用&引用，会调用两次拷贝构造函数
	//第一册是利用ct来产生一个临时对象，第二次是std::bind要返回一个CT类型对象，返回的CT对象拷贝自临时对象，std::bind执行完毕后临时对象会释放。
	bf2() = 53;//实际修改的是成员变量的值


	auto rt = std::bind(CT());//执行构造函数，拷贝构造，两次析构
	/*
	 * CT()构造临时对象，调用拷贝构造函数生成一个临时对象作为std::bind()的返回对象，
	 * bind返回仿函数类型对象，就是调用拷贝构造函数构造出来的对象
	 */

	auto bf4 = std::bind(runFunc, std::placeholders::_1);//调用时候指定第一个参数

	for (int i=0;i<10;i++)
	{
		myCallBack(i, bf4);//调用的runFunc
		
	}
	
	system("pause");
	return 0;
}
/*
* (1)std::bind绑定器和function配合使用
* (2)把成员变量地址当函数一样绑定，绑定结果放在std::function<int&(void)>保存，说白了就是用一个可调用对象类型保存。
* (3)总结：
*		bind思想，所谓的延迟调用，将可调用对象格式统一，保存起来，需要的时候在调用。
*		我们有std::function绑定一个可调用对象，类型成员不能绑定，std::bind成员函数，成员变量都可以绑定
*	2019年12月11日12点22分
* 
* (4)
* (5)
* (6)(7)
*/