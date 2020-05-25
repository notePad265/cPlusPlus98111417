#include<iostream>
#include<cstdlib>
#include<string>
#include<vector>

using namespace std;

template <typename T,int S>//typename表示T是一个类型，T是一个类型参数，
T FunctionTemplate(T a)
{
	T tem = a + S;
	return tem;
}


//非类性能参数
template<unsigned a, unsigned b>
int FunctionTemplate02()
{
	return a + b;
}

//非类型参数--比较字符书否相同
template<int L1, int L2>
int CharCompare(const char(&p1)[L1], const char(&p2)[L2])
{
	return strcmp(p1, p2);
}

int main(void)
{

	int Sum01 = FunctionTemplate02<23, 23>();//显式指定模板参数，在<>指定额外的信息。
	int a = 12;
	//int Sum02 = FunctionTemplate02<a, 32>();//error，必须用常量，编译时候就要确定

	int Sum03 = FunctionTemplate<int, 12/*指定int S=12，T的类型是int*/>(13);//25--显式指定模板参数，int类型为12
	int Sum04 = FunctionTemplate<double, 13>(28);//系统以<>内传递的参数为准 28.00000000
	cout << Sum04 << endl;

	//模板函数CharCompare
	int result01 = CharCompare("jisuanji", "jisuanjizu");//没有提供费类型模板参数，自己推断出来L1,L2
	//系统实例化为int CharCompare(const char(&p1)[9], const char(&p2)[11])
	int result02 = CharCompare<9, 11>("jisuanji", "jisuanjizu");//显式指定非类型模板参数
	
	
	system("pause");
	return 0;
}

/*
*(1)模板参数列表
*	1.在模板参数列表里面还可以定义非类型参数。
*	2.非类型参数表示的是一个数值，不能使用typename修饰。
*	3.我们需要使用以前学习的传统类型名来指定非类型参数，比如非类型参数S是个整形，可以使用int S
*	T FunctionTemplate(T a,int S)
*
*(2)为什么需要非类型参数？
*	当模板被实例化的时候，这种非类型模板参数的值，或者是用户提供的，或者是编译器推断的，都有可能。
*		但是这些值都得是常量表达式，因为实例化这些模板都是在编译的时候确定的。
*
*(3)模板定义并不会生成代码，只有在我们调用函数模板时候，编译器为我们实例化一个特定的版本函数后才会生成代码。
*	编译器生成代码的时候，需要找到函数的函数体。所以函数模板的定义通常都是在.h中。
*
*
*/