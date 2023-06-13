#include <stdio.h>
#include<string.h>
#include<stdlib.h>
#include<windows.h>

#define M 100
#define PRINT

int main()
{
    int a = M;

    printf("%d\n",M);
#undef M //这条指令用于移除一个宏定义。
//如果现存的一个名字需要被重新定义，那么它的旧名字首先要被移除。

#if 0

// 命令行定义 在Linux下 /gcc -D ARRAY_SIZE=10 test.c
// 许多C 的编译器提供了一种能力，允许在命令行中定义符号。用于启动编译过程。
// 例如：当我们根据同一个源文件要编译出不同的一个程序的不同版本的时候，这个特性有点用处。（假
// 定某个程序中声明了一个某个长度的数组，如果机器内存有限，我们需要一个很小的数组，但是另外一
// 个机器内存大写，我们需要一个数组能够大写。）
  int array [ARRAY_SIZE];
  int i = 0;
  for(i = 0; i< ARRAY_SIZE; i ++)
  {
    array[i] = i;
  }
  for(i = 0; i< ARRAY_SIZE; i ++)
  {
    printf("%d " ,array[i]);
  }
  printf("\n" );
 

#endif
//条件编译
// 在编译一个程序的时候我们如果要将一条语句（一组语句）编译或者放弃是很方便的。因为我们有条件
// 编译指令。
// 比如说：
// 调试性的代码，删除可惜，保留又碍事，所以我们可以选择性的编译。


#ifdef PRINT  //满足条件的时候就编译  如果PRINT被定义了就执行下面语句
    printf("hehe\n");
#endif
#if 1-3
    printf("haha\n");
#endif

#ifdef TEST //如果TEST被定义了就执行下面语句
     printf("TEST\n");

#endif



#if defined(TEST) //if defined(TEST) == #ifdef TEST 
     printf("TEST\n");
#endif

#ifndef TEST //如果TEST没有被定义了就执行下面语句
     printf("no TEST\n");
#endif

#if !defined(TEST) //!defined(TEST)是取反
     printf("TEST\n");
#endif


//嵌套指令
#if defined(OS_UNIX)
 #ifdef OPTION1
 unix_version_option1();
 #endif
 #ifdef OPTION2
 unix_version_option2();
 #endif
#elif defined(OS_MSDOS)
 #ifdef OPTION2
 msdos_version_option2();
 #endif
#endif

/*
comm.h和comm.c是公共模块。
test1.h和test1.c使用了公共模块。
test2.h和test2.c使用了公共模块。
test.h和test.c使用了test1模块和test2模块。
这样最终程序中就会出现两份comm.h的内容。这样就造成了文件内容的重复。
如何解决这个问题？
答案：条件编译
*/
#ifndef __TEST_H__
#define __TEST_H__
//头文件的内容
#endif   //__TEST_H__
//或者
#pragma once

    return 0;
}
