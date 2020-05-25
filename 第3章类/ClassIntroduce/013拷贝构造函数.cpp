#include<iostream>
#include<cstdlib>
#include<string>
#include<vector>
using namespace std;

//一个临时的小类-创建对象作为Time类的一个成员属性
class TemClass
{
public:
	TemClass()
	{
		cout << "TemClass的构造函数" << endl;
	}

	TemClass(TemClass&tem_class)
	{
		cout << "TemClass的拷贝构造函数" << endl;

	}
};



class Time
{
private:
	int Hour;
	int Minute;
	int Second;
public:
	//TemClass tem_class;
	
public:
	explicit Time(int Hour, int Minute, int Second);
	Time() = default;
	
public:
	//拷贝构造函数
	Time(Time&myTime, int TemHour = 10,int TemＭinute=10,int TemSecond=10);

};

Time::Time(int TemHour, int TemMinute, int TemSecond) :Hour(TemHour), Minute(TemMinute), Second(TemSecond)//把形式参数赋值给成员属性
{
}



//拷贝构造函数
Time::Time(Time& mytime/*这个是需要拷贝的对象*/, int temhour, int temｍinute, int temsecond):Hour(12),Minute(12),Second(12)
{
	cout << "这是time类的拷贝构造函数" << endl;
	//this->hour = mytime.hour;	//ok
}


void myFunciton01(Time Te)
{
	;
}

Time myFunction02()
{
	Time t;
	return t;
}
int main(void)
{
	Time myTime01 = Time(12, 12, 12);

	//Time myTime02;	//调用默认构造函数
	//myTime02 = myTime01;	//这里不是调用拷贝构造函数
	//下面都是执行拷贝构造函数
	
	//Time myTime03(myTime01);
	//Time myTime04{ myTime01 };
	//Time myTime05={ myTime01 };
	Time myTime06 = myTime01;	

	myFunciton01(myTime06);

	Time t = myFunction02();
	
	system("pause");
	return 0;

}


/*
*(1)默认情况下，类对象的拷贝是每个成员变量逐个拷贝。
*(2)拷贝构造函数
*	1.如果一个类的构造函数是所属类的类对象引用，如果还有其他额外参数，这些额外参数都有默认值。
*	函数默认参数都必须放在函数声明中，除非该函数没有函数声明。
*
*	2.拷贝构造函数：在一定的时机被系统自动调用，时机：进行对象复制的时候 =
*	3.建议拷贝构造函数第一个参数带const,且一般不要声明explicit来禁止隐式类型转换。
*	4.成员变量逐个拷贝因为我们定义的拷贝构造函数存在而失去作用。
*		我们定义的拷贝构造函数取代了系统默认的拷贝构造函数
*(3)
*	1.如果我们没有定义一个拷贝构造函数，编译器会帮我们定义一个拷贝构造函数
*	2.编译器给我们定义的叫“合成拷贝构造函数”--作用将参数TemTime的成员逐个拷贝到正在创建的对象中。
*
*	3.默认拷贝构造：每个成员的类型决定自身如何拷贝，比如说成员属性是int类型，那么就是直接的值拷贝。
*		如果成员是其他类对象，就会调用类的拷贝构造函数。
*	4.如果自己定义了拷贝构造函数，就能会取代系统的拷贝构造函数，那么就需要在拷贝构造函数中赋值。
*		以防止出现未初始化的成员变量。
*(4)还有一些情况会调用拷贝构造函数的调用
*	1.函数传递参数
*	将一个实参传递给一个非引用类型形参，会先调用构造函数构造出对象，然后调用拷贝构造函数。
*	2.函数返回值是一个局部对象类对象，会进行临时对象的拷贝，调用拷贝构造函数创建一个临时对象返回。
*/