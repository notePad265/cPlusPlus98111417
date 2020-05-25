#include<iostream>
#include<cstdlib>
#include<string>
#include<vector>
#include <memory>
#include <set>
#include <map>
#include <list>
#include <array>

using namespace std;

class A
{
public:
	A()
	{
	;
	}

public:
	int m_i;

};

int main(void)
{
	char*p1 = new char[10];
	

	memset(p1, 0, 10);
	delete[]p1;
	/*演示释放1个字节：
	 *
	 * 一块内存的回收影响范围不仅仅是分配大小的内存，前后内存都会受影响。
	 * 分配内存的时候有进行进行内存管理的占用的内存，如记录内存的大小等占用的内存，也需要释放。
	 */


	int*p2 = new int(100);
	delete p2;
	/*跟踪调试，发现在分配内存保存数据（0x64）前面有04记录分配内存的大小。
	 *  0x0038CFC4  00 00 00 00 01 00 00 00 04 00 00 00 44 00 00 00 fd fd fd fd  ............D...????
		0x0038CFD8  64 00 00 00 fd fd fd fd 52 78 b2 55 08 94 00 03 90 00 36 00  d...????Rx?U.?..?.6.

		分配内存不是简单的分配4个字节，在这4个字节周围，编译器做了很多处理，比如记录分配的字节数等。
	详细见malloc分配内存示意图
		分配内存时候为了记录和管理内存，额外多分配了不少内存，造成浪费，尤其是频繁申请小块内存，造成的浪费更加明显。
	 */

	
	system("pause");
	return 0;
}

/*
*(1)new内存分配细节探秘
*2019年11月29日17:12:35
* Sunrise于东北电力大学第二教学楼1121实验室


*(3)
*
*
*/