#include<iostream>
#include<cstdlib>
#include<string>
#include<vector>
using namespace std;

//一个类模板的例子
template<typename T>
void mySwap(T& a,T& b)
{
	T tem;
	tem = a;
	a = b;
	b = tem;
	
	return;
}

struct Student
{
	int number;
	string name;
};

int main(void)
{
	vector<int> v1;	//定义一个vector对象，名字叫v1，存储int类型的数据
	//<>是类模板中的内容，vector本身就是一个类模板，<int>就是一个类模板的实例化过程,需要告诉类型信息。

	//像上面的一个简单类模板，可以实例化如下
	int a = 3;
	int b = 5;
	mySwap<int>(a, b);
	cout << "a=" << a <<"\t"<< "b=" << b << endl;

	//可以存放自定义的数据类型
	vector<Student> stuList;	//存放结构体Student类型的容器
	vector<vector<string>> str_str;	//vector中的每一个元素都是一个存放string类型的vector
	vector<int*>v2;	//	存放int*类型
	//vector<int&>v3;	//引用是一个别名，不是一个对象所以不能存放在vector容器中



	//1.空vector
	vector<string>myStr;	//创建一个空的存储string类型的vector对象，不包含任何元素
	myStr.push_back("abcd");
	myStr.push_back("123");

	//2.进行元素拷贝的初始化方式
	vector<string>myStr2(myStr);	//把myStr元素拷贝到myStr2
	vector<string>myStr3 = myStr;	//每一个容器都有自己的内存空间，是拷贝复制出来的

	//3.c++11中的列表初始化方式{}
	vector<string>myStr4 = { "aaaa","bbbb","ccccc" };

	//4.创建指定数量的元素，有元素数量概念的东西，一般使用()
	vector<int>Number1(15, 0);	//	包含15个元素，每个元素的值是0
	vector<string>Mystr05(12, "AAAAA");
	//如果不给初值，那么系统会设置初值
	vector<int>Nubmer2(20);	//0
	vector<string>myStr06(12);	//=""

	//5.其他初始化方式()表示元素数量   {}元素内容  --但是不是绝对的
	vector<int>Nubmer03(10);	//集合中有10个元素，每个元素的值由系统给定。
	vector<int>Number04{ 10 };	//集合中有一个元素10.
	vector<string>myStr07{ "hello" };		//一个元素，是hello字符串
	vector<string>myStr08{ 10 };	//这里的10是int类型，与字符串类型不匹配，系统自动解释为10个元素，每个元素为空''
	vector<string>myStr09{ 10,"AAAA" };	//10个元素，每个元素都是AAAA

	vector<int>Number05(10, 1);	//	10个元素，每个元素值为1
	vector<int>Number06{ 10, 1 };	//	2个元素，10,1等同于初始化列表
	//总结：要想通过{}初始化列表的方式进行初始化，那么<>里面的类型必须和后面的匹配
	system("pause");
	return 0;
}

/*
* (1)vector类型简介：是标准库中的一种类型，集合或者动态数组，我们可以把若干个相同类型的对象放入其中。
*vector能把其他对象装进来，所以也被称为容器。
*
*(2)定义和初始化vector对象
*	
*/