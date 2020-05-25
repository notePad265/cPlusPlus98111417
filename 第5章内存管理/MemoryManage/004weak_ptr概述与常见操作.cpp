#include<iostream>
#include<cstdlib>
#include<string>
#include<vector>
#include <memory>

using namespace std;


int main(void)
{
	//weak_ptr一般是使用shared_ptr来创建爱女
	auto p1 = make_shared < int>(100);
	weak_ptr<int>p2Weak(p1);//p2Weak是弱引用，强引用计数不会改变，一个强引用，一个弱引用指向100
	//只有强引用决定对象的生存期。若引用对对象生存期没有影响
	weak_ptr<int>p3Weak = p2Weak;//使用一个弱引用给另一个弱引用赋值。

	//lock()的功能：检查weak_ptr所指向的对象是否存在，如果存在，就返回一个指向该对象的shared_ptr指针，
	//如果不存在,返回的指针指向为空
	//p1.reset();//释放该对象
	auto p4shared_ptr = p2Weak.lock();//p4shared_ptr是一个返回的shred_ptr,强引用计数+1
	

	//常见函数用法
	int count = p2Weak.use_count();
	cout << count << endl;	//2

	//expired--过期判断
	//指向100的两个强引用都设置为过期
	p1.reset();
	p4shared_ptr.reset();
	if (p2Weak.expired())//返回值为true
	{
		cout << "对象已经过期" << endl;
	}

	//(4)尺寸问题
	weak_ptr<int>p5_weak;
	int*p6 = nullptr;
	int length1 = sizeof(p5_weak);	//8
	int length2 = sizeof(p6);	//4
	cout << "length1=" << length1 << endl;
	cout << "length2=" << length2 << endl;

	system("pause");
	return 0;
}

/*
*(1)weak_ptr概述
*用于辅助shared_ptr指针进行工作
*强指针strong--shared_ptr
*弱指针weak--weak_ptr
*weak_ptr也是一个类模板，这个指针指向一个有shared_ptr管理的对象，但是weak_ptr不控制生存周期。
*换句话说，将weak_ptr绑定到shared_ptr上不会改变shared_ptr对象的引用计数。
*当shared_ptr需要释放所指定对象时候，不管是否有weak_ptr是否指向该对象。
*
*weak_ptr为什么需要引入？？？
*weak--能力弱，也叫弱引用，弱共享
*作用：理解为监视shared_ptr的声明周期，是对shared_ptr的一种扩充。
*weak_ptr不是一种独立的智能指针，不能用来操作所指向的资源，所以它看起来是shared_ptr的一个助手
*weak_ptr用于监视它所指向的对象是否存在。
*
*
*(2)weak_ptr的创建、
*使用shared_ptr初始化weak_ptr
*
*(3)weak_ptr用法
*	可以使用weak_ptr为shared_ptr赋值
*	
*	1.use_count() 获取该弱指针共享对象的其他shared_ptr的数量，或者说获取当前观测支援的强引用数量。
*	2.expired()是否过期的意思，弱引用指针的use_count()==0，返回true，换句话说，这个函数用于判断所观测的资源是否已经被释放。
*(4)尺寸问题
*	weak_ptr<int>pw
*	weak_+ptr和shared_ptr尺寸一样大，是裸指针的两倍
*	一个智能指针包含两个指针，（1）第一个指针指向智能指针的对象
*		（2）第二个指针指向“智能指针控制块”的数据结构，控制块里面有“强引用计数”，“弱引用计数”“其他数据等如内存分配器，自定义删除器等”
*	详细见图
*		
*
*2019年11月27日17:07:39
* Sunrise于东北电力大学第二教学楼1121实验室
*/