#include<iostream>
#include<cstdlib>
#include<string>
#include<vector>

using namespace std;



int main(void)
{
	static  int j = 23;//局部静态对象，在静态区分配内存

	int i = 10;//由系统进行分配和释放
	int *p1 = new int;//动态内存分配，初值未定义
	string *s1 = new string;//空字符串，系统调用string默认的构造函数
	string *s2 = new string(5, 'a');//aaaaa


	vector<int>* pointVector = new vector<int>{ 1,2,3,4,5 };//注意这种类型是存放int的vector*类型
	

	//值初始化
	string *s3 = new string();//用空括号来初始化就叫值初始化
	int *p2 = new int();//值为0，不是未定
	//new创建对象的时候，能够进行“值初始化”就进行初始化，防止没有初始化出现问题
	//
	//c++11中，auto可以和new配合使用
	string *s4 = new string("jisuanjizu");
	auto s5 = new auto(s4);//s4,s5指向同一段内存 s5是string**类型 指针的指针


	//const对象也可以动态分配
	const int*p4 = new const int(200);


	
	system("pause");
	return 0;
}

/*
*(1)直接内存管理 new delete
*	在一个函数内定义一个对象，但是一旦离开这个函数，这个对象就失效了，这是局部对象。
*	静态局部对象
*	1.new分配内存方式我们称为动态分配，分配在堆上，直接由程序员进行内存管理。
*	delete作用是回收new分配的内存--释放内存。不是new分配的内存，不能使用delete使用。
*	2.delete释放一块内存，只能delete一块，不能delete多次。
*	3.空指针可以多次删除，但是没什么意义。
*	4.new出来的内存一定不要忘记delete,否则内存泄漏。时间一长导致资源紧张，运行崩溃。
*	5.delet后的内存不要再使用。
*	6.指针不指向任何内存空间，要指向null.
*	7.同一块内存释放两次，也会报异常。
*	8使用new、delete进行内存管理要十分小心。
*		c++11中引入了“智能指针”，当你忘记delete，智能指针会自动帮你delete
*
*(2)创建新工程，观察内存泄漏
*MFC应用程序在一定程序上（程序退出的时候），能帮助我们发现内存泄漏。
*
*(3)
*
*
*/