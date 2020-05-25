#include<iostream>
#include<cstdlib>

#include <boost/type_index.hpp>
#include <map>
#include <string>

using namespace std;

//显示参数类型，这里不研究boost库
template<typename T>
void myFunction01(T&tem)//T是类型模板参数，T是有类型的,tem是形参，tem也是有类型的
{
	using boost::typeindex::type_id_with_cvr;
	cout << "T type=" << type_id_with_cvr<T>().pretty_name() << endl;//显示T类型
	cout << "tem type=" << type_id_with_cvr<decltype(tem)>().pretty_name() << endl;//显示T类型

}

class TescClassA
{
public:
	static int test()
	{
		return 0;
	}
};

class TescClassB
{
public:
	static double test()
	{
		return 0.12;
	}
};

//通过类模板调用上面两个类中的函数,返回值不确定
template<typename T>
auto testFunction()
{
	auto value = T::test();//调用哪个函数不确定，返回值也不确定
	return value;
}

int main(void)
{
	std::map<string, int>myMap;
	myMap.insert(make_pair("aaa", 3454));
	myMap.insert({ "bbb",222 });
	myMap.insert({ "ccc",3434 });
	for (map<string,int>::iterator iter=myMap.begin();iter!=myMap.end();iter++)
	{
		cout << iter->first << "=" << iter->second << endl;
	}
	//可以使用auto代替类型
	for (auto iter=myMap.begin();iter!=myMap.end();iter++)
	{
		cout << iter->first << "=" << iter->second << endl;
	}

	//2.当没有办法确定类型的时候，使用auto
	cout << testFunction<TescClassA>() << endl;//0
	cout << testFunction<TescClassB>() << endl;//0.12
	

	system("pause");
	return 0;
}
/*
* (1)auto适用场合举例
*	1.代替很长的类型名字，如迭代器
*	2.当没有办法确定类型的时候，使用auto
* (2)总结：
*	auto表面上是一个关键字，也可以看作一个强大的工具，善于利用。
*	2019年12月10日
*	20点47分
* (5)
* (6)(7)
*/