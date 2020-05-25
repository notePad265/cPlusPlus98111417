#include<iostream>
#include<cstdlib>

using namespace std;

int main(void)
{
	int x = 5;
	auto f1=[=]()//在捕获的这一时刻，x的值已经复制到lambda里面了
	{
		return x;
	};
	x = 10;
	cout << f1() << endl;//5,不是我们认为的10.
	//凡是按值捕获的外部变量，在lambda表达式定义的时刻就被赋值一份存储在lambda表达式中，这里输出的是lambda
	//表达式内部的值输出。这里的解决办法就是使用&引用
	system("pause");
	return 0;
}
/*
* (1)lambda表达式延迟调用易出错细节分析
* 从这个例子理解lambda的延迟调用
* 
* (2)
* (3)
* (4)
* (5)
* (6)(7)
*/