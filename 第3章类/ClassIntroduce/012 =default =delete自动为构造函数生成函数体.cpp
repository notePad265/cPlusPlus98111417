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
	Time() = default;	//编译器为=default这种函数自动生成函数体
	//Time() = delete;	//让编译器禁止生成某个函数
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
	Time myTime01 = Time(12, 12, 12);

	//默认构造函数
	Time myTime02;	//默认构造函数
	system("pause");
	return 0;

}


/*
*(1)=default =delete
	Time() = default; 编译器能够自动为我们生成函数体，用于特殊的函数
	只能用于构造函数，拷贝构造函数等特殊函数
*(2)Time() = delete;	//让编译器禁止生成某个函数
*(3)
*
*/