#include<iostream>
#include<cstdlib>
#include<string>
#include<vector>

using namespace std;

//1.使用递归组合方式方式展开参数包
template<typename ...Args>class myclass {};//主模板
										   //手写一个参数为0的特化版本
template<>class myclass<>//0个模板参数特化版本
{
public:
	myclass()
	{
		cout << "0个模板参数特化版本执行" << this << endl;
	}
};

template<typename First, typename ...Other>
class myclass<First, Other...> //:private myclass<Other...>
{
public:
	myclass() :m_i(0)
	{
		cout << "myclass的构造函数执行了" << this << endl;
	}
	//有参构造函数
	myclass(First parf, Other...Paro) :m_i(parf),m_o(Paro...)//, myclass<Other...>(Paro...)//调用父类的构造函数
	{
		cout << "有参数构造函数执行" << this << endl;
	}


public:
	First m_i;
	//组合关系
	myclass<Other...>m_o;//参数多的类包含着参数少的类
};



int main(void)
{
	myclass<int, float, double> myclass01(1, 23.32, 34.545);
	/*
	 * 0个模板参数特化版本执行0041FA94
	有参数构造函数执行0041FA8C
	有参数构造函数执行0041FA84
	有参数构造函数执行0041FA7C

	组合关系对象首地址都不一样
	 */
	
	system("pause");
	return 0;
}

/*
*(1)通过递归组合方式展开函数包
*
*(2)
*
*(3)
*
*
*/