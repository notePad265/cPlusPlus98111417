#include<iostream>
#include<cstdlib>
#include<string>
#include<vector>
using namespace std;

class Student
{
public:
	int number;
	int age;
};


class Time	//定义一个时间类
{
public:
	int Hour;
	int Minute;
	int Second;
private:
	//int MilliSecond;//私有的成员属性，不可以在外部访问
	//成员函数
public:
	Time()	//默认构造函数
	{
		;
	}
	Time(int TemHour,int TemMinute,int TemSecond)
	{
		Hour = TemHour;
		Minute = TemMinute;
		Second = TemSecond;
	}

	//一个普通的成员属性初始化方法
	void InitTime( int TemHour, int TemMinute, int TemSecond)
	{
		Hour = TemHour;
		Minute = TemMinute;
		Second = TemSecond;
	}
	
};

//初始化时间类的函数--c语言风格的写法
void InitTime(Time&TemTime/*输出参数*/,int TemHour,int TemMinute,int TemSecond)
{
	TemTime.Hour = TemHour;
	TemTime.Minute = TemMinute;
	TemTime.Second = TemSecond;
}

int main(void)
{
	//.成员方式访问
	Student stu1={100,12};
	cout << stu1.number << endl;
	//指针方式访问
	Student*pstu1 = new Student;
	pstu1->number = 200;
	pstu1->age = 13;
	

	//(2)类对象
	Time myTime;	//调用默认构造函数
	InitTime(myTime, 12, 12, 30);	//12:12:30
	
	Time myTime2(18,35,30);	//这里调用带参数的构造函数
	//c语言的初始化方法 成员属性和成员方法没有具体的关系
	myTime.InitTime(13, 13, 45);

	//（3）对象拷贝--本质上是调用拷贝构造函数--类的成员函数
	//默认情况下，这种对象的拷贝，是每个成员属性逐个拷贝
	//在后面如果在Time中定义适当的“赋值运算符”就能实现这种拷贝行为。--->运算符重载
	Time myTime03(myTime);
	Time myTime04=myTime;
	Time myTime05 = { myTime };
	Time myTime06 { myTime};
	myTime06.Hour = 8;
	//4种方式都可以初始化，

	system("pause");
	return 0;
}

/*
* (1)类基础
*	1、一个类就是用户自己定义的数据类型，我们可以把类想象成一个命名空间，包着一堆东西（成员函数、成员变量）
*	2、一个类的组成，成员变量（属性）成员函数--由很多特殊的成员函数（构造，析构）和成员属性（this指针）
*	3、访问类成员的时候，如果是类对象，就是用 对象名.成员名  来访问
*		如果使用指向对象的指针来访问，就使用 对象指针->成员属性
*	4、public成员提供类的接口，给外部使用，private成员提供各种实现类功能的细节方法。
*		但是不暴露给使用者，外界无法使用这些成员函数，只能在类内部使用
*	5.struct的成员函数和属性默认是public。class定义的结构默认是private的。
*	6.
*(2)成员函数
*
*（3）对象的拷贝
*（4）私有成员
*/