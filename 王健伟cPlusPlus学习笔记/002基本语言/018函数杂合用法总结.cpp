#include<iostream>
#include<cstdlib>
using namespace std;

void myFunction()
{
	
}

void myFunction02()	//(1)
{
	return myFunction();	//这种可以
	//return;	//	也可以
	
}


int* myFunction03()	//问题2--返回指针
{
	int temValue = 9;
	return &temValue;	//这行代码编译没有问题，但是存在巨大隐患，请看调用
	//是一个变量取地址（返回临时变量的地址，函数执行完毕后，变量内存被系统回收）
}

int& myFunction04()	//问题2--返回引用--这里返回的是局部变量的引用，运行完毕内存被回收，所以有问题
{
	int temValue = 9;
	cout << "子函数中temValue的地址" << &temValue << endl;
	return temValue;
}


int myFuction05(void)	//(3)没有形参的函数，
{
	return 1;
}



int myFunction06(int a, int b);	//(4)函数声明
int myFunction07(int a, int b);


//（6）引用做函数形式参数--间接返回多个值
struct Student
{
	int number;
	int age;
	string str;
};

void myFunction08(Student&stu)	//(06)引用，会修改外部的值
{
	stu.number = 10000;
}

//（07）函数重载
void myFunction09(int i)
{
	
}
void myFunction09(float i)
{
	
}
void myFunction09(int i,int j)
{

}
void myFunction09(int i, float j)
{

}
void myFunction09(float i, int j)
{

}




int main(void)
{

	int *p = myFunction03();
	*p = 1000;
	cout << *p << endl;	//	向回收内存空间中写入数据，存在巨大安全隐患

	//返回引用函数调用
	int&k = myFunction04();		//存在问题，局部变量已经能释放，引用不合适
	cout << "main函数中temValue的地址" << &k << endl;
	/*
	 * 子函数中temValue的地址002EF7E0
	 * main函数中temValue的地址002EF7E0
	 *
	 * 是同一段内存
	 */

	//引用是否可以使用整形变量来接收  ---这种写法ok
	int m = myFunction04();
	cout << "main函数中的地址" << &m << endl;
	/*
	 * main函数中的地址003EFC58
	 * 不是同一段内存空间是安全的。
	 */



	//（6）
	Student student1 = { 123,14,"baiqianlonga" };
	myFunction08(student1);
	cout << student1.number << endl;	//10000是修改之后的值

	
	
	system("pause");
	return 0;
}

/*
* (1)函数返回类型void表示函数不返回任何类型。但是我们可以调用一个返回类型是void的函数，
*	让它作为另一个返回类型是void类型函数的返回值。
*
*(2)函数返回指针和返回引用的情况
*	注意局部变量在函数执行完毕会释放，无论返回指针类型还是引用类型都是不安全的。
*	有的时候我们从函数中返回内容时候，系统会临时构造一些东西，做一些我们不知道的处理让我们能正常接收一些值（类型转换等）
*
*（3）不带形参的函数定义写法
*	可以保持形参列表为空，或者(void)
*
*（4）如果一个函数我们不调用的话，则该函数可以只有声明部分，没有定义部分。--多用于函数的原型设计中
*
*（5）函数定义在.cpp中，声明在.h中。定义只能定义一次，声明可以声明多次。
*
*(6)引用做函数形参--间接实现函数返回多个值。
*	值拷贝当传递的结构很大的时候，会耗费很多内存，如传递一个student结构体,不存在值拷贝问题
*	在c++中，习惯使用引用的形式参数，要习惯用引用类型的形参来代替指针类型的形参。提倡使用引用类型的形参。
*
*(7)函数重载--参数类型，个数，顺序不同都会构成函数重载
*
*	
*	2019年11月12日21:21:29
*	 Sunrise于东北电力大学第二教学楼1121实验室

*	
*/