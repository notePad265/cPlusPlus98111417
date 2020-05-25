#include<iostream>
#include<cstdlib>
#include<string>
#include<vector>
#include <memory>

using namespace std;

class A
{
public:
	A(int a):m_i(a)
	{
		cout << "构造函数执行" << endl;
	}
	A(const A&a):m_i(a.m_i)
	{
		cout << "A的拷贝构造函数执行" << endl;
	}

	~A()
	{
		cout << "A的析构函数执行" << endl;
	}
public:
	int m_i;
};

int main(void)
{
	vector<A>myA;
	for (int i=0;i<5;i++)
	{
		cout << "----------begin-----------" << endl;
		myA.push_back(A(i));
		cout << "----------end-----------" << endl;

	}
	/*
	 * ----------begin-----------
		构造函数执行
		A的拷贝构造函数执行
		A的析构函数执行
		----------end-----------
		----------begin-----------
		构造函数执行
		A的拷贝构造函数执行
		A的析构函数执行
		A的拷贝构造函数执行
		A的析构函数执行
		----------end-----------
		----------begin-----------
		构造函数执行
		A的拷贝构造函数执行
		A的拷贝构造函数执行
		A的析构函数执行
		A的析构函数执行
		A的拷贝构造函数执行
		A的析构函数执行
		----------end-----------
		----------begin-----------
		构造函数执行
		A的拷贝构造函数执行
		A的拷贝构造函数执行
		A的拷贝构造函数执行
		A的析构函数执行
		A的析构函数执行
		A的析构函数执行
		A的拷贝构造函数执行
		A的析构函数执行
		----------end-----------
		----------begin-----------
		构造函数执行
		A的拷贝构造函数执行
		A的拷贝构造函数执行
		A的拷贝构造函数执行
		A的拷贝构造函数执行
		A的析构函数执行
		A的析构函数执行
		A的析构函数执行
		A的析构函数执行
		A的拷贝构造函数执行
		A的析构函数执行
		----------end-----------
		请按任意键继续. . .

	总结：先调用构造函数，创建一个临时地对象，然后使用拷贝构造函数，将对象拷贝进myA容器中，调用析构函数析构掉对象。
		
	 */

	//查看元素个数
	cout << myA.size() << endl;//5
	//查看容器空间个数
	cout << myA.capacity() << endl;//6

	//容器的地址和第一个元素的地址不相同
	printf("第一个元素的地址=%p\n", &myA[0]);//0073B730
	printf("容器的地址=%p\n", &myA);//0036F998

	//删除下标为2的元素，只调用一次析构函数
	int icount = 0;
	cout << "-------------" << endl;
	for (vector<A>::iterator iter=myA.begin();iter!=myA.end();iter++)
	{
		icount++;
		if (icount==2)
		{
			myA.erase(iter);
			break;
		}
	}

	cout << "****************************" << endl;
	for (vector<A>::iterator iter = myA.begin(); iter != myA.end(); iter++)
	{
		icount++;
		if (icount == 3)
		{
			myA.insert(iter, A(34));
			break;
		}
	}
	/*
	 *	 构造函数执行
		A的拷贝构造函数执行
		A的拷贝构造函数执行
		A的析构函数执行
		A的拷贝构造函数执行
		A的析构函数执行
		A的拷贝构造函数执行
		A的析构函数执行
		A的拷贝构造函数执行
		A的析构函数执行
		A的析构函数执行

	 */

	//设置容器的最大元素个数
	vector<int>myint;
	myint.reserve(10);
	cout << myint.capacity() << endl;//10
	system("pause");
	return 0;
}

/*
*(1)vector容器实现类似于一个栈，向顶部增加元素和删除元素都很快，删除中间的元素很慢，查找的速度也不会太快
*
*	vector容器内存是挨着的，vector有一个“空间”的概念，每一个空间可以装一个元素。
*	当只有一个元素的时候，只有一个空间。当再插入一个元素的时候，找一段可以装两个元素的“空间”，
*	将原来的对象在新空间构造，析构掉老空间的对象。所以插入元素会调用多次构造函数和析构函数。
*	但是容器观测到你多次插入元素，容器会给你多分配内存，以便不用每次新分配内存。
*
*	也就是说，vector容器插入元素是不断寻找新的内存空间，析构和构造的过程。
*
*为什么要析构老元素，构造新元素？
*	主要的原因是这种容器的实现要求内存是连续的。
*	
*(2)我们使用vector，一般需要提前知道元素不超过多少个，把capacity设置为最大值
*
*(3)
*
*
*/