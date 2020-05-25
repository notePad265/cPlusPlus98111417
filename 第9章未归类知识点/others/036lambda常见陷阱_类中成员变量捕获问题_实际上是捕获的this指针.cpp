#include<iostream>
#include<iostream>
#include<cstdlib>
#include<functional>
#include <vector>
#include <algorithm>
#include <ctime>
using namespace std;

//全局变量，每个元素都是function，每个元素都是参数是int，返回值是bool类型
std::vector<std::function<bool(int)>> gv02;



class AT
{
public:
	int m_temvalue = 7;
	void addItem()
	{
		auto temvalue02 = this->m_temvalue;//成员变量转局部变量，lambda表达式捕获
		gv02.push_back(// c++4中允许在lambda表达式形参列表中使用auto
			//[=](auto tv)//按值捕获，解决引用捕获超出范围的问题（引用悬空）=按值，相当于有this
			//等价于
			[this](auto tv)
		{
			cout << "m_temvalue=" << m_temvalue << endl;//7
			if (tv%m_temvalue == 0)//如果tv是temValue的倍数
			{
				return true;

			}
			return false;
		}
		);
		/*
		 * 我们会认为=是按值捕获，使我们能够访问成员变量m_temvalue,lambda表达式中使用的是m_temvalue的副本。
		 *但是如果我们在调用lambda之前删除对象的指针，//46行，结果是：
		 *m_temvalue=-572662307
		 *0
		 *也就是lambda执行的正确与否却决于pat对象是否存在，这个lambda表达式在对象存在的时候才能正确执行。
		 */
		
	}
};

int main(void)
{

	AT *pat = new AT();
	pat->addItem();
	//delete pat;
	cout << gv02[0](10) << endl;//0
	delete pat;
	
	system("pause");
	return 0;
}
/*
* (1)lambda常见陷阱_形参列表可以使用auto
* c++4中允许在lambda表达式形参列表中使用auto。//18行
* (2)lambda常见陷阱_类中成员变量捕获问题_实际上是捕获的this指针
* 明确一点：捕获这个概念，只针对在创建lambda表达式的作用域内可见的，非静态 局部变量（包括形参）
* m_temvalue不是非静态局部变量，m——temvalue是AT类的成员变量，成员变量不能被捕获到的。
* 那么为什么可以在lambda中使用m_temvalue?
* this指针指向对象本身，这里使用的[=]捕获的是this指针值。
* [=](auto tv)等价于
* [this](auto tv)
* 解决办法：将成员变量赋值到一个局部变量中，捕获局部变量的值。
* (3)
* (4)
* (5)
* (6)(7)
*/