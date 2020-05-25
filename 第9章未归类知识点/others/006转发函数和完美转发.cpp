#include<iostream>
#include<cstdlib>
#include <boost/type_index.hpp>
using namespace std;
//普通函数
void myFunction(int value01,int value02)
{
	++value02;
	cout <<"Sum="<< value02 + value01 << endl;
	return;
}

//左值引用
void myFunction02(int value01, int &value02)
{
	++value02;
	cout << "Sum=" << value02 + value01 << endl;
	return;
}

//改为右值引用
void myFunction03(int &&value01, int &value02)
{
	++value02;
	cout << "Sum=" << value02 + value01 << endl;
	return;
}


//模板函数，要把收到的参数以及这些参数相对应的参数保持不变转发为其他函数myFunction  --这就是转发
template<typename F,typename T1,typename T2>
void myFunctionTramsmit(F f,T1 t1,T2 t2)//F就是要调用的第三方函数,要转发的目标函数
{
	f(t1, t2);
	

}

//将函数模板改为万能引用类型
template<typename F, typename T1, typename T2>
void myFunctionTramsmit02(F f, T1&& t1, T2 &&t2)//F就是要调用的第三方函数,要转发的目标函数
{
	/*针对主函数中的调用myFunctionTramsmit02(myFunction02, 34, i);
	 *T1=int, t1=int&&  t1是右值引用类型，t1本身是左值
	 *T2=int&,t2=int&
	 * 
	 */
	//f(t1, t2);
	//“void(int &&, int &)”: 无法将参数 1 从“int”转换为“int &&”
	//调用处的是一个右值，但是通过万能引用转换为一个左值了，t1本身是一个左值，但是函数myFunction03需要的是一个右值
	f(std::forward<T1>(t1), std::forward<T2>(t2));
	//t1中原来是左值还是右值信息存在在T1模板参数中，这里会将t1转换为原始实参的右值类型
}

int main(void)
{	int i = 50;
	myFunction(34, i);

	//通过转发函数调用
	myFunctionTramsmit(myFunction, 34, i);
	myFunctionTramsmit(myFunction02, 34, i);//这里返回后i=50,并不是我们期望的51.也就是说，T2并没有实例化为int&类型
	//void myFunctionTramsmit(void(*f)(int,int&),int t1,, int t2){}//实例化后的样子，t2这个参数并不是真正传递过去引用类型
	//怎么修改传递函数，让模板函数的参数能够保持给定实参的左值性（i有const属性也传递到模板函数中）？？？？
	/*
	 *万能引用  T&& 保存实参i的所有属性，从而让编译器推导出来函数模板最终的形参类型
	 *如果使用T&普通引用，则实参中只有const属性可以传递到函数模板，而实参中的左值和右值性就不能传递到函数模板
	 * 
	 */

	//万能引用后调用
	myFunctionTramsmit02(myFunction02, 34, i);//i的值是51

	//右值引用
	int &&number01 = 80;//右值引用绑定右值
	/*
	 * 虽然&&number01是绑定到右值的，但是number01本身是个左值，因为number01本在在等号左边。
	 * &&number01叫右值引用，number01是个左值，在内存中有地址。
	 * number01本身是个左值，但是他的类型是右值引用。也就是说左值引用，右值引用概念说的是他的类型。
	 *void myFunctionTramsmit02(F f, T1&& t1, T2 &&t2)函数形参中的变量都是左值，本身类型是右值引用
	 */
	//myFunction03(number01, i);//error，实参中要给右值，number01本质上是一个左值，形参中是一个右值引用，必须绑定一个右值
	int j = 50;
	myFunctionTramsmit02(myFunction03, 20, j);
	
	system("pause");
	return 0;
}
/*
* (1)转发和完美转发
*	通过函数指针调用函数，并把函数参数作为参数传递，就是转发。
*
*	完美转发：让我们可以写接受任意类型实参的函数模板，并将其转发到目标函数，
*		目标函数会接收到与转发函数所接收到的参数类型完全相同（左值性，右值性）
*		通过std::forword()来实现
*	
* (2)std::forward()
*	c++11中的新函数，专门为转发而存在。
*	它要么返回一个左值，要么返回一个右值。
*	使用条件：
*		调用模板函数，模板函数参数是万能引用类型，模板参数负责转发
*		void myFunctionTramsmit02(F f, T1&& t1, T2 &&t2)
*		f(std::forward<T1>(t1), std::forward<T2>(t2));
*		void myFunction03(int &&value01, int &value02)//value01要绑定一个右值
*		//调用
*		myFunctionTramsmit02(myFunction03, 20, j);
*	std::forword()的能力就是按照实参本身的类型转发。
*		1.实参原来是左值，到形参中还是左值,forward是按照形参原来的类型处理，所以std::forward处理后还是左值
*		2.实参原来是右值，到形参中变成左值,forward是按照形参原来的类型处理，所以std::forward处理后是个右值
*		所以这里看来std::forward()有强制把左值转换为右值的能力，所以forward()其实只对原来是右值的情况有用。
*
*		std::forward()的能力就是保持原始实参的类型（左值还是右值）
* (3)完美转发是如何保存原始实参的左值和右值信息？
*	是保存在转发函数（函数模板中）的模板参数T中，所以转发函数的参数类型必须是万能引用类型。
* (4)总结
*forward是强制把一个左值转换为右值，如果你的原始形参就是一个左值，那我的forward啥也不干，
*move()无条件强制类型转换，转换后原始对象名字不能使用。
* 
* (5)再谈万能引用
*	万能引用不是一种新的引用类型。是一种程序的写法。但是万能引用概念的存在是有意义的。
* 
* 1.转发函数
* 2.左值和右值
* 3.完美转发std::forward()
 
* (6)
*/