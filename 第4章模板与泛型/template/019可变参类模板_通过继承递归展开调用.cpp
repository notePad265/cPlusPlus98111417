#include<iostream>
#include<cstdlib>
#include<string>
#include<vector>

using namespace std;

//1.使用递归继承方式展开参数包
template<typename ...Args>class myclass{};//主模板
//手写一个参数为0的特化版本
template<>class myclass<>//0个模板参数特化版本
{
public:
	myclass()
	{
		cout << "0个模板参数特化版本执行"<<this << endl;
	}
};

template<typename First,typename ...Other>
class myclass<First,Other...>:private myclass<Other...>
{
public:
	myclass():m_i(0)
	{
		cout << "myclass的构造函数执行了"<<this << endl;
	}
	//有参构造函数
	myclass(First parf,Other...Paro):m_i(parf),myclass<Other...>(Paro...)//调用父类的构造函数
	{
		cout << "有参数构造函数执行"<<this << endl;
	}
	
	
public:
	First m_i;
	
	
};

int main(void)
{
	myclass<int, float, double>myc;
	/*
	 * 执行三次构造函数
	 * myclass<int,float,double>--->myclass<int ,float>--->myclass<int>
	 *
	 * 	0个模板参数特化版本执行0020F73C
		myclass的构造函数执行了0020F73C
		myclass的构造函数执行了0020F73C
		myclass的构造函数执行了0020F73C
	 */
	cout << "----------------" << endl;
	myclass<int,float,double> my_class01(12, 123.565, 344.5845734958);
	/*
	 * 0个模板参数特化版本执行0039F74C
		有参数构造函数执行0039F74C
		有参数构造函数执行0039F74C
		有参数构造函数执行0039F74C
	 */

	system("pause");
	return 0;
}

/*
*(1)可变参类模板
*允许模板中定义0个到任意个模板参数，这是中高级话题，使用不多。
*	1.使用递归继承方式展开参数包
	
每次子类都分成1+包，最后为0，进行递归调用.

注意递归继承
*	
*
*(2)在命令提示符里面使用dumbin /all 文件名字 >mytext.txt
*查看有多少类生成。
*
*(3)2019年11月25日21:49:17
* Sunrise于东北电力大学第二教学楼1121实验室

*
*
*/