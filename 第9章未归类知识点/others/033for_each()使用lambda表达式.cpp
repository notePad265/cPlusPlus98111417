#include<iostream>
#include<cstdlib>
#include<functional>
#include <algorithm>
#include <vector>
using namespace std;

void myFunction(int i)
{
	cout << "i=" << i << endl;
}

int main(void)
{
	vector<int>myVector = { 10,20,30,40 };
	int iSum = 0;
	for_each(myVector.begin(), myVector.end(), [&iSum](int value)
	{
		cout << "value=" << value << endl;
		iSum += value;
	});
	cout << "iSum=" << iSum << endl;//100
	system("pause");
	return 0;
}
/*
* for_each()使用lambda表达式
* (2)
* (3)
* (4)
* (5)
* (6)(7)
*/