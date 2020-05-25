#include<iostream>
#include<iostream>
#include<cstdlib>
#include<functional>
#include <vector>
#include <algorithm>
using namespace std;
//全局变量，每个元素都是function，每个元素都是参数是int，返回值是bool类型
std::vector<std::function<bool(int)>> gv02;

class AT
{
public:
	int m_temvalue = 7;
	void addItem()
	{
		gv02.push_back(// c++4中允许在lambda表达式形参列表中使用auto
				[abc=m_temvalue](auto tv)//将m_temvalue复制到闭包中来，lambda中使用的都是副本
					   //等价于
			//[this](auto tv)
		{
			cout << "m_temvalue=" << abc << endl;//7
			if (tv%abc == 0)//如果tv是temValue的倍数
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
	delete pat;//ok,可以提前删除
	cout << gv02[0](10) << endl;//0
	//delete pat;
	
	system("pause");
	return 0;
}
/*
* (1)广义lambda捕获generalized lambda capture
* c++14中引入，解决lambda表达式成员属性依赖this指针问题。

m_temvalue=7
0
请按任意键继续. . .

* 
* (3)
* (4)
* (5)
* (6)(7)
*/