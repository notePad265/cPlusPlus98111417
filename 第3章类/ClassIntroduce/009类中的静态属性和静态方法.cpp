#include<iostream>
#include<cstdlib>
#include<string>
#include<vector>
using namespace std;
static int number02 = 10;	//全局静态变量的作用域是定义的文件。
//限制在本文件中，不能在其他文件中使用extern来声明调用。
//
//局部静态变量保存上一次调用的时候结果的值，再次进入时候不会执行初始化工作
void myFunction()
{
	static int number1 = 5;//局部静态变量，跳出函数后值保存在静态存储区中
	//第二次调用的时候不执行上面操作，值只被初始化一次，不会再次执行初始化，但是可以修改
	number1 = 10;
}


class Time
{
public:
	int Hour;
	int Minute;
	int Second;
public:
	explicit Time(int Hour, int Minute, int Second);
	Time(int Hour);
public:
	//静态成员属性和静态成员函数
	static int myCount;	//静态成员函数的声明，没有分配内存，所以在这里不能初始化,在类外面显式初始化
	static void myStaticFunction(int testValue);
};



Time::Time(int TemHour, int TemMinute, int TemSecond) :Hour(TemHour), Minute(TemMinute), Second(TemSecond)//把形式参数赋值给成员属性
{
}
Time::Time(int Hour)
{
	this->Hour = Hour;
}
//静态成员函数
void Time::myStaticFunction(int testValue)
{
	myCount = testValue;
	//Hour = 12;	//error不是静态成员属性，不能在静态成员函数访问
}

//静态成员属性显式初始化-分配内存
int Time::myCount = 0;
int main(void)
{
	
	Time myTime01 = Time(12, 12, 12);
	Time myTime02(02, 34, 54);

	Time::myCount = 100;
	cout << myTime01.myCount << endl;

	//如何定义静态成员变量：一般在一个.cpp文件的开头定义静态成员变量。这样可以在任何函数前面进行分配内存。

	//静态成员函数
	//使用类调用
	Time::myStaticFunction(14);
	//使用类对象调用
	myTime01.myStaticFunction(45);
	
	system("pause");
	return 0;

}


/*
*(1)static成员，全局静态变量与局部静态变量
*
*(2)有没有一个成员变量或者属性是属于某个类，不属于某个对象？？
*	属于整个类的成员变量叫静态成员变量，static成员变量
*	特点：不属于某个对象，而是属于整个类，一旦在某个对象中修改了static成员变量的值。
*		其他对象可以直接访问。
*		2。这种成员函数只有一个副本，使用时  类名：：成员变量名
*		3.成员函数前面也可以加static，构成静态成员函数，属于类的成员，调用时候
*			类名::成员函数名字
*			静态成员函数只能操作静态成员属性.
*(3)
*
*/