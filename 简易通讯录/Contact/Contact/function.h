#define _CRT_SECURE_NO_WARNINGS
#include<string.h>
#include<stdio.h>
#include <stdlib.h>
/// <summary>
/// 初始化通讯录
/// </summary>
/// <param name="con"></param>
void InitContact( Contact* con);


/// <summary>
/// 增加信息
/// </summary>
/// <param name="Contact* con"></param>
void AddContact(Contact* con);

/// <summary>
/// 打印信息
/// </summary>
/// <param name="con"></param>
void PrintContact( Contact* con);

/// <summary>
/// 删除信息
/// </summary>
/// <param name="Contact* con"></param>
void DelContact(const Contact* con);


/// <summary>
/// 删除查询信息
/// </summary>
/// <param name="Contact* con"></param>
static int FindByName( Contact* con, char Name[]);

/// <summary>
/// 查询信息
/// </summary>
/// <param name="Contact* con"></param>
void SearchContact( Contact* con);


/// <summary>
/// 查询信息
/// </summary>
/// <param name="Contact* con"></param>
void ModifyContact( Contact* con);

///保存信息到文件
void SaveContact(Contact* con);
///销毁通讯录
void DestoryContact(Contact* con);
//检查容量
void Cheek_Capacity(Contact* con);
//加载内容到通讯录
void LoadContact(Contact* con);