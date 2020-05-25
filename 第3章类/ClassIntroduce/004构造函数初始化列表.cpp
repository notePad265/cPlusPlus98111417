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

};

Time::Time(int TemHour, int TemMinute, int TemSecond):Hour(TemHour),Minute(TemMinute),Second(TemSecond)//把形式参数赋值给成员属性
{
}
Time::Time(int Hour)
{
	this->Hour = Hour;
}


int main(void)
{
	Time myTime01 = Time(12, 12, 12);

	system("pause");
	return 0;

}
/*
 *(1)构造函数初始化列表。
 *	1.直接在构造函数的实现中，在函数参数列表后面：成员变量（初始化形参变量(初始值)）,成员变量值2（初始化形参变量2），
 *	这样写的执行时机是执行{}前开始执行，以后会遇到必须使用构造函数成员初始化列表形式的。
 *	2.建议使用构造函数初始化列表形式。初始化列表形式叫初始化，写在{}中的叫赋值操作(在初始化的时候是个垃圾值)。写在{}
 *		相当于放弃了初始化，由系统给一个垃圾值。
 *	3.每个成员变量的初始化顺序和系统定义顺序有关，而与构造函数初始化列表的写的顺序无关。
 *
 *(2)为什么需要构造函数初始化列表？
 *	1.初始化而不是先存入一个垃圾值，然后再赋值。
 *	2.有些场合只能使用初始化列表的方式。

*/