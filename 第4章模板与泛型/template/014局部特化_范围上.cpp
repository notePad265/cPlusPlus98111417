#include<iostream>
#include<cstdlib>
#include<string>
#include<vector>

using namespace std;

template<typename T>
class TC
{
public:
	void FunctionTest()
	{
		cout << "调用泛化版本函数" << endl;
	}
};

//范围特化版本  const
template<typename T>
class TC<const T>
{
public:
	void FunctionTest()
	{
		cout << "Const T特化版本" << endl;
	}
};

//范围特化版本  T*
template<typename T>
class TC<const T*>
{
public:
	void FunctionTest()
	{
		cout << "T*特化版本" << endl;
	}
};


//范围特化版本--左值引用
template<typename T>
class TC<const T&>
{
public:
	void FunctionTest()
	{
		cout << "T&特化版本" << endl;
	}
};

//范围特化版本--右值引用
template<typename T>
class TC<const T&&>
{
public:
	void FunctionTest()
	{
		cout << "T&&特化版本" << endl;
	}
};

int main(void)
{
	TC<double>td;
	td.FunctionTest();//调用泛化版本

	TC<double*>tdp;
	tdp.FunctionTest();//调用泛化版本

	TC<const double> tcc;
	tcc.FunctionTest();//调用const特化版本
	
	TC<int&>ti;
	ti.FunctionTest();//调用泛化版本


	TC<int&&>tii;
	tii.FunctionTest();//调用泛化版本
	
	system("pause");
	return 0;
}

/*
*(1)
*模板参数范围上  int --特化一个const int  大--小
*		从T缩小为T*
*		从T缩小为T& T&&
*		这种豆角范围缩小
*(2)局部特化，特化完毕还是个类模板，因为里面包含类型参数T。
*全特化完毕后里面不包含类型参数T
* Sunrise于东北电力大学第二教学楼1121实验室
* 2019年11月25日15:50:32
*
*(3)
*
*
*/
