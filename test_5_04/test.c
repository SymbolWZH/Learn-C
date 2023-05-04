#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <windows.h>
// 数据的存储作业讲解
/*
int main()
{
    //unsigned char取值范围0-255
    unsigned char a = 200;
   // 000000000000000000000000 11001000
    unsigned char b = 100;
   // 000000000000000000000000 01100100
   // a + b整型提升没有符号位
   // 000000000000000000000000 11001000
   // 000000000000000000000000 01100100
   // 000000000000000000000001 00101100
   //unsigned存八位  00101100 == 44
    unsigned char c = 0;
    c = a + b ;
    printf("%d %d",a+b,c);
    return 0;
}
*/
/*
int main()
{
    unsigned int  a = 0x1234;
    unsigned char b = *(unsigned char*)&a;//unsigned char一个字节所以取到00
    //低                                 高
    //00 00 12 34 大端  取到00
    //34 12 00 00 小端  取到34
    //在32为大端处理器上变量b等于 0x00
    return 0;
}*/
// 打印杨辉三角
//           1
//          1 1
//         1 2 1
//        1 3 3 1
//       1 4 6 4 1
//      1 5 10 10 1
// 1
// 1 1
// 1 2 1
// 1 3 3 1
// 1 4 6 4 1
// 1 5 10 10 1

/*
int main()
{
    int arr[10][10] = {0};
    int i =0,j=0;
    for ( i = 0; i < 10; i++)
    {
       for ( j = 0; j < i; j++)
       {
         if(j == 0)
         {
            arr[i][j] = 1;
         }
         if(i==j)
         {
            arr[i][j]=1;
         }
         if(j>=1&&i>=2){
            arr[i][j] = arr[i-1][j] + arr[i-1][j-1];
         }
       }

    }
    for ( i = 0; i < 10; i++)
    {
       for ( j = 0; j < i; j++)
       {
            printf("%d ",arr[i][j]);
       }
       printf("\n");
    }
    printf("\n");

    //
    for ( i = 0; i < 10; i++)
    {
       for ( j = 0; j < 10-i; j++)
       {
                printf(" ");
       }
       for ( j = 0; j < i; j++)
       {
           printf("%2d ",arr[i][j]);
       }

      printf("\n");
    }
}*/

/*
// 猜凶手
// 【题目内容】
// 日本某地发生了一件谋杀案，警察通过排查确定杀人凶手必为4个嫌疑犯的一个。
// 以下为4个嫌疑犯的供词:
// A说：不是我。
// B说：是C。
// C说：是D。
// D说：C在胡说
// 已知3个人说了真话，1个人说的是假话。
// 现在请根据这些信息，写一个程序来确定到底谁是凶手。
int main()
{
    char killer = 0;
    for ( killer = 'A'; killer <= 'D'; killer++)
    {
        if((killer != 'A') + (killer == 'C') + (killer == 'D') + (killer != 'D') == 3)
            printf("%c",killer);
    }
    return 0;
}
*/

// 【题目名称】
// 猜名次
// 【题目内容】
// 5位运动员参加了10米台跳水比赛，有人让他们预测比赛结果：
// A选手说：B第二，我第三；
// B选手说：我第二，E第四；
// C选手说：我第一，D第二；
// D选手说：C最后，我第三；
// E选手说：我第四，A第一；
// 比赛结束后，每位选手都说对了一半，请编程确定比赛的名次。
/*
int main()
{
    int a = 0;
    int b = 0;
    int c = 0;
    int d = 0;
    int e = 0;
    for (a = 0; a <= 5; a++)
    {
        for (b = 0; b <= 5; b++)
        {
            for (c = 0; c <= 5; c++)
            {
                for (d = 0; d <= 5; d++)
                {
                    for (e = 0; e <= 5; e++)
                    {
                        if (((b == 2) + (a == 3) == 1)
                            &&((b == 2) + (e == 4) == 1)
                            &&((c == 1) + (d == 2) == 1)
                            &&((c == 5) + (d == 3) == 1)
                            &&((e == 4) + (a == 1) == 1))
                        {
                            if(a*b*c*d*e==120)
                                printf("a=%d b=%d c=%d d=%d e=%d", a, b, c, d, e);
                        }
                    }
                }
            }
        }
    }
    return 0;
}
*/

/*
// 一级指针传参
// int *p  char*pc void*pv
void print(int *p, int sz)
{
    int i = 0;
    for (i = 0; i < sz; i++)
    {
        printf("%d\n", *(p + i));
    }
}
int main()
{
    int arr[10] = {1, 2, 3, 4, 5, 6, 7, 8, 9};
    int *p = arr;
    int sz = sizeof(arr) / sizeof(arr[0]);
    // 一级指针p，传给函数
    print(p, sz);
    return 0;
}
*/
/*
// 二级指针传参 char **p int **p
void test(int **ptr)
{
    printf("num = %d\n", **ptr);
}
int main()
{
    int n = 10;
    int *p = &n;
    int **pp = &p;
    test(pp);
    test(&p);//传一级指针变量的地址
    int * arr[10] ={0};
    test(arr);
    return 0;
}
*/
/*
void test(char **p)
{
}
int main()
{
    char c = 'b';
    char *pc = &c;
    char **ppc = &pc;
    char *arr[10];
    test(&pc);
    test(ppc);
    test(arr); // Ok?
    return 0;
}
*/

// 数组指针：指向数组的指针 int(*p)[4]

// 函数指针
/*
void test()
{
    printf("hehe\n");
}
int main()
{
    void (*pf)() = &test;//pf === test
     (*pf)();// (*pf)()==pf()
     pf();
    printf("%p\n", test);
    printf("%p\n", &test);
    return 0;
}
*/

// 代码1
//(*(void (*)())0)();
// 调用0地址处的函数
// 该函数无参，返回类型是void
//  (void (*)() -函数指针类型
//  (void (*)())0 - 对0进行强制类型转换 被解释为一个函数地址
//  *(void (*)())0) -对0地址进行了解引用操作
//  (*(void (*)())0)() -调用0地址出的函数
// 代码2
//  void (*signal(int , void(*)(int)))(int);
//  void(*)(int)-函数指针类型
//  signal(int , void(*)(int)) signal和()先结合 说明signal是函数名
//  signal函数的第一个参数类型是int  第二个参数的类型是函数指针
//  该函数指针 指向一个参数为int 返回类型为void的函数
//  signal 函数的返回类型也是一个函数指针
//  该函数指针 指向一个参数为int 返回类型是void 参数
//  signal是一个函数声明

// typedef-对类型进行重定义
// typedef void(*pfun_t)(int);   对(void (*)(int)的函数指针类型重命名为pfun_t

// 代码2太复杂，如何简化：
// typedef void(*pfun_t)(int);
// pfun_t signal(int, pfun_t);

// 函数指针数组 把函数的地址存到一个数组中，那这个数组就叫函数指针数组
/*
int Add(int x,int y)
{
    return x+y;
}
int Sub(int x,int y)
{
    return x-y;
}
int main()
{
    //数组的每个元素是int*
    int *arr[10];
    //，那函数指针的数组如何定义呢？
    int (*pf1)() = Add;
    int (*pf2)() = Sub;
    int (*pArr[2])(int ,int) ={pf1,pf2} ;//pArr就叫函数指针数组
}
*/

/*
// 使用函数指针数组的实现
int add(int a, int b)
{
    return a + b;
}
int sub(int a, int b)
{
    return a - b;
}
int mul(int a, int b)
{
    return a * b;
}
int divde(int a, int b)
{
    return a / b;
}
int main()
{
    int x, y;
    int input = 1;
    int ret = 0;
    int (*p[5])(int x, int y) = {0, add, sub, mul, divde}; // 转移表
    while (input)
    {
        printf("*************************\n");
        printf(" 1:add      2:sub \n");
        printf(" 3:mul      4:divde \n");
        printf("*************************\n");
        printf("请选择：");
        scanf("%d", &input);
        if ((input <= 4 && input >= 1))
        {
            printf("输入操作数：");
            scanf("%d %d", &x, &y);
            ret = (*p[input])(x, y);

        }
        else
            printf("输入有误\n");
        printf("ret = %d\n", ret);
    }
    return 0;
}
*/
/*
// 指向函数指针数组的指针
void test(const char *str)
{
    printf("%s\n", str);
}
int main()
{
    // 函数指针pfun
    void (*pfun)(const char *) = test;
    // 函数指针的数组pfunArr
    void (*pfunArr[5])(const char *str);
    pfunArr[0] = test;
    // 指向函数指针数组pfunArr的指针ppfunArr
    void (*(*ppfunArr)[5])(const char *) = &pfunArr;
    return 0;
}
*/
// 回调函数
/*回调函数就是一个通过函数指针调用的函数。如果你把函数的指针（地址）作为参数传递给另一个
函数，当这个指针被用来调用其所指向的函数时，我们就说这是回调函数。回调函数不是由该函数
的实现方直接调用，而是在特定的事件或条件发生时由另外的一方调用的，用于对该事件或条件进
行响应。*/
// 回调函数重新实现加减法
/*
int add(int a, int b)
{
    return a + b;
}
int sub(int a, int b)
{
    return a - b;
}
int mul(int a, int b)
{
    return a * b;
}
int divs(int a, int b)
{
    return a / b;
}
int Calc(int (*pf)(int, int))
{
    int x, y;
    printf("输入操作数：");
    scanf("%d %d", &x, &y);
    return pf(x, y);//当Calc使用时调用pf函数  --->回调函数
}
int menu()
{
    printf("*************************\n");
    printf(" 1:add      2:sub \n");
    printf(" 3:mul      4:div \n");
    printf("*************************\n");
    printf("请选择：");
}
int main()
{
    int input = 1;
    do
    {
        menu();
        scanf("%d", &input);
        switch (input)
        {
        case 1:
            printf("ret = %d\n", Calc(add));
            break;
        case 2:
            printf("ret = %d\n", Calc(sub));
            break;
        case 3:
            printf("ret = %d\n",  Calc(mul));
            break;
        case 4:
            printf("ret = %d\n", Calc(divs));
            break;
        case 0:
            printf("退出程序\n");
            break;
        default:
            printf("选择错误\n");
            break;
        }
    } while (input);

    return 0;
}
*/
// qsort函数的使用者得实现一个比较函数stdio.h库函数的方法
#include <stdlib.h>
#include <string.h>
int int_cmp(const void *p1, const void *p2)
{
    return (*(int *)p1 - *(int *)p2);
}
struct Stu//结构体排序
{
    char name[20];
    int age;
};
int sort_by_age(const void *p1, const void *p2)
{
    return ((struct Stu *)p1)->age - ((struct Stu *)p2)->age;
}
int sort_by_name(const void *p1, const void *p2)
{
    return strcmp(((struct Stu *)p1)->name,((struct Stu *)p2)->name);
}
int main()
{
    int arr[] = {1, 3, 5, 7, 9, 2, 4, 6, 8, 0};
    int i = 0;
    qsort(arr, sizeof(arr) / sizeof(arr[0]), sizeof(int), int_cmp);
    //第一个参数是待排序的第一个对象的地址
    //目标对象的长度
    //目标元素字节大小
    //函数指针  用来比较待排序数据的2个元素的函数
    for (i = 0; i < sizeof(arr) / sizeof(arr[0]); i++)
    {
        printf("%d ", arr[i]);
    }
    printf("\n");
    struct Stu s[4] = {{"zhangsan",40},{"lisi",500},{"wangwu",30},{"zhaoliu",60}};
    qsort(s,sizeof(s) / sizeof(s[0]), sizeof(s[0]), sort_by_name);
    return 0;
}