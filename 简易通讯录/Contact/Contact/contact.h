#define _CRT_SECURE_NO_WARNINGS
#include <string.h>
#include <stdio.h>
#include <stdlib.h>

#define MAX_NAME 20
#define MAX_SEX 10	//�Ա�
#define MAX_TELE 12 //�绰
#define MAX_AGE 5 //����
#define MAX_ADDR 30 //��ַ
#define MAX 1000    //�����
#define DEAFULT_SZ 3
#define INT_SZ 2

typedef struct PeoInFo
{
	char name[MAX_NAME];
	char gender[MAX_SEX];
	char  age[MAX_AGE];
	char phone[MAX_TELE];
	char address[MAX_ADDR];
}PeoInFo;

//��̬�汾ͨѶ¼
//typedef struct Contact
//{
//	PeoInFo data[MAX];//�����ӽ������˵���Ϣ
//	int sz;//��¼���ǵ�ǰͨѶ¼����Ч��Ϣ�ĸ���
//}Contact;
//��̬�汾ͨѶ¼
typedef struct Contact
{
	PeoInFo *data;//ָ��̬����Ŀռ�
	int sz;//��¼���ǵ�ǰͨѶ¼����Ч��Ϣ�ĸ���
	int capacity;//��¼��ǰͨѶ¼���������
}Contact;

enum Option//ѡ��
{
	EXIT,
	ADD,
	DEL,
	SEARCH,
	MODIFY,
	SORT,
	PRINT
};