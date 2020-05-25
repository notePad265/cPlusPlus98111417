#include<iostream>
#include<cstdlib>

using namespace std;

//在两个命名空间中定义的同名函数实体

namespace zhangsan
{

	void radius()
	{
		cout << "hello zhangsan " << endl;
	}
}


namespace lisi
{

	void radius()
	{
		cout << "hello lisi " << endl;
	}
}
int main002(void)
{

	zhangsan::radius();	//调用zhangsan命名空间的radius()函数
	lisi::radius();	//调用lisi命名空间的radius()函数

	system("pause");
	return 0;
}
/*
* （1）实际项目是多个人来编写，那么在不同的人在命名函数，类名，变量名（统称为同名实体）的时候
*	 有时候会发生冲突，那么就需要引入命名空间来解决这个问题。
* （2）命名空间就是为防止名字冲突引入的一种机制。系统中可以定义多个命名空间，每个命名
*		空间都可以有自己的名字。
*	（3）可以把命名空间当成一个作用域，在不同命名空间里面定义的同名实体不是一个实体，不同
*		命名空间的实体之间不影响。
*		方法：
*		namespace 命名空间名字
*		{
*			函数名字 变量 类定义
*		}
*	（4）当一个命名空间已经被定义的时候，再次定义就先当于向命名空间添加实体。
*	（5）访问格式：
*		命名空间名字::实体名字（函数，类名字，变量名字） ---::叫作用域运算符
*
*	（6）每次都适用lisi命名空间--using namespace lisi;--这个语句要放在lisi命名空间定义后面
*/