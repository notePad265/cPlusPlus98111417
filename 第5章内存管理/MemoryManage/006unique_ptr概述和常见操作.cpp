#include<iostream>
#include<cstdlib>
#include<string>
#include<vector>
#include <memory>

using namespace std;

class A
{
public:
	A(){}
	~A()
	{
		;
	}
};

auto myFunction()
{
	return unique_ptr<string>(new string("jisuanjiz"));//这是个右值
	//临时对象都是右值
}

int main(void)
{
	unique_ptr<int>p1;//指向一个空指针
	if (p1==nullptr)
	{
		cout << "p1是空指针" << endl;

	}
	unique_ptr<int>p2(new int(34354));//p2指向一个值为34354的int对象
	//make_unique c++14中引入，不需要指定删除器的时候选择这个
	unique_ptr<int>p3 = make_unique<int>(234);
	auto p4 = make_unique<int>(200);//p4是一个智能指针

	//2.1
	unique_ptr<string>p5(new string("jisuanjizuchengyaunli"));
	//智能指针不支持拷贝动作,也不支持赋值操作
	//unique_ptr<string> p6(p5);//error
	//unique_ptr<string>p7 = p5;//error

	//2.2移动语义
	unique_ptr<string>p8 = std::move(p5);//p5为空，p8指向原来的内存空间

	//2.3 release()释放
	unique_ptr<string>p9(p5.release());//使用p5的裸指针来初始化p9
	string *p10 = p9.release();
	delete p10;//一旦release()就需要手工释放
	
	//2.4
	unique_ptr<string>p11(new string("dsfsdf"));
	//p11.reset();//释放内存空间，
	p11.reset(p5.release());//release释放p5指向的内存空间的联系，同时p11指向这个空间
	
	//2.5nullptr
	unique_ptr<int>p12(new int(234));
	p12 = nullptr;

	//*2.6指向一个数组
	unique_ptr<int[]>pArray(new int[123]);
	pArray[0] = 0;
	pArray[1] = 0;

	unique_ptr<A[]>pAA(new A[10]);//当有自己的析构函数<>里面必须加上[]，否则会报异常

	//2.7get() 返回智能指针中返回的裸指针
	//注意得到裸指针不要释放内存空间，让智能指针自己释放更好，否则会释放2次出错
	
	

	//2.11 转换成shared_ptr类型，转换后赋值
	shared_ptr<string>p13 = myFunction();

	
	system("pause");
	return 0;
}

/*
*(1)unique_ptr独占式指针-对象的专属所有权
*同一时刻智能有一个unique_ptr指向这个对象。当unique_ptr被释放的时候，它所指向的对象也被销毁。
*	1.常规初始化
*	2.
*(2)unique_ptr常用操作
*	2.1unique_ptr不支持的操作
*	2.2 移动语义
*	2.3release(),放弃对指针指向对象的控制权，返回裸指针，同时将智能指针置空。
*		返回的裸指针可以正常使用。
*	2.4reset()
*	不带参数，释放智能指针对象所占的内存空间，并经智能指针置空
*	带参数，释放原来的内存空间，并且指向新对象
*
*	2.5 =nullptr释放智能指针所指向的内存空间，并将智能指针置空
*
*	2.6指向一个数组
	2.7get() 返回智能指针中返回的裸指针
	
*	2.8解引用 *获取智能指针的对象，直接进行操作
*	2.9swap()交换两个智能指针所指向的对象
*	2.10智能指针名字作为if判断条件
*
*	2.11 unique_ptr转换成shared_ptr类型，转换后赋值
*	shared_ptr包含一个显式的构造函数，
*	转换的过程中会创建控制块
*(3)
*
*	unique_ptr是没有控制块的
*
*/