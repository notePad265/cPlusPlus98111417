#include<iostream>
#include<cstdlib>
using namespace std;

struct Student
{
//private:
	int number;
	char name[128];
	void functionInc()	//在内部都能访问成员属性
	{
		number++;
		return;
	}
};


int main013(void)
{
	//加上private，就不能使用这种方法，因为不能在结构体外面访问私有属性或者私有方法
	Student student1 = { 1000, "baiqianlong" };
	
	system("pause");
	return 0;
}

/*
* (1)类的定义域权限修饰符
*	a.public 共有的
*		公共的意思，用这个修饰符修饰结构/类中的成员变量和成员函数可以被外界访问。
*		一般我们需要能够被外部访问的属性或者变量，定义为public,就好像该类的外部接口一样。
*	b.private 私有的
*		用这个修饰符修饰类中的成员属性或者成员函数，只有类中的属性或者方法访问。
*	c.protected 保护类型（这节课不讲解--在继承中讲解）
*	结论：struct结构体默认是是public类型的，不写访问修饰符，就是public类型的。
*	 Sunrise于东北电力大学第二教学楼1121实验室 2019年11月2日12:40:05
*/