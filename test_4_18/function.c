#include <stdio.h>
#include<string.h>
#include<stdlib.h>
#include<windows.h>
#include <math.h>
//C语言中函数分为：库函数和自定义函数
// IO函数  printf scanf getchar putchar
// 字符串操作函数  strcmp strlen
// 字符操作函数    toupper
// 内存操作函数    memcpy memcmp memset
// 时间/日期函数   time
// 数学函数        sqrt pow
// 其他库函数
// int main()
// {
//     char arr1[20] = {0};
//     char arr2[] = "hello";
//     strcpy(arr1,arr2);
//     //char * strcpy ( char * destination, const char * source );拷贝
//     printf("%s",arr1);
//     return 0;
// }
// int main()
// {
//     char str[] = "almost every programmer should know memset!";
//     memset (str,'y',6);
//     //void * memset ( void * ptr, int value, size_t num );
//     puts (str);//yyyyyy every programmer should know memset!字符串替换
//     return 0;
// }
//自定义函数
// ret_type fun_name(para1, * )
// {
//  statement;//语句项
// }
// ret_type 返回类型
// fun_name 函数名
// para1    函数参数
//形参实例化之后其实相当于实参的一份临时拷贝
// 1 传值调用
// 函数的形参和实参分别占有不同内存块，对形参的修改不会影响实参。
// 2 传址调用
// 传址调用是把函数外部创建变量的内存地址传递给函数参数的一种调用函数的方式。
// 这种传参方式可以让函数和函数外边的变量建立起真正的联系，也就是函数内部可以直接操
// 作函数外部的变量。
// void Swap(int* pa,int* pb)
// {
//     int z = 0;
//     z = *pa;
//     *pa = *pb;
//     *pb=z;
// }
// int main()
// {
//     int a = 10;
//     int b = 20;
//     printf("交换前： a=%d b= %d\n",a,b);
//     Swap(&a,&b);
//     printf("交换后： a=%d b= %d\n",a,b);
// }
//写一个函数判断是不是素数
// int is_prime(int pa)
// {
//     int i = 0;
//     for(i=2;i<=sqrt(pa);i++){
//         if( pa % i == 0)
//             return 0;
//     }
//     return 1;
// }
// int main()
// {
//     int i =0;
//     int count = 0;
//     for(i = 100;i <= 200;i++)
//     {
//         if(is_prime(i) == 1)
//         {
//             count++;
//             printf("%d,",i);
//         }
//     }
//     printf("\ncount = %d\n",count);
//     return 0;
// }
//二分查找
int binary_search(int arr[],int key,int sz){
    int left = 0;
    int right = sz - 1;
    while (left<=right)
    {
        /* code */
        int mid = (right + left) / 2;
        if(arr[mid] > key){
        right = mid -1;
        }
        else if(arr[mid]<key){
        left = mid + 1;
        }
        else{
        return mid;
        }
    }
    
    return -1;
}
int main()
{
    int arr[11] = {10,11,12,13,14,15,16,17,18,19,20};
    int key;
    printf("10 is %d",10);
    printf("arr is %d",arr);
    printf("请输入查询的数字：");
    scanf("%d",&key);
    int sz = sizeof(arr) / sizeof(arr[0]);
    int num = binary_search(arr,key,sz);
    if(num != -1)
        printf("%d的下标是%d",key,num);
    else
        printf("没找到！！！");
}