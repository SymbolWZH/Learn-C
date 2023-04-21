#include <stdio.h>
#include<string.h>
#include<stdlib.h>
#include<windows.h>
// void Add(int *pa)
// {
//    (*pa)++;
// }
// //当需要改变实参的值的时候传地址过去
// int main()
// {
//     int num = 0;
//     Add(&num);
//     printf("%d",num);
//     return 0;
// }
//函数的嵌套调用和链式访问
//嵌套调用
// void tset(){
//     return 1;
// }
// void tset1(){
//     tset();
//     return 1;
// }
//链式访问 把一个函数的返回值作为另外一个函数的参数。
// int main()
// {
//     char arr[20] = "hello";
//     int ret = strlen(strcat(arr,"bit"));//这里介绍一下strlen函数
//     printf("%d", printf("%d", printf("%d",43)));// 4321
//     printf("%d\n", ret);// 8
//     return 0;
// }

//函数的声明
// int main()
// {
//     int a =10;
//     int b = 20;
//     int Add(int x, int y);//函数在主函数下面时需要声明 不然找不到
//     int c = Add(a,b);
//     printf("%d",c);
// }
// int Add(int x, int y)
// {
//     return x+y;
// }
// 模块化写法

#include "add.h"
//导入静态库
// #pragma comment(lib, "sub.lib")
int main()
{
	int a = 10;
	int b = 20;
	int c = Add(a, b);
	printf("%d\n", c);
	return 0;
}


