#include<iostream>
#include<cstdlib>
#include<string>
#include<vector>

using namespace std;

template<typename T, typename U,typename W>
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

//模板参数数量--偏特化，2个参数特化
template< typename U>//T W绑定到具体的类型
class  TC<int,U,int>
{
public:
	void FunctionTest01()
	{
		cout << "数量--偏特化版本化版本" << endl;
	}
};




int main(void)
{
	
	TC<double, double, double> tcddd;
	tcddd.FunctionTest01();//调用泛化版本
	TC<int, double, int >tcidi;
	tcidi.FunctionTest01();//调用数量--偏特化版本


	
	system("pause");
	return 0;
}

/*
*(1)类型模板偏特化--也叫局部特化
*	1.模板参数数量上
*
*(3)
*
*
*/