#include<iostream>
#include<cstdlib>
#include<string>
#include<vector>

using namespace std;

//递归终止函数
void myFunction02()
{
	cout << "参数解包完成，这是终止函数" << endl;
}


//例子2
template<typename T, typename ...U>
void myFunction02(const T&firstarg, const U&...otherargs)
{
	cout << sizeof...(otherargs) << endl;//sizeof...可变参的数量
	//注意下面的递归调用展开，，把一包东西分为1+1包，直到最后为1+0
	cout << "第一个参数的值为：" << firstarg << endl;
	myFunction02(otherargs...);//当只有一个参数的时候，需要进行递归中值函数
	
}

void func()
{

	myFunction02(1, 23, 43);//2,至少有一个参数
}

int main(void){
	func();
	system("pause");
	return 0;
}

/*

*(2)可变参函数模板参数包的展开_一个参数加一包函数容易解包
*展开的套路比较固定，一般都是使用递归函数的方式来展开:c
*要求我们在代码编写过程中有一个参数包展开函数和递归终止条件。
* 一个参数+一包参数，最合适参数包的展开。
void myFunction02(const T&firstarg,const U&...otherargs)
*
*
*(3)
*
*
*/