#include<iostream>
#include<cstdlib>
#include<string>
#include<vector>
#include"myArray.h"
using namespace std;


int main(void)
{

	myArray<int, 100>my_array01;
	myArray<int>my_array02;//使用一个默认参数

	my_array02.myFunction01();
	
	system("pause");
	return 0;
}

/*
*(1)非类型模板参数
*	1.一般浮点型不做非类型模板参数 float double一般不可以做
*	2.类类型一般也不允许做非类型模板参数。
*
*(2)
*
*(3)
*
*
*/