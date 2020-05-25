#pragma once
template<typename T=int,int size=10>
class myArray
{
private:
	T arr[size];
public:
	//构造函数
	myArray();
	//声明一个成员函数
	void myFunction01();
	
};

template <typename T, int size>
void myArray<T, size>::myFunction01()	//函数返回值 实例化的子类：：函数名字
{
	cout << "这是myArray的测试函数" << endl;
	cout << "size=" << size << endl;
}


//构造函数
template <typename T, int size>
myArray<T,size>::myArray()//构造函数中将每个数组元素的值都设置为0
{
	for (int i=0;i<size;i++)
	{
		arr[i] = 0;
	}
}