#pragma once
#ifndef __MYVECTOR__
#define __MYVECTOR__

//定义myvector类
template <typename T>//名字为T的模板参数，用来表示myVector所保存的运算类型
class myVector
{
public:
	//迭代器，
	typedef T* myIterator ;	//如传递过来int类型，这里为int*---这是类型成员
public:
	myVector();//构造函数
	myVector&operator=(const myVector&my_vector);//赋值运算符重载，在类内部使用模板名字不需要提供模板参数
	//myVector<T>&operator=(const myVector<T>&my_vector);//ok
public:
	myIterator mybegin();//迭代器的其实位置
	myIterator myend();//迭代器的最后一个元素的下一个位置

	void myTestFunctin();
};

//构造函数
template <typename T>
myVector<T>::myVector()
{
	
}

//使用typedef自定义了数据类型
template <typename T>
typename myVector<T>::myIterator/*函数返回值*/     myVector<T>::mybegin()
{
	
}

//使用typedef自定义了数据类型
template <typename T>
//typename用法2.访问类型成员myIterator
//typename 的用处就是显式告诉编译器myVector<T>::myIterator是一个类型
typename myVector<T>::myIterator/*函数返回值*/     myVector<T>::myend()
{
	
}

//第一个T要返回一个实例化的类模板类型，第二个T表示是一个实例化的类
template <typename T>
myVector<T>& myVector<T>::operator=(const myVector& my_vector)
{
	
}

template<typename  T>
void myVector<T>::myTestFunctin()
{
	cout<<"这是测试函数"	<<endl;
}


#endif
