// 指针进阶
/*
1. 字符指针
2. 数组指针
3. 指针数组
4. 数组传参和指针传参
5. 函数指针
6. 函数指针数组
7. 指向函数指针数组的指针
8. 回调函数
9. 指针和数组面试题的解析
*/
#include <stdio.h>
/*
int main()
{
    char *ps = "hello world";//把首字符的地址存储在了ps中了
    char arr[] = "hello ";

    //printf("%s\n",ps); == printf("%s\n",arr);
    return 0;
}
*/
/*
int main()
{
    char str1[] = "hello";
    char str2[] = "hello";
    char* str3 = "hello";
    char* str4 = "hello";
    if(str1 == str2)//str1 != str2 因为存的地址不一样都独自开辟了一个地址空间
        printf("str1 and str2 are same \n");
    else
        printf("str1 and str2 no same \n");

    if(str3 == str4)//str3 == str4 因为存的地址一样相当于一个地址
        printf("str3 and str4 are same \n");
    else
        printf("str3 and str4 no same \n");

    return 0;
}
*/
/*
    int* arr1[10]; //整形指针的数组
    char *arr2[4]; //一级字符指针的数组
    char **arr3[5];//二级字符指针的数组
*/

/*
int main()
{
    int a[5] = {1, 2, 3, 4, 5};
    int b[] = {2, 3, 4, 5, 6};
    int c[] = {3, 4, 5, 6, 7};
    
    int *arr[3] = {a, b, c};
    int i = 0;
    for (i = 0; i < 3; i++)
    {
        int j = 0;
        for (j = 0; j < 5; j++)
        {
           // printf("%d ", *(arr[i] + j ));
            printf("%d ", arr[i][j]);
        }
        printf("\n");
    }
    return 0;
}
*/

//数组指针 指向数组的指针 
/*
int main()
{
    int a= 0;
    int *pa = &a;
    char ch = 'w';
    char *pc = &ch;

    int arr[10] = {1,2,3,4,5};
    int (*parr)[10] =&arr;//取出的是数组的地址
    //parr 就是一个数组指针 其中存放的是数组的地址
    int i = 0;
    for ( i = 0; i < 10; i++)
    {
       *(parr[i]) = 0;
       printf("%d ", *(parr[i]));// 0 0 0 0 0 0 0 0 0 0
    }
    
    double* d[5];
    double* (*pd)[5] = &d;//ok  pd就是一个数组指针
}
*/

/*
int main()
{
    int arr[10] = {0};
    int *p1 = arr;
    int (*p2)[10]= &arr;

    printf("%d\n",p1);
    printf("%d\n",p1+1);

    printf("%d\n",p2);
    printf("%d\n",p2+1);
    // 根据上面的代码我们发现，其实&arr和arr，虽然值是一样的，但是意义应该不一样的。
    // 实际上： &arr 表示的是数组的地址，而不是数组首元素的地址。（细细体会一下）
    // 本例中 &arr 的类型是： int(*)[10] ，是一种数组指针类型
    // 数组的地址+1，跳过整个数组的大小，所以 &arr+1 相对于 &arr 的差值是40

//数组名是什么？ 数组名是数组首元素的地址
//有两个例外  
//1. sizeof(数组名) --- 数组名表示整个数组 -计算的是整个数组的大小单位是字节
//2. &(取地址)数组名 --- 数组名表示整个数组，取出的是这个数组的地址
}
*/

int main()
{
    int arr[10] = {1,2,3,4,5,6,7,8,9};
    int (*pa)[10] = &arr;
    int i = 0;
    for ( i = 0; i < (sizeof(arr) / sizeof(arr[0])); i++)
    {
        printf("%d ", *(*pa+i));//1 2 3 4 5 6 7 8 9 0 
    }
    return 0;
}