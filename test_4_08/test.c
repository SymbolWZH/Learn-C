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
// extern int g_val;
// int main()
// {
//     printf("%d\n",g_val);
//     return 0;
// }
// ##### 数据类型

// ```
// 类型的多个：             所占字节sizeof()
// 选择性和空间利用率越高						
// char        //字符数据类型	1
// short       //短整型		  2
// int         //整形		   4
// long        //长整型		  4
// long long   //更长的整形		 8
// float       //单精度浮点数	4
// double      //双精度浮点数	8
// printf("%d")中 %d是打印一个整数
// sizeof -关键字-操作符-计算类型或者变量所占空间的大小（bit 1个bit=2个位）
// byte - 字节 = 8bit kb = 1024byte mb = 1024kb gb = 1024mb tb = 1024gb pb = 1024tb
// //全局变量 - {}外部定义的
// //局部变量 - {}内部定义的 
// scanf函数是输入函数
// scanf("%d %d",&a,&b);
// 生命周期
// 变量的生命周期 变量的创建和销毁之间的时间段
// 常量
// 字面常量
// const 修饰的常变量 修饰后值不能被修改 //const int a = 10; a之后不可被修改
// #define 定义的标识符常量 #define Max 10;
// 枚举常量 可以一一列举的常量 默认从0开始可以赋初始值 enum Gender{MALE}
// 字符串默认隐藏/0 
// ```
//写一个函数求两个整数的较大值
//如：输入：10 20输出较大值：20
// int main()
// {
//     int i=0;
//     int j=0;
//     scanf("%d %d",&i,&j);
//     if(i>j)
//         return i;
//     else
//         return j;
// }
//给定两个数，求这两个数的最大公约数
// #include <stdio.h>
// int gcd(int a, int b ) {
//    if(b%a==0){
//         return a;
//     }
//     else{ 
//         return gcd(b%a,a);
//     }
// }
// //打印1000年到2000年之间的闰年
// int main()
// {
//     unsigned int i =0;
//     for ( i = 1000; i <=2000; i++)
//     {
//        if(i % 4 == 0 )
//        {
//         if(i%100!=0) // 如果year不能内100整除，则一定是闰年
// 			{
// 				printf("%d ", i);
// 			}
//        }
//        if(i%400 == 0)  // 每400年再润一次
// 		{
// 			printf("%d ", i);
// 		}
//     }
//     return 0;
// }
//写一个代码：打印100~200之间的素数
// int main()
// {
//  	int i = 0;//
// 	int count = 0;


// 	for(i=101; i<=200; i++)
// 	{
// 		//判断i是否为素数
// 		//2->i-1
// 		int j = 0;
// 		for(j=2; j<=i/2; j++)
// 		{
// 			if(i%j == 0)
// 			{
// 				break;
// 			}
// 		}
// 		//...
// 		if(j>i/2)
// 		{
// 			count++;
// 			printf("%d ", i);
// 		}
// 	}
// 	printf("\ncount = %d\n", count);
// 	return 0;
// }
//写代码将三个整数数按从大到小输出。
// void print(int a,int b,int c)
// {
//     if(a<b)
//     {
//         int tmp = a;
//         a=b;
//         b=tmp;
//     }
//     if(a<c)
//     {
//         int tmp = a;
//         a=c;
//         c=tmp;
//     }
//     if(b<c)
//     {
//         int tmp = b;
//         b=c;
//         c=tmp;
//     }
//      printf("a=%d b=%d c=%d\n", a, b, c);
    
// }
// int main(){
//     int a=0;
//     int b=0;
//     int c=0;
//     scanf("%d %d %d",&a,&b,&c);
//     print(a,b,c);
//     return 0;
// }

//写一个代码打印1-100之间所有3的倍数的数字
// int main()
// {
//     for (size_t i = 1; i < 100; i++)
//     {
//         if(i % 3 == 0)
//             printf("%d ",i);
//     }
    
// }
//编写代码在一个整形有序数组中查找具体的某个数
// int main()
// {
//     int arr[] = {1,2,3,4,5,6,7,8,9,10};
// 	int key = 3;
// 	int left = 0;
// 	int right = sizeof(arr)/sizeof(arr[0]); // right位置的数据取不到

// 	while(left<right) // right位置没有数据，此处不需要添加=
// 	{
// 		int mid = left+(right-left)/2;
// 		if(arr[mid]>key) // key小于中间位置数据，说明key可能在左半侧，需要改变右边界
// 		{
// 			right = mid; // right位置的数据取不到，因此right=mid，不需要减1
// 		}
// 		else if(arr[mid]<key)// key大于中间位置数据，说明key可能在右半侧，需要改变左边界
// 		{
// 			left = mid+1; // left位置的数据可以取到，因此left=mid+1
// 		}
// 		else
// 		{
// 			printf("找到了，下标是：%d\n", mid);
//             break;
// 		}
// 	}
   
// 	if(left>=right)
// 		printf("找不到\n");
// 	return 0;
// }
//编写程序数一下 1到 100 的所有整数中出现多少个数字9
// int main()
// {
//     int num =0;
//     for (size_t i = 0; i < 100; i++)
//     {

//             if(i / 10  == 9  )
//                 num++;
//             if(i % 10 == 9  )
//                 num++;
        
//     }
//     printf("%d",num);
//     return 0 ;
// }

//分数求和【题目内容】计算1/1-1/2+1/3-1/4+1/5 …… + 1/99 - 1/100 的值，打印出结果
/*
思路：
1. 从上述表达式可以分析出
   a. 该表达式主要由100项，基数项为正，偶数项为负
2. 设置一个循环从1~100，给出表达式中的每一项：1.0/i, 注意此处不能使用1，否则结果全部为0
    然后使用flag标记控制奇偶项，奇数项为正，偶数项为负
    然后将所有的项相加即可
*/
// int main()
// {
//     double num = 0.0;
//     int i=0;
//     int flag=1;
//     for ( i = 1; i <=100; i++)
//     {
//         num += flag*1.0/i;
//         flag = -flag;
//     }
//     printf("%lf",num);
//     return 0;
// }
//求10 个整数中最大值
// int main()
// {
//     int arr[10] = {0};
//     int i = 0;
//     for(i=0; i<10; i++)
// 	{
// 		scanf("%d", &arr[i]);
// 	}
//     int tmp = arr[0];
//     for ( i = 1; i < 10; i++)
//     {
//        if(arr[i] > tmp)
//             tmp = arr[i];
//     }
//     printf("%d",tmp);
//     return 0;
// }
//在屏幕上输出9*9乘法口诀表
int main()
{   
    int i = 0;
    for ( i = 1; i <= 9; i++)
    {
        int j=0;
        for ( j = 1; j <i+1; j++)
        {
            printf("%dx%d=%d ",i,j,i*j);
        }
        printf("\n");
    }
}
