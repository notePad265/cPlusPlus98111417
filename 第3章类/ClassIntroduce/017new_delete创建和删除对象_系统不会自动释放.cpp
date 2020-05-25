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
	Time();
	~Time();
	

};

Time::~Time()
{
	cout << "析构函数" << endl;
}


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
Time::Time()
{
	;
}


int main(void)
{
	Time myTime01(12, 12, 12);
	Time myTime02 = myTime01;	//初始化--调用拷贝构造函数
	Time myTime03;

	myTime03 = myTime01;	//这个是赋值运算符，系统默认重载


	//使用new创建对象,返回的是创建对象的指针（地址）
	Time *Ti = new Time;//调用不带参数的构造函数
	Time*Ti2 = new Time();//调用不带参数的构造函数 ----两个区别不研究


	//new出来的对象必须自己手动释放
	delete Ti;	//调用析构函数
	delete Ti2;
	system("pause");
	return 0;

}

/*
 *(1)new对象的时候调用系统的构造函数。
 *	但是我们new出来的对象，必须自己释放，系统不会帮我们释放。
 *	在系统停止运行的某个时刻之前必须自己使用delete释放。
 *	你什么时候delete系统就会调用析构函数。
 * (2)
 * (3)
 */
