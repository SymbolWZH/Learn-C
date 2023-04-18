#include <stdio.h>
#include "gobal.c" //不能忘记引用
//c语言是从主函数的第一行开始执行
//main函数是入口 int整型函数返回类型
//printf-库函数-在屏幕上打印信息的 包含头文件(stdio.h)
//一个工程中main函数有且仅有一个
// int main()
// {
//     char* ch = "a";
//     printf("%d\n",g_val);
//     printf("%d");//打印函数
//     printf("%d\n",sizeof(char));//字符数据类型	1
//     printf("%d\n",sizeof(short));//短整型		  2
//     printf("%d\n",sizeof(int)); //整形		   4
//     printf("%d\n",sizeof(long));//长整型		  4
//     printf("%d long\n",sizeof(long long));//更长的整形		 8
//     printf("%d\n",sizeof(float));//单精度浮点数	4
//     printf("%d\n",sizeof(double));//双精度浮点数	8
//     return 0;
// }
extern int g_val;
int main(){
    printf("%d\n",g_val);
    return 0;
}
