#include<iostream>
#include<cstdlib>
#include <functional>

using namespace std;

//普通函数可调用对象
void myFunciton(int value)
{
	cout << "myFunciton函数执行了" << endl;
}

class CB
{
private:
	std::function<void()>fcallBack;
	
public:
	CB(const std::function<void()>&f):fcallBack(f)//引用
	{
		int i = 1;
	}
	//调用回调函数的成员函数
	void runCallBack(void)
	{
		fcallBack();
	}
};

class CT
{
public:
	void operator()(void)//重载函数调用运算符
	{
		cout << "CT类operator函数执行" << endl;
	}
};
int main(void)
{
	//小案例演示
	CT ct;//可调用对象
	CB cb(ct);//cb需要可调用对象做参数来构造，ct因为有operator()所以可以转换为std::function<void()>&对象
	cb.runCallBack();//调用CT中的operator()函数

	system("pause");
	return 0;
}
/*
* (1)function()可调用对象包装器_范例演示1
* 
	CT类operator函数执行
	请按任意键继续. . .

*
*
*/