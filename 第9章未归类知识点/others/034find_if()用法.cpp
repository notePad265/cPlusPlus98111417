#include<iostream>
#include<cstdlib>
#include<functional>
#include <vector>
#include <algorithm>
using namespace std;

int main(void)
{
	vector<int>myVector = { 10,20,30,40 };
	auto result = find_if(myVector.begin(), myVector.end(), [](int value)
	{
		cout << "value=" << value << endl;
		if (value>20)
		{
			return true;//返回true停止遍历。
		}
		return false;//只要返回false就一直遍历，遍历完毕为止。一直到返回true或者遍历完毕位置
		//find_if第三个参数这个可调用对象返回true，find_if就停止遍历。
		//find_if返回一个迭代器，指向第一个满足条件的元素，如果不存在这样的元素，则这个迭代器会指向myVector.end()
	});
	system("pause");
	return 0;
}
/*
* (1)find_if()
* 函数模板，按条件查找，按照第三个参数给定的函数对象查找
* 
* (2)总结：多学习别人写的代码学习find_if()用法
* 
* (3)
* 
* (4)
* 
* (5)
* 
* (6)
* 
* (7)
*/