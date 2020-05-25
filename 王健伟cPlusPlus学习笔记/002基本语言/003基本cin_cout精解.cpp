#include<iostream>
#include<cstdlib>
using namespace std;

//(3)在c语言中叫结构，在c++中叫对象。通过结构体可以模拟出std中的输出对象
struct Student
{
	char name[128];
	int number;
};

namespace  Student1
{
	int structTest;
	struct Student cout1;//这里是模拟std中的一个标准输出对象
}


int main003(void)
{
	std::cout << "很高兴和大家一起学习C语言" << endl;
	//std 标准命名空间 standard adj标准的
	//cout=console out 是一个对象，标准输出对象，发送给这个对象的内容都会输出到屏幕上（上面通过结构体模拟cout对象）
	//<<表示流向cout，同样>>流向一个变量。学习过运算符重载就知道，相当于cout对象调用了函数operator<< (参数)来实现
	//如果封装成函数来实现，那么cout是第一个参数，后面是第二个参数	function(cout,...)
	//ostream &std::cout.operator<< ()--它返回值写入了给定值的cout对象，返回值还是一个cout对象
	//（std::cout << "很高兴和大家一起学习C语言" ）<<endl;多值函数返回值是一个引用，所以通过引用来实现多值参数函数。

	int x = 3;
	std::cout << x << "的平方是" << x*x << std::endl;	//9
	x++;
	std::cout << x << "的平方是" << x*x << std::endl;	//16
	//std::endl是一个模板函数。功能（1）输出换行（2）强制刷新输出缓冲区
	/*
	 *输出缓冲区：是一段内存区域（逻辑地址空间--网卡缓存，显卡，输出都会在内存中占有一段内存空间）。
	 *cout输出内容都是输出到输出缓冲区，
		 *(a)当输出缓冲区满的时候
		 *(b)执行return，
		 *(c)强制换行的输出
		 *(d)当系统不忙的时候，就会查看缓冲区的内容，发现新的内容就会输出到屏幕上
	 *的时候将缓冲区的内容输出
	*	 */

	
	int i = 3;
	cout << i-- << endl << i-- << endl;
	//输出结果是 2  3.要避免在一行中多次改变一个变量的值。cout是右侧结合性


	std::cout << "请输入两个整数：" << endl;
	int value1 = 0;
	int value2 = 0;
	std::cin >> value1 >> value2;
    cout << "value1+value2=" << value1 + value2 << endl;
	
	//std::cin>>标准输入流,也是一个iostream相关对象，是标准输入--键盘
	//函数的原型是 isteam&  std::cin.operator>> () 
	

	
	system("pause");
	return 0;
}
/*
 *重点：（1）cout是一个对象，通过结构体来模拟
 *（2）cout的返回值是引用类型，通过引用类型来实现多值函数，右结合性
 *(3)cout cin 可以输出，输入int float char类型是通过函数（运算符）重载来实现。
 *
 * (1)c++中不使用printf()函数，而是使用c++提供的库函数
 * (2)不要排斥适用c++标准库，与c++语言一起学习。stl是不可或缺的c++组成部分
 *	iostream输入输出流，流式文件是一种模拟，类似于流水一样的指令集中实现。
 *	
 *  Sunrise于东北电力大学第二教学楼1121实验室2019年10月28日13:24:40
 */