#include<iostream>
#include<cstdlib>
#include<string>
#include<vector>
#include <memory>

using namespace std;

//测试类
class CT:public enable_shared_from_this<CT>
{
public:
	shared_ptr<CT>getself()
	{
		//return shared_ptr<CT>(this);
		return shared_from_this();//enable_shared_from_this类中的方法
	}
};

class B;//声明B类
class A
{
public:
	
	shared_ptr<B> pm_b;
	//解决办法：
	//weak_ptr<B>pm_b''
	~A()
	{
		cout << "A的析构函数" << endl;
	}
};


class B
{
public:
	shared_ptr<A> pm_a;
	~B()
	{
		cout << "B的析构函数" << endl;
	}
};
//A类和B类循环引用

shared_ptr<int>createFunction(int value)
{
	return make_shared<int>(value);//返回一个shared_ptr指针
}
//
//void myFunction(int value)
//{
//	shared_ptr<int>pTem = createFunction(100);
//	return;//离开作用域后，pTem所指向的内存会被自动释放
//}


shared_ptr<int> myFunction(int value)
{
	shared_ptr<int>pTem = createFunction(100);
	return pTem;//返回局部对象
}


void myFuncion02(shared_ptr<int>ptr)
{
	return;
}

int main(void)
{
	//(1)
	myFunction(100);
	shared_ptr<int>p1 = myFunction(10);//如果不用变量来接受，返回的局部变量就会销毁。


	//2.1慎用裸指针
	int*p = new int(100);
	//myFuncion02(p);//error,不允许隐式类型转化
	myFuncion02(shared_ptr<int>(p));//参数是临时的shared_ptr，用一个裸指针显式的构造
	*p = 22;//这一段内存已经被回收，临时对象传递给函数会是个局部量，函数运行完毕会释放。
	//内存对象的管理已经交给智能指针，这里不要再使用裸指针

	//不要使用裸指针初始化多个shared_ptr--会导致内存释放多次 p3,p4无关
	/*int*p2 = new int(200);
	shared_ptr<int>p3(p2);
	shared_ptr<int>p4(p2);*/
	//更改方法：
	shared_ptr<int>p3(new int(200));
	shared_ptr<int>p4(p3);//这种写法是ok的，用的是同一个控制块，指向同一块内存块
	
	//2.2慎用get()函数的返回值--返回指正对象指针的裸指针，不能删除
	shared_ptr<int>p5(new int(234));
	int *p6 = p5.get();
	//delete p;
	//不可以将其他智能指针绑定到get返回的裸指针上
	//shared_ptr<int>p7(p6);//两个智能指针没有关系，当一个释放的时候，另一个再释放一次就会出错
	//每个智能指针用裸指针创建，他们之间的引用是相互分离的。

	//3.不要把类对象指针（this）作为shared_ptr返回，改用enable_shared_from_this返回
	shared_ptr<CT>Pct1(new CT);
	//shared_ptr<CT>Pct2(Pct1);//两个强引用,使用同一个控制块
	shared_ptr<CT>pct3 = Pct1->getself();//两个智能指针之间不是使用同一个控制块，没有关系.有一种使用裸指针初始化智能指针的
	//解决办法：c++标准库中的类模板enalbe_shared_from_this，返回的是一个智能指针


	//2.4避免循环引用
	shared_ptr<A> pca(new A);
	shared_ptr<B> pcb(new B);
	pca->pm_b = pcb;//指向pcb的有两个强引用
	pcb->pm_a = pca;//指向pca的有两个强引用
	/*
	 * 最终所有的内存都没有释放，因为对象互相包含对象，每个对象的强引用都是2，都不能释放。
	 * 解决办法：
	 *	只需要将其中一个变为弱引用即可。
	 */

	//3.2移动语义
	shared_ptr<int>p7(new int(1000));
	shared_ptr<int>p8(std::move(p1));//移动构造，移动构造一个新的智能指针对象p8,p7不再指向1000，
	//引用计数还是1

	//43.优先使用make_shared，编译器有优化这个函数。
	shared_ptr<string>p9(new string("jisuan"));
	/*
	 * 分配两次内存，一次存储jisuan，一次用来存放p9的控制块
	 */
	auto p10 = make_shared<string>("jisuajis");//只分配一次内存
	system("pause");
	return 0;
}

/*
*(1)shared_ptr使用场景-
*	从函数中return shared_ptr类型指针
*	
*
*(2)智能指针是用错误分析
*	2.1慎用裸指针--使用裸指针赋值给智能指针后，内存管理的责任就交给智能指针，就不应该再使用裸指针访问内存了。
*		不用使用裸指针初始化多个shared_ptr
*	2.2慎用get()函数的返回值
*	返回智能对象的裸指针不能delete，否则会异常
*	永远不要用get()得到的裸指针来初始化另一个智能指针。
*	3.不要把类对象指针（this）作为shared_ptr返回，改用enable_shared_from_this返回
*		返回对象的this指针，使用public继承enable_shared_from_this<>，然后返回shared_from_this()
*	原理：enable_shared_from_this中有一个弱指针weak_ptr,通过这个弱指针监视this指针。
*	在我们调用shared_from_this()方法的时候，这个方法内部调用了weak_ptr的lock()方法，返回shared_ptr指针计数—+1
*	并返回shared_ptr指针
*	2.4避免循环引用
*		
*(3)性能说明
*3.1尺寸问题
*	shared_ptr，weak_ptr的尺寸都是裸指针的2倍。
*	创建控制块的时机：
*	1.make_shared,分配并初始化一个对象，返回指向此对象的shared_ptr
*	2.用裸指针来创建爱女一个shared_ptr对象时候，使用裸指针会产生多个控制块，详见2.2
*	
*3.2移动语义
*移动肯定比赋值块，复制要增加引用计数，但是移动不会增加引用计数。
*
*(4)补充说明和使用建议
*	1.分配器等问题没有讲解。
*	2.智能指针也不是刻意随心所欲的使用，谨慎使用。
*	3.优先使用make_shared，编译器有优化这个函数。
*
*/