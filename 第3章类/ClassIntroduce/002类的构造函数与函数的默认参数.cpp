#include<iostream>
#include<cstdlib>
#include<string>
#include<vector>
using namespace std;

class Time
{
public:
	int Hour;	//小时
	int Minute;	//分钟
	int Second;	//秒
public:
	//Time(int TemHour, int TemMinute, int TemSecond);	//构造函数
	Time(int TemHour, int TemMinute, int TemSecond=30);	//构造函数

	Time();	//无参构造函数
};

//构造函数的实现
Time::Time(int TemHour, int TemMinute, int TemSecond)
{
	Hour = TemHour;
	Minute = TemMinute;
	Second = TemSecond;
}

//无参构造函数
Time::Time()	//默认时间是10：10：10
{
	Hour = 10;
	Minute = 10;
	Second = 10;
}

//普通函数带默认构造函数
int functionSum(int a,int b=10)
{
	return a + b;
}

//int functionSum(int a)
//{
//	return a;
//}

int main(void)
{
	//创建类对象
	Time myTime01(12, 34, 23);
	Time myTime02=Time(12, 13, 45);
	Time myTime03 = Time{ 13, 23, 45 };
	Time myTime04{ 12, 14, 56 };
	Time myTime05 = { 13, 13, 45 };
	
	//Time myTime06();	//vs1015编译通过，但是不是调用无参构造函数，也不是调用有参数构造函数，系统有处理
	Time myTime07;	//下面都是调用无参构造函数，
	Time myTime08 = Time();
	Time myTime09{};
	Time myTime10={};

	//(2)对象拷贝
	Time myTime20 = {12,12,12};	//调用默认无参构造函数
	Time myTime21 = myTime20;	//都是调用默认拷贝构造函数
	Time myTime22(myTime20);
	Time myTime23{ myTime20 };
	Time myTime24 = { myTime20 };

	//（3）构造函数带默认参数
	Time myTime25(12, 12);
	//(3)普通函数带默认参数
	int Number01 = functionSum(33,13);	//错误--有多个函数实例与函数调用匹配
	int Number02 = functionSum(10);
	
	
	system("pause");
	return 0;

}

/*
(1)构造函数
	为什么需要构造函数？
	为了方便类对象的初始化操作。构造函数被系统自动调用。构造函数的目的就是初始化类对象的数据成员。
	在类中有一类特殊的成员函数，函数名字与类名相同，我们在创建类对象的时候，
	自动调用这个特殊的成员函数，这个成员函数就叫构造函数。
总结：
	1.与类名字相同，并且没有返回值,连void也没有。
	2.不可以手动调用构造函数，否则会出错、
	3.构造函数应该声明为public，否则在类的外部不能调用。类内的属性不谢默认是private，所以要显式写上public
	4.构造函数中如果有多个参数，那么我们创建对象的时候需要传递参数。
	5.写了带参数的构造函数，系统就不会添加默认构造函数。
问题引入：一个类中是否可以存在多个构造函数？
		可以。多个构造函数可以为类对象提供多种初始化方法。但是各个构造函数之间要构成函数重载。

(2)对象拷贝
	
(3)函数的默认参数
	在函数的形式参数加上“=值”来显式的制定默认值
	（1）默认值只能放在函数的声明中，不要放在函数的定义中。除非该函数没有函数声明.
	(2)在具有多个参数的函数中制定默认值的时候，默认参数必须出现在参数列表的最右侧，
		一旦一个参数有默认值，它右侧的参数必须都是具有默认值.--默认参数都出现在不默认参数的右侧。
	(3)默认参数遇上函数重载。当三个参数有一个是默认参数遇见只有两个参数的函数，会调用哪一个？

*/