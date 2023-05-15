#include <stdio.h>
#include<string.h>
#include<stdlib.h>
#include<windows.h>
#include<assert.h>

// 内存操作函数
// memcpy 内存拷贝  拷贝不重叠的内存
// void* my_memcpy( void *dest, const void *src, size_t num ){
//     void* ret = dest;
//     assert(dest && src);
//     while (num--)
//     {
//         *(char*)dest = *(char*)src;

//         dest = (char*)dest+1;
//         src = (char*)src+1;/* code */
//     }
//     return ret;
// }
// int main()
// {
//     int arr[10] = {1,2,3,4,5,6,7,8,9,10};
//     int arr2[10] = {0};
//     memcpy(arr2,arr,20);// 按照字节
//     for (size_t i = 0; i < 11; i++)
//     {
//         printf("%d ",arr2[i]);
//     }
//     system("pause");
//     return 0;
// }
// memmove  可以出来内存重叠的情况
//  void *memmove( void *to, const void *from, size_t count );
//  功能: 与mencpy相同，不同的是当to 和 from 重叠，函数正常仍能工作。
// void* my_memmove( void *dest, const void *src, size_t num )
// {
//     void * ret = dest;
//     assert(dest && src);
//     if(dest < src)
//     {
//         while (num--)
//         {
//             *(char*)dest = *(char*)src;
//             (char*)dest++;
//             (char*)src++;
//         }
        
//     }
//     else
//     {
//         while (num--)
//         {
//             *((char*)dest+num) = *((char*)src+num);
//         }
        
//     }
//     return ret;
// }

// int main()
// {
//     int arr[10] = {1,2,3,4,5,6,7,8,9,10};
//     my_memmove(arr,arr+3,20);// 按照字节
//     for (size_t i = 0; i < 10; i++)
//     {
//         printf("%d ",arr[i]);
//     }
//     system("pause");
//     return 0;
// }
// memset
//  #include <string.h>
//   void *memset( void *buffer, int ch, size_t count );
//  功能: 函数拷贝ch 到buffer 从头开始的count 个字符里, 并返回buffer指针。 memset() 可以应用在将一段内存初始化为某个值。例如：
//     memset( the_array, '\0', sizeof(the_array) );这是将一个数组的所以分量设置成零的很便捷的方法。
int main()
{
    int arr[4];
    memset(arr,0,16);//以字节为单位设置内存
    for (int i = 0; i < 4; i++)
    {
       printf("%d ",arr[i]);
    }
    
    printf("%d\n",0);
    return 0;
}

// memcmp  内存比较
//  #include <string.h>
//int memcmp( const void *buffer1, const void *buffer2, size_t count );
// Value         解释 
// less than 0  buffer1 is less than buffer2 
// equal to 0   buffer1 is equal to buffer2 
// greater than 0 buffer1 is greater than buffer2
 

// int main()
// {
//     float arr1[] = {1.0,2.0,3.0,4.0};
//     float arr2[] = {1.0,3.0};
//     int ret = memcmp(arr1,arr2,4);
//     printf("%d\n",ret);
//     return 0;
// }
