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
	printf("������ѡ�\n");
}
int main()
{
	int input;
	// ����ͨѶ¼
	Contact con;//ͨѶ¼
	//��ʼ��ͨѶ¼����
	InitContact(&con);
	//��ǰͨѶ¼�ܹ��м���Ԫ��
	do
	{
		menu();
		scanf("%d", &input);
		switch (input)
		{
			case ADD:    //�����˵���Ϣ
				AddContact(&con);
				break;
			case DEL:    //ɾ���˵���Ϣ
				DelContact(&con);
				break;
			case SEARCH: //��ѯ�˵���Ϣ
				SearchContact(&con);
				break;
			case MODIFY: //�޸��˵���Ϣ
				ModifyContact(&con);
				break;
			case SORT:   //�˵���Ϣ
				break;
			case PRINT:  //��ӡ�˵���Ϣ
				PrintContact(&con);
				break;
			case EXIT:  
				//������Ϣ���ļ�
				SaveContact(&con);
				//����ͨѶ¼
				DestoryContact(&con);
				printf("�˳�ͨѶ¼\n");
				break;   
			default:
				printf("ѡ�����������ѡ��\n");
				break;
		}
	} while (input);
}