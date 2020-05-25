#include<iostream>
#include<iostream>
#include<cstdlib>
#include<functional>
#include <vector>
#include <algorithm>
#include<initializer_list>
#include<stdarg.h>//...的头文件
using namespace std;

void printValue(initializer_list<int>temArr)
{
	for (auto beg=temArr.begin();beg!=temArr.end();beg++)
	{
		cout << *beg << endl;
	}
	cout << "temArr.size()="<<temArr.size() << endl;//查看列表中的元素个数，
}


class CT
{
public:
	CT(const initializer_list<int>&temArray)
	{
		cout << "initializer_list类做构造函数的初始化列表的函数执行了" << endl;
	}
};

//省略号形参(...)--求出若干个double类型变量的值
double sum01(int num,...)//可变参数...
{
	va_list valist01;//创建一个va_list类型的变量
	double sum = 0;
	va_start(valist01, num);//使valist01指向其实的参数，确定在内存空间的位置
	for(int i=0;i<num;i++)
	{
		//遍历参数
		sum = sum + va_arg(valist01, int);//参数2说明返回的类型为int
	}
	va_end(valist01);//释放valist01
	return sum;
	
}

//char*版省略号形参...
void funcChar(const char*msg,...)//通过msg得到可变参数数量
{
	va_list valist;//创建与i个va_list变量
	int intmsg = atoi(msg);//获取可变参数数量
	va_start(valist, msg);//绑定
	int parmCount = 0;
	while (parmCount<intmsg)
	{
		char*p;//假设给定的参数都是字符串，
		p = va_arg(valist, char*);
		printf("第%d个字符是%s\n", parmCount, p);
		parmCount++;
	}
	va_end(valist);
	
}

int main(void)
{
	initializer_list<int>myArray;//数组，元素类型是int,空列表，空数组
	initializer_list<int>myArray02 = { 1,2,3,4,4,5 };//int类型数组
	//注意一旦初始化完毕，后不能改变，也就是说initializer_list中的元素永远是常量值，不能被改变

	//2.1begin() end()遍历,size()获取元素的个数
	printValue(myArray);//0
	printValue({ 1,2,3,4,4,5,56,6,6,67,7,7,2,7,7 });//传递值序列，则必须把序列放在{}中作为一个整体传递  15个元素
	//其实c++11将使用{}大括号初始化{初始化列表}作为一种比较通用的初始化方式，可用于很多类型。
	//
	//支持迭代器，可以使用返回for语句进行遍历
	for(auto&temItem:myArray02)//使用引用不用值传递
	{
		cout << temItem << endl;
	}

	//2.2拷贝和赋值
	initializer_list<string> myArray03 = { "aa","bbb","ccc" };
	initializer_list<string>myArray04(myArray03);//调用拷贝构造
	initializer_list<string>myArray05;
	myArray05=myArray03;//调用拷贝构造

	/*内存地址完全相同
	 [原始视图]={_First=0x0053fcb4 "aa" _Last=0x0053fd08 <读取字符串的字符时出错。> }
	 [原始视图]={_First=0x0053fcb4 "aa" _Last=0x0053fd08 <读取字符串的字符时出错。> }
	 [原始视图]={_First=0x0053fcb4 "aa" _Last=0x0053fd08 <读取字符串的字符时出错。> }
	 */
	CT ct={ 12, 34, 34, 345, 54, 54, 5, 54, 5 };//隐式类型转换
	
	CT ct02{ 234,43,5,45,4,5,46,5 };//不加=，不是隐式类型转换
	CT ct03 = CT({ 234,34,32,345,4 });


	//3省略号形参(...)
	cout << sum01(4, 100, 200, 300, 400) << endl;//第一个参数指定有几个参数

	printf("value=%d,value02=%d", 1, 2);
	/*f12可以看到：
	 *
	 * _CRT_STDIO_INLINE int __CRTDECL printf(
    _In_z_ _Printf_format_string_ char const* const _Format,
    ...)
	 */

	funcChar("3","aaaa", "bbbb", "cccccc");
	system("pause");
	return 0;
}
/*
* (1)可变参数列表
* 能接受非固定个数参数的函数就是可变参数函数。
* initializer_list标准库类型。前提条件：所有的实参类型相同
* (2)initializer_list初始化列表
* 实参数量不可预知，但是所有参数的类型相同，我们可以使用initializer_list类型的形参来接受。
* initializer_list是c++提供的新类型，也是一个类模板。
* 理解成某种类型的数组，这个类模板里指定的类型模板参数就是这个数组里面保存的数据的类型。
*包含头文件#include<initializer_list>
*
*	2.1begin() end()遍历,size()获取元素的个数
*	2.2拷贝和赋值
*		拷贝和赋值一个initializer_list对象，不会拷贝列表中的元素。原来对象和拷贝或者赋值出来的对象共享表中的元素内存空间。
*
*	2.3初始化列表做构造函数参数
* (3)省略号形参(...)
* 类类型传递给省略号形参一般会出问题，一般可以处理int ,char*等类型。
* 这种省略号形式的可变参数函数，虽然参数数量不确定，但是函数的所有参数是存储在连续线性的栈空间中的。
* 而且带...的可变参数函数必须至少要有一个普通参数，我们就可以通过这个普通参数来寻址。
*
*总结：1.至少有一个有效的形参，不能完全是...
*2.  ...形参只能出现在形参列表中最后一个位置，
*3.  第一个参数会进行类型检查，...中的参数不会进行类型检查。
*4.  ...之前的逗号可以省略void funcChar(const char*msg...)
*5.如果有多个普通参数，那么va_start(valist,msg),第二个参数必须绑定...之前的那一个参数。
*6.可变参数是int或者字符串类型可以基本正常处理，其他自定义类类型可能不能正常处理。
*
*要求：自己写程序尽量不要用...可变参数类型，遇见可以看懂即可。
*
* (4)shift+f11调试时候退出当前函数
* (5)
* (6)(7)
*/