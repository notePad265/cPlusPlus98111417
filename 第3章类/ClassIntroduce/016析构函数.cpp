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
	~Time()
	{
		cout << "析构函数执行" << endl;
	}
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
void playObj()
{
	Time myTime01 = Time(12, 12, 12);
	Time myTime02 = myTime01;	//初始化--调用拷贝构造函数
	Time myTime03;

	myTime03 = myTime01;	//这个是赋值运算符，系统默认重载

}

int main(void)
{
	playObj();

	system("pause");
	return 0;

}


/*
*(1)析构函数--与构造函数相反，对象销毁的时候就会调用构造函数。
*如果我们不写自己的析构函数，编译器就会为我们生成一个默认的析构函数。
*在构造函数里面new一段内存，就要在析构函数函数里面调用delete函数释放内存。
*析构函数也是类的成员函数，是~类名(){}。没有返回值，不接受任何参数，不能被重载。所以只能有一个析构函数。
*
*函数重载：函数名字相同，但是函数的参数个数，参数类型，参数顺序不同。
*	那么我们调用的时候会根据参数类型，个数，顺序来调用不同的函数。
*
*(2)构造函数的成员初始化
*	构造函数做的工作可以分为两部分：
*		1.函数体之前（初始化列表的形式）都是用来初始化类的成员属性的。
*		2.函数体中对成员变量的操作是赋值，不是初始化。这种浪费了系统初始化的一次机会，因为系统也会给一个默认值初始化。
*	析构函数也是2部分：
*		1.析构函数先执行函数体{}，进行释放内存等操作。销毁自己new出来的东西。
*		2.函数体之后是系统销毁对象（成员变量），进行系统销毁，不是我们手动销毁。
*
*(3)成员变量的创建和销毁时机
*	创建对象的时候，先定义的先初始化。每个成员变量是按照成员变量定义的顺序来初始化（先定义的成员变量先有值）
*	销毁的时候，先定义的时候，后销毁。
*
*
*/