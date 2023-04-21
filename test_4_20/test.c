#include <stdio.h>
#include<string.h>
#include<stdlib.h>
#include<windows.h>
// int main()
// {
// printf("");
// system("pause");
// return 0;
// }
// 汉诺塔
/*
1 A->C  1
2 A->B A->C B->C  3 
3 A->C A->B C->B A->C B->A A->C  7
64  2^64-1
*/
// void moves(char* pos1,char* pos2)
// {
//     printf("%s -> %s ",pos1,pos2);
// }
/*
n 代表盘子的个数
pos1 代表其实位置
pos2 代表中转位置
pos3 代表目标位置
*/
// void Hanoi(int n,char* pos1,char* pos2,char* pos3)
// {
//     if(n == 1)
//     {
//         moves(pos1,pos3);
//     }
//     else
//     {
//         Hanoi(n-1,pos1,pos3,pos2);
//         moves(pos1,pos3);
//         Hanoi(n-1,pos2,pos1,pos3);
//     }

// }
// int main()
// {
//     Hanoi(5,"A","B","C");
// }
// 1-100 9出现的个数


// int main()
// {
//     int i = 0;
//     int count = 0;
//     for(i = 1;i <=100;i++)
//     {
//         if(i % 10 == 9)
//             count++;
//         if(i / 10 == 9)
//             count++;
//     }
//     printf("%d ",count);
// }


// 计算 1/1 - 1/2 + 1/3-........+ 1/99 -1 /100
// int main()
// {
//     int i =1;
//     int flag = 1;
//     double sum = 0.0;
//     for ( i = 1; i <=100; i++)
//     {
//         sum += flag*1.0 / i;
//         flag = -flag;
//         /* code */
//     }
//     printf("%lf\n",sum);
//     return 0;
// }


//求十个整数中最最大值
// int main()
// {
//     int arr[10] = {0};
//     scanf("%d %d %d %d %d %d %d %d %d %d",&arr[0],&arr[1],&arr[2],&arr[3],&arr[4],&arr[5],&arr[6],&arr[7],&arr[8],&arr[9],&arr[10]);
//     int i = 0;
//     int max = arr[0];
//     int length = sizeof(arr) / sizeof(arr[0]);
//     for ( i = 1; i <length ; i++)
//     {
//         if(max < arr[i])
//             max = arr[i];
//         /* code */
//     }
//     printf("%d\n",max);
//     return 0;
// }


//乘法口诀表
// int main()
// {
//     int i = 1;
//     int j = 1;
//     for (i = 1; i < 10; i++)
//     {
//         for (j = 1; j <= i; j++)
//         {
//            printf("%d*%d=%-2d ",i,j,i*j);
//         }
//         printf("\n");
//     }
//     return 0;
// }


//反转字符串
// int my_strlen(char* str)
// {
//     int count =0;
//     while (*str != '\0')
//     {
//         count++;
//         str++;
//     }
//     return count;
// }
// void reverse_string(char* str)//逆序递归
// {
//     char tmp = *str;//1
//     int len = my_strlen(str);
//     *str = *(str + len -1);//2
//     *(str + len -1) = '\0';//3
//     if(my_strlen(str+1)>=2)
//     {
//         reverse_string(str+1);//4
//     }
//     *(str+len - 1) =tmp;//5
// }
// {//替换
//     int left = 0;
//     int right = my_strlen(str) -1;
//     while (left<right)
//     {
//         char tmp = str[left];//解引用方法 *(str + left)
//         str[left] = str[right];
//         str[right] = tmp;
//         left++;
//         right--;
//         /* code */
//     }
// }
// int main()
// {
//     char arr[] = "abcdefghjkl";
//     reverse_string(arr);
//     printf("%s\n",arr);
//     return 0;
// }

//写一个递归函数 DigitSum(n) 输入非负整数，返回组成他的数字之和
// 输入 1729 返回1+7+2+9 19
// int DigitSum(int n)
// {
//     if(n>9){
//          return DigitSum(n / 10) + n% 10;
//     }
//     else
//         return n;
//     }
// int main()
// {
//     int num = 0;
//     scanf("%d",&num);
//     printf("%d\n",DigitSum(num));
//     return 0;
// }

//编写一个函数实现n的k次方 使用递归实现
double Pow(int n,int k)
{
    
    if( k == 0)
        return 1.0;
    else if(k > 0)
        return n * Pow(n,k -1 );
    else
        return 1.0 / (Pow(n,-k ));
}
int main()
{
    int num = 0;
    int k = 0;
    scanf("%d %d",&num,&k);
    printf("%.2lf\n",Pow(num,k));
    return 0;
}