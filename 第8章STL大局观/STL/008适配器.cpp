#include<iostream>
#include<cstdlib>
#include<string>
#include<vector>
#include <memory>
#include <set>
#include <map>
#include <list>
#include <array>
#include <functional>

using namespace std;

class A
{
public:
	bool operator()(int value)
	{
		return 40 < value;
	}
};

int main(void)
{
	//*算法适配器bind
	vector<int>myVector = { 23,34,45,5,4,5453,34354 };
	//统计某个值出现的次数
	int count01 = count(myVector.begin(), myVector.end(), 34);
	cout << count01 << endl;//1

	//统计值大于40的元素，使用count_if
	A a;
	count01 = count_if(myVector.begin(), myVector.end(), a);
	cout << count01 << endl;//3
	//如果使用less中的带两个参数的来实现我们的功能--使用bind，把其中的一个参数绑定为40
	bind(less<int>(), 40, placeholders::_1);
	/*less<int>的operator()第一个参数绑定为40，这样当调用这个可调用对象时候，第二个参数就是
	 *这里placeholders::_1表示，在调用这个函数时候，被传入的第一个参数所取代
	 * 
	 */
	int count02 = count_if(myVector.begin(), myVector.end(), bind(less<int>()/*临时对象*/, 40, placeholders::_1));// placeholders::_1是一个占位符
	cout << count02 << endl;


	
	//例子
	//auto bf = bind(less<int>(), 40, placeholders::_1);
	//bf(19);//19传递给placeholders::_1


	//反向适配器
	cout << "RRRRRRRRRRRRRRRRRRRRRRRRRRRRRRRRRRRR" << endl;
	for (vector<int>::reverse_iterator riter=myVector.rbegin();riter!=myVector.rend();riter++)
	{
		cout << *riter << endl;
	}

	
	system("pause");
	return 0;
}

/*
*(1)适配器的基本概念
*把一个既有的东西，进行适当的改造，比如增加东西，或者减少东西，构成一个适配器。
*Adapter(适配器) 通过限制模型的功能以让它满足另一个模型的功能，相当于改变了接口，但实现不变。
*
*(2)适配器分类
*容器适配器
*	2.1如学习的stack是deque的限制部分功能来实现的。
*		queue也是deque的适配器。
*算法适配器
*	最典型的就是绑定器binder
*	老版本中的bind1st bind2nd在c++11中修改为bind，
*	查阅资料网站：
*	https://en.cppreference.com/w/
*	https://www.cplusplus.com/
*	
*迭代器适配器
*	反向适配器
*(3)总结
*
*
*
*/