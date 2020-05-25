#include<iostream>
#include<cstdlib>
#include<string>
#include<vector>

using namespace std;


int main(void)
{
	//左值引用
	int number01 = 10;
	int&reference_number01 = number01;
	reference_number01 = 20;

	//2const 引用
	const int reference_number02 = number01;

	//右值引用-绑定到右值  临时
	int&& reference_number03 = 3;//使用完3之后不需要保留
	reference_number03 = 12;


	//左值引用   指针可以指向一个空，可以不初始化，但是引用必须初始化
	//没有空引用，左值引用初始化的时候就绑定到左值
	int number04 = 200;
	int&Reference_number05 = number04;
	//int &number06 = 4;//error 左值引用不能绑定到右值，必须绑定到左值
	const int &tem = 3;//const引用可以绑定到右值。const引用比较特殊。系统内部生成了一个临时变量
	/*
	 * temValue=3;
	 * int&tem=temValue;
	 */

	//右值引用--必须是绑定到右值的引用。使用&&、--绑定临时对象上
	int &&reference_number07 = 3;	//右值引用可以理解成一个对象的名字。



	//其他范例
	string str{ "jisuanjizuchengyaunli" };
	string &reference_str = str;
	//string &reference_str02{ "jisuanizuchengyaunli" };//error不可以，左值引用不能绑定到临时对象
	//临时变量被系统当做右值
	//
	const string &reference_str03 = "jisuanjizuchengyuanli";//ok
	//const不但可以绑定到右值，而且可以执行隐式类型转换，经临时对象绑定到string临时变量中。
	
	//string &&reference_str04{ str };//error,右值引用不能半丁到左值
	string &&reference_str05{ "jisuanjizjiifisidf" };//可以绑定到临时对象

	int number06 = 100;
	int&reference_number08 = number06;
	//int&&reference_number09 = number06;//error

	//右值结果绑定到右值
	int &&reference_nubmer10 = number06 * 100;//ok

	//为什么前置运算符是一个左值表达式??
	/*++i;
	 *系统直接在内部给变量i加1，然后返回i本身
	 * 因为i是变量，所以可以被赋值，赋值后还是一个对象
	 *
	 * i++为什么是一个右值表达式？？？
	 * 先用后加，
	 * 先产生一个临时变量，记录的值用于使用，再给i加1，接着返回这个临时变量（临时变量是右值）
	 */

	int number11 = 300;
	(++number11) = 199;//number11=199
	//(number11++) = 2000;//error
	int&&reference13 = number11++;//成功绑定右值，但是reference11绑定的不是number11,绑定的是返回的临时量

	//std::move()函数--左值转换为右值
	int number14 = 14;
	int&&reference_number15 = std::move(number14);//ok
	reference_number15 = 15;
	cout << reference_number15 << endl;	//15,可以绑定

	int &&reference_nubmer16 = 100;
	int&&reference_number17 = std::move(reference_nubmer16);	//ok 将一个左值引用转化为右值


	string str18 = "jisuanjizuchegnaun";//没有移动，触发了string类的移动构造函数。移动后把str18清空了。reference19是重新开辟的内存。
	//string reference19 = std::move(str18);
	
	//把一段右值绑定到右值上
	string &&str20 = std::move(str18);
	
	system("pause");
	return 0;
}

/*
*(1)引用分类
*	1.左值引用-绑定到左值
*	2.常量引用-不改变原来的值
*	3.右值引用  使用&& c++11标准
*(2)左值引用是什么？
*	引用左右，绑定到左值上
*
*(3)右值引用，必须绑定到右值上
*为什么引入右值引用？
*	希望右值引用来绑定一些即将销毁的或者一些临时对象上。
*总结：能绑定到左值上的对象一般不能绑定到右值上。
*	返回左值引用的函数连同赋值，下标，解引用，和前置递增递减运算符都是返回表达式的例子。
*	我们可以将一个左值引用绑定到这列表达式的结果上。
*
*	返回非引用类型的函数，连同算术，关系，以及后置递增递减运算符（i--）,不能将一个左值引用绑定到这类
*	表达式上，但是可以将一个const或者右值引用绑定到这列表达式上。
*
*1.所有的变量，看成左值，因为他们是由地址的
*2.任何函数的形参都是左值。如void function(int&a);a虽然是引用，但是是左值
*3.临时对象是右值。
*
*
*(4)右值引入目的
*	1.右值引入是c++11的新概念，可以认为&&是一种新的数据类型，引入这种新的数据类型目的见2.
*	2.引入&&是为了提高运算效率，把拷贝对象变成移动对象来提高运送效率。拷贝时候需要分配内存，
*		然后再一个一个项拷贝，移动直接把内存块指针转给B，而不需要分配内存。具体见移动构造函数章节。
*	3.移动对象是如何发生的？怎么触发移动对象？
*		当用一个对象给另一个对象赋值，移动移动构造函数，移动赋值运算符（需要的参数是右值引用）
*		拷贝构造函数，赋值运算符需要的参数是左值引用
*
*(5)std::move()函数
*	std::move()只有一个目的：把一个左值，强制转换为一个右值。--结果：一个右值可以绑定上去了。
*
*2019年11月22日16:00:10
* Sunrise于东北电力大学第二教学楼1121实验室
*
*/