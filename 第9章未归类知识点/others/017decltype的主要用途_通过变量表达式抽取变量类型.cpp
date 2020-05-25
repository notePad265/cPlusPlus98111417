#include<iostream>
#include<cstdlib>
#include <vector>

using namespace std;


int main(void)
{
	//2.2decltype的主要用途_通过变量表达式抽取变量类型
	vector<int> myV;
	myV.push_back(1);
	myV.push_back(2);
	myV.push_back(3);
	vector<int>::size_type mySize = myV.size();
	cout << mySize << endl;//3
	decltype(myV)::size_type mysize02 = mySize;//抽取myV的类型，
	cout << mysize02 << endl;//3

	typedef decltype(sizeof(0)) size__t;//等价与size__t是int类型
	/*
	 * typedef decltype(sizeof(int)) size__t
	 * typedef unsigned int size__t
	 */

	system("pause");
	return 0;
}
/*
* 2.2decltype的主要用途_通过变量表达式抽取变量类型
*
*/