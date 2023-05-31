#define _CRT_SECURE_NO_WARNINGS
#include "contact.h"
#include "function.h"
//void InitContact(Contact* con)��̬�汾
//{
//	 con->sz = 0;
//	//memset(); �ڴ�����
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
	//���ļ�
	PeoInFo tmp = { 0 };
	while (fread(&tmp, sizeof(tmp), 1, pf))
	{
		Cheek_Capacity(con);
		con->data[con->sz] = tmp;
		con->sz++;
	}

	//�ر��ļ�
	fclose(pf);
	pf = NULL;
}
//��̬�汾 ��ʼ��
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
	//memset(); �ڴ�����
	//memset(con->data, 0, sizeof(con->data));
	//�����ļ�
	LoadContact(con);
}
/// <summary>
/// ������Ϣ
/// </summary>
/// <param name="Contact* con"></param>
//void AddContact(Contact* con) //��̬�汾������ϵ��
//{
//	if (con->sz == MAX)
//	{
//		printf("ͨѶ¼�������޷����\n");
//		return;
//	}
//	//����һ���˵���Ϣ
//	printf("����������: ");
//	scanf("%s", con->data[con->sz].name);
//	printf("�������Ա�: ");
//	scanf("%s", con->data[con->sz].gender);
//	printf("����������: ");
//	scanf("%s", con->data[con->sz].age);
//	printf("������绰: ");
//	scanf("%s",con->data[con->sz].phone);
//	printf("�������ַ: ");
//	scanf("%s", con->data[con->sz].address);
//
//	con->sz++;
//	printf("���ӳɹ�\n");
//}
void Cheek_Capacity(Contact* con)
{
	if (con->sz == con->capacity)
	{
		//��������
		PeoInFo* ptr = (PeoInFo*)realloc(con->data, (con->capacity + INT_SZ) * sizeof(PeoInFo));
		if (ptr != NULL)
		{
			con->data = ptr;
			con->capacity += INT_SZ;
			printf("���ݳɹ�\n");
		}
		else
		{
			perror("AddContact error\n");
			printf("����ʧ��\n");
			return;
		}
	}
}
void AddContact(Contact* con)
{
	
	Cheek_Capacity(con);
	//����һ���˵���Ϣ
	printf("����������: ");
	scanf("%s", con->data[con->sz].name);
	printf("�������Ա�: ");
	scanf("%s", con->data[con->sz].gender);
	printf("����������: ");
	scanf("%s", con->data[con->sz].age);
	printf("������绰: ");
	scanf("%s",con->data[con->sz].phone);
	printf("�������ַ: ");
	scanf("%s", con->data[con->sz].address);

	con->sz++;
	printf("���ӳɹ�\n");
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
	printf("%-20s\t%-5s\t%-2s\t%-12s\t%-15s \n","����","����","�Ա�","�绰","��ַ");
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
		printf("ͨѶ¼Ϊ�գ�����ɾ��\n");
		return;
	}
	printf("������ɾ���˵�������");
	scanf("%s", Search_Name);
	//1. ���ҵ���
	int pos = FindByName( con, Search_Name);
	if (pos == -1)
	{
		printf("Ҫɾ�����˲�����\n");
		return;
	}
	//ɾ��
	int i = 0;
	for ( i = pos; i < con->sz; i++)
	{
		con->data[i] = con->data[i + 1];
	}
	printf("ɾ���ɹ�");
}

void SearchContact(Contact *con)
{
	char Search_Name[MAX_NAME];
	printf("����������˵�������");
	scanf("%s", Search_Name);
	int pos = FindByName(con, Search_Name);
	if (pos == -1)
	{
		printf("Ҫ���ҵ��˲�����\n");
		return;
	}
	else
	{
		printf("%-20s\t%-5s\t%-2s\t%-12s\t%-15s \n", "����", "����", "�Ա�", "�绰", "��ַ");
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
	printf("�������޸��˵�������");
	scanf("%s", Search_Name);
	int pos = FindByName(con, Search_Name);
	if (pos == -1)
	{
		printf("Ҫ�޸ĵ��˲�����\n");
		return;
	}
	else
	{
		printf("��ѯ�ɹ�\n");
		//����һ���˵���Ϣ
		printf("����������: ");
		scanf("%s", con->data[pos].name);
		printf("�������Ա�: ");
		scanf("%s", con->data[pos].gender);
		printf("����������: ");
		scanf("%s", con->data[pos].age);
		printf("������绰: ");
		scanf("%s", con->data[pos].phone);
		printf("�������ַ: ");
		scanf("%s", con->data[pos].address);

		printf("�޸ĳɹ�\n");

		printf("%-20s\t%-5s\t%-2s\t%-12s\t%-15s \n", "����", "����", "�Ա�", "�绰", "��ַ");
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
	//д�ļ�
	int i = 0;
	for ( i = 0; i < con->sz; i++)
	{
		fwrite(con->data + i, sizeof(PeoInFo), 1, pf);
	}

	//�ر��ļ�
	fclose(pf);
	pf = NULL;
}