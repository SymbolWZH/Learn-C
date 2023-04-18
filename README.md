# Learn C form 2023.4.08

##### 数据类型

```
类型的多个：             所占字节sizeof()
选择性和空间利用率越高						
char        //字符数据类型	1
short       //短整型		  2
int         //整形		   4
long        //长整型		  4
long long   //更长的整形		 8
float       //单精度浮点数	4
double      //双精度浮点数	8
printf("%d")中 %d是打印一个整数
sizeof -关键字-操作符-计算类型或者变量所占空间的大小（bit 1个bit=2个位）
byte - 字节 = 8bit kb = 1024byte mb = 1024kb gb = 1024mb tb = 1024gb pb = 1024tb
//全局变量 - {}外部定义的
//局部变量 - {}内部定义的 
scanf函数是输入函数
scanf("%d %d",&a,&b);
生命周期
变量的生命周期 变量的创建和销毁之间的时间段
常量
字面常量
const 修饰的常变量 修饰后值不能被修改 //const int a = 10; a之后不可被修改
#define 定义的标识符常量 #define Max 10;
枚举常量 可以一一列举的常量 默认从0开始可以赋初始值 enum Gender{MALE}
字符串默认隐藏/0 
```

