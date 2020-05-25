#include<iostream>
#include<cstdlib>
#include<string>
#include<vector>

using namespace std;

class TestClass
{
public:
	void CommanFunction(int value)
	{
		cout << "普通成员函数被调用" << endl;
	}

	virtual void Function(int value)
	{
		cout << "VirtualFunction 被调用" << endl;
	}

	static void StaticFunction(int value)
	{
		cout << "StaticFunction被调用" << endl;
	}
	int number;
	static int Static_number;
};
int TestClass::Static_number = 100;

int main(void)
{
	//对于普通成员变量，
	int TestClass::*p1 = &TestClass::number;//定义一个普通成员变量的指针,需要附着上特定的对象上
	//p1 = 0x00000004 {???}--并不是一个真正意义上的指针，是该成员变量的与该类对象的偏移量。
	//因为成员对象有虚函数，编译器为类生成虚函数表。则对象中有一个虚函数表指针占有4个字节指向虚函数表。
	//成员变量是属于类对象。
	TestClass tc;
	tc.*p1 = 202;//通过类成员变量指针来修改成员变量的值，等价于
	//tc.number = 202;


	//对于静态成员变量--属于类,有真正的内存地址的
	int*staticPoint = &TestClass::Static_number;
	//staticPoint = 0x00c6b000 s是个真正的内存地址
	*staticPoint = 400;
	//等价于
	//TestClass::Static_number = 400;
	
	

	system("pause");
	return 0;
}

/*
*(1)类成员变量指针
*	这些涉及到c++对象模型等，
*
*
*/