#include<iostream>
#include<cstdlib>
#include<string>
#include<vector>
#include <map>

using namespace std;
//给已经知道的数据类型起个别名
typedef unsigned int uint;//给无符号整形起一个别名uint
using u_int = unsigned int;

typedef std::map<std::string, int> myMap;
using myMap006 = std::map<std::string, int>;

//如果在开发中定义的类型不固定，如map容器中的key固定，但是值value不固定，使用typedef很难完成。
//c++98中使用类模板来实现
template <typename T>
class map_s
{
public:
	typedef  std::map<std::string, T > mymap02;//自定义类型，键key是string，值是T类型
};

//c++11实现上述功能
template<typename T>
using str_map_t = std::map<string, T>;//别名在前面。
/*用法：通过using关键字给一个类型模板起名字，或者起别名。
 *用法2：将父类的同名函数在子类中暴露出来。
 *用法3：定义类型，如函数类型 
 */
//using定义函数类型
using myFunction = void(*)(int, int);
typedef void(*myFunction02)(int, int);//等价



//using练习
template<typename T>
using myFunction_m = int(*)(T, T);//定义"类型模板"，既不是类模板，也不是函数模板，相当于模板起的别名

int testFunction(int a,int b)
{
	return  a + b;
}


int main(void)
{
	//(1)
	uint a = 10;
	myMap map1;
	map1.insert({ "aaaa", 1 });
	map1.insert({ "bbbb",2 });

	//key固定，value值不确定
	map_s<int>::mymap02 map001;
	map001.insert({ "aaaaa",1 });
	map_s<string>::mymap02 map002;
	map002.insert({ "bbbbb","2" });


	//c++11实现上述功能
	str_map_t<int> map003;
	map003.insert({ "dfsdf",3 });


	//using练习
	myFunction_m<int> pointFunc;//根据函数指针类型定义函数指针
	pointFunc = testFunction;//把函数地址赋值给函数指针变量
	//pointFunc = &testFunction;//ok
	cout << pointFunc(23, 45) << endl;

	system("pause");
	return 0;
}

/*
*(1)using 定义模板别名
*	1.typedef一般用来定义类型别名
	2.typedef  std::map<std::string, T > mymap02;//自定义类型，键key是string，值是T类型
*	3.using用于定义类型或者类型模板的是时候，包含了typedef的所有功能。
		定义基本类型别名
		定义类型模板
		定义函数指针
*
*	2019年11月25日10:28:07
*	 Sunrise于东北电力大学第二教学楼1121实验室

*
*
*/