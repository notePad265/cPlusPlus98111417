#include<iostream>
#include<cstdlib>
using namespace std;



int main(void)
{
	const int abc = 12;
	//abc = 123;	//错误

	char str[] = "I love China";	//空格也占有一个字符
	char*p = str;	//定义指针指向字符串开头位置
	*p = 'Y';	//	可以修改
	p++;
	cout << str << endl;

	
	const char*p2 = str;	//p2指向的内存空间不能修改
	p2++;	//	可以
	//*p2 = 'Y';	//error

	//等价于const char*p2
	char const*p3 = str;
	//*p3 = 'Y';
	p3++;


	char*const p4 = str;	//定义时候必须初始化，指针的指向不可以改变，但是指针指向的内存空间可以改变
	*p4 = 'Y';
	//p4++;	//	错误，指针的指向不能改变
	
	const char*const p5 = str;	//指针的指向和指针指向的内存空间都不能改变


	int i = 100;
	const int&a = i;	//	i的内容不能通过a来修改。加上const表示a具有常量属性，但是i本身可以修改


	//int &b = 12;	//	错误
	const int &b = 12;	//正确
	cout << b << endl;	//12--猜想系统做了工作，系统是分配了内存的

	
	system("pause");
	return 0;
}

/*
* (1)const char*     char const *     char*const的区别
* 
*/