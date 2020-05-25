#include<iostream>
#include<cstdlib>
#include<string>
#include<vector>
#include <memory>
#include <set>
#include <map>
#include <list>
#include <array>

using namespace std;
class A
{
public:
	void myFunction()
	{
		A*a = new A();
		delete a;
	}
	static void *operator new[](size_t size);
	static void operator delete[](void*pHead);

	A()
	{
		cout << "这是类A的构造函数" << endl;
	}
	~A()
	{
		cout << "这是类a的析构函数" << endl;
	}
public:

};

void* A::operator new[](size_t size)
{
	A*p1 = (A*)malloc(size);
	return p1;
}

void A::operator delete[](void* pHead)
{

	free(pHead);
}



int main(void)
{
	A*p1 = new A[3];
	delete[]p1;

	system("pause");
	return 0;
}

/*
	重载类中的new[] delete[]运算符--释放数组的内存空间
*(1)
*operator new 和operator delete被调用1次，但是构造函数和析构函数被调用3次
*
*为为什么调用operator new函数分配7个字节？每个对象占用1个字节，多分配4个字节
*分配了一个整形用于存储数组元素的个数 3
*
p1 = 0x0057d3a0		operator new()分配的地址，这是是分配的向后的7个字节
p1 = 0x0057d3a4		返回的地址
0x0057D3A0  03 00 00 00 cd cd cd fd fd fd fd dd 
0x0057D3AC  dd dd dd dd 10 a8 ac 25 dd dd 00 80  

*2019年11月29日18:47:29
* Sunrise于东北电力大学第二教学楼1121实验室

*/