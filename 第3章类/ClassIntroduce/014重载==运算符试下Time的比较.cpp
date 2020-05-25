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
	Time(int Hour);
	Time() = default;	//编译器默认创建函数体
public:
	//重载运算符==
	bool operator==(Time&myTime01);

};

Time::Time(int TemHour, int TemMinute, int TemSecond) :Hour(TemHour), Minute(TemMinute), Second(TemSecond)//把形式参数赋值给成员属性
{
}
Time::Time(int Hour)
{
	this->Hour = Hour;
}

//运算符重载==
bool Time::operator==(Time& myTime01)
{
	if ((this->Hour==myTime01.Hour)&&(this->Minute==myTime01.Minute)&&(this->Second==myTime01.Second))
	{
		return true;
	}
	return false;
}


int main(void)
{
	Time myTime01 = Time(12, 12, 12);
	Time myTime02(12, 12, 12);

	//当不进行重载==运算符时候，这里会报错  “没有与这种操作匹配的“==”运算符”
	if (myTime01==myTime02)
	{
		cout << "判断两个Time类相等" << endl;
	}
	
	system("pause");
	return 0;

}


/*
*(1)为什么需要重载运算符？？？
*	当判断整数是否相等，使用==判断，其他运算符如>= <= !=等可以进行整数和浮点数的运算。其实内部已经进行的重载。
*	同样，对于cout<< cin>>可以用来输出输入各种各样的类型数据，其实它们内部已经对这些基本的数据类型进行了重载。
*	所以才可以输出各种基本运算和输入输出操作。
*
*	当我们需要对自己定义的类进行操作或者判断是否相等时候，，就需要重载运算符
*(2)什么是运算符重载？
*	说白了，就是写一个成员函数，这个成员函数名字就叫	operator 运算符号   operator ==,实现判断两个类是否相等
*	里面的相等逻辑是由开发者写的。
*
*	调用的时候为 myTime01.operator==(myTime02) 等价于myTime01==myTime02
*	
*(3)运算符重载本质上是一个函数，这个函数的名字是:operator 重载的运算符
*	本质上是一个函数，那么就有函数3要素，函数名字，函数返回值，函数参数列表。
*	如果我们不重载运算符，对于简单的运算符，如赋值运算符系统会自动生成一个。但是对复杂的运算符，如==，系统不会生成。
*
*	注意：(1)成员函数可以减少一个参数，隐藏在this指针里面。
*
*/