#include<iostream>
#include<cstdlib>
#include<string>
#include<vector>

using namespace std;

class TestClass
{
public:
	int value01;
	int value02;
	
public:
	TestClass() { ; }
	TestClass(int value01=0,int value02=0)
	{
		this->value01 = value01;
		this->value02 = value02;
		cout << "调用了带参数的构造函数" << endl;
	}
	
	TestClass(const TestClass&tem):value01(tem.value01),value02(tem.value02)//拷贝构造函数
	{
		cout << "拷贝构造函数执行" << endl;
	}
	virtual ~TestClass()
	{
		cout << "调用了析构函数" << endl;
	}
	//拷贝赋值运算符
	TestClass&operator=(const TestClass&temc)
	{
		this->value01 = temc.value01;
		this->value02 = temc.value02;
		cout << "调用了拷贝赋值运算符" << endl;
		return *this;
	}
public:
	//int Add(TestClass& tc)
	int Add(TestClass tc)
	{
		//普通函数
		int tem = tc.value01 + tc.value02;
		cout << tem << endl;
		return tem;	//会调用析构函数，把tc这个临时对象析构，因为这个对象就临时使用了一下
		
	}
	
		
};

//统计字符ch在strsource里面出现的次数，把次数返回回去
//去掉const--无法用 "char [128]" 类型的值初始化 "std::string &" 类型的引用(非常量限定)--系统认为你会修改临时对象的倾向	
int countCh(const string &strsource,char ch)
{
	const char*p = strsource.c_str();
	int iCount = 0;

	return iCount;
}

//类属性变为原来2倍
TestClass DoubleTestClass(TestClass&tc)
{
	TestClass te(0,0);//会产生一次构造函数和析构函数的调用
	te.value01 = tc.value01 * 2;
	te.value02 = tc.value02 * 2;
	return te;	//调用了拷贝构造函数，产生一个临时对象，返回后并调用析构函数（如果没有接收）
	//优化
	//return TestClass(tc.value01 * 2, tc.value02 * 2);
}
int main(void)
{


	int number01 = 100;
	int&&reference01 = number01++;
	//右值引用，reference01和number01没有关系了，
	reference01 = 2032;


	//1.以传值方式给函数传递参数
	TestClass testclass01(12, 12);	//调用拷贝构造函数
	int sum = testclass01.Add(testclass01);	//调用拷贝构造函数
	cout << "sum=" << sum << endl;



	//2.类型转换生成临时对象--隐式类型转换以保证函数调用成功

	TestClass testclass02(21,32);
	testclass02 = 2000;//这一行产生了一个临时对象调用了构造函数（带默认参数）和析构函数
	/*
	 *  调用了带参数的构造函数
		调用了拷贝赋值运算符
		调用了析构函数
		执行了3个操作：
			1.使用2000创建了一个临时testClass对象
			2.调用拷贝赋值运算符把临时对象的值赋值给testclass02对象
			3.调用析构函数销毁testclass02对象
	 */
	//优化方法--把定义对象和给对象赋值放在一行上
	cout << "------------------------------" << endl;
	TestClass testclass03 = 1000;	//只调用了构造函数
	/*
	 * 定义testclass03对象，系统就分配了内存空间。
	 * 用1000构造testclass03对象直接在分配的内存空间分配，没有产生临时对象
	 */

	
	//隐式类型转换以保证函数调用成功
	char mystr[128] = "chchjjjjjjjooooo";
	int result = countCh(mystr, 'o');//编译器会自动构造一个string类型的临时对象，传递过去
	/*系统只会为const string &strsource产生临时变量，而不会为非const对象string &strsource产生临时变量
	 */


	//3.函数返回对象的情况

	TestClass test_class04(23, 34);
	test_class04=DoubleTestClass(test_class04);
	//这里接收临时对象调用拷贝赋值运算符函数进行赋值，就不会调用析构函数

	//如果使用右值引用来接受
	TestClass &&test_class05 = DoubleTestClass(test_class04);//临时对象不会被析构,因为是引用，所以不会调用拷贝赋值运算符
	system("pause");
	return 0;
}

/*
*(1)临时对象的概念
*	++i返回左值表达式
*	i++返回右值表达式(一个临时对象用于使用目的，然后i=i+1)
*
*什么是临时对象？为什么要少产生临时对象？
*
*	另外一些临时对象，是因为我们代码书写问题而产生的，统称临时变量为临时对象。
*	在栈上分配的临时对象，不用我们手工去释放，但是临时对象产生会影响程序的效率。
*	这些临时对象是我们后面深入学习的基础。
*	
*	
*
*(2)产生临时对象的情况和解决
*	1.以传值方式给函数传递参数--会调用拷贝构造函数
*		如何优化，变为引用
*	2.类型转换生成临时对象--隐式类型转换以保证函数调用成功
*	3.函数返回对象的情况
*
*		临时对象没有接收，会立刻调用析构函数析构，如果有接收，可能调用拷贝赋值运算符。引用不调用。
*
*
*
*2019年11月22日21:42:59
* Sunrise于东北电力大学第二教学楼1121实验室
*


*
*/