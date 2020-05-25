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
    Time(){}

};

Time::Time(int TemHour, int TemMinute, int TemSecond) :Hour(TemHour), Minute(TemMinute), Second(TemSecond)//把形式参数赋值给成员属性
{
}
Time::Time(int Hour)
{
	this->Hour = Hour;
}


int main(void)
{
	//Time myTime01 = Time(12, 12, 12);

	Time myTime02;	//调用默认构造函数
	system("pause");
	return 0;

}


/*
*(1)默认构造函数--没有任何参数的构造函数
*	1.如果没有任何构造函数，系统默认给一个默认构造函数，编译器自动定义一个默认构造函数，这个叫“合成的默认构造函数”
*	2.一旦我们写了构造函数，系统就不会自动创建默认构造函数。
*(2)当进行类的组合时候，会包含其他类的对象，必须使用成员初始化列表和初始值，手工写自己的构造函数。
*(3)
*2019年11月17日09:11:05 Sunrise于东北电力大学第二教学楼1121实验室
*
*/