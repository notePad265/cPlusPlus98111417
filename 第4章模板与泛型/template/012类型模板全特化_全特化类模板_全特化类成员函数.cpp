#include<iostream>
#include<cstdlib>
#include<string>
#include<vector>

using namespace std;
template<typename T,typename U>
class TC//泛化的tc类模板
{
public:
	void FunctionTest01()
	{
		cout << "泛化版本" << endl;
	}
	//构造函数
	TC()
	{
		cout << "泛化版本构造函数" << endl;
	}
};

//必须先有泛化版本，才能存在特化版本
//当T和U都为int类型，我们希望做一个特化版本--当两个参数都是int，系统执行我们的特化版本函数
//全特化：所有的类型模板参数，T U都用具体的类型代表
template<>//全特化，都用int代表
class TC<int,int>
{//上面泛化版本的T U参数分别对应这里的int   int
	//这里可以对特化版本做操作
public:
	void FunctionTest01()
	{
		cout << "int int 特化版本版本" << endl;
	}
	
};


template<>//全特化，都用double代表
class TC<double,int>
{//上面泛化版本的T U参数分别对应这里的int   int
 //这里可以对特化版本做操作
public:
	void FunctionTest01()
	{
		cout << "double int 特化版本版本" << endl;
	}

};



template<>//全特化
void TC<double,double>::FunctionTest01()
{
	cout << "double doubel FunctionTest01特化版本版本" << endl;
}


int main(void)
{
	//特化版本代码，编译器会优先选择
	TC<char, int>tchar;
	tchar.FunctionTest01();//调用泛化版本

	TC<int, int>tint;
	tint.FunctionTest01();//调用int,int 特化版本

	TC<double, int>tdouble;
	tdouble.FunctionTest01();//调用double int版本


	//特化成员函数，而不是类模板
	TC<double, double>tdooo;
	tdooo.FunctionTest01();//调用全特化的成员函数

	system("pause");
	return 0;
}

/*
*(1)特化---泛化
*泛化--可以随便指定类型
*特化--对特殊的类型模板参数进行特殊对待，给它写适合它的专用代码
*	类模板全特化
*		1.常规全特化
*		2.特化成员函数，而不是模板
*特化版本可以任意多。
*--------------------------------------------------------
*泛化版本构造函数
泛化版本
int int 特化版本版本
double int 特化版本版本
泛化版本构造函数
double doubel FunctionTest01特化版本版本
请按任意键继续. . .
*
*(3)
*
*
*/