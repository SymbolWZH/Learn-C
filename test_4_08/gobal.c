#include <stdio.h>
int g_val = 2000;
/*
    知识点：
*/

/*
    程序要求：
*/
// Add(num1,num2){
//     int z = 0;
//     z = num1+num2;
//     return z;
// };

// int main()
// {
//     int num = 0;
//     int num1 = 0;
//     scanf("%d%d",&num,&num1);
//     int sum = Add(num,num1);
//     printf("%d\n",sum);

//     // 数组 一组相同类型的元素的集合
//     // 10个整形1 -10 存起来
//     // 数组是用下标来访问的
//     int arr[10] = {1,2,3,4,5,6,7,8,9,10};//不填满的部分默认为0

//     return 0;
// }

//移位操作符 >>  <<
//操作符是移动的二进制位
// int main(){
//     int a = 10;
//     int b = a>>5;
//     printf("%d\n",b);
// }
//  ~ 按位取反  按二进制位 取反   1变成0 0变成1
// int main(){
//     int a = 10;
//     printf("%d\n",~a);
//     return 0;
// }
// 逗号 表达式 整个是从左向右依次计算的
// 整个表达式的结果是最后一个表达式的结果
// int main(){
//     int a =0;
//     int b =3;
//     int c = 5;
//     int d = (a = b+3,c=a+4,d=a+c);
//     printf("%d\n",d);
//     //
//     //register int num = 100;
// }
// typedef unsigned int u_int; 类型重命名
// static 修饰局部如果全局变量被定义static之后变成了内部变量 就不会被其他
//文件所访问到

// define预处理指令 定义常量 和 宏 
// #define ADD(X,Y) (X + Y)
// int main()
// {
//     printf("%d\n",4 * ADD(2,3));
//     printf("%p\n",4 * ADD(2,3));
//     int a = ADD(2,3);
//     int * pa = &a; //pa使用了存放地址的，在c语言钟pa叫是指针变量 
//     printf("%p\n",pa);
//     *pa = 10; //解引用操作 *pa就是通过pa里面的地址找到a
//     printf("%d\n",a);
//     // int pa说明执行的对象是int 类型的

//     printf("%d\n",sizeof (char*)); //指针的大小和地址线有关 
//     printf("%d\n",sizeof (short*));//32位4个字节 64位8个字节
//     printf("%d\n",sizeof (double*));
// }


// struct Stu
// {
//     char name[20];
//     int age;
//     float id;
//     /* data */
// };
// int main()
// {
//     struct Stu s = {"张三",20,80.5};//结构体的创建和初始化
//     printf("%s,%d,%lf",s.name,s.age,s.id);//
//     struct Stu * pa = &s;
//     printf("%s,%d,%lf",(*pa).name,(*pa).age,(*pa).id);//解引用
//     printf("%s,%d,%lf",pa->name,pa->age,pa->id);//解引用 三个都是一样


//     int n = 10;
//     int arr[n];
//     printf("%d\n",strlen(arr));
//     return 0;
// }


// int main()
// {
//     int ch = getchar();//getchar获取键盘输入的第一个字符；
//     //gets 读一行
//     // EOF - end of file -文件结束标识
//     putchar(ch);//输出一个字符

//     //两个字符串进行比较 不能用 == 
//     // 比较使用if(strcmp(username,"123456") == 0)
//     return 0;
// }