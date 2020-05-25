#include<iostream>
#include<cstdlib>
#include<string>
#include <vector>

using namespace std;


int main(void)
{
	int number01 = 10;	//每个对象占有一块内存空间

	number01 = 22;
	//左值当右值使用，
	number01 = number01 + 1;//number01本质上是左值。虽然它出现在等号右侧。
	/*
	//number01用在等号右侧的时候，我们说number01具有右值属性，不是右值。
	*number01出现在左边，用的是内存中的地址，nubmer01具有左值属性
	*用在右侧，用的是nubmer01的值。
	*总结：一个左值，可以同时具有左值属性和右值属性。
	 */
	//1.赋值运算符结果是左值
	printf("%d", number01 = 4);
	//整个赋值语句的结果是个左值，可以赋值
	(number01 = 4) = 23;

	//2取地址
	&number01;
	cout << &number01 << endl;

	//string vector []都是左值
	string str = "jisuanji";
	str[1];
	//迭代器也是左值
	vector<int>::iterator iter;
	iter++;
	
	system("pause");
	return 0;
}

/*
*(1)左值：能在赋值语句等号左侧的东西，它能够代表一段内存空间
*	右值：不能作为左值的值就是右值，右值不能出现在赋值语句中等号的左侧。
*	结论：c++中的一条表达式，要么是左值，要么是右值，不可能两者都不是。、
*	但是有时候左值也可以当做右值使用。
*
*用到左值的运算符：
*	1.=赋值运算符 左侧是左值、
*	2.&取地址运算符
*	3.cstring vector 下标[]都是左值
*	4.迭代器的递增，递减运算符等
*	一般在字面值上不能操作，就需要用到左值。
*	在资料上叫左值表达式就是左值，，右值表达式就是右值
*	左值：代表一个地址，所以左值表达式求值结果，就是一个对象，就需要有地址。变量名为内存空间的别名。
*		求值结果为对象的表达式，不一定是左值，需要具体分析。
*
*(2)
*
*(3)
*
*
*/