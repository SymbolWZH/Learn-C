#include <stdio.h>
#include<string.h>
#include<stdlib.h>
#include<windows.h>
#include <assert.h>
#include <errno.h>
// 求字符串长度
// strlen
// size_t my_strlen(const char *arr)
// {
//     size_t len = 0;
//     assert(arr != NULL);
//     while (*arr != '\0')
//     {
//         len++;
//         arr++;
//     }
//     return len;
// }
// int main()
// {
//     char arr[] = "abc";// 3
//     //char arr[] = {'a','b','c'};
//     size_t len = my_strlen(arr);
//     printf("%d",len);
//     return 0;
// }
// 长度不受限制的字符串函数
// strcpy
// int main()
// {
//     char arr[20] = "#####";
//     char *p = "hello world";//这是h的地址
//     // strcpy(arr,p);
//     // strcpy(arr,"hello");
//     char arr2[] = {'a','b','c'};
//     strcpy(arr,p);
//     printf("%s\n",arr);
//     return 0;
// }
// strcat字符串追加
// char* my_strcat(char * dest,char* src)
// {   //1找到目标字符串中的\0
//     char * ret = dest;
//     assert(dest && src);
//     while (*dest)
//     {
//         dest++;//找到\0 找到0while循环结束
//     }
//     while (*dest++ = *src++)
//     {
//         ;/* code */
//     }
//     return ret;
// }
// int main()
// {
//     char  arr[20] = "hello ";
    
//     printf("%s\n",my_strcat(arr,"world111"));
//     return 0;
// }
// strcmp
// 长度受限制的字符串函数介绍
// int my_strcmp(const char * dest,const char * src)
// {
//     assert(dest && src);
//     while (*dest == *src)
//     {
//         if(*dest == '\0')
//         {
//             return 0;
//         }
//         dest++;
//         src++;
//     }
//     return *dest - *src;
// }
// int main()
// {
//     char* arr= "abc";
//     char* arr2= "abc";
//     printf("%d\n",my_strcmp(arr,arr2));
//     return 0;
// }
// strncpy
// int main()
// {
//     char arr1[20] = "abcdef";
//     char arr2[] = "qwer";
//     strncpy(arr1,arr2,6);
//     printf("%s\n",arr1);
//     return 0;
// }
// strncat
// int main()
// {
//     char arr1[20] = "abcdasdddddddddddef ";
//     char arr2[] = "qwasderasdasd";
//     strncat(arr1,arr2,6);
//     printf("%s\n",arr1);
//     return 0;
// }
// strncmp
// int main()
// {   
//     char * p = "abced";
//     char * d = "abcpl";
//     int ret = strncmp(p,d,4);
//     printf("%d\n",ret);
//     return 0;
// }
// 字符串查找
// strstr
// char * my_strstr(const char*dest,const char * src)
// {
//     assert(dest && src);
//     const char* s1 = NULL;
//     const char* s2 = NULL;
//     const char * pth = dest;
//     if(*src == '\0')
//         return (char*)dest;
//     while (*pth)
//     {
//         s1 = pth;
//         s2 = src;
//         while (*s1 && *s2 &&(*s1 == *s2))
//         {
//             s1++;
//             s2++;
//         }
//         if(*s2 == '\0')
//             return (char*)pth;
//         pth++;
//     }
//     return NULL;
// }
// int main()
// {   
//     char arr[] = "adsasdad";
//     char arr2[] = "asd";
//     char * ret = my_strstr(arr,arr2);
//     if(ret == NULL)
//     {
//         printf("没找到,%s\n",ret);
//     }
//     else
//     {
//          printf("找到了,%s\n",ret);
//     }
//     return 0;
// }
// strtok  切割字符串
// int main()
// {
//     char arr[] = "wzh@163.com";
//     char *p = "@.";
//     char tmp[20] = {0};
//     strcpy(tmp,arr);//copy 
//     char * ret =NULL;
//     for (ret = strtok(tmp,p);ret !=NULL;ret=strtok(NULL,p))
//     {
//        printf("%s\n",ret);
//     }
    


//     // ret = strtok(tmp,p);
//     // printf("%s\n",ret);
//     // ret = strtok(NULL,p);
//     // printf("%s\n",ret);
//     // ret = strtok(NULL,p);
//     // printf("%s\n",ret);
//     return 0;
// }
// 错误信息报告
// strerror
// int main()
// {

//     // printf("%s\n",strerror(0));//No error 没有错误
//     // printf("%s\n",strerror(1));//Operation not permitted 操作被拒绝
//     // printf("%s\n",strerror(2));//No such file or directory 没有找到这个文件
//     // printf("%s\n",strerror(3));//No such process 没有这个进程
//     // printf("%s\n",strerror(4));//Interrupted function call  调用函数被终端
//     // printf("%s\n",strerror(5));//Input/output error  输入输出错误
//     FILE* pf = fopen("test.x","r");
//     if(pf == NULL)
//     {
//         printf("%s\n",strerror(errno));
//         perror("fopen");
//         return 1;
//     }
//     fclose(pf);
//     return 0;
// }
//函数 如果他的参数符合下列条件就返回真
// iscntrl 任何控制字符
// isspace 空白字符：空格‘ ’，换页‘\f’，换行'\n'，回车‘\r’，制表符'\t'或者垂直制表符'\v'
// isdigit 十进制数字 0~9
// isxdigit 十六进制数字，包括所有十进制数字，小写字母a~f，大写字母A~F
// islower 小写字母a~z
// isupper 大写字母A~Z
// isalpha 字母a~z或A~Z
// isalnum 字母或者数字，a~z,A~Z,0~9
// ispunct 标点符号，任何不属于数字或者字母的图形字符（可打印）
// isgraph 任何图形字符
// isprint 任何可打印字符，包括图形字符和空白字符
// int main()
// {   
//     char ch = 'a';
//     int ret =islower(ch);
//     printf("%d\n",ret);
//     return 0;
// }
//字符转换
// int toupper(int c);//转大写
// int tolower(int c);//转小写
int main()
{
    char arr[20] = {0};
    scanf("%s",arr);
    int i =0;
    while (arr[i] != '\0')
    {
        if(isupper(arr[i]))
        {
            arr[i] = tolower(arr[i]);
        }
        else{
             arr[i] = toupper(arr[i]);
        }
        printf("%c ",arr[i]);
        i++;
    }
    
    
    return 0;
}
// 字符操作
// 内存操作函数
// memcpy
// memmove
// memset
// memcmp
// int main()
// {
// printf("");
// system("pause");
// return 0;
// }