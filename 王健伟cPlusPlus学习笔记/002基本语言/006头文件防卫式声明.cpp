#include<iostream>
#include<cstdlib>
#include"Head.h"
#include"Head2.h"	//要加宏来防止重复包含问题

using namespace std;

int main006(void)
{
	//因为head2.h包含了head.h，所以会出现重定义问题
	//引入条件编译 #dendef #define

	
	cout << g_globalh1 << endl;
	cout << g_globalh2 << endl;


	
	system("pause");
	return 0;
}
/*
* (1)使用#ifndef #define，#endif来进行头文件防卫式编程
*  Sunrise于东北电力大学第二教学楼1121实验室
2019年10月28日16:25:03
*/