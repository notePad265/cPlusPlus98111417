#include<iostream>
#include<cstdlib>
#include<string>
#include<vector>

using namespace std;

int main(void)
{

	//1
	vector<int>Number1;
	if (Number1.empty())
	{
		cout << "Number容器为空" << endl;
	}

	//2
	Number1.push_back(1);
	Number1.push_back(2);
	for (int i=0;i<10;i++)	//vector中可以包含重复的元素
	{
		Number1.push_back(i);
	}
	Number1.push_back(50);

	//3
	cout << Number1.size() << endl;	//13

	//4 clear
	/*Number1.clear();
	cout << Number1.size() << endl;*/

	//5访问容器元素
	cout << Number1[3] << endl;	//输出编号为0的值

	//6
	vector<int>Number2;
	Number2.push_back(2222);
	Number2 = Number1;	//Number2中原来的元素被覆盖
	//使用{}重新赋值
	Number2 = { 11,22,33,44 };

	//7
	vector<int>Number3 = Number2;
	if (Number3==Number2)
	{
		cout << "两个容器相等" << endl;
	}


	//8范围for语句
	vector<int>Number4 = { 1,2,3,4,5,6,7 };
	for (auto& x:Number4)	//这里要修改原来的值，必须用引用
	{
		//变为原来的2倍
		x = 2 * x;	
	}
	for (auto x:Number4)	//这里是拷贝出来
	{
		cout << x << endl;
	}
	//范围for语句错误
	vector<int>Number5 = { 11,22,33,44 };
	for (auto x:Number5)	//遍历开始就记录结束位置了，不能添加，删除元素。
	{
		Number5.push_back(888);	//本意是想输出，但是在前面插入元素了，会导致错误
		//这一行导致错误
		cout << x << endl;
	}
	//因为第一次循环的时候，就记录了结尾的值，但是循环输出的时候导致错误（插入新的元素导致结尾位置发生改变）
	/*
	 * 结论：在for语句中，遍历一个容器的操作中，千万不要改动vector容器的容量，增加，删除元素都不可以执行。
	 * 千万不要做这种操作。
	 */
	system("pause");
	return 0;
}

/*
* (1)vector对象的操作。最见得情况是我们不知道vector中包含多少元素，在使用过程中动态的创建和减少。
* 所以一般都是先创建空的vector对象。
* 很多操作和string类似
* 
*	1.判断vector是否为空.empty()
*	2.push_back()用于向末尾添加元素
*	3.size()返回元素的个数
*	4.clear()用来清空容器
*	5.v[n] 返回编号为n的元素，编号从0开始。超过下标的范围产生不可预测的结果
*	6，赋值运算符=
*	7相等和不相等 ！= ==（元素数量相同，对应位置的元素也必须相等）
*	8.范围for应用
*/