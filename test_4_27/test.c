#include <stdio.h>
#include <assert.h>

// int main()
// {
//     int arr = {1,2,3,4,5,6,7,8,9,10};
//     int* p = arr;

//     //arr[2]  <==> *(arr + 2) <==> *(p+2)<==>  *(2+p)  <==>   *(2+arr) <==> 2[arr]
// }

// 二级指针
//  int main()
//  {
//      int a = 10;
//      int * pa = &a;//pa是指针变量 一级指针
//      //ppa 是一个二级指针变量
//      int* *ppa = &pa;//pa也是个变量 &pa去除pa在内存中起始地址0
//      int** *pppa = &ppa; //三级指针
//      //*ppa == pa *pa = a  * *ppa == a

//     //指针数组-存放指针的数组

//     int* parr[5];//整型指针的数组
//     char * charr[5];// 字符指针的数组
//     return 0;
// }
// 结构体
struct Point
{
    int x;
    int y;
} p1, p2; // 声明类型的同时定义变量p1 p2全局

struct Node
{
    int data;
    struct Point p;
    struct Node *next;
} n1 = {10, {4, 5}, NULL}; // 结构体嵌套初始化

struct Node n2 = {20, {5, 6}, NULL}; // 结构体嵌套初始化
// int main()
// {
//     struct Point p3 = {7,8}; //定义结构体变量p2 局部
//     struct Point* pa = &p3;
//     printf("%d\n",pa->x);
//     printf("%d\n",(*pa).y);
// }

//  结构体传参
// 直接上代码：
struct S
{
    int data[1000];
    int num;
};
struct S s = {{1, 2, 3, 4}, 1000};
// 结构体传参
void print1(struct S s)
{
    printf("%d\n", s.num);
}
// 结构体地址传参
void print2(struct S *ps)
{
    printf("%d\n", ps->num);
}
int main()
{
    assert(0 != NULL); // 断言 如果不满足会报错
    print1(s);         // 传结构体
    print2(&s);        // 传地址
    return 0;
}
// 上面的 print1 和 print2 函数哪个好些？
// 答案是：首选print2函数。
// 原因：
// 函数传参的时候，参数是需要压栈的。
// 如果传递一个结构体对象的时候，结构体过大，参数压栈的的系统开销比较大，所以会导致性能的
// 下降。
// 结论：
// 结构体传参的时候，要传结构体的地址。
// #include <assert.h>
