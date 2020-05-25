#include<iostream>
#include<cstdlib>
#include<string>
#include<vector>
#include <memory>
#include <array>
using namespace std;


int main(void)
{
	//包含5个元素的数组
	array<string, 5>mystring = { "fsdfd","fsfds","ds","dsf","dfd" };
	cout << mystring.size() << endl;//5
	mystring[0] = "fsdffffsdfsdfsdfsdfsfsfdf";
	cout << sizeof(string) << endl;//字符串类型的大小---28
	for (size_t i=0;i<mystring.size();i++)
	{
		cout << "------------------------------1" << endl;
		const char*p = mystring[i].c_str();
		cout << "元素内容为:" << p << endl;
		printf("对象地址为=%p", &mystring[i]);
		cout << endl;
		printf("指向的字符串地址=%p", p);
		cout << endl;
		cout << "------------------------------2" << endl;

	}
	
	/*
			 ------------------------------1
			元素内容为:fsdffffsdfsdfsdfsdfsfsfdf
			对象地址为=002EFB60
			指向的字符串地址=0063DA38
			------------------------------2
			------------------------------1
			元素内容为:fsfds
			对象地址为=002EFB7C
			指向的字符串地址=002EFB80
			------------------------------2
			------------------------------1
			元素内容为:ds
			对象地址为=002EFB98
			指向的字符串地址=002EFB9C		//string 比较短，直接在后面存储
			------------------------------2
			------------------------------1
			元素内容为:dsf
			对象地址为=002EFBB4
			指向的字符串地址=002EFBB8
			------------------------------2
			------------------------------1
			元素内容为:dfd
			对象地址为=002EFBD0
			指向的字符串地址=002EFBD4
			------------------------------2
			请按任意键继续. . .


	 */
	//总结：对象是连续的，但是对象指向的字符串的内存空间没有关系
	
	
	system("pause");
	return 0;
}

/*
*(1)容器的分类
*vector
*list
*map
*容易用于保存数据，
*STL中的容器可以分为3大类
*	1.顺序容器(Sequence containers)，放在那里就在那里，array,vector,deque ,list, Forward-List
*	2.关联容器（Associative Containers）,元素一般是hi键值对，使用键（key）来找值（value）特别适合查找
*		set /multiset map/multimap
*		根据键自动在内部排序，能控制插入内容，但是不能控制插入位置。
*		可以使用树，或者哈希来实现
*		
*	3.无序容器（unordered containers）c++11中推出的新名字。元素的位置不重要，重要的是元素是否在容器中
*		无序容易也是属于一种关联容器。
*		随着元素的的插入，每个元素在容器中的位置可能随着发生改变。内部可能使用哈希表来实现
*		常见的有：unordered_set unordered_multiset unordered_map  unordered_multimap
*	c++标准没有规定是用什么算法实现上面容器
*
*(2)容器的说明说明和应用事项例
*	2.1array本质上是一个内存空间连续的数组，大小固定，不能增加它的大小
*	对象是连续的，但是对象指向的字符串的内存空间没有关系
*
*(3)
*
*
*/