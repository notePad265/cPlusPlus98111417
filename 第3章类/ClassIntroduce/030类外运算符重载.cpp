#include<iostream>
#include<cstdlib>
#include<string>
#include<vector>

using namespace std;

class myClass
{
public:
	int number01;
	int number02;
};

myClass operator+(myClass&myclass01,myClass&myclass02)
{
	myClass myclass03;
	myclass03.number01 = myclass01.number01 + myclass02.number01;
	myclass03.number02 = myclass01.number02 + myclass02.number02;
	return myclass03;

}
int main(void)
{
	myClass my_class01;
	my_class01.number01 = 100;
	my_class01.number02 = 200;
	myClass my_class02;
	my_class02.number01 = 1000;
	my_class02.number02 = 200;

	myClass my_class03 = operator+(my_class01, my_class02);
	

	system("pause");
	return 0;
}

/*
 * 类外运算符重载	--需要使用两个类对象引用，在类内进行运算符重载，调用的左值隐藏在this指针里面
 */