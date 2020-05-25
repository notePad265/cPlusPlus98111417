#include<iostream>
#include<cstdlib>
#include<string>
#include<vector>
#include <memory>
#include<queue>
#include<map>
#include <set>
#include <unordered_set>
using namespace std;

class A
{
public:
	A(int a) :m_i(a)
	{
		cout << "构造函数执行" << endl;
	}
	A(const A&a) :m_i(a.m_i)
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
	deque<A>myDeque;
	for (int i=0;i<5;i++)
	{
		cout << "----------begin------------" << endl;
		myDeque.push_front(A(i));
		cout << "----------end------------" << endl;

	}
	for (int i = 0; i<5; i++)
	{
		cout << "----------begin2------------" << endl;
		myDeque.push_back(A(i));
		cout << "----------end2------------" << endl;

	}
	
	for (int i=0;i<myDeque.size();i++)
	{
		cout << "下标为i="<<i<<"的值为"<< myDeque[i].m_i << endl;
		//输出地址
		printf("每个元素的地址为:%p\n", &myDeque[i]);
	}
	

	//6
	map<int, string> myMap;
	myMap.insert(make_pair(1, "老罗"));
	//方法2
	myMap.insert(pair<int, string>(2, "老白"));
	//查找
	auto iter02 = myMap.find(1);
	if (iter02!=myMap.end())//输出使用first second
	{
		cout << "找到了" << endl;
		cout << iter02->first << iter02->second << endl;
	}


	//7
	set<int>myset;
	myset.insert(1);
	myset.insert(2);
	for (auto iter03=myset.begin();iter03!=myset.end();++iter03)
	{
		cout << *iter03 << endl;
	}

	//8
	cout << "888888888888888888888" << endl;
	unordered_set<int>myUnset;
	cout << "bunket_count=" << myUnset.bucket_count() << endl;//8
	for (int i=0;i<10;i++)
	{
		myUnset.insert(i);
	}
	cout << "bunket_count=" << myUnset.bucket_count() << endl;//64
	//篮子数量不少于元素数量，查看最多篮子数量
	cout << "max_bucket_count=" << myUnset.max_bucket_count() << endl;//536870911
	
	
	system("pause");
	return 0;
}

/*
*(1)deque双端队列，可以在两端进行插入和删除 double-ended queue ,相当于数段动态数组，头部和尾部插入数据速度快。
*	总结：内部是使用分段数组的方式存储。
*(2)stack栈，只有一个开口，是先进后出，
*vector支持从中间插入和删除，虽然效率不高，stack不支持从中间插入和删除元素，只能操作栈顶的元素。
*
*(3)queue 是一个普通队列，特点是先进先出，一端入队列，一端出队列。
*
*(4)list 双向链表。，不需要元素内存联系在一起。
*	查找效率不突出，但是插入元素效率高。
*	vector随机存取元素，查找相比list快。
*
*(5)其他
*Forword-list单向链表*(受限list)，c++11新标准中引入
*	只能向一个方向插入
*
*(6)map关联容器
*内部的实现数据结构多为红黑树，
*我们向这种容器中插入数据的时候，不需要我们指定数据位置，容器会自动安排数据位置。
*(key, value),通过key找value特别快。map不允许key相同，但是multimap可以相同
*
*(7)set集合不存在键值对的说法，会自动排序，是一个集合，元素值不能重复，如果想重复，就使用multiset
*	1.插入时，因为要排序，所以插入速度可能慢，但是查找速度快。
*	一般使用树实现
*	
*(8)unordered_set unordered_multiset unordered_map  unordered_mulmap
*以往的hash_map hash_multimap  hash_set hash_multiset等都不推荐使用
*无序容器内部一般使用哈希表实现
*
*
*散列表（Hash table，也叫哈希表），是根据关键码值(Key value)而直接进行访问的数据结构。也就是说，
*它通过把关键码值映射到表中一个位置来访问记录，以加快查找的速度。这个映射函数叫做散列函数，
*存放记录的数组叫做散列表。给定表M，存在函数f(key)，对任意给定的关键字值key，
*代入函数后若能得到包含该关键字的记录在表中的地址，则称表M为哈希(Hash）表，
*函数f(key)为哈希(Hash) 函数。

2019年11月28日20:29:41
 Sunrise于东北电力大学第二教学楼1121实验室
*()()()()()()
*/