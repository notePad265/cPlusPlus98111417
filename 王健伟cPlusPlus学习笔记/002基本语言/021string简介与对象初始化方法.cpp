#include<iostream>
#include<cstdlib>
#include<string>
using namespace std;

int main(void)
{

	//c语言中的字符数组类型，最后一个字符是\0
	char str1[512] = "I love China 哈哈哈";

	//c++中的string类型包含了很多的方法，是std命名空间中的一个类型。
	string s1;	//默认初始化，s1="";空串，表示里面没有任何字符
	string s2 = "I Love China";	//I Love China拷贝到s2指向的内存空间中，拷贝时不包括末尾的\0
	//字符串常量末尾有一个\0
	string s3("I love China");
	string s4 = s2;	//把 S2中的内容拷贝到s4的内存空间中

	int num = 6;
	string s5(num, 'A');	//s5=AAAAAA,这种方式不推荐，会创建临时对象，对效率有影响。
	
	
	
	system("pause");
	return 0;
}

/*
* (1)前言
*	c++和c语言有很多内置类型--》 int float char 类型等，这些都是c语言内部提供的类型。
*	因为c++接触到标准库，其中很多标准库中的类型非常常用，如string，vector类型
*
*	string本身是用来处理可变成字符串类型，vector是一种集合或者容器的概念。c++标准库中有很多东西都是现成的。
*	我们尽量不要重复开发存在的东西。标准库中的代码是经过多年沉淀的，在效率上很优秀。
*
*
*（2）string类型简介--可变长字符串
*	包含头文件string
*
*（3）定义和初始化string对象
*	string 对象的初始化方法--5种初始化方法
*
*
*	
*
*
*/