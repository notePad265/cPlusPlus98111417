#include<iostream>
#include<cstdlib>
#include<string>
#include<vector>
#include"myVector.h"
using namespace std;

int main(void)
{

	myVector<int> temVec;//生成一个具体的类 T---->int
	myVector<double>temVec02;
	myVector<string>temVec03;
	/*
	 *注意：myVector是类模板名字，他不是一个类名，类模板是用来实例化类用的
	 *所以myVector<string>、myVector<int>才是一类型名---实例化的类型
	 *一个实例化的类型，总会使用<>包含模板参数
	 */
	temVec.myTestFunctin();
	
	system("pause");
	return 0;
}

/*
*(1)类模板概念与定义
*	用类模板来实例化一个特定的类。编译器不能为类模板推断类型。
*	使用类模板必须模板名字用<>提供额外的信息。这些信息对应着模板类里面的参数。如vector<int> v1;
*		int是模板参数。表示容器里面存储的是int类型的数据。
*	为什么使用类模板？
*		对于不同的数据类型，可以相同的算法，定义类模板实现对不同的数据类型的相同操纵的抽象。
*类模板定义：
*template<typename 形参名字1,typename 形参名字2>
*class XXX
*{
*
*}
*实例化类模板要有类的全部信息，包括类模板中的成员函数的函数体。
*所以一个类模板的所有信息都要放在一个.h文件中
*(2)类模板成员函数
*如果类模板成员函数直接写在类模板定义中，隐式声明为内联函数。
*写在外面每一个函数都需要加上template <typename T>类型说明
*
*类模板一旦被实例化之后，那么模板的每个实例都会有自己版本的成员函数。
*所以类模板的成员函数和这个类模板有相同的模板参数。（在类外实现可以看见）
*
*2.定义在类模板之外的成员函数必须以关键字template开始，后边接类模板参数列表
*	同时类名后面使用<>把模板参数列表里面的所有参数模板名字列出来，多个模板参数之间使用,逗号分开
*template <typename T>
 typename myVector<T>::myIterator myVector<T>::myend()
 {
	//typename 模板参数名::函数返回值 类名（实例化后）::函数名字
 }

一个实例化的类的成员函数只有在被调用的时候，才会被实例化
*(3)模板类名字的使用
*写在类外面的成员函数要返回实例化的类类型
*
*(4)非类型模板参数
*
*
*
*/