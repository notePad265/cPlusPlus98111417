#include<iostream>
#include<cstdlib>
#include<string>
#include<vector>
#include <memory>
#include <set>
#include <map>
#include <list>
#include <array>
#include<algorithm>

using namespace std;

//for_each源码示意图
//template<class InputIterator ,class Function>
//Function for_each(InputIterator first, InputIterator end,Function f)
//{
//	for (;first!=end;first++)
//	{
//		f(*first);
//	}
//}
/*
 * 这段代码标明2个问题
 *	1.某些算法区分种类，这个种类决定着算法的效率
 *	2.f(*first)是一个可调用对象，（可调用对象概念重要。）
 */

void myfunc(int i)//参数是容器中的元素类型
{
	cout << i << endl;
}


bool myFunciton06(int i,int j)
{
	return i > j;
}


int main(void)
{

	//函数参数
	list<int>myList = { 100,300,4,545,4546 };
	list<int>::iterator iterBegin = myList.begin();
	list<int>::iterator iterEnd = myList.end();//最后一个元素的下一个元素
	//除了计算距离的算法，传递的是一个前闭后开的区间[iterBegin,iterEnd)
	//好处：算法只要判断元素等于后面的开区间，就表示迭代结束
	//	2.如果第一个形参==第二个形参，表示是一个空区间，-----最后一个元素位置相当于标志。
	//总结：是一种搭配迭代器使用的全局函数，算法和具体的容器无关。算法跟具体的容器没有关系。只需要根据迭代器开发算法，增加算法开发的弹性。
	//		泛型编程方式增加了灵活性，缺失了直观性。
	//		某些数据结构（容器的迭代器）和算法直接的兼容性也不是太好。


	//for_each()
	vector<int>myVector = { 12,34,34,54,45,454,54,565,6,5 };
	for_each(myVector.begin(), myVector.end(), myfunc);
	//对每个元素使用myfunc函数处理，不断迭代两个迭代器之间的元素，以元素为实参，调用函数


	//find()算法
	vector<int>myVector02 = { 12,34,34,54,45,454,54,565,6,5 };
	vector<int>::iterator iter04 = find(myVector02.begin(), myVector02.end(), 45);
	if (iter04!=myVector02.end())//判断是否找到需要使用！=第二个参数来判断
	{
		cout <<"找打元素"<< *iter04 << endl;
	}
	//当有全局函数和容器的局部函数时候，优先使用局部函数，这种局部函数对容器等进行了优化
	map<int, string>myMap;
	myMap.insert(make_pair(1, "aaaa"));
	myMap.insert(make_pair(2, "bbbb"));
	myMap.insert(make_pair(3, "cccc"));
	map<int, string>::iterator iter05 = myMap.find(2);//优先使用局部函数
	if (iter05!=myMap.end())
	{
		cout << "找到编号为" << iter05->first << "的元素" << iter05->second << endl;
	}

	auto iter06 = find_if(myVector02.begin(), myVector02.end(), [](int value)
	{
		if (value>15)
		{
			return true;
		}
		return false;
	});//lumbda表达式也是一个可调用对象
	if (iter06!=myVector02.end())
	{
		cout << "找到大于15的元素结果为:" << *iter06 << endl;//34 只会找到第一个满足条件的元素
	}


	//sort()函数排序
	sort(myVector02.begin(), myVector02.end());//myVector02.begin()+3
	for (vector<int>::iterator iter07=myVector02.begin();iter07!=myVector02.end();iter07++)
	{
		cout << *iter07 << endl;
	}
	//默认是从小到大排序，，要想从大到小排序，可以写自己的排序函数
	sort(myVector02.begin(), myVector02.end(), myFunciton06);
	for (vector<int>::iterator iter07 = myVector02.begin(); iter07 != myVector02.end(); iter07++)
	{
		cout << *iter07 << endl;
	}
	
	system("pause");
	return 0;
}

/*
*(1)算法概述  一般是全局函数/全局函数模板
*	算法的实现是函数模板，比如查找，排序
*	算法的前两个参数类型，一般是迭代器类型，表示容器中元素的一个权健
*
*(2)算法内部的处理
*	算法一般传递容器的迭代器即可。算法根据传递来的迭代器来分析是哪种迭代器，不同种类迭代器有不同的处理。
*	这种编写不同代码来处理不同种类的迭代器会影响算法的效率。
*	这也是stl内部为什么要给容器进行分类的目的。
*
*(3)一些典型的算法使用举例
*增加algorithm头文件
*	for_each()
*	find()
*	find_if()
*	sort()
*
*	2019年11月29日09:46:40
*	 Sunrise于东北电力大学第二教学楼1121实验室
*/