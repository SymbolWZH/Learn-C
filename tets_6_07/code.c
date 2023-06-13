#include <stdio.h>
#include<string.h>
#include<stdlib.h>
#include <assert.h>
#include <ctype.h>
#include <limits.h>
//atoi 把字符串转换为整数
//模拟实现
// enum State
// {
// 	INVALID,//0
// 	VALID   //1
// };

// //state 记录的是my_atoi 返回的值是合法转化的值，还是非法的状态

// enum State state = INVALID;

// int my_atoi(const char* s)
// {
// 	int flag = 1;
// 	//assert(NULL != s);
// 	// 
// 	//空指针
// 	if (NULL == s)
// 	{
// 		return 0;
// 	}
// 	//空字符
// 	if (*s == '\0')
// 	{
// 		return 0;
// 	}
// 	//跳过空白字符
// 	while (isspace(*s))
// 	{
// 		s++;
// 	}
// 	//+/-
// 	if (*s == '+')
// 	{
// 		flag = 1;
// 		s++;
// 	}
// 	else if (*s == '-')
// 	{
// 		flag = -1;
// 		s++;
// 	}
// 	//处理数字字符的转换
// 	long long n = 0;
// 	while (isdigit(*s))
// 	{
// 		n = n * 10 + flag*(*s - '0');
// 		if (n > INT_MAX || n < INT_MIN)
// 		{
// 			return 0;
// 		}
// 		s++;
// 	}
// 	if (*s == '\0')
// 	{
// 		state = VALID;
// 		return (int)n;
// 	}
// 	else
// 	{
// 		state = VALID;
// 		//非数字字符的情况
// 		return (int)n;
// 	}
// }

// int main() 
// {
// 	//1. 空指针
// 	//2. 空字符串
// 	//3. 遇到了非数字字符
// 	//4. 超出范围
	
// 	//const char* p = "-123111111111111111111111111111111111111";
// 	//"0"
// 	//int ret = my_atoi(p);
// 	const char* p = "     23";
// 	int ret = my_atoi(p);

// 	if (state == VALID)
// 		printf("正常的转换：%d\n", ret);
// 	else
// 		printf("非法的转换：%d\n", ret);

// 	return 0;
// }

//模拟实现strncat

// char * mystrncat(char * dst, const char * src, size_t n)
// {
// 	char * tmp = dst;
 
// 	while (*dst)
// 	{
// 		dst++;
// 	}
 
// 	int i;
// 	for (i = 0; src[i] && i < n; i++)
// 	{
// 		dst[i] = src[i];
// 	}
 
// 	dst[i] = 0;
// 	return tmp;
// }
 
// int main(){
// 	char dest[1024] = "my name is ";
// 	const char source[] = "wzh!";
// 	if (dest != NULL&&*source != '\0'){
// 		//printf("strncat=%s\n",strncat(dest, source, strlen(source)));
// 		printf("%s\n", mystrncat(dest, source, strlen(source)));
 
// 	}
// 	return 0;
// }

//模拟实现一个 strncopy
// char*my_strncpy(char*dest, const char*src, size_t n)
// {
// 	assert(dest != NULL);
// 	assert(src != NULL);
// 	char*ret = dest;
// 	while (n)
// 	{
// 		*dest = *src;
// 		src++;
// 		dest++;
// 		n--;
// 	}
// 	return ret;
// }
 
// int main()
// {
// 	char arr[20] = { 0 };
// 	char*p = "bit";
// 	int n = 0;
// 	printf("请输入拷贝的字符个数：\n");
// 	scanf("%d", &n);
// 	char*ret = my_strncpy(arr, p,n);
// 	printf("%s\n", ret);
// 	return 0;
// }


//找出只出现一次的数字
// void Find(int arr[],int sz,int *px,int*py)
// {
//     // 1  把所有数字异或
//     int i = 0;
//     int ret = 0;
//     for ( i = 0; i < sz; i++)
//     {
//         ret ^= arr[i];
//     }
//     int pos = 0;
//     //计算ret哪一位为1
//     for ( i = 0; i < 32; i++)
//     {
//         if((ret>>1) & 1 == 1)
//         {
//             pos = i;
//             break;
//         }
//     }
//     // 把从低位向高位低pos位为1，为0的放在另外一个组
//     int num1 = 0;
//     int num2 = 0;
//     for ( i = 0; i < sz; i++)
//     {
//         if(((arr[i]>>pos)&1)==1)
//         {
//             num1 ^= arr[i];
//         }
//         else
//         {
//             num2 ^= arr[i];
//         }
//     }
//     *px = num1;
//     *py = num2;
    
// }
// int main()
// {
//     int arr[] = {1,2,3,4,5,6,1,2,3,4};
//     int x= 0;
//     int y = 0;
//     const int sz = sizeof(arr) / sizeof(arr[0]);
//     Find(arr,sz,&x,&y);
//     printf("%d %d",x,y);
//     return 0;
// }

//写一个宏 可以将一个数的二进制位的奇数位和偶数位互换
// #define SWAP(N) ((N & 0xaaaaaaaa)>>1) + ((N & 0x55555555)<<1)

// int main()
// {
//     int a = 10;
//     int ret = SWAP(a);
//     printf("%d",ret);
// }
//写一个宏 可以计算出一个结构体中成员的偏移量
#include <stddef.h>
#define OFFSETOF(struct_name,mem_name) (int)&(((struct_name*)0)->mem_name)
struct A
{
    char a;
    int b;
    short c;
    long d;
};
int main()
{
    
    printf("%d\n",OFFSETOF(struct A,a));
    printf("%d\n",OFFSETOF(struct A,b));
    printf("%d\n",OFFSETOF(struct A,c));
    printf("%d\n",OFFSETOF(struct A,d));
    return 0;
}