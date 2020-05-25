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
	Time()
	{}
public:
	void AddHour(int TemHour)const;
	void test(string& str)
	{
		cout << str << endl;
	}
};

Time::Time(int TemHour, int TemMinute, int TemSecond) :Hour(TemHour), Minute(TemMinute), Second(TemSecond)//把形式参数赋值给成员属性
{
}
Time::Time(int Hour)
{
	this->Hour = Hour;
}

//常量成员函数--不能修改成员变量的值
void Time::AddHour(int TemHour) const
{
	//Hour = Hour + TemHour;	//error不能修改成员变量的属性
	
}


int main(void)
{
	Time myTime01 = Time(12, 12, 12);
	const Time myTime02;	//定义const对象，这种对象一旦初始化就不能修改。
	myTime02.AddHour(12);
	//myTime02.test();	//不兼容的修饰符号，不能调用非const函数。
	
	/*1.s声明为const的对象不能调用普通的成员函数
	 *2.但是这种对象可以调用const常量成员函数
	 *3.const不能放在普通函数的末尾
	 * 
	 */
	system("pause");
	return 0;

}


/*
*(1)在成员函数(声明和定义)后面增加const
*	作用：告诉系统，这个成员函数，不会修改该对象里面任何成员变量的值，
*		也就是说，这个成员函数不会修改类Time的任何状态。
*		后面加一个const的成员函数也叫常量成员函数
*(2)
*(3)
*
*/