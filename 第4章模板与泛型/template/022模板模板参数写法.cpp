#include<iostream>
#include<cstdlib>
#include<string>
#include<vector>
#include <list>

using namespace std;
//从类模板引入
//template<typename T,typename U>//t u叫模板参数，更具体叫类型模板参数（前面有typename）
template<
	typename T,//类型模板参数
	template<class>class Container	//这是一个模板模板参数---怎么理解这一行？？
	//另外一种等靠写法
	//template<typename W>typename Container02//W毫无用处，是占位置用的
	
>
class  myClass
{
public:
	T m_i;
	Container<T>myc;	//container作为一个类模板来使用，类似于vector<int>myc;所以他是一个类模板
	//要明白，要把Container当做一个类模板来使用，就必须为“模板模板参数”

	//构造函数
	myClass()
	{
		for (int i=0;i<10;i++)
		{
			myc.push_back(i);
		}
	}
};

//给容易定义一个别名
template<typename T>
using myVec = vector<T, allocator<T>>;//手工指定分配器

template<typename T>
using myList = list<T, allocator<T>>;//手工指定分配器


int main(void)
{

	myClass<int, myVec>myvectorobj;//本意是向容易中塞入元素，元素为int
	//vector，第一个参数是元素,第二个参数是分配器allocator

	
	system("pause");
	return 0;
}

/*
*(1)模板模板参数
*从类模板引入
*类型模板参数
*模板模板参数：首先是个模板参数，这个模板参数本身又是个模板。
*(2)
*
*(3)
*
*
*/