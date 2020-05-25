#include<iostream>
#include<cstdlib>
#include<string>
#include<vector>

using namespace std;


struct  Student
{
	int age;
	int number;
};

int main(void)
{
	vector<int>Number1 = { 100,200,300,400 };
	//定义迭代器变量
	vector<int>::iterator iter;	//	vector<int>::iterator就是变量类型，iter是变量名字。
	//每一种容器中都会定义一个iterator的成员，是固定的
	//大家在理解的时候vector<int>::iterator就是一种类型，这种类型就是迭代器类型。用这个数据类型定义一个变量就是迭代器

	//迭代器begin() end()操作
	iter = Number1.begin();	//如果容器中有元素，返回的是迭代器，指向容器中的第一个元素。
	//相当于iter指向编号为0的元素
	iter = Number1.end();	//返回的并不是最后一个元素，而是最后一个元素的下一个位置。理解为end()指向不存在的一个位置

	//如果是一个空容器，那么begin()和end()返回的就相同了
	vector<int>Number2;
	vector<int>::iterator beginIter = Number2.begin();
	vector<int>::iterator endIter = Number2.end();
	if (beginIter==endIter)	//验证了，指向同一个位置
	{
		cout << "两个迭代器指向同一个位置" << endl;
	}

	
	//遍历输出容器中的内容
	for (vector<int>::iterator iter2=Number1.begin();iter2!=Number1.end();iter2++)
	{
		cout << *iter2 << endl;	//迭代器可以当做指针来看待  100 200 300 400
	}

	//反向访问，先访问最后一个元素--反向迭代器(逆向迭代器)
	/*
	 * rbegin()返回一个反向迭代器，指向反向迭代器的第一个元素
	 * rend() 返回一个反向迭代器，指向反向迭代器的最后一个元素的下一个元素
	 * 
	 */
	//反向输出Number1中的内容
	for (vector<int>::reverse_iterator rIter3=Number1.rbegin();rIter3!=Number1.rend();rIter3++)
	{
		cout << *rIter3 << endl;	//400 300 200 100
	}

	//容器中存储结构体，并遍历输出---输出成员
	vector<Student> stuVector;
	Student myStu = { 12,1000 };
	stuVector.push_back(myStu);	//复制进容器后，就是两个无关的东西，每个都有自己的内存
	//输出结构体中的内容
	vector<Student>::iterator iter04 = stuVector.begin();
	cout << (*iter04).number << endl;
	cout << iter04->number << endl;


	//const_iterator迭代器--当容器被定义为常量容器的时候，必须使用常量迭代器
	const vector<int>Number04 = { 0,1,2,3,4 };
	for (vector<int>::const_iterator cIter = Number04.begin();cIter!=Number04.end();cIter++)
	{
		//*cIter = 12;	//不可以修改
		cout << *cIter << endl;	//可以正常读	
	}
	
	//(5)cbegin cend
	for (auto iter05=Number04.cbegin();iter05!=Number04.end();iter05++)
	{
		//*iter05 = 6;//error
		cout << *iter05 << endl;	
	}


	//(6)复习范围for语句内部就是使用迭代器实现的
	vector<int>Number06 = { 1,2,3,4,5 };
	for (auto x:Number06)
	{
		cout << x << endl;
	}
	//等价于迭代器
	for (auto beg=Number06.begin(),end1=Number06.end();beg!=end1;beg++)
	{
		cout << *beg << endl;
	}

	
	system("pause");
	return 0;
}

/*
* (1)迭代器简介
*	vector是一个容器，迭代器就是一种遍历容器内元素的数据类型。这种数据类型像指针。
*	我们理解迭代器就指向容器中的某个元素。
*
*	如vector和string中可以通过下标运算符[]来访问元素，其实在c++中很少通过下标来访问，一般通过迭代器来访问。
*	通过迭代器，我们可以读容器中的元素值，读string中的每个字符，还可以修改某个迭代器所指向的元素值。迭代器也有++  --等操作
*	尽量使用迭代器来访问迭代器中的元素。
*
*（2）容器的迭代器类型
*	每一种容器中都会定义一个iterator的成员，是固定的
*
*	迭代器begin() end() rbegin() rend()操作
*		begin() end()用于返回迭代类型，
*		1.begin()返回一个迭代器类型，理解为返回一个迭代器
*		2.end()并不指向容器中的任何元素，起的作用实际上是标记作用。
*		3.遍历输出容器中的内容for
*
*（3）迭代器运算符
*	*iter--返回迭代器iter所指向的元素的引用。必须要保证迭代器指向的是有效的元素。不能指向end()
*	++iter  iter++ 迭代器指向下一个元素。指向end()不能再++
*	--iter iter--指向容器中的上一个元素
*	iter1==iter2 != 判断两个迭代器是否相等===
*
*（4）const_iterator迭代器--一般表示常量迭代器，表示不能通过迭代器去修改容器中元素的值。迭代器本身的指向是可以改变的。
*	感觉起来有点像常量指针。
*（5）	cbegin() cend()函数 返回的都是常量迭代器，与是否是常量容器无关
*

*	
*	
*/