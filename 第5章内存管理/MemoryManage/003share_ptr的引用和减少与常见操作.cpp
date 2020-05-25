#include<iostream>
#include<cstdlib>
#include<string>
#include<vector>
#include <memory>

using namespace std;

class A
{
public:
	A()
	{}
	~A()
	{
		
	}
};

//void myfunction(shared_ptr<int>&myp)//使用引用，引用计数不会增加
void myfunction(shared_ptr<int>myp)
{
	cout << "智能指针做函数参数，引用计数增加" << endl;
}

shared_ptr<int> myfunction02(shared_ptr<int>&myp)
{
	cout << "智能指针做函数返回值，引用计数增加" << endl;
	return  myp;
}


void mydelete(int*p)//自己指定的删除器
{
	cout << "这是我们自己定义的删除器" << endl;
	//......
	delete p;
}

//3.函数模板封装
template<typename T>
shared_ptr<T>make_shared_array(size_t size)
{
	return shared_ptr<T>(new T[size], default_delete<T[]>());
}


int main(void)
{
	//1引用用计数的增加
	auto p1 = make_shared<int>(100);//int =100对象只有一个引用者，p1
	auto p2(p1);//两个引用者p1,p2		2 strong refs
	myfunction(p2);//把智能指针当做函数实参传递给函数 --引用计数增加1
	//作为函数实参传递，会增加引用
	auto p3 = myfunction02(p2);


	//2引用计数的减少
	auto p4 = make_shared<int>(400);//p4指向新对象，p4引用计数为1
	p1 = make_shared<int>(500);//p1引用计数减少为1

		//3.当一个shared_ptr类型的指针从1变为0，他会自动释放自己所管理（指向）的对象
	auto p5 = make_shared<int>(1000);
	auto p6 = make_shared<int>(1000);
	p6 = p5;//这是是赋值，p6的引用计数变为2， p5引用计数变为2，


	//shared_ptr返回有多少个智能指针指向某个对象
	int myCount = p6.use_count();
	cout << myCount << endl;	//2
	int myCount02 = p5.use_count();
	cout << myCount02 << endl;	//2

	//2.unique(*)是否该智能指针独占指向某个对象，返回true或者false
	shared_ptr<int> p7(new int(7));
	if (p7.unique())
	{
		cout << "unique成立，只有p7指向一块内存对象" << endl;
	}

	//reset不带参数，复位，置空
	shared_ptr<int> p8(new int(8));
	auto p9(p8);
	p8.reset();
	if (p8==nullptr)
	{
		cout << "p8指针为空" << endl;
	}
	//reset带参数new一个新对象
	shared_ptr<int> p10(new int(10));
	p10.reset(new int(11));//释放原来内存，指向新的内存

	//空指针也可以使用reset重新初始化
	shared_ptr<int>p11;
	p1.reset(new int(11));
	
	//4解引用
	shared_ptr<int>p12(new int(12));
	cout << *p12 << endl;
	
	//get()返回指针
	shared_ptr<int>p13(new int(13));
	int*p14 = p13.get();
	cout << *p14 << endl;
	//这里不要手工释放p14，它指向的内存空间归智能指针p13管理

	//swap()
	shared_ptr<string> p15(new string("aaaa"));
	shared_ptr<string> p16(new string("bbbb"));
	swap(p15, p16);
	cout << *p15 << endl;//bbbb
	cout << *p16 << endl;//aaaa

	//=nullptr
	p15 = nullptr;

	//智能指针名字作为判断条件
	if (p16)
	{
		cout << "p16指向一个对象" << endl;
		p16 = nullptr;
		
	}

	//指定自定定义的删除器
	shared_ptr<int>p17(new int(17), mydelete);
	p17 = nullptr;//调用自己写的删除器,自己需要在函数里面进行内存的释放
	//删除器可以是一个lambda表达式
	shared_ptr<int>p18(new int(18), [](int*p) {delete p; });


	//有些情况下，默认删除器处理不了---动态数组
	shared_ptr<int>p19(new int[10], [](int*p) {delete[]p; });

	//可以使用default_delete来做删除器，default_delete是标准库里面的模板类
	shared_ptr<A>pA(new A[10], std::default_delete<A[]>());//加上[]表示是删除的一个数组

	//c++17  定义数组的时候在<>中添加[]

	//shared_ptr<A[]>pA2(new A[10]);//这样c++17可以正常处理数组的释放问题


	//shared_ptr模板封装
	shared_ptr<int>p20 = make_shared_array<int>(5);
	
	system("pause");
	return 0;
}

/*
*(1)shared_ptr引用计数的增加和减少
*共享式指针--引用计数--每一个shared_ptr都指向相同的内存，最后一个指针负责释放。
*	1.引用计数的增加
*	每个shared_ptr都会记录有多少其他的shared_ptr指针指向相同的对象。
*	在如下情况下：所有指向这个兑现的shared_ptr引用计数都会增加1：
*		使用一个指针初始化另一个指针
*		把智能指针当做函数实参传递给函数（使用引用，引用计数不会增加）
*		作为函数返回值
*	2.引用计数的减少
*		1.给shared_ptr赋予新的值，让shared_ptr指向一个新的对象
*		2.局部的shared_ptr离开引用
*		3.当一个shared_ptr类型的指针从1变为0，他会自动释放自己所管理（指向）的对象
*		
*(2)shared_ptr类型指针的常用操作
*	1.shared_ptr返回有多少个智能指针指向某个对象
*	2.unique(*)是否该智能指针独占指向某个对象，返回true或者false
*	3.reset()复位，恢复，重置
*		reset()不带参数，那么指针是唯一指向的指针，那么释放指向的内存空间，并将指针置空
*				若不是指向该对象的唯一指针，那么引用该对象的引用计数会减少，同时将指针置空。
*		reset()带参数，参数一般是new出来的指针，
*			若指针是唯一指针，则释放指针指向的对象，让指针指向新对象
*			若指针不是唯一指针，则不释放指针，引用计数减少1，指向新对象
*	4.解引用，使用*或者指针指向的内容
*	5.get返回p中保存的指针，如果智能指针释放了所指向的对象，返回的裸指针也就没有意义。
*		因为有些第三方库的函数参数，有的需要一个裸指针，而不是智能指针
*	6.swap()交换两个智能指针所指向的对象
*	7.=nullptr指向空
*		1.将指针的引用计数减少1，若引用计数减少为0，则释放指针指向的对象
*		2.将智能指针置空
*	8.智能指针名字作为判断条件
*	9.指定删除器和数组问题
*		一定时机，智能指针会帮助我们删除所指向的对象，将delete运算符作为默认的资源析构方式。
*		如果我们有自己的需求，可以指定自己的删除器取代系统提供的默认删除器。
*		shared_ptr在参数中添加具体的删除器函数名字即可。
*
*	指定删除器额外说明：
*		******就算两个share_ptr指定了不同的删除器，但是只要他们执行的对象类型相同，这连个share_ptr类型指针就是同一个类型。
*			类型相同，就代表可以放到元素类型为该对象类型的容器里来。
*			
*		make_shared是提倡的方法，但是不能生成自己的删除器。
*(3)函数模板来封装shared_ptr数组
*
*
*其他：引用计数算在内的指针叫强引用。
*
*2019年11月27日13:19:27
* Sunrise于东北电力大学第二教学楼1121实验室

*/