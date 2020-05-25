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

//(3)验证迭代器所属种类的代码：
//如下这些_display_category（）是重载函数；
void _display_category(random_access_iterator_tag mytag)
{
	cout << "random_access_iterator_tag" << endl;
}

void _display_category(bidirectional_iterator_tag mytag)
{
	cout << "bidirectional_iterator_tag" << endl;
}

void _display_category(forward_iterator_tag mytag)
{
	cout << "forward_iterator_tag" << endl;
}

void _display_category(output_iterator_tag mytag)
{
	cout << "output_iterator_tag" << endl;
}

void _display_category(input_iterator_tag mytag)
{
	cout << "input_iterator_tag" << endl;
}

template <typename T>
void display_category(T ite)
{   //T的类型编译器能推导出来
	cout << "---------------begin-------------------" << endl;

	//整个这个类型叫 过滤器（萃取机），用来获取T迭代器类型的种类；
	typename iterator_traits<T>::iterator_category cagy; //相当于获取迭代器种类；
	_display_category(cagy); //编译器会挑选一个最适合的参数的重载_display_category
	cout << "typeid(ite).name() = " << typeid(ite).name() << endl; //第三章10节讲rtti时

	cout << "---------------end-------------------" << endl;
};



int main(void)
{

	//(1)
	vector<int>iv = { 100,200,3300 };
	for (vector<int>::iterator iter=iv.begin();iter!=iv.end();iter++)
	{
		cout << *iter << endl;
	}

	//3
	display_category(array<int, 100>::iterator());  //这种 类型()：代表产生 一个临时对象；
	display_category(vector<int>::iterator());
	display_category(list<int>::iterator());
	display_category(map<int, int>::iterator());
	display_category(set<int>::iterator());
	
	
	system("pause");
	return 0;
}

/*
*(1)迭代器
*官方说：迭代器是一个“可遍历stdl容器全部或者部分元素”的对象，行为类似指针的对象。
*迭代器用于表示容器中的某一个位置，具体实现和容器相关，迭代器是有容器来提供的
*也就是说，一般来讲，容器里面定义选择迭代器。
*理解成：迭代器适合容器密切相关的（绑定）的。不同容器关联的迭代器是不同的。
*iter 指针，*iter迭代器指向的元素
*
*
*(2)迭代器的分类问题
*分类依据：迭代器的移动特定（双向和单向）和容器上所能进行的操作。
*迭代器行为如指针，到处跳，表示衣蛾位置，我们一般分类是依据它的跳跃能力，每个分类对应一个struct
*	1.输出型迭代器output iterator				--向前写入
*		struct output_iterator_atg
*		一步一步往前走，并且能够通过这个迭代器来改写对应位置的值。  *iter=value  前++，--等
*	2.输入型迭代器								--向前读取一次
*		struct input_iterator_atg
*		一次一个以向前的元素读取元素，按照顺序，一个一个返回元素的值
*	3.前向迭代器 forward iterator			--向前读取，继承自input iterator
*	4.双向迭代器bidierctional iterator		--双向读取
*	5.随机访问迭代器					--随机读取
*		random-access iterator
*	这些结构是有继承关系的，5-->4--->3--->2
*
*	大多数容器都有迭代器，但是并不是所有迭代器都有迭代器，如stack queue就不提供迭代器。
*(3)验证迭代器所属种类的代码
*
*
*
*/