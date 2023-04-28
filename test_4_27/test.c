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
// struct Point
// {
//     int x;
//     int y;
// } p1, p2; // 声明类型的同时定义变量p1 p2全局

// struct Node
// {
//     int data;
//     struct Point p;
//     struct Node *next;
// } n1 = {10, {4, 5}, NULL}; // 结构体嵌套初始化

// struct Node n2 = {20, {5, 6}, NULL}; // 结构体嵌套初始化
// // int main()
// // {
// //     struct Point p3 = {7,8}; //定义结构体变量p2 局部
// //     struct Point* pa = &p3;
// //     printf("%d\n",pa->x);
// //     printf("%d\n",(*pa).y);
// // }

// //  结构体传参
// // 直接上代码：
// struct S
// {
//     int data[1000];
//     int num;
// };
// struct S s = {{1, 2, 3, 4}, 1000};
// // 结构体传参
// void print1(struct S s)
// {
//     printf("%d\n", s.num);
// }
// // 结构体地址传参
// void print2(struct S *ps)
// {
//     printf("%d\n", ps->num);
// }
// int main()
// {
//     assert(0 != NULL); // 断言 如果不满足会报错
//     print1(s);         // 传结构体
//     print2(&s);        // 传地址
//     return 0;
// }
// // 上面的 print1 和 print2 函数哪个好些？
// // 答案是：首选print2函数。
// // 原因：
// // 函数传参的时候，参数是需要压栈的。
// // 如果传递一个结构体对象的时候，结构体过大，参数压栈的的系统开销比较大，所以会导致性能的
// // 下降。
// // 结论：
// // 结构体传参的时候，要传结构体的地址。
// // #include <assert.h>
// // 代码1
// void test1()
// {
//     int n = 10;
//     int m = 20;
//     int *p = &n;
//     *p = 20; // ok?  ok
//     p = &m;  // ok?  ok
// }
// void test2()
// {
//     //代码2
//     int n = 10;
//     int m = 20;
//     const int *p = &n;//const指向的n的内容 n的内容不能改变
//     *p = 20; // ok? no
//     p = &m;  // ok? ok
// }
// void test3()
// {
//     int n = 10;
//     int m = 20;
//     int *const p = &n;//const指向的指针变量p 表示指针变量不能被改变但是指针的内容可以改变
//     *p = 20; // ok? ok
//     p = &m;//ok? no
// }
// void test3()
// {
//     int n = 10;
//     int m = 20;
//     const int *const p = &n;//const指向的指针变量p 表示指针变量不能被改变但是指针的内容可以改变
//     *p = 20; // ok? no
//     p = &m;//ok? no
// }
// int main()
// {
//     //测试无cosnt的
//     test1();
//     //测试const放在*的左边
//     test2();
//     //测试const放在*的右边
//     test3();
//     return 0;
// }
// 结论：
// const修饰指针变量的时候：
// 1. const如果放在*的左边，修饰的是指针指向的内容，保证指针指向的内容不能通过指针来改
// 变。但是指针变量本身的内容可变。
// 2. const如果放在*的右边，修饰的是指针变量本身，保证了指针变量的内容不能修改，但是指
// 针指向的内容，可以通过指针改变。
size_t my_strlen(const char* str)
{
    //assert(str != NULL);
    assert(str);
    size_t num = 0;
    while (*str++ != '\0')
    {
        /* code */
        num++;
    }
    return num;
    
}

// int main()
// {
//     char str[] = {'h','e','l','l','o'};
//     int len = my_strlen(str);
//     printf("%d",len);
//     return 0;
// }


// int main()//求二进制为为1 的 个数
// {
//     int n = -15;
//     int count =0;
//     while (n)
//     {
//         n = n &(n-1);
//         count++;
//         /* code */
//     }
//     printf("%d",count);
// }

// int main()//求二进制为为1 的 个数
// {
//     int n = 22;
//     int m = 33;
//     int count =0;
//     int ret = m ^ n; //亦或相同为0 相异为1
//     while (ret)
//     {
//         ret = ret &(ret-1);
//         count++;
//         /* code */
//     }
//     printf("%d",count);
// }

// int main()//打印n二进制中的基数位 偶数位
// {
//     int n = 20;
//     int i=0;
//     for ( i = 31; i >=1; i -=2)
//     {
//         printf("第%d位的值为%d\n",i,(n>>1)&1);
//         /* code */
//     }
//      for ( i = 30; i >=0; i -=2)
//     {
//         printf("第%d位的值为%d\n",i,(n>>1)&1);
//         /* code */
//     }
    
// }

int main()//交换两个变量不创建第三个的情况下
{
    int a = 10;
    int b = 20;
    a = a ^ b;
    b = a ^ b ;//a ^ b ^ b
    a = a ^ b;//a ^ b ^ a 
    printf("a = %d  b =%d\n",a,b);
}