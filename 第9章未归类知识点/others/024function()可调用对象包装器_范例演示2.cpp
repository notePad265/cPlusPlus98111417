#include<iostream>
#include<cstdlib>
#include <functional>

using namespace std;

//
void myCallBack(int value,const std::function<void(int)>&f)
{
	f(value);
}

void runfunction(int value)
{
	cout << "value=" << value << endl;
}


int main(void)
{
	//小案例演示
	for (int i=0;i<10;++i)
	{
		myCallBack(i, runfunction);
	}
	system("pause");
	return 0;
}
/*
* (1)function()可调用对象包装器_范例演示2

value=0
value=1
value=2
value=3
value=4
value=5
value=6
value=7
value=8
value=9
2019年12月11日10点29分
*
*
*/