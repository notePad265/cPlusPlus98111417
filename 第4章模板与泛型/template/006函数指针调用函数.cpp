#include<iostream>
#include<cstdlib>
#include<string>
#include<vector>


using namespace std;
int myFunction(int a,int b)
{
	return  a + b;
}
//把函数指针作为另外一个函数的参数传递？？
//
//定义一个函数指针类型
typedef int(*FunType)(int, int);
//定义一个函数接收函数的指针
void TestFunction(int i,int j,FunType myfun)
{
	//这里可以通过函数指针调用函数
	int result = myfun(i, j);
	cout << result << endl;
}


int main(void)
{
	TestFunction(1, 2, myFunction);//函数名字就相当于一个函数地址
	TestFunction(1, 2, &myFunction);//ok。取地址也可以调用成功

	system("pause");
	return 0;
}

/*
*(1)函数指针做其他函数的参数
*
*
*(2)
*
*(3)
*
*
*/