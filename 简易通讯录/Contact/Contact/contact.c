#define _CRT_SECURE_NO_WARNINGS
#include "contact.h"
#include "function.h"
void menu()
{
	printf("************************************\n");
	printf("*******  1. add    2. del     ******\n");
	printf("*******  3. search 4. modify  ******\n");
	printf("*******  5. sort   6. print   ******\n");
	printf("*******  0. exit              ******\n");
	printf("************************************\n");
	printf("请输入选项：\n");
}
int main()
{
	int input;
	// 创建通讯录
	Contact con;//通讯录
	//初始化通讯录函数
	InitContact(&con);
	//当前通讯录总共有几个元素
	do
	{
		menu();
		scanf("%d", &input);
		switch (input)
		{
			case ADD:    //增加人的信息
				AddContact(&con);
				break;
			case DEL:    //删除人的信息
				DelContact(&con);
				break;
			case SEARCH: //查询人的信息
				SearchContact(&con);
				break;
			case MODIFY: //修改人的信息
				ModifyContact(&con);
				break;
			case SORT:   //人的信息
				break;
			case PRINT:  //打印人的信息
				PrintContact(&con);
				break;
			case EXIT:  
				//保存信息到文件
				SaveContact(&con);
				//销毁通讯录
				DestoryContact(&con);
				printf("退出通讯录\n");
				break;   
			default:
				printf("选择错误，请重新选择\n");
				break;
		}
	} while (input);
}