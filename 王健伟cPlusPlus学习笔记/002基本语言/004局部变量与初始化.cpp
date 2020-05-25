#include<iostream>
#include<cstdlib>
using namespace std;

int main004(void)
{
	/*
	 * c语言所有定义都要在文件头部，c++可以随时需要，随时定义
	 */
	for (int i = 0; i < 10;i++)
	{
		cout << i << endl;	//i的作用域仅仅限制在for循环内部
	}


	//c++可以使用{}初始化变量
	int aaa = 5;	//C语言定义的时候初始化
	int bbb{ 6 };	//c++语言可以使用{}初始化变量
	int ccc = { 7 };	//可以加=，也可以不加=
	for (int i{ 0 }; i < 10;i++)
	{
		cout << i << endl;
	}

	//数组使用{}初始化
	int arrayInt[]{11, 12, 34};	//c++语言写法
	//int arrayInt[]={11, 12, 34};//c语言写法
	for (int i{ 0 }; i < sizeof(arrayInt)/sizeof(arrayInt[0]);i++)
	{
		cout << arrayInt[i] << endl;
		cout << *(arrayInt + i) << endl;
	}

	int ddd = 3.5f;	//仅仅是一个警告，ddd=3;--系统执行了隐式浮点数到整数的转换
	//int eee{ 3.5f };	//提示需要收缩转换，报错
	//直接使用等号赋值，是c语言语法，类型转换不会报错，但是{}是c++语法，转换会报错
	
	
	system("pause");
	return 0;
}
/*
* (1)c++使用{}初始化变量。
*/