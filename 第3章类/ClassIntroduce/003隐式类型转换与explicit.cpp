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

Time::Time(int Hour, int Minute, int Second)//把形式参数赋值给成员属性
{
	this->Hour = Hour;
	this->Minute = Minute;
	this->Second = Second;
}
Time::Time(int Hour)
{
	this->Hour = Hour;
}

void functionTransform(Time TemTime)
{
	return;
}

int main(void)
{
	Time myTime01 = 12;
	//Time myTime03(12, 23, 43, 54);	//错误
	Time myTime04 = { 16 };
	//大括号内部可以当做一个对象·	--如果带一个参数的构造函数加explicit就会进行隐式类型转换，都会错误
	Time myTime02=(12, 23, 43, 54);	//会调用单参数的构造函数--相当于逗号表达式，最后是Hour=54

	functionTransform(12);	//首先会调用一个参数的构造，构造一个Time临时对象

	//explicit防止隐式类型转化
	//Time myTime05 = { 12,12,12 };	//错误，不能隐式类型转换
	Time myTime06(2, 12, 34);//正确，调用构造函数
	Time myTime07=(2, 12, 34);//正确，调用构造函数
	/*
	 * 总结：一般可以认为()是参数，{}是一个对象
	 * (1)对于单个参数的构造函数，一般声明为explicit,除非有特殊原因。
	 */

	system("pause");
	return 0;

}
/*
 *(1)隐式类型转换和explicit
 *		编译系统私下做了很多我们不知道的事情，当参数不够或者类型不匹配时候就会进行隐式类型转换
 *(2)是否可以强制系统明确要求构造函数不做强制类型转换？
 *	可以。如果构造函数中声明explicit(显式的)。则这个构造函数只能用于初始化显式类型转换。不能进行隐式类型转化。
 *(3)
 * 
 */