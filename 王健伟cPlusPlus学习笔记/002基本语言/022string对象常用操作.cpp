#include<iostream>
#include<cstdlib>
#include<string>
using namespace std;

int main(void)
{
	string s1;
	if(s1.empty())	//	判断字符串为空
	{
		cout << "s1字符串为空" << endl;
	}


	string s2 = "我爱中国";
	cout << s1.size() << endl;	//0
	cout << s2.size() << endl;	//8
	cout << s2.length() << endl;	//8
	//3
	string s3 = "jisuanjizuchengyaun";
	if (s3.size()>3)
	{
		cout << s3[4] << endl;
		s3[4] = '*';
		cout << s3[4] << endl;	//能修改成功
	}

	//4字符串链接
	string s4 = "12345";
	string s5 = "abcdef";
	string s6 = s4 + s5;
	cout << s6 << endl;	//12345abcdef

	//5字符串赋值
	string s7 = "123";
	string s8 = "abc";
	s7 = s8;
	cout << s7 << endl;	//abc

	//6判断字符串是否相等
	if (s7==s8)
	{
		cout << "s7==s8" << endl;	//成立。前面进行赋值了
	}

	//c语言中的老代码精华藏需要这么转换
	string  s9 = "abcde";
	string s10 = "abCde";
	const char*p = s10.c_str();	//p指向字符串的起始位置的指针
	char str[128]={0};
	strcpy_s(str, sizeof(str), p);
	cout << str << endl;	//abCde

	//用c语言类型的字符数组转换为c++语言的字符串方式
	string s11(str);


	//9读写string对象
	/*string s12;
	cin >> s12;
	cout << s12 << endl;*/

	//10.字面值和string相加
	string s13 = "123";
	string s14 = "abc";
	string s15 = s13 + " and " + s14;
	cout << "s15=" << s15 << endl;
	//string s16 = "fsdf" + "fsdffsdf";	//	语法上不允许两个字面量相加，因为不知道转换成什么样的默认类型，必须有一个有类型，
	//左侧结合性。
	string s16 = "fsdf" + s15 + "fsdffsdf";	//ok
	//string s16 = "fsdf" + "fsdffsdf" + s15;	//error


	//striing 中的范围for
	string s17 = "jisuanjizuchengyaunli";
	for (auto x:s17)	//auto变量类型自动推断
	{
		cout << x << endl;	//输出每一个字符，然后换行
	}
	for(auto&c:s17)
	{
		c = toupper(c);	//函数把小写字母转换成大写
	}
	cout << s17 << endl;
	system("pause");
	return 0;
}

/*
* (1)string对象的常用操作
*		1.判断是否为空.empty()
*		2.size() length() 返回字节，字符数量，代表字符串的长度
*		3.s[n] 返回s中的编号为n的字符，位置从0开始编号，到size()-1,如果超过了范围的内容，
*			或者本身是一个空串，用s[n]去访问，产生不可预测的结果
*		4.s1+s2表示字符串链接，返回连接后的结果，其实就是一个新的string对象
*		5.s1=s2 字符串对象的赋值，用s2内容的代替s1中的内容
*		6.s1==s2 判断两个字符串是否相等，并且字符串对大小写字符敏感（大写字符和小写字符是不同的字符）
*		7.s1!=s2 s1不等于 s2
*		8.s.c_str()返回一个字符串s中的内容指针。返回一个指向c字符串的指针常量，也就是以\0结尾的。
*			这个函数的引入是为了与c语言兼容，在c语言中没有string类型，所以我们同过string类对象的c_str()
*			成员函数把string对象转换成c语言中的字符串样式。
*			c---const
*
*		9.读写string对象
*		10.字面值和string相加
*
*		11.范围for语句针对string使用，c++11中提供了范围for语句
*			遍历访问范围for中的所有元素
*		
*/