#include<iostream>
#include<iostream>
#include<cstdlib>
#include<functional>
#include <vector>
#include <algorithm>
#include <ctime>
using namespace std;

//全局变量，每个元素都是function，每个元素都是参数是int，返回值是bool类型
std::vector<std::function<bool(int)>> gv;

void myFunction()
{
	srand((unsigned)time(nullptr));
	int temValue = rand() % 6;//产生一个0-5之间的种子
	gv.push_back(
		[&](int tv)//这里改为按值捕获可以解决=
	{
		if (tv%temValue == 0)//如果tv是temValue的倍数
		{
			return true;

		}
		return false;
	}
	);//把lambda表达式插入vector容器中
}

int main(void)
{
	myFunction();
	cout << gv[0](10) << endl;
	/*
	 * gv[0](10)调用的时候，temValue是个局部变量已经超出作用域了，这里调用有问题
	 * temValue的内存空间已经释放了。解决办法，改为按值捕获。
	 */
	
	system("pause");
	return 0;
}
/*
* (1)lambda常见陷阱_捕获列表中的&_局部变量超出作用域
* 捕获外部区域中的所有变量，并作为引用在lambda表达式中使用。
* 按照引用这种捕获方式，会导致lambda包含绑定到局部变量中的引用。
* (2)
* (3)
* (4)
* (5)
* (6)(7)
*/