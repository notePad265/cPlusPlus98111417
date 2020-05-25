#include<iostream>
#include<cstdlib>
#include<string>
#include<vector>
#include <cctype>

using namespace std;

int main(void)
{
	string str("jisuanjizuochegnyuanli");
	for (auto iter=str.begin();iter!=str.end();iter++)
	{
		*iter = std::toupper((*iter));
	}
	cout << str << endl;


	
	system("pause");
	return 0;
}

/*
* (1)用迭代器变脸string类型数据
*/