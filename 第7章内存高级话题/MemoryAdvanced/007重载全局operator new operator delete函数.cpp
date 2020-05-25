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

void *operator new(size_t size)
{
	return  malloc(size);
}

void *operator new[](size_t size)
{
	return  malloc(size);
}

void operator delete(void *p)
{
	free(p);
}

void operator delete[](void *p)
{
	free(p);
}


class A
{
public:
	A()
	{
		cout << "调用类A的构造函数" << endl;
	}

	~A()
	{
		cout << "调用类A的析构函数" << endl;
	}
public:
	
	
};

int main(void)
{
	//(1)
	int *p1 = new int(123);
	delete p1;

	char*p2 = new char[100];
	delete[]p2;
	//会调用重写的全局operator new[] operator delete[]等

	A *a1 = new A();
	delete a1;

	A *a2 = new A[10];
	delete[]a2;
	
	system("pause");
	return 0;
}

/*
*(1)重载全局operator new operator delete函数
*如果类中重载了operator new delete运算符，会调用类内部的重载函数。
*2019年11月29日21:08:25
* Sunrise于东北电力大学第二教学楼1121实验室

*
*/