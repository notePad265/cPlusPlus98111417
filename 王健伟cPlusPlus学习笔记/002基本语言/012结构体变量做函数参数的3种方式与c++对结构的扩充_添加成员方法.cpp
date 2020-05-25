#include<iostream>
#include<cstdlib>
using namespace std;

struct Student
{
	//成员变量
	int number;	//学号
	char name[100];	//学生名
};

void functionStruct(Student temstu)	//	形参用结构体变量
{
	temstu.number = 1002;
	strcpy_s(temstu.name, sizeof(temstu.name), "lisi");
	return;
}



void functionStruct02(Student &temstu)	//	形参用结构体引用
{
	temstu.number = 1002;
	strcpy_s(temstu.name, sizeof(temstu.name), "lisi");
	return;
}

void functionStruct03(Student *ptemstu)	//	用指向结构体变量的指针做函数参数
{
	ptemstu->number = 1002;
	strcpy_s(ptemstu->name, sizeof(ptemstu->name), "lisi");
	return;
}

//扩充后的成员函数可以包含成员函数，方法
struct  Teacher
{
	int number;
	char name[128];

	//成员属性，也叫方法
	//void functionInc(int number)
	void functionInc()	//	调用成员变量不需要写参数

	{
		number++;
		return;
	}
};


int main012(void)
{
	//结构是自定义的数据类型--定义结构体变量
	Student student1;	//定义结构变量，在c++中可以省略struct，直接使用结构体名字
	student1.number = 10001;
	//student1.name = "baiqianlong";	//不能直接把字符串赋值给字符数组类型
	strcpy_s(student1.name, sizeof(student1.name), "baqianlong");
	cout << student1.name << endl;	//baiqianlong 
	cout << student1.number << endl;	//10001

	//调用函数，查看能否改变结构体变量的值--把结构体变量传递给函数
	functionStruct(student1);//效率低，数据从实参传递给形式参数，发生了内存空间的数据拷贝

	//值没有改变
	cout << student1.name << endl;	//baiqianlong 
	cout << student1.number << endl;	//10001


	
	functionStruct02(student1);	//	使用引用，是同一块内存空间 shift+f9快速监视
	/*
	 * &student1	0x003afe04 {number=10001 name=0x003afe08 "baqianlong" }	Student *
	   &temstu	    0x003afe04 {number=1002 name=0x003afe08 "lisi" }		Student *
	 */


	functionStruct03(&student1);	//使用结构体变量的指针做函数参数

	cout << student1.name << endl;	//值改变为调用函数的值
	cout << student1.number << endl;	


	//c++对结构体的扩充--包含成员方法
	struct Teacher teacher1;
	teacher1.number = 1000;
	strcpy_s(teacher1.name, sizeof(teacher1.name), "baiqianlong");
	teacher1.functionInc();	//	结构变量名.成员函数。
	
	cout << teacher1.number;	//1001


	
	system("pause");
	return 0;
}

/*
* (1)结构回顾
*	a.--直接使用结构体变量做函数参数
*	b.--用引用做函数参数
*	c.--用指向结构体的指针做函数参数
*	查看实参和形参的地址，可以看到是值传递
&student1	0x002ffcc4 {number=10001 name=0x002ffcc8 "baqianlong" }	Student *
&temstu		0x002ffb8c {number=1002 name=0x002ffb90 "baqianlong" }	Student *
*	数据从实际参数传递给形式参数，发生值拷贝传递
*
*（2）c++中的结构和c中的结构有什么不同
*	c++中的结构除了具有c语言的所有功能，还增加了很多拓展功能，其中之一就是c++中的结构不仅仅有
*	成员变量，而且可以定义成员函数（方法）--这是为后面引入类的概念
*	
*/