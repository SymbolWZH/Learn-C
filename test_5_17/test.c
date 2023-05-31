#include <stdio.h>
#include<string.h>
#include<stdlib.h>
#include<windows.h>
//  联合大小的计算
// 联合的大小至少是最大成员的大小。
// 当最大成员大小不是最大对齐数的整数倍的时候，就要对齐到最大对齐数的整数倍。
/// @brief 联合体联合类型的定义
/// @return 
union Un
{
    char c;
    int i;
};

int main()
{
        //联合变量的定义
    union Un un;
    un.c = 100;
    un.i = 1000;
    printf("%p\n", &un);
    printf("%p\n", &(un.c));
    printf("%p\n", &(un.i));
    //计算连个变量的大小
    printf("%d\n", sizeof(un));
    return 0;
}