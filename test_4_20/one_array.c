#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <windows.h>
// 数组  一组相同类型元素的集合
// 数组是一组相同类型元素的集合。
//  数组的创建方式：
// type_t   arr_name   [const_n];
// type_t 是指数组的元素类型
// const_n 是一个常量表达式，用来指定数组的大小
/*
    int main()
    {
    int n = 8;
    int b[n]; // c99语法支持
    int arr[10] = {0};
    int i = 0;
    int sz = sizeof(arr) / sizeof(arr[0]);
    for (i = 0; i < sz; ++i)
    {
        printf("&arr[%d] = %p\n", i, &arr[i]);

        &arr[0] = 000000000061FDA0
        &arr[1] = 000000000061FDA4
        &arr[2] = 000000000061FDA8
        &arr[3] = 000000000061FDAC
        &arr[4] = 000000000061FDB0
        &arr[5] = 000000000061FDB4
        &arr[6] = 000000000061FDB8
        &arr[7] = 000000000061FDBC
        &arr[8] = 000000000061FDC0
        &arr[9] = 000000000061FDC4

    }
    return 0;
    }
*/
// 数组在内存中是连续存放的

// 2.1 二维数组的创建
// 2.2 二维数组的初始化
// 2.3 二维数组的使用
// 二维数组的使用也是通过下标的方式。
// 看代码：
// 数组创建
// int arr[3][4];
// char arr[3][5];
// double arr[2][4];
// // 数组初始化
// int arr[3][4] = {1, 2, 3, 4}; // 二维数组的使用也是通过下标的方式。
/*   行：0   1   2  3 的下标
    列↓
    0    1, 2,  3,  4
    1    5, 6,  7,  8
    2    9, 10, 11, 12
*/
// int main()
// {
//     int arr[3][4] = {0};
//     int i = 0;
//     for (i = 0; i < 3; i++)
//     {
//         int j = 0;
//         for (j = 0; j < 4; j++)
//         {
//             arr[i][j] = i * 4 + j;
//         }
//     }
//     for (i = 0; i < 3; i++)
//     {
//         int j = 0;
//         for (j = 0; j < 4; j++)
//         {
//             printf("%d ", arr[i][j]);
//         }
//         printf("\n");
//     }
//     return 0;
// }
// int arr[3][4] = {{1, 2}, {4, 5}}; //[[1,2,0,0],[4,5,0,0],[0,0,0,0]]
// int arr[][4] = {{2, 3}, {4, 5}};  // 二维数组如果有初始化，行可以省略，列不能省略[[2,3,0,0],[4,5,0,0],[0,0,0,0]]

// 2.4 二维数组在内存中的存储
// 像一维数组一样，这里我们尝试打印二维数组的每个元素。
// int main()
// {
//     int arr[3][4];
//     int i = 0;
//     for (i = 0; i < 3; i++)
//     {
//         int j = 0;
//         for (j = 0; j < 4; j++)
//         {
//             printf("&arr[%d][%d] = %p\n", i, j, &arr[i][j]);
//         }
//     }
//     return 0;
// }
/*
&arr[0][0] = 000000000061FDE0   相邻相差都是4个字节
&arr[0][1] = 000000000061FDE4
&arr[0][2] = 000000000061FDE8
&arr[0][3] = 000000000061FDEC
&arr[1][0] = 000000000061FDF0
&arr[1][1] = 000000000061FDF4
&arr[1][2] = 000000000061FDF8
&arr[1][3] = 000000000061FDFC
&arr[2][0] = 000000000061FE00
&arr[2][1] = 000000000061FE04
&arr[2][2] = 000000000061FE08
&arr[2][3] = 000000000061FE0C
通过结果我们可以分析到，其实二维数组在内存中也是连续存储的。
*/


//数组作为函数参数
// int bubble_Sort(int arr[],int len)
// {
//     int i =0;
//     for ( i = 0; i < len -1; i++)
//     {
//         int j = 0;
//         for ( j = 0; j < len - i - 1; j++)
//         {
//             if(arr[j] > arr[j+1]){
//                 int tmp = arr[j];
//                 arr[j] = arr[j+1];
//                 arr[j+1] = tmp;
//             }
//         }
//     }
//     return 0;
// }
// int main()
// {
//     int arr[] = {9,8,7,6,5,4,3,2,1,0};
//     int len = sizeof(arr) / sizeof(arr[0]);
//     bubble_Sort(arr,len);
//     int i = 0;
//     for ( i = 0; i < len; i++)
//     {
//         printf("%d",arr[i]);//0123456789
//     }
    
// }

//数组名是什么？ 数组名是数组首元素的地址
//有两个例外  
//1. sizeof(数组名) --- 数组名表示整个数组 -计算的是整个数组的大小单位是字节
//2. &(取地址)数组名 --- 数组名表示整个数组，取出的是这个数组的地址
int main()
{
    int arr[10] = {};
    printf("%p\n",&arr);//&arr取出的是数组的地址
    printf("%p\n",&arr + 1);//数组地址加一

    printf("%p\n",arr);//表示取数组首元素
    printf("%p\n",arr + 1);//表示取数组首元素地址加一 4 字节
    printf("%p\n",&arr[0]);
    return 0;
}