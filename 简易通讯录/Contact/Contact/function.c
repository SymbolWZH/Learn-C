#define _CRT_SECURE_NO_WARNINGS
#include "contact.h"
#include "function.h"
//void InitContact(Contact* con)静态版本
//{
//	 con->sz = 0;
//	//memset(); 内存设置
//	memset(con->data, 0, sizeof(con->data));
//}
void LoadContact(Contact* con)
{
	FILE *pf = fopen("contact.bat", "r");
	if (pf == NULL)
	{
		perror("LoadContact");
		return;
	}
	//读文件
	PeoInFo tmp = { 0 };
	while (fread(&tmp, sizeof(tmp), 1, pf))
	{
		Cheek_Capacity(con);
		con->data[con->sz] = tmp;
		con->sz++;
	}

	//关闭文件
	fclose(pf);
	pf = NULL;
}
//动态版本 初始化
void InitContact(Contact* con)
{
	con->data  = (PeoInFo*) malloc(DEAFULT_SZ * sizeof(PeoInFo));
	if (con->data == NULL)
	{
		perror("InitContact error");
		return;
	}
	con->sz = 0;
	con->capacity = DEAFULT_SZ;
	//memset(); 内存设置
	//memset(con->data, 0, sizeof(con->data));
	//加载文件
	LoadContact(con);
}
/// <summary>
/// 增加信息
/// </summary>
/// <param name="Contact* con"></param>
//void AddContact(Contact* con) //静态版本增加联系人
//{
//	if (con->sz == MAX)
//	{
//		printf("通讯录已满，无法添加\n");
//		return;
//	}
//	//增加一个人的信息
//	printf("请输入名字: ");
//	scanf("%s", con->data[con->sz].name);
//	printf("请输入性别: ");
//	scanf("%s", con->data[con->sz].gender);
//	printf("请输入年龄: ");
//	scanf("%s", con->data[con->sz].age);
//	printf("请输入电话: ");
//	scanf("%s",con->data[con->sz].phone);
//	printf("请输入地址: ");
//	scanf("%s", con->data[con->sz].address);
//
//	con->sz++;
//	printf("增加成功\n");
//}
void Cheek_Capacity(Contact* con)
{
	if (con->sz == con->capacity)
	{
		//增加容量
		PeoInFo* ptr = (PeoInFo*)realloc(con->data, (con->capacity + INT_SZ) * sizeof(PeoInFo));
		if (ptr != NULL)
		{
			con->data = ptr;
			con->capacity += INT_SZ;
			printf("增容成功\n");
		}
		else
		{
			perror("AddContact error\n");
			printf("增容失败\n");
			return;
		}
	}
}
void AddContact(Contact* con)
{
	
	Cheek_Capacity(con);
	//增加一个人的信息
	printf("请输入名字: ");
	scanf("%s", con->data[con->sz].name);
	printf("请输入性别: ");
	scanf("%s", con->data[con->sz].gender);
	printf("请输入年龄: ");
	scanf("%s", con->data[con->sz].age);
	printf("请输入电话: ");
	scanf("%s",con->data[con->sz].phone);
	printf("请输入地址: ");
	scanf("%s", con->data[con->sz].address);

	con->sz++;
	printf("增加成功\n");
}
void DestoryContact(Contact* con)
{
	free(con->data);
	con->data = NULL;
	con->sz = 0;
	con->capacity = 0;
}
void PrintContact(const Contact* con)
{
	int len = 0;
	printf("%-20s\t%-5s\t%-2s\t%-12s\t%-15s \n","名字","年龄","性别","电话","地址");
	for (len = 0; len < con->sz; len++)
	{
		printf("%-20s\t%-5s\t%-2s\t%-12s\t%-15s \n",
			con->data[len].name,
			con->data[len].gender,
			con->data[len].age,
			con->data[len].phone,
			con->data[len].address
		);
	}
}

static int FindByName( Contact* con, char Name[])
{
	int i = 0;
	for ( i = 0; i < con->sz; i++)
	{
		if (strcmp(con->data[i].name, Name) == 0)
			return i;
	}
	return -1;
}

void DelContact( Contact* con)
{
	char Search_Name[MAX_NAME];
	if (con->sz == 0)
	{
		printf("通讯录为空，无需删除\n");
		return;
	}
	printf("请输入删除人的姓名：");
	scanf("%s", Search_Name);
	//1. 查找到了
	int pos = FindByName( con, Search_Name);
	if (pos == -1)
	{
		printf("要删除的人不存在\n");
		return;
	}
	//删除
	int i = 0;
	for ( i = pos; i < con->sz; i++)
	{
		con->data[i] = con->data[i + 1];
	}
	printf("删除成功");
}

void SearchContact(Contact *con)
{
	char Search_Name[MAX_NAME];
	printf("请输入查找人的姓名：");
	scanf("%s", Search_Name);
	int pos = FindByName(con, Search_Name);
	if (pos == -1)
	{
		printf("要查找的人不存在\n");
		return;
	}
	else
	{
		printf("%-20s\t%-5s\t%-2s\t%-12s\t%-15s \n", "名字", "年龄", "性别", "电话", "地址");
			printf("%-20s\t%-5s\t%-2s\t%-12s\t%-15s\n",
				con->data[pos].name,
				con->data[pos].gender,
				con->data[pos].age,
				con->data[pos].phone,
				con->data[pos].address
			);
	}		
}


void ModifyContact(Contact* con)
{
	char Search_Name[MAX_NAME];
	printf("请输入修改人的姓名：");
	scanf("%s", Search_Name);
	int pos = FindByName(con, Search_Name);
	if (pos == -1)
	{
		printf("要修改的人不存在\n");
		return;
	}
	else
	{
		printf("查询成功\n");
		//增加一个人的信息
		printf("请输入名字: ");
		scanf("%s", con->data[pos].name);
		printf("请输入性别: ");
		scanf("%s", con->data[pos].gender);
		printf("请输入年龄: ");
		scanf("%s", con->data[pos].age);
		printf("请输入电话: ");
		scanf("%s", con->data[pos].phone);
		printf("请输入地址: ");
		scanf("%s", con->data[pos].address);

		printf("修改成功\n");

		printf("%-20s\t%-5s\t%-2s\t%-12s\t%-15s \n", "名字", "年龄", "性别", "电话", "地址");
		printf("%-20s\t%-5s\t%-2s\t%-12s\t%-15s\n",
			con->data[pos].name,
			con->data[pos].gender,
			con->data[pos].age,
			con->data[pos].phone,
			con->data[pos].address
		);
	}
}

void SaveContact(Contact* con)
{
	FILE* pf = fopen("contact.bat", "w");
	if (pf == NULL)
	{
		perror("SaveContact");
		return ;
	}
	//写文件
	int i = 0;
	for ( i = 0; i < con->sz; i++)
	{
		fwrite(con->data + i, sizeof(PeoInFo), 1, pf);
	}

	//关闭文件
	fclose(pf);
	pf = NULL;
}