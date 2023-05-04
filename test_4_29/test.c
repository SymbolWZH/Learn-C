// 指针进阶
/*
1. 字符指针
2. 数组指针
3. 指针数组
4. 数组传参和指针传参
5. 函数指针
6. 函数指针数组
7. 指向函数指针数组的指针
8. 回调函数
9. 指针和数组面试题的解析
*/
#include <stdio.h>
/*
int main()
{
    char *ps = "hello world";//把首字符的地址存储在了ps中了
    char arr[] = "hello ";

    //printf("%s\n",ps); == printf("%s\n",arr);
    return 0;
}
*/
/*
int main()
{
    char str1[] = "hello";
    char str2[] = "hello";
    char* str3 = "hello";
    char* str4 = "hello";
    if(str1 == str2)//str1 != str2 因为存的地址不一样都独自开辟了一个地址空间
        printf("str1 and str2 are same \n");
    else
        printf("str1 and str2 no same \n");

    if(str3 == str4)//str3 == str4 因为存的地址一样相当于一个地址
        printf("str3 and str4 are same \n");
    else
        printf("str3 and str4 no same \n");

    return 0;
}
*/
/*
    int* arr1[10]; //整形指针的数组
    char *arr2[4]; //一级字符指针的数组
    char **arr3[5];//二级字符指针的数组
*/

/*
int main()
{
    int a[5] = {1, 2, 3, 4, 5};
    int b[] = {2, 3, 4, 5, 6};
    int c[] = {3, 4, 5, 6, 7};
    
    int *arr[3] = {a, b, c};
    int i = 0;
    for (i = 0; i < 3; i++)
    {
        int j = 0;
        for (j = 0; j < 5; j++)
        {
           // printf("%d ", *(arr[i] + j ));
            printf("%d ", arr[i][j]);
        }
        printf("\n");
    }
    return 0;
}
*/

//数组指针 指向数组的指针 
/*
int main()
{
    int a= 0;
    int *pa = &a;
    char ch = 'w';
    char *pc = &ch;

    int arr[10] = {1,2,3,4,5};
    int (*parr)[10] =&arr;//取出的是数组的地址
    //parr 就是一个数组指针 其中存放的是数组的地址
    int i = 0;
    for ( i = 0; i < 10; i++)
    {
       *(parr[i]) = 0;
       printf("%d ", *(parr[i]));// 0 0 0 0 0 0 0 0 0 0
    }
    
    double* d[5];
    double* (*pd)[5] = &d;//ok  pd就是一个数组指针
}
*/

/*
int main()
{
    int arr[10] = {0};
    int *p1 = arr;
    int (*p2)[10]= &arr;

    printf("%d\n",p1);
    printf("%d\n",p1+1);

    printf("%d\n",p2);
    printf("%d\n",p2+1);
    // 根据上面的代码我们发现，其实&arr和arr，虽然值是一样的，但是意义应该不一样的。
    // 实际上： &arr 表示的是数组的地址，而不是数组首元素的地址。（细细体会一下）
    // 本例中 &arr 的类型是： int(*)[10] ，是一种数组指针类型
    // 数组的地址+1，跳过整个数组的大小，所以 &arr+1 相对于 &arr 的差值是40

//数组名是什么？ 数组名是数组首元素的地址
//有两个例外  
//1. sizeof(数组名) --- 数组名表示整个数组 -计算的是整个数组的大小单位是字节
//2. &(取地址)数组名 --- 数组名表示整个数组，取出的是这个数组的地址
}
*/

/*

int main()
{
    int arr[10] = {1,2,3,4,5,6,7,8,9};
    int (*pa)[10] = &arr;//(*pa)[10]相当于拿到整个数组
    int i = 0;
    for ( i = 0; i < (sizeof(arr) / sizeof(arr[0])); i++)
    {
        printf("%d ", *(*pa+i));//1 2 3 4 5 6 7 8 9 0 
    }
    return 0;
}
*/

/*
void print1(int arr[3][5],int row,int col)
{
    int i=0,j=0;
    for ( i = 0; i < row; i++)
    {
        for ( j = 0; j < col; j++)
        {
            printf("%d ",arr[i][j]);
        }
        printf("\n");
    }
    
}
void print2(int (*p)[5],int row,int col)//(*p)表示第一行首地址
{
    int i=0,j=0;
    for ( i = 0; i < row; i++)
    {
        for ( j = 0; j < col; j++)
        {
            printf("%d ",*(*(p+i)+j));
        }
        printf("\n");
    }
    
}
int main()
{
    int arr[3][5] = {{1,2,3,4,5},{3,4,5,6,7},{5,6,7,8,9}};
    print1(arr,3,5);
    print2(arr,3,5);
    return 0;
}
*/

/*
int arr[5];//整型数组
int *parr1[10];//整型指针的数组
int (*parr2)[10];//数组指针，该指针能够指向一个数组，数组10个元素，每个元素的类型是int
int (*parr3[10])[5];//parr3是一个存储数组指针的数组该数组能够存放10个数组指针
//每个数组指针能够指向一个数组，数组五个元素 ，每个元素是int类型
*/

/*
 一维数组传参
void test(int arr[])//ok? ok
{}
void test(int arr[10])//ok? ok
{}
void test(int *arr)//ok? ok//首元素地址
{}
void test2(int *arr[20])//ok?  ok
{}
void test2(int **arr)//ok? ok
{}
int main()
{
 int arr[10] = {0};
 int *arr2[20] = {0};//整型指针数组
 test(arr);
 test2(arr2);
}
*/

/*
//二维数组传参
void test(int arr[3][5])//ok？ok
{}
void test(int arr[][])//ok？no
{}
void test(int arr[][5])//ok？ok
{}
//总结：二维数组传参，函数形参的设计只能省略第一个[]的数字。
//因为对一个二维数组，可以不知道有多少行，但是必须知道一行多少元素。
//这样才方便运算。
void test(int *arr)//ok？ no
{}
void test(int* arr[5])//ok？ ok
{}
void test(int (*arr)[5])//ok？ ok
{}
void test(int **arr)//ok？ no
{}
int main()
{
 int arr[3][5] = {0};
 test(arr);
}
*/

//做题
/*
int i;//默认为0
int main()
{
    i--;//-1 
    if(i > sizeof(i))
    //sizeof是以一个unsgint 类型  比较的时候会默认转成unsgint 类型所以会变成一个很大的数字
    //如果是 sizeof(i) > i unsgint 类型会转成int类型
        printf(">\n");
    else
        printf("<\n");
}
*/

//给定一个数字输出他的和
//例  2+22+222+2222+22222
/*
int main()
{
    int a =0;
    int n = 0;
    scanf("%d %d",&a,&n);
    int i=0;
    int ret = 0;
    int sum = 0;
    for ( i = 0; i < n; i++)
    {
        ret = ret * 10 +a;
        sum +=ret;
    }
    printf("%d",sum);
}
*/
/*
//不使用下标打印出来数组
int main()
{
    int arr[] = {1,2,3,4,5,6,7,8,9,10};
    int* p = &arr;
    int n = sizeof(arr) / sizeof(arr[0]);
    int i = 0;
    for ( i = 0; i < n; i++)
    {
       // printf("%d ",(*p+i));
        printf("%d ",*(p+i));
    }
    
    return 0;
}
*/
/*
#include <math.h>
//求0-100000之间的所有”水仙花数“并输出
//例 153 = 1 ^ 3  + 5 ^ 3 + 3 ^ 3
int main()
{
    int j = 0;
    for ( j = 0; j <= 100000; j++)
    {
        int n =1;//计算j的位数
        int tmp = j;
        while (tmp /10)
        {   
            n++;
            tmp = tmp/10;
        }
        //计算j的每一位次方之和
        tmp = j;
        int sum = 0;
        while (tmp)
        {
            sum += pow(tmp % 10 , n);
            tmp = tmp / 10;
        }
        if(sum == j)
            printf("%d ",j);
    }
    return 0;
}
*/
/*
//打印一个菱形
void print(int m)
{
    int line = m;//上面的行数
    int i = 0;
    for ( i = 0; i < line; i++)
    {
        int j = 0;
        for ( j = 0; j <line -1 -i; j++)
        {
            printf(" ");
        }
        for ( j = 0; j < 2 *i +1; j++)
        {
            printf("*");
        }
        printf("\n");
    }
    //下
    for ( i = 0; i < line-1; i++)
    {
        int j = 0;
        for ( j = 0; j <=i; j++)
        {
            printf(" ");
        }
        for ( j = 0; j < 2 *(line -1 - i) -1; j++)
        {
            printf("*");
        }
        printf("\n");
    }
    
}
int main()
{
    int i = 0;
    scanf("%d",&i);
    print(i);
}
*/
/*
//喝汽水 1瓶1元 2个空瓶可以换1瓶 给20 可以多少喝多少瓶
void total(int price,int num,int money)
{
    int sum = money / price;
    int totals = sum;
    while (totals >= 2)
    {
        sum+=totals / 2;
        totals = totals / 2 + totals % 2;
    }
    printf("%d",sum);
}  
int main()
{
    int price = 0;
    int num = 0;
    int money = 0;
    scanf("%d %d %d",&price,&num,&money);    
    total(price,num,money);
    return  0;
}
*/

//将一组数组中的数据按照奇数在前偶数在后方式排列
void print(int arr[],int len)
{
    for (size_t i = 0; i < len; i++)
    {
        printf("%d ",arr[i]);
    }
    
}
void move(int arr[],int len)
{
    int left = 0;
    int right = len-1;

   while (left < right)
   {
        while (arr[left] % 2 != 0)
        {
            /* code */
            left++;
        }
        while (arr[right] % 2 == 0)
        {
            /* code */
            right--;
        }
        if(left < right)
        {
            int tmp = arr[left];
            arr[left] = arr[right];
            arr[right] = tmp;
        }
   }
}
int main()
{
    int arr[] = {1,2,3,4,5,6,7,8,9,10};
    int len = sizeof(arr) / sizeof(arr[0]);
    move(arr,len);
    print(arr,len);
    return 0;
}
