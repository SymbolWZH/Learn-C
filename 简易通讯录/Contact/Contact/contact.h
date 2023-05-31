#define _CRT_SECURE_NO_WARNINGS
#include <string.h>
#include <stdio.h>
#include <stdlib.h>

#define MAX_NAME 20
#define MAX_SEX 10	//性别
#define MAX_TELE 12 //电话
#define MAX_AGE 5 //年龄
#define MAX_ADDR 30 //地址
#define MAX 1000    //最大数
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

//静态版本通讯录
//typedef struct Contact
//{
//	PeoInFo data[MAX];//存放添加进来的人的信息
//	int sz;//记录的是当前通讯录中有效信息的个数
//}Contact;
//动态版本通讯录
typedef struct Contact
{
	PeoInFo *data;//指向动态申请的空间
	int sz;//记录的是当前通讯录中有效信息的个数
	int capacity;//记录当前通讯录的最大容量
}Contact;

enum Option//选项
{
	EXIT,
	ADD,
	DEL,
	SEARCH,
	MODIFY,
	SORT,
	PRINT
};