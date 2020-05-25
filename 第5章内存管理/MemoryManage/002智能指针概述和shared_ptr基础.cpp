#include<iostream>
#include<cstdlib>
#include<string>
#include<vector>
#include <memory>

using namespace std;

shared_ptr<int> testFunction(int value)
{
	//return new int();//error，不可以将new得到的int*类型转换为shared_ptr
	return shared_ptr<int>(new int(value));//OK，强制类型转换
}

int main(void)
{
	//shared_ptr指针用法
	shared_ptr<int>p1(new int(100));//p1指向值为100的int类型内存空间
									//shared_ptr<int>p2 = new int(100);//error智能指针是explicit,不可以进行隐式类型转换，
									//=一般用于隐式类型zhuanhaun


									//返回值是shared_ptr
	shared_ptr<int> p2 = testFunction(234);

	//裸指针可以初始化shared_ptr,但是不推荐
	string* s1 = new string("23432434");
	shared_ptr<string>s2(s1);
	//建议使用
	shared_ptr<string>s3(new string("sdfdsf"));

	//空的shared_ptr指针
	shared_ptr<int>p3;//指向int的智能指针，但还是目前为空==nullptr

					  //(3)make_shared
	shared_ptr<int>p4 = make_shared<int>(1345);//shared_ptr指向一个值为100的整形内存空间。
	shared_ptr<string>p5 = make_shared<string>(5, 'a');//p5指向aaaaa的字符串内存空间
	shared_ptr<int>p6 = make_shared<int>();//p6指向一段内存空间int=0
	p6 = make_shared<int>(1000);
	/*p6指向一段新的int，先释放指向0的内存空间，然后指向int值为1000的内存空间。
	*
	*/

	system("pause");
	return 0;
}

/*
*ptr==pointer的缩写
*
*(1)智能指针综述
*常见错误
*if()
*{
*	.....
*	return ;
*}
*delete p；//执行不到这里
*
*多个指针指向同一块内存空间，释放内存只能释放一次。
*所以new delete的写法要十分小心，要小小早早释放，也小心忘记释放。
*
*裸指针：直接new返回的指针。没有经过任何包装，这种指针强大，灵活，但是开发者要全程维护。
*引入智能指针解决裸指针的各种问题。
*智能指针：就理解成对裸指针进行了包装，包装后：
*最突出优点：智能指针“能够自动释放所指向的对象内存。”不用担心new出来的内存忘记释放。
*
*建议：优先使用智能指针，使用智能指针的程序更容易编写和调试。
*
*c++中有4种智能指针：
*auto_ptr（c++98）
*unique_ptr(c++11)
*shared_ptr(c++11)
*weak_ptr(c++11)
*帮助我们进行动态分配对象的生命周期的管理，能够有效防止内存泄漏。
*
*c++11标准中反对使用auto_ptr;目前auto——ptr已经完全被unique_ptr取代。
*c++11中的3种智能指针都是类模板，我们可以将new获得的地址赋值给他们
*重点是shared_ptr：共享式指针--多个指针指向同一个对象，最后一个指针被销毁时候，释放对象的内存空间。
*weak_ptr是辅助shared_ptr;
*unique_ptr独占式指针，在一个时间内，只有一个指针能够指向该对象，该对象的所有权是可以移交出去的。
*
*你忘记delete的时候，智能指针帮你delete，或者说，你不需要手动delete了。
*
*(2)shared_ptr基础
*共享所有权--不是被一个shared_ptr拥有，而是多个shared_ptr之间相互协作。
*工作原理：引用计数，每个shared_ptr都指向相同的内存，所以最后一个指向不需要指向该对象的时候。
*那么最后一个share_ptr去释放该对象。
*
*最后一个指向对象的shared_ptr在什么情况下释放该对象（shared_ptr所指向的对象）？
*	1.shared_ptr声明周期结束，被析构时候
*	2.这个shared_ptr指向其他对象的时候。
*	这种操作类似于java中的垃圾回收机制。
*是类模板,<>里面就是指针可以指向的类型，后边再跟智能指针名字
*格式：shared_ptr<指向的类型>智能指针名字
*
*
*(3)make_shared函数，标准库里面的函数模板，安全高效分配和使用shared_ptr
*能够在堆中分配内存并初始化一个对象，然后返回指向此对象的shared_ptr
*make_shared不能自定义删除器，因此需要自定义删除器的时候，不能使用。
* Sunrise于东北电力大学第二教学楼1121实验室
* 2019年11月26日22:03:05
*
*
*/