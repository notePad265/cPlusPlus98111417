#include<iostream>
#include<cstdlib>
using namespace std;

int main010(void)
{
	int *p = NULL;//C语言写法，
	p = (int*)malloc(sizeof(int));	//在堆中分配4个字节
	if (p!=NULL)
	{
		//分配内存成功
		*p = 5;
		cout << "堆中分配内存的存储的内容为：" << *p << endl;

		//释放堆中分配的内存，
		free(p);
		p = NULL;	//指针的指向和指针指向的内存空间是不同的内存空间，最后要把指针指向NULL
	}

	//分配字符型内存空间
	char*pChar = NULL;
	pChar = (char*)malloc(100*sizeof(char));	//100个内存空间
	if (pChar!=NULL)
	{
		//内存分配成功
		strcpy_s(pChar, 100,"helloworld");
		cout << pChar << endl;
		free(pChar);
		pChar = NULL;
			
	}

	int*p2 = (int*)malloc(sizeof(int) * 100);	//分配可以存储100个int
	if (p2 != NULL)
	{
		int*q = p2;
		*q++ = 1;	//右结合性--相当于*（q++），第一个元素赋值为1
		*q++ = 2;	//第二个元素为2
		cout << *p2 << endl;	//1
		cout << *(p2 + 1) << endl;	//2
		//注意这里为什么要定义一个指针接过来，因为此时q已经指向第二个内存空间，p还指向开始的位置
		//如果这里不接过来，那么此时指针指向第二个元素，没办法释放内存
		free(p2);
		
	}


	//new和delete在C++分配和释放内存
	//用法1
	int*pInt1 = new int;
	if (pInt1!=NULL)
	{
		*pInt1 = 8;
		cout << *pInt1 << endl;
		delete pInt1;
		pInt1 = NULL;
	}

	//用法2
	int*pInt2 = new int(9);
	if (pInt2 != NULL)
	{
		cout << *pInt2 << endl;
		delete pInt2;
		pInt2 = NULL;
	}

	//用法3
	int *pInt3 = new int[100];
	if (pInt3!=NULL)
	{
		int*q = pInt3;	//接过来，方便后面释放内存
		*q++ = 10;	//第一个位置存储为10
		*q++ = 11;	//第二个位置存储为11
		cout << *pInt3 << endl;	//10
		cout << *(pInt3 + 1) << endl;	//11
		//释放数组内存空间，必须使用[]
		delete[] pInt3;
	}
	
	system("pause");
	return 0;
}

/*
* (1)动态内存分配问题
*	在C语言中，供程序使用的存储空间，有程序区，静态存储区，动态存储区
*	c++中，我们把程序进一步分为5个区域：
*	(1)栈：一般函数内部的局部变量分配在这里，由编译器自动分配和释放
*	（2）堆：程序员手动分配的内存，malloc()/free,new/delete来分配和回收
*	（3）全局、静态存储区：存放全局变量和静态变量，一般程序结束时由系统释放
*	（4）常量存储区：字符串常量等"I love china"
*	（5）程序代码区：用于存放程序的二进制代码
*
*（2）堆和栈不同的用途和区别
*		（1）栈的空间有限，这是系统定义的，分配速度快，程序员也控制不了
*		（2）堆只要不超出实际拥有的物理内存，在操作系统允许分配的最大内存之内，
*			都可以分配给你，分配速度相对较慢，可以随时分配（malloc new）和释放(free delete)
*		(3)malloc 和free：在c语言中，使用malloc和free从堆中分配和释放内存，malloc() free()是函数
*			memory allocation；动态内存分配
*			函数形式是：void *malloc(int NumByte)	//	要分配的字节数目
*			如果分配成功，返回执行被分配内存的指针，分配失败返回NULL；
*			当这块内存不使用的时候，应该使用free来释放内存，供其他程序使用
*			free释放内存 void free(void*FirstByte)将之前使用malloc分配的内存返还给操作系统。
*			供其他程序使用。
*		（4）new和delete分配和释放内存
*			(a)是运算符（标识符），c++中使用new、delete分配和释放内存，不再使用c++中的malloc free分配和释放内存。
*			(b)new和delete也是分配和释放内存，但是使用new和delete会调用类的构造函数和析构函数。在c++中一定要使用new、delete
*			(c)new的三种方式
*				(1)指针变量名字=new 类型标识符
*				(2)指针变量名字=new 类型标识符（指针初始值）  --注意这里是（）
*				(3)指针变量名字=new 类型标识符[内存单元的个数]---[]表示是数组
*					()初始化，[]数组
*		(5)总结：a.配对使用，malloc-free new-delete
*			b.free 和delete使用且只能使用一次。多次释放内存空间会崩溃。
*
*
*/