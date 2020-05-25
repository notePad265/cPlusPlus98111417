
#include<iostream>
#include<cstdlib>
#include<string>
#include<vector>
using namespace std;

class  Human
{
private:
	int age;
	string name;
public:
	//构造函数
	Human();
	Human(int age, string name);
	//析构函数
	~Human()
	{
		cout << "Human析构函数" << endl;
	}
	//友元函数
	friend  void myFriendFunction01(const Human&temHuman) ;	//声明这个函数是Human的友元函数
};


//友元函数的实现
void myFriendFunction01(const Human&temHuman)
{
	cout << "我是Human类的友元函数" << endl;
	cout << temHuman.age << endl;//友元函数可以访问private成员
	
}


Human::Human()
{
	cout << "Human默认构造函数" << endl;
}

Human::Human(int age, string name)
{
	this->age = age;
	this->name = name;

}



int main(void)
{
	Human h1 = Human(12, "jisuanji");
	myFriendFunction01(h1);

	
	system("pause");
	return 0;

}
/*
*(1)普通函数做类友元函数，
*3种访问权限：public,protected,private.
*只要让函数成为类的友元函数，就可以访问类的所有成员（包括成员函数和成员变量（public ,protected private））都可以
*
*	在类内部声明友元函数，使用 friend 函数声明
*	在类外部定义友元函数
*	1.一般要传递类成员作为函数参数，因为只有类对象才可以访问成员属性和成员函数。
*
*	2019年11月20日16:45:35
*	 Sunrise于东北电力大学第二教学楼1121实验室
*/



