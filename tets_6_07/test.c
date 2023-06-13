#include <stdio.h>
#include<string.h>
#include<stdlib.h>
#include<windows.h>
/*
__FILE__      //进行编译的源文件
__LINE__     //文件当前的行号
__DATE__    //文件被编译的日期
__TIME__    //文件被编译的时间
__STDC__    //如果编译器遵循ANSI C，其值为1，否则未定义
*/
#define PRINT(X) printf("the value of "#X" is %d\n",X);
#define Cat(x,y) x##y 
//  使用 # ，把一个宏参数变成对应的字符串
//  ##可以把位于它两边的符号合成一个符号 可以三个。。。
#define MAX(x,y) ((x)>(y)?(x):(y))

#define MALLOC(num,type) (type*)malloc(num*sizeof(type))
int main()
{
    printf("hello world\n");
    printf("hello ""world\n");
    int a = 100;
    PRINT(a);
    //the value of a is 100
    int b = 200;
    PRINT(b);
    //the value of b is 200
    int c = 300;
    PRINT(c);
    //the value of c is 300
    int class101 = 100;
    printf("%d\n",Cat(class,101));
    printf("%d\n",class101);


    int i = 5;
    int j = 8;
    printf("i = %d j=%d\n",i,j);
    int m = MAX(i++,j++);
    printf("i = %d j=%d\n",i,j);
    printf("%d\n",m);
    //当宏参数在宏的定义中出现超过一次的时候，
    //如果参数带有副作用，那么你在使用这个宏的时候就可能
    //出现危险，导致不可预测的后果。
    //副作用就是表达式求值的时候出现的永久性效果
    //x+1;//不带副作用
    //x++;//带有副作用


    //malloc(10*sizeof(int));
    int *p = MALLOC(10,int);
    return 0;
}