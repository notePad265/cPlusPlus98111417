#include<iostream>
#include<cstdlib>
#include<string>
#include<vector>
using namespace std;

class Time
{
private:
	mutable int Hour;
	int Minute;
	int Second;
public:
	explicit Time(int Hour, int Minute, int Second);
	Time(int Hour);
	Time(){}
public:
	//返回对象自身的应用，返回对象自身
	Time&AddHour(int TemHour);
	//Time&AddHour(Time *const this,int TemHour);	//等价于这种，隐藏this指针
	Time&AddMinute(int TemMinute);
};

Time::Time(int TemHour, int TemMinute, int TemSecond) :Hour(TemHour), Minute(TemMinute), Second(TemSecond)//把形式参数赋值给成员属性
{
}
Time::Time(int Hour)
{
	this->Hour = Hour;
}
//返回对象自身的引用
Time& Time::AddHour(int TemHour)
{
	//Hour = (Hour + TemHour) % 24;	//时间是0-24小时
	this->Hour = (this->Hour + TemHour) % 24;
	cout << this->Hour << endl;	//10
	return *this;	//返回对象自身
}

Time& Time::AddMinute(int TemMinute)
{
	this->Minute = (this->Minute + TemMinute) % 60;
	cout << this->Minute << endl;
	return *this;
}



int main(void)
{
	Time myTime01 = Time(12, 12, 12);
	myTime01.AddHour(22);
	//返回对象本身，就可以实现多值函数的调用，类似于cout<<可以实现调用多次，返回的就是ofstream对象本身
	//返回对象本身可以实现函数连续调用，多值函数
	myTime01.AddHour(13).AddMinute(54);
	
	system("pause");
	return 0;

}


/*
*(1)返回自身对象的引用  *this
*(2)this指针
*	每一个成员对象都有一个隐含的成员属性this指针，指向自己本身的地址，当进行函数调用的时候，把this指针
*	（自己本身的地址）当做第一个参数传递过去，后面依次是自己写的参数。
*	对系统看来，任何对成员属性的访问都是通过this指针来访问的。
*(3)
*	1.隐藏的this指针只能在成员函数中，全局函数和静态函数（static）中不存在this指针
*	2.在普通成员函数中，this是一个指向非const对象的const指针。this只能指向当前对象，指向不能改变。
*	3.在const成员函数中，this指针就是一个指向const对象的const指针。const Time *const this
*
*总结：
*	返回对象本身可以实现函数连续调用，多值函数
*2019年11月16日21:18:54
* Sunrise于东北电力大学第二教学楼1121实验室
*/