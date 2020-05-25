#include<iostream>
#include<cstdlib>
#include<string>
#include<vector>
using namespace std;

class Time
{
private:
	mutable int Hour;	//mutable修饰
	int Minute;
	int Second;
public:
	explicit Time(int Hour, int Minute, int Second);
	Time(int Hour);
	Time(){}
public:
	void AddHour(int TemHour)const
	{
		//用mutable修饰一个成员变量，就表示这个成员变量永远处于可以修改状态，及时在const常成员函数中.
		Hour = Hour + TemHour;
	}

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

	const Time myTime02;
	myTime02.AddHour(12);
	
	

	
	system("pause");
	return 0;

}


/*
*(1)mutable 不稳定，容易改变的<---->const
*	mutable的引入就是为了突破const的限制。
*	当成员函数后面有const，是不能修改成员变量的值，如果想在const常成员函数中修改成员变量的值。就是用mutable。
*(2)mutalbe是为了突破const限制而开的一个后门。
*2019年11月16日21:15:45
* Sunrise于东北电力大学第二教学楼1121实验室
*(3)
*
*/