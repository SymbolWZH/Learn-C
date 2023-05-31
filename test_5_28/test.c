#include <stdio.h>
#include<string.h>
#include<stdlib.h>
#include<windows.h>
#if 0
int main()
{
   
   FILE * fp = NULL;

   fp = fopen("a.txt","a+");

   if(fp == NULL)
   {
    perror("fail open");
    return 1;
   }
   char ch;
   fputs ("fopen exampleaaaa",fp);
   
    printf("%s",ch);
    fclose(fp);
    return 0;

}
#endif

#if 0 
//scanf 针对标准输入的格式化的输入语句      stdin
//fscanf 针对所有输入流的格式化的输入语句
//sscanf 从一个字符串中读取一个格式化的数据
//printf 针对标准输出的格式化输出语句       stdout
//fprintf 针对所有输出流的格式化输出语句  - stdout/文件
//sprintf 把一个格式化的数据，转化为字符串

struct S
{
    char arr[10];
    int age;
    float f;
};
int main()
{
    struct S s = {"hello",20,2.0};
    struct S tmp = {0};
    char buf[100] = {0};
    sprintf(buf,"%s %d %.2f",s.arr,s.age,s.f);
    //从buf字符串中还原出一个结构体数据
    sscanf(buf,"%s %d %f",tmp.arr,&(tmp.age),&(tmp.f));
    printf("%s %d %.2f\n",tmp.arr,tmp.age,tmp.f);
    printf("%s\n",buf);
    return 0;
}
#endif
#if 0

int main()
{
     FILE *pf = fopen("a.txt","r");
    if(pf == NULL)
    {
        perror("fopen");
        return 1;
    }
    //读取文件
    int ch = fgetc(pf);
    printf("%c\n",ch);
    //fseek 根据文件的偏移量定位文件指针  int fseek( FILE *stream, long offset, int origin );
    // SEEK_SET 从文件的开始处开始搜索 
    // SEEK_CUR 从当前位置开始搜索 
    // SEEK_END 从文件的结束处开始搜索 

    fseek(pf,1,SEEK_CUR);
    ch = fgetc(pf);
    printf("%c\n",ch);
    //long ftell( FILE *stream );ftell()函数返回stream(流)当前的文件位置,如果发生错误返回-1. 
    printf("%d\n",ftell(pf));
    //函数rewind()把文件指针移到由stream(流)指定的开始处, 同时清除和流相关的错误和EOF标记. void rewind( FILE *stream );
    rewind(pf);
    printf("%d\n",ftell(pf));
    //关闭文件
    fclose(pf);
    pf = NULL;
}

#endif

#if 0
int main()
{
    int a = 10000;
    FILE *pf = fopen("text.txt","wb");
    if(pf == NULL)
    {
        perror("fopen");
        return 1;
    }
    //写文件
    // int fwrite( const void *buffer, size_t size, size_t count, FILE *stream );
    //fwrite()函数从数组buffer(缓冲区)中, 写count个大小为size(大小)的对象到stream(流)指定的流. 返回值是已写的对象的数量. 
    fwrite(&a,sizeof(int),1,pf);
    //feof 不能用于判断文件读取是否结束    应用于 判断读取失败结束  还是遇到文件尾结束
    //fgetc 函数再读取结束的时候 会返回EOF 正常读取的时候返回的是字符的ASCII码值
    //fgets 函数在读取结束的时候会返回NULL  正常读取的时候 返回存放字符串的空间起始地址
    //fread 函数在读取的时候 返回的是实际读取到的完整元素的个数 如果发现读取到的完整的元素的个数小于指定的元素个数，这就是最后一次读取
    //关闭文件
    fclose(pf);
    pf = NULL;
}

#endif
#if 0

int main()
{
    //文件拷贝
    //读取要拷贝的文件
    FILE*pf_str = fopen("a.txt","r");
    if(pf_str == NULL)
    {
        perror("fopen");
        return 1;
    }
    //创建拷贝文件
    FILE*pf_copy = fopen("b.txt","w");
    if(pf_str == NULL)
    {
        fclose(pf_str);
        pf_str = NULL;
        perror("fopen");
        return 1;
    }
    //读写文件
    //一个字符一个字符读
    int ch = 0;
    while ((ch =fgetc(pf_str)) != EOF)
    {
        fputc(ch,pf_copy);
        /* code */
    }
    //判断是什么原因结束
    //ferror()函数检查stream(流)中的错误, 如果没发生错误返回0,否则返回非零. 如果发生错误, 使用perror()检测发生什么错误. 
    if(ferror(pf_str))
        puts("I/O error when reading");
    else if(feof(pf_str))
    //函数feof()在到达给出的文件流的文件尾时返回一个非零值
        puts("End of file reached successfully");
    //关闭文件
    fclose(pf_str);
    fclose(pf_copy);
    pf_str = NULL;
    pf_copy = NULL;
}
#endif

//#if 0
// ANSIC 标准采用“缓冲文件系统”处理的数据文件的，所谓缓冲文件系统是指系统自动地在内存中为程序
// 中每一个正在使用的文件开辟一块“文件缓冲区”。从内存向磁盘输出数据会先送到内存中的缓冲区，装
// 满缓冲区后才一起送到磁盘上。如果从磁盘向计算机读入数据，则从磁盘文件中读取数据输入到内存缓
// 冲区（充满缓冲区），然后再从缓冲区逐个地将数据送到程序数据区（程序变量等）。缓冲区的大小根
// 据C编译系统决定的。
//VS2013 WIN10环境测试
int main()
{
    FILE*pf = fopen("test.txt", "w");
    fputs("abcdef", pf);//先将代码放在输出缓冲区
    printf("睡眠10秒-已经写数据了，打开test.txt文件，发现文件没有内容\n");
    Sleep(10000);
    printf("刷新缓冲区\n");
    fflush(pf);//刷新缓冲区时，才将输出缓冲区的数据写到文件（磁盘）
    //注：fflush 在高版本的VS上不能使用了
    printf("再睡眠10秒-此时，再次打开test.txt文件，文件有内容了\n");
    Sleep(10000);
    fclose(pf);
    //注：fclose在关闭文件的时候，也会刷新缓冲区
    pf = NULL;
    return 0;
}
//#endif