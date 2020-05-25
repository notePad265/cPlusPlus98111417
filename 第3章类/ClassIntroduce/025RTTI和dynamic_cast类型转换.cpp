#include<iostream>
#include<cstdlib>
#include<string>

using namespace std;

class  Human
{
public:
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

	virtual void eat()
	{
		cout << "Human eat()函数" << endl;
	}
};

class Man :public Human
{
public:
	Man();
	~Man()
	{
		cout << "man的析构函数执行" << endl;
	}
	virtual void eat()
	{
		cout << "Man eat()函数" << endl;
	}
public:

};

class Woman :public Human
{
public:
	Woman();
public:
	~Woman()
	{
		cout << "Woman析构函数执行" << endl;
	}

	virtual void eat()
	{
		cout << "woman eat()函数" << endl;
	}

};

Woman::Woman()
{
	cout << "这是woman的构造函数" << endl;
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

Man::Man()
{
	cout << "Man类的默认构造函数" << endl;
}


int main(void)
{
	//(1)运行时类型识别
	Human *p_human = new Man;
	Human&q = *p_human;//*p_human表示指针所指向的对象。
	q.age = 12;
	q.name = "jisuanji";
	q.eat();

	//怎么讲父类指针转换为子类对象
	Man *m1 = (Man*)(p_human);//c语言强制类型转换，可以成功--但是要求明确知道是什么类型才安全，否则不安全
	m1->eat();//调用Man中的eat()函数
	Woman *w1 = (Woman*)p_human;	//转换为其他类型也成功，不安全
	
	//dynamic_cast可以帮助我们做安全检查
	Man*m2 = dynamic_cast<Man*>(p_human);	//强父类指针转换为子类类型指针
	m2->eat();//执行man类的eat()函数
	//对于引用，如果用dynamic_cast转换失败，系统会抛出一个std::bad_cast异常，
	Human&m_reference = *p_human;
	try
	{
		Man m3 = dynamic_cast<Man&>(m_reference);	//成功
		//(2)typeid运算符
		cout << typeid(m_reference).name() << endl;	//class Man
		cout << typeid(m3).name() << endl;		//class Man
		
	}

	catch (std::bad_cast)
	{
		cout << "std::bad_cast" << endl;
	}

	Human h1 = Human(12, "jisuanjiii");
	cout << typeid(h1).name() << endl;	//class Human
	int a = 10;
	cout << typeid(a).name() << endl;	//int
	cout << typeid("jisuanjizuchengyuanli").name() << endl;	//char const [22]


	//1.两个指针定义的类型相同
	Human*p_human02 = new Woman;
	if (typeid(p_human)==typeid(p_human02))
	{
		cout << "p_human和p_human02是同一种指针类型" << endl;	//成立，和我们预料的不同
		/*比较的时候是比较的定义的类型，而不是new后面出的类型，这也可以验证前面的RTTI类型识别
		 */	
	}

	//我们如果想比较new出来的对象的实际类型进行比较，该怎么做？
	Woman*p_woman = new Woman;
	Human*p_human03 = p_woman;	//
	/*
	 * p_woman对象里面有一个我们看不见的指针，指向的是这个对象所在类的Woman的虚函数表。
	 * 虚函数表的第一列是type_info()类对象，确定P-woman指向哪一个对象，去调用对应的虚函数。
	 */
	if (typeid(*p_human)==typeid(*p_human03))//不成立，实际指向的对象类型比较
	{
		cout << "p_human和p_human03对象类型相同" << endl;

	}
	/*	基类中必须有虚函数，否则上边条件不成立
	 * 总结：比较的时候要使用typeid(*指针)进行实际对象的比较，而不要进行定义指针类型的比较。
	 * 切记：只有当基类中有虚函数的时候，编译器才会对typeid()的表达式求值，否则某个类型不含有虚函数
	 *	则typeid()反悔的是静态类型（定义时候的类型）,既然是定义的类型，编译器就不需要对表达式求只也知道表达式的类型。
	 *	
	 */

	//type_info类型
	int aa = 11;
	const type_info&aa_reference = typeid(aa);//返回值是type_info静态类型
	cout << aa_reference.name() << endl;
	
	
	system("pause");
	return 0;
}

/*
 *(1)Rtti runtime type identification	运行时类型识别
 *通过运行时类型识别，程序能够使用基类的指针或者引用来所指对象的实际派生类型。
 *RTTI我们看成一种系统提供给我们的能力，或者一种功能，这种功能是通过两个运算符来实现：
 *	1.dynamic_cast运算符：能够将基类的指针或者引用安全的转化为派生类的指针或者引用。
 *	2.typeid运算符，返回指针或者引用所指对象的实际类型。
 *	注意：要想两个运算符正常工作，在基类中必须有一个虚函数。不然的话，两个运算符工作的结果就和预测的不同。
 *		只有虚函数存在，这两个运算符才会使用指针或者引用所绑定的动态类型。
 *		否则，编译的时候就确定了调用哪个类型。
 *(2)typeid(类型(指针，引用))运算符
 *	也可以是typeid(表达式)
 *	拿到对象信息，typeid就会返回一个常量对象的引用，这个常量对象是一个标准库类型，type_info(类、类类型)
 *	主要方法：
 *		1.  typeid().name()返回常量对象的名字
 *		2.
 *	主要用于：用于比较两个指针是否指向同意类型的对象
 *		1.两个指针定义的类型相同
 *	
 *(3)RTTI与虚函数表
 *C++中如果含所有虚函数，编译器就会对该类产生一个虚函数表。
 *虚函数里面有很多项，每一项都是一个指针，每个指针指向这个类里面的虚函数的入口地址（一个类有多个虚函数）
 *虚函数表项里面，第一个表项很特殊，它指向的不是虚函数的入口地址，它指向的实际上是这个类的type_info()对象。
 *
 *
 *
 * 每个类对象隐藏一个指向类的虚函数表的指针。
 * 虚函数表第一列是type_info()类型，用于说明实际的类对象类型。调用子类或者父类的函数（虚函数）
 */