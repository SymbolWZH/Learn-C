#include <stdio.h>
#include<string.h>
#include<stdlib.h>
#include<windows.h>

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
int main()
{
    //ps = &s; //err
    struct Book b3 = {'c',100,99};//创建方式二  局部   sizeof(b3) 是16 是因为16 刚好是最大字节数8 的倍数
    struct Book3 b5;
    struct Book4 b6;
    printf("%d\n", sizeof(b5));
    printf("%d\n", sizeof(b6));
    printf("%c %d %c %d", b3.name,b3.price,b3.id,sizeof(b3));
    return 0;
}

