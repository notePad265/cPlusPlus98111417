#include<iostream>
#include<cstdlib>
#include<string>
#include<vector>

using namespace std;

class A
{
public:
	
	A()
	{
		cout << "构造函数被执行" << endl;
	}
	~A();
	
};
A::~A()
{
	cout << "析构函数被执行" << endl;
}


int main(void)
{
	//(1)
	A*a1 = new A();//调用类A的构造函数
	delete a1;//该类的析构函数被执行

	int *p1 = new int(100);
	delete p1;
	//operator new()  和operator delete()是函数
	/*
	 * new干了两个事情
	 * （1）在堆上分配内存，就是通过operator new()来分配内存
	 * （2）调用构造函数来初始化内存。
	 *delete也干了两个事情：
	 *（1）调用析构函数，做一些对象释放前的操作
	 *（2）释放内存 --调用operator delete()函数来释放内存
	 */

	//operator new()函数可以直接调用
	void* myPoint = operator new (100);//直接分配100个字节


	//(2)
	int *p3 = new int(23);//分配4个字节
	delete p3;//删除的时候，编译器是怎么知道要释放4个字节？？？
	/*
	 * new出的内存空间中单独分配空间来记录分配的内存空间的大小，自己内部有记录机制。不需要深入了解。
	 */
	
	//(3)申请和释放一个数组  这些可以在MFC框架下演示
	int *p4 = new int[2];//int类型数组，有2个元素，占有8个字节 没有回收

	A a2;
	cout << sizeof(a2) << endl;//1  泄漏一个字节
	cout << sizeof(A) << endl;//1

	A*p5 = new A();//泄漏1字节

	A*p6 = new A[2]();//泄漏6个字节，比我们想的多出来4个字节
	
	/*
	 * 为什么空A对象a2占有1个字节？
	 * 因为每个对象分配了内存空间，至少占有一个地址空间，至少占有1个字节的地址。
	 *
	 *
	 * 疑问：为什么定义类型A数组会多泄漏，也就是给类型A对象数组多分配4个字节，而内置类型int并没有多分配？
	 * 定义类对象数组，需要额外的4个字节来记录是多少个数组元素，以便后面调用多少次析构函数，
	 */

	int *p7 = new int[3];
	delete p7;//没有使用[]，也可以释放，没有内存泄漏，但是建议使用delete []p7;

	A*p8 = new A[2]();//泄漏6字节，其中2个字节是对象数组，另外4个。。。是一个整形，记录的是数组元素的个数，这里是数字2
	delete[]p8;//类类型必须使用[]，不使用会报异常  ----调用2次析构函数


	/*A*p9 = new A;
	delete[]p9;*/
	//系统一直调用析构函数，因为不知道数组元素的个数
	
	system("pause");
	return 0;
}

/*
*(1)new delete探秘
*	1.sizeof new delete都是运算符，不是运算符
*	2.new delete是一对，malloc() free()是一对，new和delete会调用构造函数和析构函数。
*		也就是说new和delete具备对堆上所分配内存初始化，反初始化的能力。malloc 和free不具有这种能力。
*	总结：进行运算符的重载来进行函数operator new() operator delete()来进行不同数据类型的分配和释放。
*	
*(2)基本new如何记录分配的内存大小供delete使用？
*	不同编译器new内部有不同的实现方式。
*
*(3)申请和释放一个数组
*	new进行类对象数组分配的时候会额外占用内存空间记录数组个数，这里是占用4个字节记录类对象数组的元素个数，
*	以便后面调用析构函数释放多少次析构函数。
*	如果没有析构函数，系统就不会额外分配内存空间记录额外的类对象数组个数。
*
*(4)为什么对数组释放内存不加[]就会报异常？？
*A*p8 = new A[2]();
*delete[]p8;//这里使用delete p8;就会报异常
*写成delete p8;
*	1.只会调用一次析构函数只析构了一个对象，有内存泄漏
*	2.调用operator delete(p8)释放内存的时候，因为不知道数组元素的个数，会导致释放内存错乱。不知道释放多少个内存空间。
*总结:new delete 和new[] delete[]配套使用
*
*
*
*/