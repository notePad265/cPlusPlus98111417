#include<iostream>
#include<cstdlib>
using namespace std;

struct Student
{
	int number;
	int age;
	string name;
};

void ModifyStudent(Student&stu)
{
	stu.number = 100000;
}

//形参加上const
void ModifyStudent02(const Student&stu)	//学习这种形参中加const的写法，这样不会修改主调函数的值
{
	//stu.number = 100000;	//不能修改
	
}


void myFunction(const int&a)
{
	return;
}



int main(void)
{

	Student student1 = { 343,12,"baiqianlong" };
	ModifyStudent(student1);
	cout << student1.number << endl;	//	是修改后的值


	//（2）实参类型可以更加灵活--例子1
	const Student&student2 = student1;
	//student2是const类型，student2不能作为ModifyStudent函数的参数，但是可以作为ModifyStudent02()函数参数
	ModifyStudent02(student2);
	//ModifyStudent(student2);

	//（2）实参类型可以更加灵活--例子2
	int aaa = 10;
	myFunction(aaa);
	myFunction(123);	//函数定义必须加上const
	
	system("pause");
	return 0;
}

/*
* (1)函数形参中带cosnt，表示函数返回值不能修改主函数中的值
* 优点：
*	（1）可以防止无意中修改形式参数导致实参的值被修改
*	（2）实参类型可以更加灵活,可以使用const或者普通变量类型来调用
*/