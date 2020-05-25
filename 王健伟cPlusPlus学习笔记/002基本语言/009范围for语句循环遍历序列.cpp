#include<iostream>
#include<cstdlib>
using namespace std;

int main090(void)
{
	//范围for语句--用于遍历一个序列
	int ArrayInt[]{11, 12, 13, 14, 15};
	for (auto x:ArrayInt)	//数组ArrayInt中的每个元素，依次拷贝到x中(拷贝费时间)
	{
		cout << x << endl;
	}
	//可以直接加一个队列
	for (auto x : {21,22,23,24,25})
	{
		cout << x << endl;
	}
	//为了节约拷贝时间，可以使用引用来提高系统效率
	for (auto &x:ArrayInt)
	{
		cout << x << endl;
	}
	
	
	
	system("pause");
	return 0;
}
/*
* (1)shift+F9添加快速监视
*/