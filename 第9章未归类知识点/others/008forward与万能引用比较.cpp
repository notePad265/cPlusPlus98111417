#include<iostream>
#include<cstdlib>

using namespace std;

template<typename T>
void myFunction(T&&tem)
{}

int main(void)
{
	int ix = 12;//ix是左值
	int&&reference = std::move(ix);//左值转换为右值绑定
	int&&reference02 = std::forward<int>(ix);//ok 可以把左值成功的转换为右值

	myFunction(ix);//i是左值，T=int&,tem=int&
	myFunction(100);//100是右值，T=int,tem=int&&

	/*std::forward<int>(ix);转换还是不转换，取决于<>里面的值，可以类比于万能引用，
	 *14行是T=int,tem=int&&类型
	 * 
	 */
	
	system("pause");
	return 0;
}
/*
* (1)std::forward用法补充
*		应用于模板转发函数	把一个值转换为原始实参的类型
* (2)
* (3)
* (4)
* (5)
* (6)(7)
*/