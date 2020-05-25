#include<iostream>
#include<cstdlib>
#include<string>
#include<vector>
#include <memory>
#include <list>

using namespace std;


int main(void)
{
	//list<int, std::allocator<int>>myList;
	//2
	list<int>myList;//双向链表，内存中不要求连续
	myList.push_back(10);
	myList.push_back(20);
	myList.push_back(30);
	myList.push_back(40);
	myList.push_back(50);
	for (auto iter=myList.begin();iter!=myList.end();iter++)
	{
		cout << *iter << endl;
		cout <<&(*iter) << endl;
	}
	/*
	 * 10
004BD648
20
004BD680
30
004BD6B8
40
004BD6F0
50
004BD728
	总结：内存不连续，底层不是使用内存池技术实现，估计是直接调用malloc()函数
	 */



	//3分配器的使用--自己实现分配器，不建议使用，不是c++语言的要求
	allocator<int>aalloc;//定义一个aalloc分配器对象
	int*p = aalloc.allocate(3);//allocate()是分配器中的重要函数，用于分配一段原始内存，
	//分配一段能保存3个int类型的对象，这里为12字节
	int*q = p;
	*q = 1;
	q++;
	*q = 2;
	q++;
	*q = 3;
	aalloc.deallocate(p, 3);//deallocate()是分配器中的重要函数，用于释放函数，
	//释放的首地址和对象的个数
	
	system("pause");
	return 0;
}

/*
*(1)分配器，一般都不需要自己指定，是一个类模板，控制对对象进行内存分配。
list<int, std::allocator<int>>myList;
*多次分配小内存，没次都需要分配很多内存进行内存分配的管理。分配器就是对内存分配方法进行管理，提高效率。
*内存池方法就是分配一大块内存，每次从中取出一下快满足要求的内存。
*
*(2)测试allocator是否使用了内存池技术。
*
*(3)分配器的使用
*分配器是一个类模板，指定类型模板参数，，我们极少会用到allocator这种容器的分配器。
*但是从语法上，allocator分配器是能够直接编码使用的。
*
*(4)其他的分配器及原理说
*linux GNU
*使用内存池来实现分配器，但是进行内存回收是个苦难的。
*那么可以设置一个全局的分配器，每个分配器设置若干个内存池，供每个容器模板实现。详细见图。
*
*(5)自定义分配器
*	代码繁琐，并不好写
*
*	2019年11月28日21:04:30
*	Sunrise 于东北电力大学第二教学楼1121实验室
*/