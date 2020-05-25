#include<iostream>
#include<cstdlib>
#include<string>
#include<vector>
using namespace std;

class Time
{
private:
	int Hour;
	int Minute;
	int Second;
public:
	explicit Time(int Hour, int Minute, int Second);
	Time(Time&TemTime);
	Time(int Hour);
	Time() = default;

public:
	//重载赋值运算符
	Time& operator=(const Time&TemTime);

};

Time::Time(int TemHour, int TemMinute, int TemSecond) :Hour(TemHour), Minute(TemMinute), Second(TemSecond)//把形式参数赋值给成员属性
{
}
Time::Time(int Hour)
{
	this->Hour = Hour;
}
//拷贝构造函数
Time::Time(Time& TemTime)
{
	this->Hour = TemTime.Hour;
	this->Minute = TemTime.Minute;
	this->Second = TemTime.Second;
}

//重载赋值运算符
Time& Time::operator=(const Time& TemTime)	//建议写上const，常量属性
{
	this->Hour = TemTime.Hour;
	this->Minute = TemTime.Minute;
	this->Second = TemTime.Second;
	return *this;
}



int main(void)
{
	Time myTime01 = Time(12, 12, 12);
	Time myTime02 = myTime01;	//初始化--调用拷贝构造函数
	Time myTime03;
	
	myTime03 = myTime01;	//这个是赋值运算符，系统默认重载，没有调用拷贝构造函数
	//系统会调用一个拷贝赋值运算符,我们可以自己进行运算符的重载,重载后调用重载后的重载函数
	//myTime03就是赋值运算符重载返回的*this
	//等价于
	myTime03.operator=(myTime01);
	
	system("pause");
	return 0;

}


/*
*(1)拷贝赋值运算符
*	我们可以自己重载赋值运算符，如果没有重载，编译器自动生成的赋值运算符重载比较粗糙，一般就是将非static
*	成员属性赋值给运算符左侧的对象的成员中去。如果成员是类对象，可能还要调用类的拷贝构造函数。
*(2)重载赋值运算符
*	有返回类型和参数列表，这里的参数就表示运算符的运算对象，如void operator=(Time&TemTime);中的TemTime
*	函数名字就是operator=
*
*	赋值运算符重载一般返回左侧对象本身的引用。
*(3)
*
*2019年11月18日15:28:51
* Sunrise于东北电力大学第二教学楼1121实验室
*/