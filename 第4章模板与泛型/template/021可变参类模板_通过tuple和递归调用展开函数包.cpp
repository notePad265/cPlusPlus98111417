#include<iostream>
#include<cstdlib>
#include<string>
#include<vector>
#include<queue>
#include<functional>

using namespace std;

//mycount用于统计，myMaxCount表示参数数量
template<int mycount,int myMaxCount,typename ...T>
class myclass
{
public:
	static void myFunction02(const tuple<T...>&t)
	{
		cout << "value="<<get<mycount>(t) << endl;
		myclass<mycount + 1, myMaxCount, T...>::myFunction02(t);
		
	}
};


//特化版本用于结束调用
template<int myMaxCount,typename ...T>
class myclass<myMaxCount,myMaxCount,T...>
{
public:
	static void  myFunction02(const tuple<T...>&t)
	{
		;
	}
};

template<typename ...T>
void myFunction(const tuple<T...>&t)//可变参函数模板
{
	myclass<0, sizeof...(T), T...>::myFunction02(t);
}


int main(void)
{
	//元组示意
	tuple<float, int, int>mytuple(12.34f, 100, 1);
	cout << get<0>(mytuple) << endl;
	cout << get<1>(mytuple) << endl;


	myFunction(mytuple);
	system("pause");
	return 0;
}

/*
*(1)通过tuple和递归调用展开函数包--需要些类的特化版本，有一定的难度。
*有一个从0开始的计数器，每次处理一个参数，计数器+1，一直到所有参数处理完毕。
*最后使用使用一个模板偏特化，作为递归调用结束。
*
*(2)
12.34
100
value=12.34
value=100
value=1

*
*(3)总结
*	获取参数包里面的参数方式有很多种，但是一般来讲都离不开递归这种手段。
*	
*
*
*/