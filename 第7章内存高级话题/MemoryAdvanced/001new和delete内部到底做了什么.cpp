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
	/*A()
	{
		;
	}*/

	virtual void myFunction()
	{
		
	}
public:
	int m_i;
	
};

int main(void)
{

	A *pa1 = new A;
	A *pa2 = new A();

	//2.4基本类型加不加()的区别
	int *p3 = new int;//初值随机
	int*p4 = new int();//初值0
	int*p5 = new int(100);//初值100

	//2.5 new 对象的时候到底做了什么
	A *p6 = new A();
	delete p6;
	/*
	 *  012054A9  push        8  
		012054AB  call        operator new (012012B2h)  
		012054B0  add         esp,4  
		012054B3  mov         dword ptr [ebp-158h],eax  
		012054B9  cmp         dword ptr [ebp-158h],0  
		012054C0  je          main+1A2h (012054E2h)  
		012054C2  xor         eax,eax  
		012054C4  mov         ecx,dword ptr [ebp-158h]  
		012054CA  mov         dword ptr [ecx],eax  
		012054CC  mov         dword ptr [ecx+4],eax  
		012054CF  mov         ecx,dword ptr [ebp-158h]  
		012054D5  call        A::A (0120129Eh)  
		012054DA  mov         dword ptr [ebp-160h],eax  
		012054E0  jmp         main+1ACh (012054ECh)  
		012054E2  mov         dword ptr [ebp-160h],0  
		012054EC  mov         edx,dword ptr [ebp-160h]  
		012054F2  mov         dword ptr [p6],edx


	delete p6;
	
	008C54F5  mov         eax,dword ptr [p6]  
	008C54F8  mov         dword ptr [ebp-164h],eax  
	008C54FE  push        8  
	008C5500  mov         ecx,dword ptr [ebp-164h]  
	008C5506  push        ecx  
	008C5507  call        operator delete (08C1050h)  
	008C550C  add         esp,8  
	008C550F  cmp         dword ptr [ebp-164h],0  
	008C5516  jne         main+1E4h (08C5524h)  
	008C5518  mov         dword ptr [ebp-16Ch],0  
	008C5522  jmp         main+1F4h (08C5534h)  
	008C5524  mov         dword ptr [p6],8123h  
	008C552B  mov         edx,dword ptr [p6]  
	008C552E  mov         dword ptr [ebp-16Ch],edx 

	总结：调用了 operator new函数，在 operator new函数里面调用malloc。然后调用构造函数构造对象
		delete的时候调用先调用析构函数，然后 operator delete释放内存调用free()函数
	 */
	system("pause");
	return 0;
}

/*
*(1)综述和回顾
*	对理解模板类中的内存分配有重要作用。
*
*(2)从new说起
*		A *pa1 = new A;
		A *pa2 = new A();
*	2.1new对象的时候加不加()的差别
*		如果是个空类，两个写法没有区别，
*		如果类A中有成员变量,带()初始化会把一些和成员变量有关的内存清0，但是不是整个内存全部清0；
*	2.2	当类有构造函数，两种写法一样。
*		当没有构造函数，但是有一个虚函数的时候，还是会把成员变量m_i清0.
*		总结：如果没有构造函数，编译器会给我们给
*
*	2.3 加上()，有一种函数调用的感觉，不加()实际上还是会调用默认构造函数。
*	2.4基本类型加不加()的区别
*	2.5 new 对象的时候到底做了什么
*		
	总结：调用了 operator new()函数，在 operator new函数里面调用malloc。然后调用构造函数构造对象
		delete的时候调用先调用析构函数，然后 operator delete()函数释放内存调用free()函数
*(3)malloc做了什么事情？malloc是怎么分配内存的？
*	这是操作系统内部的内存管理，牵涉到内存分配，管理，合并，释放等问题。
*	malloc会调用操作系统更底层的借口来实现真正的内存分配。
*(4)总结：
*
*/