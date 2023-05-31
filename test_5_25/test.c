#include <stdio.h>
#include<string.h>
#include<stdlib.h>//动态内存引用库函数
#include<windows.h>
// 动态内存开辟
/**
 * 栈区  局部变量  函数形参
 * 堆区  动态内存开辟   malloc  calloc  free  realloc
 * 静态区  全局变量  静态变量
*/

// int main()
// {
//     int val = 20;//在栈空间上开辟四个字节
//     char arr[10] = {0};//在栈空间上开辟10个字节的连续空间
//     /**
//      * 但是上述的开辟空间的方式有两个特点：
//         1. 空间开辟大小是固定的。
//         2. 数组在申明的时候，必须指定数组的长度，它所需要的内存在编译时分配。
//     */
//    //动态内存开辟
//     int *p= malloc(10*sizeof(int));
//     //int *p= malloc(100000000000*sizeof(int));  malloc error没有足够的空间
//     if(p == NULL)
//     {
//         printf("malloc error\n");
//         return 0;
//     }
//     //使用
//     int i=0;
//     for ( i = 0; i < 10; i++)
//     {
//         *(p+i) = i;
//     }
    
//     for ( i = 0; i < 10; i++)
//     {
//         printf("%d ",*(p+i));//p[i]
//     }
//     //回收空间  free
//     free(p);//动态内存需要被回收 但是p不会被销毁会指向初始位置的地址
//     p = NULL; // 避免造成非法访问，自己制成空指针

// }


// C 库函数 void *calloc(size_t nitems, size_t size) 
// 分配所需的内存空间，并返回一个指向它的指针。malloc 和 calloc 之间的不同点是，
// malloc 不会设置内存为零，而 calloc 会设置分配的内存为零。
// 注意：calloc() 函数将分配的内存全部初始化为零。如果不需要初始化，
// 可以使用 malloc() 函数代替。另外，使用 calloc() 函数时需要注意，如果分配的内存块过大，可能会导致内存不足的问题。
// int main()
// {
//     int * p = calloc(10,sizeof(int));
//     int i =0;
//     for ( i = 0; i < 10; i++)
//     {
//          printf("%d ",*(p+i));//p[i]
//     }
//     //当我需要更多的内存
//     int * ptr = realloc(p,20*sizeof(int));//用一个新的指针去接收避免p指针为空的情况
//     // int * p = (int*)realloc(NULL,40);这里的功能类似于malloc，就是直接在堆区开辟40个字节
//     if(ptr == NULL)
//     {
//         perror("realloc error");
//         return 1;
//     }
//     else
//     {
//         p = ptr;
//     }
//      printf("\n");//p[i]
//     for ( i = 0; i < 20; i++)
//     {
//          printf("%d ",*(p+i));//p[i]
//     }
//     free(p);
//     p = NULL;
// }


///常见的动态内存错误 5种
// 1 对NULL指针的解引用操作
// 2 对动态开辟空间的越界访问
// 3 对非动态开辟存内使用free释放
// 4 使用free释放一块动态开辟内存的一部分
// 5 对同一块动态内存多次释放
// 6 动态开辟内存忘记释放（内存泄漏）
// void test()
// {
//  int *p = (int *)malloc(INT_MAX/4);
//  *p = 20;//如果p的值是NULL，就会有问题
//  free(p);
// }
// //对动态开辟空间的越界访问
// void test()
// {
//  int i = 0;
//  int *p = (int *)malloc(10*sizeof(int));
//  if(NULL == p)
//  {
//  exit(EXIT_FAILURE);
//  }
//  for(i=0; i<=10; i++)
//  {
//  *(p+i) = i;//当i是10的时候越界访问
//  }
//  free(p);
// }

//对非动态开辟内存使用free释放
// void test()
// {
//  int a = 10;
//  int *p = &a;
//  free(p);//ok?
// }

// 使用free释放一块动态开辟内存的一部分
void test()
{
 int *p = (int *)malloc(100);
 p++;
 free(p);//p不再指向动态内存的起始位置
}   
//对同一块动态内存多次释放
void test()
{
 int *p = (int *)malloc(100);
 free(p);
 free(p);//重复释放
}
//动态开辟内存忘记释放（内存泄漏）
void test()
{
    int *p = (int *)malloc(100);
    if(NULL != p)
    {
    *p = 20;
    }
}
int main()
{
    test();
    while(1);
}

//动态开辟的空间 2种回收方式
//1 主动 free 
//2 程序结束

// C/C++程序内存分配的几个区域：
// 1. 栈区（stack）：在执行函数时，函数内局部变量的存储单元都可以在栈上创建，函数执行结
// 束时这些存储单元自动被释放。栈内存分配运算内置于处理器的指令集中，效率很高，但是
// 分配的内存容量有限。 栈区主要存放运行函数而分配的局部变量、函数参数、返回数据、返
// 回地址等。
// 2. 堆区（heap）：一般由程序员分配释放， 若程序员不释放，程序结束时可能由OS回收 。分
// 配方式类似于链表。
// 3. 数据段（静态区）（static）存放全局变量、静态数据。程序结束后由系统释放。
// 4. 代码段：存放函数体（类成员函数和全局函数）的二进制代码。