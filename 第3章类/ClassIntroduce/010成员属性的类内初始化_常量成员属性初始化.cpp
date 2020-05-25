#include<iostream>
#include<cstdlib>
#include<string>
#include<vector>
using namespace std;

class Time
{
public:
	int Hour;
	int Minute={0};
	int Second=0;	//类内初始值
	//常量属性使用构造函数初始化列表方式初始化
	const int TestConst;
public:
	explicit Time(int Hour, int Minute, int Second);
	Time(int Hour);
	Time():TestConst(12) {}

};
//友元函数访问类中的私有数据成员。公有数据成员可以直接访问。
void ReadTime(Time&MyTime)
{
	cout << MyTime.Hour << endl;
}

Time::Time(int TemHour, int TemMinute, int TemSecond) :Hour(TemHour), Minute(TemMinute), Second(TemSecond),TestConst(12)//把形式参数赋值给成员属性
{
}
Time::Time(int Hour):TestConst(12)
{
	this->Hour = Hour;
}


int main(void)
{
	Time myTime01 = Time(12, 12, 12);

	//类相关的非成员函数调用
	ReadTime(myTime01);

	//类内初始化
	Time myTime02;	//Minute=Second=0  
	
	system("pause");
	return 0;

}


/*
*(1)类相关非成员函数
*	和类几乎无关的成员函数，访问私有数据成员---友元函数
*	访问公有数据成员，可以直接访问
*(2)类内初始化
*	在c++11中我们可以为类内成员变量提供一个初始值。创建对象的时候，使用初始值来初始化该成员变量。
*	
*(3)常量属性的成员属性必须在构造函数初始化列表中初始化，在{}后不能给值。
*
*/