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
	
	virtual void VirtualFunction(int value)
	{
		cout << "VirtualFunction 被调用" << endl;
	}

	static void StaticFunction(int value)
	{
		cout << "StaticFunction被调用" << endl;
	}
};

int main(void)
{

	//定义一个普通的类成员函数指针
	void (TestClass::*myCommanPointor)(int);//定义一个指向普通函数的指针
	myCommanPointor = &TestClass::CommanFunction;//指向类中的成员函数
	/*
	 * 成员函数是属于类的，不属于成员对象，有类在就有成员函数地址存在。
	 *	不要理解为要先创建一个类对象。
	 *	但是要用成员函数指针，就必须把它绑定在一个类对象上。
	 *	使用函数指针的格式：
	 *	“类对象名.*函数指针变量名”来调用
	 *	如果是个对象指针，则调用格式"指针名->*函数指针变量名"来调用
	 */

	TestClass tc, *ptc;
	ptc = &tc;
	(tc.*myCommanPointor)(199);//对象tc，调用指针变量所指向的成员函数
	(ptc->*myCommanPointor)(123);//类对象指针调用指针变量所指向的成员函数

	//指向成员虚函数的指针--与类中普通函数指针相同
	void(TestClass::*myVirtualPointor)(int);//虚函数指针
	myVirtualPointor = &TestClass::VirtualFunction;//"这个是真正的内存地址"
	(tc.*myVirtualPointor)(200);//绑定到类对象上调用类中虚函数
	(ptc->*myVirtualPointor)(201);

	/*
	 * 对于静态成员函数
	 * 使用：
	 * 1.使用“*函数指针变量名”来声明静态成员函数指针（因为是属于一个类的）
	 * 2.使用“&类名：：成员函数名”来获取成员静态函数地址
	 * 
	 */
	//定义一个静态成员变量指针并赋值
	void(*myStaticPointor)(int) = &TestClass::StaticFunction;
	//不需要类对象，直接调用
	myStaticPointor(100);
	
	
	system("pause");
	return 0;
}

/*
*(1)类成员函数指针
*通俗的讲是一个指针，指向类成员函数
*	1.普通成员函数
*	函数返回值 （类型：：*函数指针变量名）   声明普通成员函数指针
*	&类名：：成员函数名		来获取成员函数的地址--“这是个真正的内存地址”
*	2.静态成员函数
*	3.虚函数指针变量

 Sunrise于东北电力大学第二教学楼1121实验室
2019年11月23日22:16:46

*
*
*/