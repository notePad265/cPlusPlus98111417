#include<iostream>
#include<cstdlib>
#include<string>
#include<vector>
using namespace std;



int main(void)
{
	vector<int> Number1{ 1,2,3,4,5 };
	auto beg = Number1.begin();
	auto end = Number1.end();


	for (;beg!=end;beg++)
	{
		//Number1.erase(beg);	//移除beg迭代器指向的元素，返回下一个元素的位置
		
	}

	//一个一个清除，每次计算end()的值--可以使用
	vector<int>::iterator iter = Number1.begin();
	while(iter!=Number1.end())
	{
		iter = Number1.erase(iter);
	}

	//另一种删除方法--每次指向开头，每次判断是否为空
	while (!Number1.empty())
	{
		auto iter2 = Number1.begin();
		Number1.erase(iter2);
	}


	
	system("pause");
	return 0;
}

/*
 *（1）灾难程序演示2
*/


