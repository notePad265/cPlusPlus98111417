#include<iostream>
#include<cstdlib>
using namespace std;

class Student
{
public:
	int number;
	char name[128];

public:
	void functionInc()	//成员方法
	{
		number++;
		return;
	}
};


int main014(void)
{
	Student std1;
	std1.number = 1000;
	strcpy_s(std1.name, sizeof(std1.name), "baiqianlong");
	
	system("pause");
	return 0;
}

/*
 *目的：由结构到类的转换
* (1)类简介
*	也是用户自定义的数据类型，大家已经知道如下内容
*	a--不管c还是c++，结构都是使用struct定义
*	b--老师已经说过，为了方便大家理解，曾经说过：大家就把c++中的类当做结构来理解。
*		并不全面，只是为了方便大家理解。
*	那么，结构和类到底有什么区别？？
*		a-类，只有在c++中才有这个概念，c语言中没有
*		b-结构使用struct定义，类使用class来定义。
*		在c语言中，我们定义一个属于该结构的变量，叫结构变量。
*		在c++中，我们定义的一个属于该类的变量，叫做对象。
*		说白了，结构变量和类对象都是一块能够存储数据并且具有某种类型的内存空间。
*（2）在c++中，结构和类极其相似，区别有两点：
*	a.c++结构体内部的成员变量和成员函数默认都是private属性。而结构体中是public属性。
*		建议：不管是定义结构体还是类，都默认写上修饰符，public或者private属性
*	b.c++结构体继承默认是public.而c++类的继承默认是private。
*	结论：c++中明确写上访问级别，那么struct和类可以混用。
*
*	额外说明（1）c++标准库中包含了大量丰富的类和函数，供大家使用
*		   （2）以后定义类，我们在c++一般以类为单位写代码。
*	
*问题：
*	1.类和结构体的默认访问属性？？
*/