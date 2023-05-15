#include <string.h>
#include <stdio.h>
//动态内存开辟
// p = malloc();
// 申请： malloc
// 使用
// 释放： free(p);
// p =NULL;

//字符串左旋
//实现一个函数 可以左旋字符串中的k个字符
// void string_rotate(char * arr,int k)//左旋
// {
//     int len = strlen(arr);
//     int i =0;
//     for ( i = 0; i < k; i++)
//     {
//         int j=0;
//         for ( j = 1; j < len; j++)
//         {
//             char tmp = *arr;
//             *arr =arr[len-j];
//             arr[len-j] = tmp;
//         }
        
//     } 
// }
void string_rotate(char * arr,int k)//右旋
{
    int len = strlen(arr);
    int i =0;
    for ( i = 0; i < k; i++)
    {
        int j=0;
        for ( j = 1; j < len; j++)
        {
            char tmp = *(arr+len-j);
            *(arr+len-j) =*(arr+len-j-1);
            arr[len-j-1]= tmp;
        }
        
    } 
}
// void string_rotate(char * arr,int k)//左旋
// {
//     int len = strlen(arr);
//     int i =0;
//     for ( i = 0; i < k; i++)
//     {
//          char tmp = *arr;
//         int j=0;
//         for ( j = 0; j < len-1; j++)
//         {
//            *(arr+j) = *(arr+j+1);
//         }
//         *(arr+len-1)= tmp;
//     }
// }
int main()
{
    char arr[10] ="ABCDEF";
    int k = 10;
    string_rotate(arr,k);
    printf("%s\n",arr);
    return 0;
}