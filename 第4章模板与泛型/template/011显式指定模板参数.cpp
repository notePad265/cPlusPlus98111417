#include<iostream>
#include<cstdlib>
#include<string>
#include<vector>
#include <map>

using namespace std;
//定义函数模板
template<typename T1,typename T2,typename T3>
T1 Sum(T1 i,T3 j)
{
	T1 result = i + j;
	return result;
}

int main(void)
{
	//(1)
	auto result = Sum<int, int, int>(2000000000, 2000000000);
	auto restult02 = Sum<double, int, int>(2000000000, 2000000000);

	cout << result << endl;//-294967296
	cout << restult02 << endl; //4e+09


	system("pause");
	return 0;
}

/*
*(1)显式指定类模板参数
*能推倒的模板参数系统会自动推断，但是显式指定模板参数系统会以显式指定的优先。、
*一般建议：模板函数调用能指定参数类型都指定参数类型

*2019年11月25日10:49:52
* Sunrise于东北电力大学第二教学楼1121实验室

*
*/