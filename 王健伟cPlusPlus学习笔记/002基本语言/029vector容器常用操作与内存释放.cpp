#include<iostream>
#include<cstdlib>
#include<string>
#include<vector>
//用于保存配置文件的结构体
struct Config
{
	char IterName[128];	//条目名字
	char ItemContent[128];	//条目内容
};
using namespace std;


//根据item查找content的内容
char* getInfo(vector<Config*>&conflist,char*pItem)
{
	for (auto pos=conflist.begin();pos!=conflist.end();pos++)
	{
		if (strcmp((*pos)->IterName,pItem)==0)
		{
			return (*pos)->ItemContent;
		}
	}
	return nullptr;
}


int main(void)
{
	Config*pConfig = new Config;
	strcpy_s(pConfig->IterName, sizeof(pConfig->IterName), "ServerName");
	strcpy_s(pConfig->ItemContent, sizeof(pConfig->ItemContent), "1区");

	Config*pConfig2 = new Config;
	strcpy_s(pConfig2->IterName, sizeof(pConfig2->IterName), "ServerID");
	strcpy_s(pConfig2->ItemContent, sizeof(pConfig2->ItemContent), "100000");

	vector<Config*>ConfList;
	ConfList.push_back(pConfig);	//元素0
	ConfList.push_back(pConfig2);	//元素1
	/*
	 * 注意：容器中存储指针类型，那么数据只存在一份，但是外面使用new创建的指针对象（pConfig pConfig2）和容器中
	 * 的元素0 元素1都是指向同一快内存空间。也就是说，两个指针指向同一块内存空间。
	 */
	//怎么根据item返回对应的content内容
	char*p_Tem = getInfo(ConfList, "ServerName");
	if (p_Tem!=nullptr)
	{
		cout << p_Tem << endl;	//1区域
	}

	//我们需要自己释放内存，自己new的就要自己释放，否则就会造成内存泄漏
	//每次遍历一次，就把容器中元素指向的内存空间释放但是容器中的元素不释放。
	for (vector<Config*>::iterator pos=ConfList.begin();pos!=ConfList.end();pos++)	
	{
		delete(*pos);//	容器中的元素本来就指针，pos相当于二级指针,所以*pos才是那个指针
	}
	ConfList.clear();	//这一操作可以没有，系统系统在运行结束自动清空容器
	
	system("pause");
	return 0;
}

/*
* (1)实践程序
* ServerName=1区 服务器名字
* ServerID=1000 服务器ID
*
*  Sunrise于东北电力大学第二教学楼1121实验室
*  2019年11月14日12:07:53
*  
*/