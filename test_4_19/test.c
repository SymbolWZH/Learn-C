//函数递归 函数自己调用自己
#include <stdio.h>
#include<string.h>
#include<stdlib.h>
#include<windows.h>
// 接受一个整型值（无符号），按照顺序打印它的每一位。
// 例如：
// 输入：1234，输出 1 2 3 4


// int main()
// {
//     void print(int n);
//     unsigned int num = 0;
//     scanf("%u",&num);
//     print(num);
//     return 0;
// }
// void print(int n)
// {
//     if(n>9)
//     {
//         print(n/10);//执行进去后直到执行完毕后会还会回来执行printf("%d ", n%10);
//     }
//     printf("%d ", n%10);
// }



//编写函数不允许创建临时变量，求字符串的长度。
// int main()
// {
//     int my_strlen(char* str);
//     char arr[] = "hello";
//     //模拟实现一个strlen函数
//     printf("%d\n",my_strlen(arr));
//     return 0;
// }
// int my_strlen(char* str)//char* 找到arr的地址  递归方法
// {
//     if(*str != '\0')
//         return 1 + my_strlen(str +1);  //*str 进来是第一个不是然后让他加一去第二个再次循环直到最后一个
//     else
//         return 0;//当循环找到\0的时候 走else 返回 0 后 1 + 依次回溯返还所有长度
// }
// { 计数器方法
//     int num = 0; 不允许创建变量
//     while (*str!='\0')
//     {
//         num++;
//         str++;
//         /* code */
//     }
//     return num;
// }



// 求阶乘
// int main()
// {
//     int factorial(int n);
//     int n = 0;
//     scanf("%d",&n);
//     printf("%d\n",factorial(n));
//     return 0;
// }
// int factorial(int n)
// {
//     if( n <= 1 )
//     {
//         return 1;
       
//     }else
//     {
//         return n * factorial(n - 1);
//     }
// }



//求第n个斐波那契数
int main()
{
    int FibonacciNum(int num);
    int num = 0;
    scanf("%d",&num);
    int ret = FibonacciNum(num);
    printf("%d\n",ret);
    return 0;
}
int FibonacciNum(int num)
// { 递归这样计算效率会非常低因为从最大的那个数开始从尾往前要找到第一个然后再顺次计算
//     if(num <= 2)
//         return 1;
//     else
//         return FibonacciNum(num - 1) + FibonacciNum(num - 2);
// }
{//从第一个开始计算这样效率更高 也不会堆栈溢出
     int a = 1;
     int b = 1;
     int c = 1;
    while ( num > 2 )
    {
        c = a + b;
        a = b;
        b = c;
        num--;
        /* code */
    }   
    return c;
}