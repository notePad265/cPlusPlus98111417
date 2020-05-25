#include<iostream>
#include<cstdlib>
#include<string>
#include<vector>
#include"myArray.h"
using namespace std;

int myFunction(int a, int b)
{
	return  a + b;
}


//把函数指针作为另外一个函数的参数传递？？
//
//定义一个函数指针类型
typedef int(*FunType)(int, int);

template <typename T, typename F=FunType>//声明的时候指定类型
void testFunction(const T&i, const T&j, F myfunc=myFunction)//有默认参数
{
	cout << myfunc(i, j) << endl;
}

int main(void)
{
	//a
	myArray<> my_array01;//完全用模板参数的默认缺省值
	myArray<int >my_array02;//第二个参数使用默认缺省值


	//b.函数模板的默认参数 testFunction最后参数有默认值
	testFunction(3, 4);
	
	system("pause");
	return 0;
}

/*
*(1)默认模板参数
*	a.类模板--类模板名字后面必须使用<>来提供额外的信息。<>表示这是一个模板
*	b.函数模板的默认参数
*		老标准只能为类模板提供默认模板参数，c++11新标准可以为函数模板提供默认参数
*(2)
*
*(3)
*
*
*/