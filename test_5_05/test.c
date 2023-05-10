#include <stdio.h>
/*
int main()
{
    int a[5][5];// [][][][][] [][][][][] [][][][][] [][][p4 2][][] [][][a4 2][][]
    //                    1        2        3       4
    int (*p)[4];//p指向一个数组每个数组四个元素
    p=a;//int(*)5 指针和指针相减得到元素的个数 -4
    printf("%p,%d\n", &p[4][2] - &a[4][2], &p[4][2] - &a[4][2]);
    //                  FFFFFFFFC              -4
    return 0;
}
*/
/*
int main()
{
    int aa[2][5] = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10}; // {[1,2,3,4,5],[6,7,8,9,10]}
    int *ptr1 = (int *)(&aa + 1);//&aa是这个数组的地址加一跳过了这个地址 -1左移一位的地址解引用得到10
    int *ptr2 = (int *)(*(aa + 1));//aa表示第一行[1,2,3,4,5]的地址 加一指向[6,7,8,9,10]的地址解引用得到第一个6的地址
    printf("%d,%d\n", *(ptr1-1), *(ptr2-1));//ptr1-1=10 ptr2-1 = 6-5

}
*/

/*
int main()
{
    char * a[] = {"work","at","alibaba"};
    // a = char * work
    //     char * at
    //     char * alibaba
         
    char * * pa = a;// char *pa就等于a = char * work
    pa++;// pa++ 就指向下一个 =char * at
    printf("%s\n",*pa);// *解引用就得到 at
    return 0;
}
*/

/*
int main()
{
    char * c[] = {"ENTER","NEW","POINT","FIRST"};
    char ** cp[] = {c+3,c+2,c+1,c}; //c+3 FIRST  c+2 POINT c+1 NEW c ENTER
    char *** cpp = cp;//
    printf("%s\n",**++cpp);//POINT ++之后cpp的指向变量
    printf("%s\n",*-- * ++cpp +3);//ER ++优先级高所以再++的时候就是c+1= NEW 然后* --得到 c+1-1=c此时c-1也变成了c 解引用得到ENTER 再加三从E到R 得到ER
    printf("%s\n",* cpp[-2]+3);//*ST cpp[-2]+3 ==**（cpp-2)+3  上一步之后cpp=c=NEW c-2=FIRST +3== ST
    printf("%s\n",cpp[-1][-1]+1);//EW *(*(cpp-1)-1)+1 cpp=c=ENTER cpp-1 得到NEW 解引用得到NEW +1 得到EW
}
*/
//杨氏矩阵 查找元素  时间复杂度小于 O(N)
/*
    1 2 3
    4 5 6
    7 8 9
*/
// int find_num(int arr[3][3],int r,int c,int k)
// {
//     int x = 0;
//     int y = c-1;

//     while (x<r && y>=0)
//     {
//         if(arr[x][y] < k){
//             x++;
//         }else if(arr[x][y] > k){
//             y--;
//         }else{
//             printf("%d %d",x,y);
//             return 1;
//         }
//     }
//     return 0;
// }
int find_num_path(int arr[3][3],int *px,int *py,int k)
{
    int x = 0;
    int y = *py-1;

    while (x<*px && y>=0)
    {
        if(arr[x][y] < k){
            x++;
        }else if(arr[x][y] > k){
            y--;
        }else{
            *px=x;
            *py=y;
            return 1;
        }
    }
    return 0;
}
int main()
{
    int arr[3][3] = {1,2,3,4,5,6,7,8,9};
    int k = 7;
    int x=3;
    int y=3;
    //int ret = find_num(arr,3,3,k);
    int ret = find_num_path(arr,&x,&y,k);
    if(ret == 1)
    {

        printf("x=%d y=%d 找到了！",x,y);
    }
    if(ret == 0)
    {
         printf("x=%d y=%d 没找到！",x,y);
    }
}