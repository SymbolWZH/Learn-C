#include <stdio.h>
#include<string.h>
#include<stdlib.h>
#include<windows.h>
#include<stddef.h>
struct Book
{
    char name;
    int price;
    double id;
}b1,b2;//创建方式一 全局

//匿名结构体类型
// struct
// {
//     char c;
//     int i;
//     double d;
// }s;

//匿名结构体指针
// struct
// {
//     char c;
//     int i;
//     double d;
// }* ps;


// struct A
// {
//     int i;
//     char ch;
// };
// struct B
// {
//     int i;
//     struct A s;//可以结构体中声明结构体
//     char ch;
// };


// struct N
// {
//     int d;
//     struct N n;//会死循环 不可以这样
// };
//正确的自引用方式：
//代码2
// struct Node
// {
//  int data;
//  struct Node* next;//4 8
// };


//代码3
// typedef struct
// {
//  int data;
//  Node* next;
// }Node;
//这样写代码，可行否？
//解决方案：
// typedef struct Node
// {
//  int data;
//  struct Node* next;
// }Node;
// 如何计算？
// 首先得掌握结构体的对齐规则：
// 1. 第一个成员在与结构体变量偏移量为0的地址处。
// 2. 其他成员变量要对齐到某个数字（对齐数）的整数倍的地址处。
// 对齐数 = 编译器默认的一个对齐数 与 该成员大小的较小值。
// VS中默认的值为8
// 3. 结构体总大小为最大对齐数（每个成员变量都有一个对齐数）的整数倍。
// 4. 如果嵌套了结构体的情况，嵌套的结构体对齐到自己的最大对齐数的整数倍处，结构体的整
// 体大小就是所有最大对齐数（含嵌套结构体的对齐数）的整数倍。
struct Book2
{
    char dou;
    int c;
    double i;
};
struct Book3
{
    char c1;
    struct Book2 b4;
    double i;
};
struct Book4
{
    double c2;
    int i;
    char c1;
    
};
#pragma pack(2)//表示下面的默认对齐树为2 一般设置2的n次方   如果设置1 取里面的整型不好取
struct Book5
{
    char c2;
    int i;
    char c1;
    
};
// int main()
// {
//     //ps = &s; //err
//     struct Book b3 = {'c',100,99};//创建方式二  局部   sizeof(b3) 是16 是因为16 刚好是最大字节数8 的倍数
//     struct Book3 b5;
//     struct Book4 b6;
//     struct Book5 b7;
//     printf("%d\n", sizeof(b5));
//     printf("%d\n", offsetof(struct Book5,i));// #include<stddef.h> offsetof 计算结构体中某变量相对于首地址的偏移
//     printf("%d\n", sizeof(b6));
//     printf("%d\n", sizeof(b7));
//     printf("%c %d %c %d", b3.name,b3.price,b3.id,sizeof(b3));
//     return 0;
// }

// 什么是位段
// 位段的声明和结构是类似的，有两个不同：
// 1.位段的成员必须是 int、unsigned int 或signed int 。
// 2.位段的成员名后边有一个冒号和一个数字。
// 1. 位段的成员可以是 int unsigned int signed int 或者是 char （属于整形家族）类型
// 2. 位段的空间上是按照需要以4个字节（ int ）或者1个字节（ char ）的方式来开辟的。
// 3. 位段涉及很多不确定因素，位段是不跨平台的，注重可移植的程序应该避免使用位段。
//举例
// 00 男
// 01 女
// 10 保密
// 11
struct A
{
 int _a:2;//成员占2个bit位
 int _b:5;
 int _c:10;
 int _d:30;
};
enum day//枚举 声明枚举类型
{
    Mon,//枚举类型的可能取值的常量
    Tues,
    Wed,
    the=5
};
int main()
{
    enum day dy = Mon;
    printf("%d\n",Mon);
    printf("%d\n",Tues);
    printf("%d\n",Wed);
    printf("%d\n",the);
}