#define _CRT_SECURE_NO_WARNINGS
#include<string.h>
#include<stdio.h>
#include <stdlib.h>
/// <summary>
/// ��ʼ��ͨѶ¼
/// </summary>
/// <param name="con"></param>
void InitContact( Contact* con);


/// <summary>
/// ������Ϣ
/// </summary>
/// <param name="Contact* con"></param>
void AddContact(Contact* con);

/// <summary>
/// ��ӡ��Ϣ
/// </summary>
/// <param name="con"></param>
void PrintContact( Contact* con);

/// <summary>
/// ɾ����Ϣ
/// </summary>
/// <param name="Contact* con"></param>
void DelContact(const Contact* con);


/// <summary>
/// ɾ����ѯ��Ϣ
/// </summary>
/// <param name="Contact* con"></param>
static int FindByName( Contact* con, char Name[]);

/// <summary>
/// ��ѯ��Ϣ
/// </summary>
/// <param name="Contact* con"></param>
void SearchContact( Contact* con);


/// <summary>
/// ��ѯ��Ϣ
/// </summary>
/// <param name="Contact* con"></param>
void ModifyContact( Contact* con);

///������Ϣ���ļ�
void SaveContact(Contact* con);
///����ͨѶ¼
void DestoryContact(Contact* con);
//�������
void Cheek_Capacity(Contact* con);
//�������ݵ�ͨѶ¼
void LoadContact(Contact* con);