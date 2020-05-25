#include<iostream>
#include<cstdlib>
#include<string>
#include<vector>
using namespace std;



int main(void)
{
	vector<int> Number1{ 1,2,3,4,5 };
	auto beg = Number1.begin();
	auto end = Number1.end();
	while (beg!=end)
	{
		cout << *beg << endl;
		Number1.insert(beg, 1000);	//插入元素，第一个为元素位置,是一个迭代器位置，2为元素的值
		//这条语句会导致迭代器失效，具体哪个迭代器失效，取决于容器的实现原理，我们不去详细研究。最明智的做法就是
		//一插入数据就立刻break出来，重新建立迭代器，重新循环遍历
		break;
		++beg;
	}
	//前面插入数据，重新循环遍历，前面的迭代器已经失效
	beg = Number1.begin();
	end = Number1.end();
	while (beg != end)
	{
		cout << *beg << endl;
		++beg;
	}


	//如果不使用break方法，就每次更新end()
	auto beg2 = Number1.begin();
	int iCount = 0;
	while(beg2!=Number1.end())	//每次更新，放置end失效
	{
		beg2 = Number1.insert(beg2, iCount + 80);//查看每次插入结果
		iCount++;
		if (iCount>10)
		{
			break;
		}
		++beg2;
	}
	for(beg2=Number1.begin();beg2!=Number1.end();beg2++)
	{
		cout << *beg2 << endl;
	}



	
	system("pause");
	return 0;
}

/*
* (1)
* *()6)迭代器失效问题
*	回顾范围for循环--使用迭代器实现
*	在操作迭代器的过程中，千万不要改变vector容器的容量。不要增加或者删除vector中的元素的个数
*	增加或者删除元素，这种操作可能导致指向容器的迭代器失效。失效就表示不能再代表任何容器中的元素。一旦使用失效的东西，
*	就等于犯了园中的程序错误。在很多情况下，程序会直接崩溃。list map中都是顺序存储的，插入或删除元素都需要排序。
*	插入或者删除会导致种种迭代器失效。
*
*灾难程序演示1--
*迭代器改变了元素的个数，马上break出来
*/


