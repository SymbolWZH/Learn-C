
#include <stdio.h>
//如何避免野指针
/*
    1. 指针初始化
    2. 避免越界  c语言本身不会检测数组越界行为
    3. 指针指向空间释放即使置为NULL
    4. 指针使用之前检查有效性
*/


// int main()
// {
//     int *p;//p是一个局部的指针变量，没有初始化的时候是一个随机值
//     *p = 20; //非法访问内存 野指针
//     return 0;
// }


// int * test()
// {
//     int a = 10;
//     return &a;//当进入函数的时候取到地址 但是函数结束之后地址就销毁了
// }
// int main()
// {
//     int *p = test();//非法访问
//     *p = 20; //
//     return 0;
// }
// int main()
// {
//     int* p = NULL;//当不知道地址的时候初始化为NULL

//     return 0;
// }
/*

    指针+-整数   
    指针减去指针得到的是两个指针元素之间的个数：前提两个指针指向同一块空间
    #define N_VALUES 5
    float values[N_VALUES];
    float *vp;
    //指针+-整数；指针的关系运算
    for (vp = &values[0]; vp < &values[N_VALUES];)
    {
        *vp++ = 0;
    }
    指针-指针
*/