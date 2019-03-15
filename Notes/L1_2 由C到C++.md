# 由C到C++
> OOP第一课

## C语言的局限

- 类型检查机制相对较弱，使得程序中的一些错误不能在编译时由编译器检查出来。
- C语言本身没有支持代码重用的语言结构
- 不适合开发大型程序，当程序的规模达到一定的程度时，程序员很难控制程序的复杂性。

## C++的特点
C++继承了C的优点，并有自己的特点，主要有：
1. 全面兼容C，C的许多代码不经修改就可以为Cpp所用，用C编写的库函数和实用软件可以用于Cpp。
2. 用C++编写的程序可读性更好，代码结构更为合理，可直接在程序中映射问题空间结构。
3. 生成代码的质量高，运行效率高。
4. 从开发时间、费用到形成软件的可重用性、可扩充性、可维护性和可靠性等方面有了很大提高，使得大中型的程序开发项目变得容易得多。
5. 支持面向对象的机制，可方便的构造出模拟现实问题的实体和操作。

## C++的程序特征

##### 例1.1 输出一行字符： “This is a C++ program.”。

程序如下：
```cpp
#include <iostream> //包含头文件iostream
using namespace std; //使用命名空间std
int main( )
{
    cout<<″This is a C++ program.″;
    return 0;
}
```
在运行时会在屏幕上输出以下一行信息:
This is a C++ program.

- 用main代表“主函数”的名字。每一个C++程序都必须有一个 main 函数。main前面的int的作用是声明函数的类型为整型。程序第6行的作用是向操作系统返回一个零值。如果程序不能正常执行，则会自动向操作系统返回一个非零值，一般为-1。
- 函数体是由大括号{}括起来的。本例中主函数内只有一个以cout开头的语句。注意C++所有语句最后都应当有一个分号。
- 再看程序的第1行“#include<iostream>”，这不是Cpp的语句，而是Cpp的一个预处理命令，它以“#”开头以与Cpp语句相区别，行的末尾没有分号。
- #include <iostream>是一个“包含命令”，它的作用是将文件iostream的内容包含到该命令所在的程序文件中，代替该命令行。文件iostream的作用是向程序提供输入或输出时所需要的一些信息。
- iostream是i-o-stream3个词的组合，从它的形式就可以知道它代表“输入输出流”的意思，由于这类文件都放在程序单元的开头，所以称为“头文件” (head file)。在程序进行编译时，先对所有的预处理命令进行处理，将头文件的具体内容代替#include命令行，然后再对该程序单元进行整体编译。
- 程序的第2行“using namespace std;”的意思是“使用命名空间std”。Cpp标准库中的类和函数是在命名空间std中声明的，因此程序中如果需要用到Cpp标准库(此时就需要用#include命令行)，就需要用“using namespace std;”作声明，表示要用到命名空间std中的内容。
- 在初学C++时，对本程序中的第1,2行可以不必深究，只需知道： 如果程序有输入或输出时，必须使用“#include <iostream>”命令以提供必要的信息，同时要用“using namespace std;”，使程序能够使用这些信息，否则程序编译时将出错。

##### 例1.2 求a和b两个数之和

```cpp
// 求两数之和 (本行是注释行)
#include <iostream> //预处理命令
using namespace std; //使用命名空间std
int main( ) //主函数首部
{ //函数体开始
    int a,b,sum; //定义变量
    cin>>a>>b; //输入语句
    sum=a+b; //赋值语句
    cout<<″a+b=″<<sum<<endl; //输出语句
    return 0; //如程序正常结束，向操作系统返回一个零值
} //函数结束
```

本程序的作用是求两个整数a和b之和sum。

第1行“//求两数之和”是一个注释行，Cpp规定在一行中如果出现“//” ，则从它开始到本行末尾之间的全部内容都作为注释。

##### 例1.3 给两个数x和y， 求两数中的大者

```cpp
#include <iostream> //预处理命令
using namespace std;
int max(int x,int y) //定义max函数，函数值为整型，形式参数x， y为整型
{ //max函数体开始
    int z; //变量声明，定义本函数中用到的变量z为整型
    if(x>y) z=x; //if语句，如果x>y， 则将x的值赋给z
    else z=y; //否则，将y的值赋给z
    return(z); //将z的值返回，通过max带回调用处
} //max函数结束
int main( ) //主函数
{ //主函数体开始
    int a,b,m; //变量声明
    cin>>a>>b; //输入变量a和b的值
    m=max(a,b); //调用max函数，将得到的值赋给m
    cout<<″max=″<<m<<′\\n′; //输出大数m的值
    return 0; //如程序正常结束，向操作系统返回一个零值
} //主函数结束
```

本程序包括两个函数:主函数main和被调用的函数max。

程序运行情况如下:
- 18 25 ↙ (输入18和25给a和b)
- max=25 (输出m的值)

注意输入的两个数据间用一个或多个空格间隔，不能以逗号或其他符号间隔。

在上面的程序中，max函数出现在main函数之前，因此在main函数中调用max函数时，编译系统能识别max是已定义的函数名。如果把两个函数的位置对换一下，即先写main函数，后写max函数，这时在编译main函数遇到max时，编译系统无法知道max代表什么含义，因而无法编译，按出错处理。

为了解决这个问题，在主函数中需要对被调用函数作声明。上面的程序可以改写如下：
```cpp
#include <iostream>
using namespace std;
int max(int x,int y); //对max函数作声明
int main( )
{
    int a,b,c;
    cin>>a>>b;
    c=max(a,b); //调用max函数例1.3 给两个数x和y， 求两数中的大者。
    cout<<″max=″<<c<<endl;
    return 0;
}
int max(int x,int y) //定义max函数
{
    int z;
    if(x>y) z=x;
    else z=y;
    return(z);
}
```

只要在被调用函数的首部的末尾加一个分号，就成为对该函数的函数声明。函数声明的位置应当在函数调用之前。

## C++程序的结构特性

一个面向对象的C++程序一般由**类的声明**和**类的使用**两大部分组成。

类的使用部分一般由主函数及有关子函数组成。

##### 典型的C++程序结构
```cpp
#include <iostream.h>
//类的声明部分
class A{
    int x,y,z;
    ……
    fun( ){……}
    ……
};
//类的使用部分
int main()
{
    A a;
    ……
    a.fun();
    return 0;
}
```

在C++程序中，程序设计始终围绕“类”展开。通过声明类，构建了程序所要完成的功能，体现了面向对象程序设计的思想。

## C＋＋程序的编辑、编译和运行

C++源程序文件的扩展名为.CPP

可以用多种编译器编辑、编译和运行

## C++对C的补充

### 1. 注释与续行

- **注释符**：“/\*”和“\*/” 或“//” 。

Cpp新增了注释语句，它由“//”开始，到行尾结束。
例如：
```cpp
X = y + z; /*This is a comment */
X = y + z; //This is a comment
```
- **续行符**：“\”（反斜杠）。作用是当一个语句太长时可以用该符号把它分段写在几行中。
例：
```cpp
cout << ‘\n’ << “x=” << x << “y=” << y << “z=” << z\
 << “u=” << u << “v\
=” << v << “w=” << w << endl;
```

### 2. 输入输出流

C中I/O操作出现的问题：
```cpp
int i;
float f;
scanf(“%f”,i);
printf( “%d”,d);
```

Cpp中使用更安全更方便的方法：
```cpp
int i;
float f;
cin >> i;
cout << f;
```

cout和cin分别是C++的标准输出流和输入流。 Cpp支持重定向，但一般cout指的是屏幕， cin指的是键盘。

操作符“<<”和“>>”除了具有C语言中定义的左移和右移的功能外，在这里符号“<<”是把右方的参数写到标准输出流cout中；相反，符号“>>”则是将标准输入流的数据赋给右方的变量。

##### 例1.4 一个完整的C++程序

```cpp
#include <iostream.h>
int main()
{
    char name[20];
    cout << "Hello， your name： ";
    cin >> name;
    cout << name;
    return 0;
}
```
注意：
- 程序中必须包含头文件`iostream.h`
- `cin`和`>>`,`cout`和`<<`配套使用
- `cin`可以输入多个数据,但要用空白符隔开（tab，空格，回车）
    > 如： `cin >> a >> b >> c;`
- 换行符：‘\n’或endl
    > 如： `cout << “x=” << x << endl;` `cout << “x=” << x << ‘\n’;`
- 使用`cout`和`cin`时，也可以对输入和输出的格式进行控制，比如可用不同的进制方式显示数据，只要设置转换基数的操作符`dec`、`hex`和`oct`即可。

##### 例1.5 操作符dec、 hex和oct的使用

```cpp
#include<iostream.h>
void main()
{
    int x=25;
    cout << hex << x << ' ' << dec << x << ' ' << oct << x << '\n';
}
```
输出结果为： 19 25 31

### 3. 灵活的变量说明

##### 定义变量的位置

在程序中的不同位置采用不同的变量定义方式，决定了该变量具有不同的特点。变量的定义一般可有以下三种位置：

1. 在函数体内部

在函数体内部定义的变量称为**局部变量**，这种局部变量只在进入定义它的函数体时起作用，离开该函数体后该变量就消失（被释放），即不再起作用。因此，不同函数体内部可以定义相同名称的变量，而互不干扰。

2. **形式参数**

当定义一个有参函数时，函数名后面括号内的变量，统称为形式参数。

3. **全局变量**

在所有函数体外部定义的变量，其作用范围是整个程序，并在整个程序运行期间有效。

- 在C语言中，全局变量声明必须在任何函数之前，局部变量必须集中在可执行语句之前。
- Cpp中的变量声明非常灵活，它允许变量声明与可执行语句在程序中交替出现。
例如
```cpp
f( )
{
    int i;
    i=10;
    int j;
    j=25;
    // …
}
float fun(int x,int y)
{
    for(int i=0;i<10;i++)
    {
        int sum=0;
        sum=sum+i;
        cout<<“sum=”<<sum;
    }
    int z=0;
    z=x+y;
}
```

### 4. 结构、联合和枚举名

在C++中，结构名、联合名、枚举名都是类型名。在定义变量时，不必在结构名、联合名或枚举名前冠以struct、union或enum。

例如：
```cpp
enum boole{FALSE,TRUE};
struct string{
    char *string;
    int length;
};
union number{
    int i;
    float f;
};
```

在传统的C中，定义变量时，必须写成：
```c
enum boole done;
struct string str;
union number x;
```
但是，在C++中，可以说明为：
```cpp
boole done;
string str;
number x;
```

### 5. 函数原型

C语言**建议**编程者为程序中的每一个函数建立原型，而Cpp**要求**为每一个函数建立原型，以说明函数的名称、参数类型与个数，以及函数返回值的类型。

其主要目的是让C++编译程序进行类型检查，即形参与实参的类型匹配检查，以及返回值是否与原型相符，以维护程序的正确性。

例如
```cpp
int sum(int a,int b);   //是函数sum的原型
```

- 函数原型语法的一般形式为：**返回类型 函数名（参数表）；**
- 函数原型是一条语句，它必须以分号结束。

##### 例1.6 函数原型的说明

```cpp
#include<iostream.h>
void write(char *s);
void main()
{write("Hello,world!");}
void write(char *s)
{cout<<s;}
```

在程序中，要求一个函数的原型出现在该函数的调用语句之前。

#### 说明：
- 1. 函数原型的参数表中**可不包含参数的名字**，而只包含它们的类型。例如： `long Area(int ,int);`
- 2. 函数定义由函数首部和函数体构成。函数首部和函数原型基本一样，但函数首部中的参数必须给出名字而且不包含结尾的分号。
- 3. Cpp的参数说明必须放在函数说明后的括号内，不可将函数参数说明放在函数首部和函数体之间。这种方法只在C中成立。
- 4. 主函数不必进行原型说明，因为它被看成自动说明原型的函数。
- 5. 原型说明中没有指定返回类型的函数(包括主函数main)，Cpp默认该函数的返回类型是int
- 6. 如果一个函数没有返回值，则必须在函数原型中注明返回类型为void，主函数类似处理。
- 7. 如果函数原型中未注明参数，Cpp假定该函数的参数表为空(void)。

### 6. const修饰符

- 在C中，习惯使用#define定义常量。

一般格式： **#define 宏名 常数**

如
```c
#define PI 3.14
…………
s = 2 * PI * r;
…………
```

- C++利用const定义正规常数

一般格式： **const 数据类型标识符 常数名=常量值；**

采用这种方式定义的常量是类型化的，它有地址，可以用指针指向这个值，但不能修改它。

#### 说明:
1. const必须放在被修饰类型符和类型名前面
2. 数据类型是一个可选项，用来指定常数值的数据类型，如果**省略**了该数据类型，那么编译程序认为它是 **int** 类型。
    > 如： `const int a=10;` 表示定义了一个初始值为10的整型常量，它在程序中不可改变，但可用于表达式的计算中。

##### 例2.6 `#define`的不安全性
```cpp
#include "iostream.h"
main()
{
    int a=1;
    #define T1 a+a
    #define T2 T1-T1
    cout<<"T2 is "<<T2<<endl;
    return 0;
}
```
但实际的输出是： T2 is 2

const作用与`#define`相似，但消除了`#define`的不安全性。

如果用`const`取代了两个`#define`,就不会引起这个错误。
```cpp
#include<iostream.h>
int main()
{
    int a=1;
    const T1=a+a;
    const T2=T1-T1;
    cout <<"T2 is"<<T2<<endl;
    return 0;
}
```

#### `const`可以与指针一起使用

- （1）**指向常量的指针**：一个指向常量的指针变量。

例如：
```cpp
const char* pc=“abcd”;  //声明指向常量的指针
pc[3]=‘x’;  //错误
pc=“efgh”;  //允许
```

- （2）**常指针**：把指针本身，而不是它指向的对象声明为常量。

例如：
```cpp
char* const pc=“abcd”;  //常指针
pc[3]=‘x’;  //合法
pc=“efgh”;  //出错
```
创建一个常指针，就是创建一个不能移动的固定指针，但是它所指的数据可以改变。例如:


- （3）**指向常量的常指针**：这个指针本身不能改变，它所指向的值也不能改变。

要声明一个指向常量的常指针，二者都要声明为const。

例如：
```cpp
const char* const pc=“abcd”;    //指向常量的常指针
pc[3]=‘x’;  //出错
pc=“efgh”;  //出错
```

这个语句的含义是：声明了一个名为pc的指针变量，它是一个指向字符型常量的常指针，用“abcd”的地址初始化该指针。

#### 说明
- (1). 如果用`const`定义的是一个整型常量，关键词**int可以省略**。所以下面的两语句是等价的
    - `const int bufsize=200;`
    - `const bufsize=200;`
- (2). **常量**一旦被建立，在程序的任何地方都**不能再更改**。
- (3). 与`#define`定义的常量有所不同，`const`定义的常量可以有自己的数据类型，这样C++的编译程序可以进行更加严格的类型检查，具有良好的编译时的检测性。
- (4). 函数参数也可以用`const`说明，用于保证实参在该函数内部不被改动，大多数C++编译器能对具有`const`参数的函数进行更好的代码优化。
    > 例如：通过函数`i_Max`求出整型数组`a[200]`中的最大值，函数原型应该是：`int i_Max(const int* ptr);`
    > > 这样做的目的是确保原数组的数据不被破坏，即在函数中对数组元素的操作只许读，而不许写。调用时的格式可以是：i_Max(a);

### 7. void型指针

void 通常表示无值，但将void作为指针的类型时，它却**表示不确定的类型**。

这种void型指针是一种通用型指针，也就是说任何类型的指针值都可以赋给void类型的指针变量。

例如下面的程序段
```cpp
void pa;    //错误，不能声明void类型的指针变量
void* pc;   //正确，可以声明void类型的指针
int i=456;
char c=‘a’;
pc=&i;
pc=&c;
```

void型指针可以接受任何类型的指针的赋值，但对已获值的void型指针，对它在进行处理，如输出或传递指针值时，则必须进行**强制类型转换**，否则会出错。

```cpp
#include <iostream.h>
main()
{
    void *pc;
    int i=456;
    char c='a';
    pc=&i;
    cout<<*(int *)pc<<endl;
    pc=&c;
    cout<<*(char *)pc<<endl;
    return 0;
}
```

### 8. 内联函数

调用函数时系统要付出一定的开销，用于信息入栈出栈和参数传递等。特别是对于那些函数体较小但调用又较频繁的函数，计算机的开销相对就比较可观。

在C语言中，用宏替换，可解决这个问题。例如，有如下的函数：
```c
add(int x,int y)
{
    return x+y;
}
```
用宏替换时，上面的函数功能可写为：
```c
#define add(x,y) x+y
```
C++引进了内联函数（inline function）的概念。

宏替换实质上是文字替换。内联函数与一般函数不同的是，在进行程序的编译时，编译器将内联函数的目标代码作拷贝并将其插入到调用内联函数的地方。

##### 例1.7 内联函数的使用
```cpp
#include "iostream.h"
inline double circle(double r)
{return 3.1416*r*r;}
int main()
{
    for(int i=1;i<=3;i++)
        cout<<"r="<<i<<" area="<<circle(i)<<endl;
    return 0;
}
```

#### 说明：
- (1). 内联函数在第一次被调用前必须进行声明或定义，否则编译器将无法知道应该插入什么代码。
- (2). C++的内联函数具有与C中的宏定义`#define`相同的作用和类似机理，但消除了`#define`的不安全性。
- (3). 内联函数体内一般不能有循环语句和开关语句。
- (4). 后面类结构中所有在类说明体内定义的函数都是内联函数。
- (5). 通常较短的函数才定义为内联函数。

### 9. 带有缺省参数值的函数

在C++中，函数的参数可以有缺省值。

当调用有缺省参数的函数时，如果相应的参数没有给出实参，则自动用相应的缺省参数值作为其实参。

函数的缺省参数，是在**函数原型**中给定的。

例如：
```
int init(int x=5, int y=10);
init(100,80);   //允许
init(25);   //允许
init();   //允许
```

#### 说明：
- （1）在**函数原型**中，所有取缺省值的参数必须出现在不取缺省值的参数的右边。
    > - `int fun(int I,int j=5,int k);` 错误
    > - `int fun(int I,int k,int j=5);` 正确
- （2）在**函数调用**时，若某个参数省略，则其后的参数皆应省略而采用缺省值。
    > - `init (,20)` 错误

##### 例.编写一个带有默认参数的函数，使得在默认情况下显示两个整数的较大者，否则显示两个整数的较小者。

```cpp
int main()
{
    void showValue(int x, int y, bool Max = true); // 声明函数
    int a = 5, b = 10;
    showValue(a,b);
    showValue(a,b,false);
    return 0;
}
void showValue(int x, int y, bool Max = true) // 定义函数
{
    if(Max)
        cout << “the bigger value is: " << (x>y)?x:y << endl;
    else
        cout << "the smaller value is: " << (x<y)?x:y << endl;
}
```

### 10. 函数重载

#### (1) 什么是函数重载

函数重载是指一个函数可以和同一作用域中的其他函数具有相同的名字，但这些同名函数的参数类型、参数个数不同。如：
```cpp
#include <iostream.h>
void whatitis(int i)
{ cout<<"this is integer"<<i<<endl;}
void whatitis(char c[])
{ cout<<“this is string”<<c<<endl; }
main()
{
    int i=1;
    char c[]="abcdef";
    whatitis(i);
    whatitis(c);
}
```
在本例中定义了两个名称都叫`whatitis`的函数，但它们的形参类型不同。因此，这两个函数就是重载函数。

#### (2) 为什么要使用函数重载

在原有C语言中，每个函数必须有其唯一的名称，这样的缺点是所有具有相同功能、而只是函数参数不一样的函数，就必须用一个不同的名称.

而C++中采用了函数重载后，**对于具有同一功能的函数**，如果只是由于函数参数类型不一样，则**可以定义相同名称的函数**。

#### (3) 匹配重载函数的顺序

由于重载函数具有相同的函数名，在进行函数调用时，系统一般按照调用函数时的参数个数、类型和顺序来确定被调用的函数。

具体来说，按以下三个步骤的先后次序找到并调用那个函数：
- （1）寻找一个**严格**的匹配，即：调用与实参的数据类型、个数完全相同的那个函数。
- （2）通过**内部转换**寻求一个匹配，即：通过（1）的方法没有找到相匹配的函数时，则由C++系统对实参的数据类型进行内部转换，转换完毕后，如果有匹配的函数存在，则执行该函数。
- （3）通过**用户定义的转换**寻求一个匹配，若能查出有唯一的一组转换，就调用那个函数。即：在函数调用处由程序员对实参进行**强制类型转换**，以此作为查找相匹配的函数的依据。

##### 例1.8 重载例子
```cpp
#include <iostream.h>
void print(double d)
{ cout<<"this is a double "<<d<<"\n"; }
void print(int i)
{ cout<<"this is an integer "<<i<<"\n"; }
void main()
{
    int x=1,z=10;
    float y=1.0;
    char c='a';
    print(x);   //按规则（1）自动匹配函数void print(int i)
    print(y);   //按规则（2）通过内部转换匹配函数 void print(double i)
    //因为系统能自动将float型转换成double型
    print(c);   //按规则（2）通过内部转换匹配函数 void print(int i)
    //因为系统能自动将char型转换成int型
    print(double(z));   //按规则（3）匹配void print(double i)
    //因为程序中将实参z强制转换为double型。
}
```

##### 例 重载例子

编写一个程序，用来求两个整数或3个整数中的最大数。如果输入两个整数，程序就输出这两个整数中的最大数，如果输入3个整数，程序就输出这3个整数中的最大数。

```cpp
#include <iostream>
using namespace std;
int main( )
{
    int max(int a,int b,int c); //函数声明
    int max(int a,int b); //函数声明
    int a=8, b=-12, c=27;
    cout<<"max(a,b,c)="<<max(a,b,c)<<endl; //3个整数中的最大者
    cout<<"max(a,b)="<<max(a,b)<<endl; //2个整数中的最大者
}
int max(int a,int b,int c)
{
    if(b>a) a=b;
    if(c>a) a=c;
    return a;
}
int max(int a,int b)
{
    if(a>b) return a;
    else return b;
}
```

#### (4) 定义重载函数时的注意事项

- 重载函数间不能只是函数的返回值不同，应至少在形参的个数、参数类型或参数顺序上有所不同。
如：
```
void myfun(int i)
{………………}
int myfun(int i)
{………………}
// 这种重载是错误的
```
- 应使所有的重载函数的功能相同。如果让重载函数完成不同的功能，会破坏程序的可读性。

#### (5) 函数模板

1) **函数模板 (function template)**： 

建立一个通用函数，其函数类型和形参类型不具体指定，而是一个虚拟类型。

2) **应用情况**：

凡是函数体相同的函数都可以用这个模板来代替，不必定义多个函数，只需在模板中定义一次即可。在调用函数时系统会根据实参的类型来取代模板中的虚拟类型，从而实现了不同函数的功能。

3) 一般形式：
    - `template < typename T> // 模板头` 通用函数定义
    - `template <class T> // 模板头` 通用函数定义
    - `template <class T1,typename T2> // 多个参数` 通用函数定义
> 说明： class与typename可以通用

```cpp
#include <iostream>
using namespace std;
template<typename T> // 模板声明，其中T为类型参数
T max(T a, T b) // 定义一个通用函数， T作为虚拟的类型名
{
    if(b>a) return b;
    else return a;
}
//template <typename T> T max(T a, T b)
//{
//…
//}
int main( )
{
    int i1=111, i2=222, i;
    double d1=12.34, d2=56.78,d;
    i=max(i1,i2); // 调用模板函数，此时T被 int 取代
    d=max(d1,d2,d3); // 调用模板函数，此时T被 double 取代
    cout<<"i_max=" << i <<endl;
    cout<<"f_max=" <<f<<endl;
    return 0;
}
```

##### 函数模板说明：

1) 在对程序进行编译时，遇到第13行调用函数max(i1,i2)， 编译系统会将函数名max与模板max相匹配，将实参的类型取代了函数模板中的虚拟类型T。此时相当于已定义了一个函数，然后调用它。
```cpp
int max(int a,int b)
{
if(b>a) a=b;
if(c>a) a=c;
return a;
}
```
2) **与重载函数比较**：用函数模板比函数重载更方便，程序更简洁。但应注意**它只适用于：函数的参数个数相同而类型不同，且函数体相同的情况**。如果参数的个数不同，则不能用函数模板；
3) main函数不能定义为模板函数。

### 11. 作用域标示符::

通常情况下，如果有两个同名变量，一个是全局的，另一个是局部的，那么局部变量在其作用域内具有较高的优先权。

下面的例子说明了这个问题。
```cpp
#include "iostream.h"
int avar=10;
main( )
{
    int avar;
    avar=25;
    cout<<"avar is"<<avar<<endl;
    return 0;
}
```

如果希望在局部变量的作用域内使用同名的全局变量，可以在全局变量加上“::”，此时`::avar`代表全局变量`avar`

```cpp
#include <iostream.h>
int avar=10;
main()
{
int avar;
avar=25;
cout<<"local avar ="<<avar<<endl;
cout<<"global avar="<<::avar<<endl;
return 0;
}
```

### 12. 无名联合

无名联合是C++中的一种特殊联合，可以声明一组无标记名共享同一段内存地址的数据项。如：
```
union{
    int i;
    float f;
}
```

在此无名联合中，声明了变量i和f具有相同的存储地址。无名联合可通过使用其中数据项名字直接存取，例如可以直接使用上面的变量i或f，如：`i=20;`

### 13. 强制类型转换

在C中数据类型转换的一般形式：**（数据类型标识符）表达式**
```cpp
int i=10;
float x=(float) i;
```

C++支持这样的格式，还提供了一种更为方便的函数调用方法，即将类型名作为函数名使用，使得类型转换的执行看起来好像调用了一个函数。形式为：**数据类型标识符 （表达式）**
```cpp
int i=10;
float x=float(i);
```
以上两种方法C++都接受，但推荐使用后一种方式。

### 14. 动态内存分配

作为对C语言中malloc和free的替换，C++引进了new和delete操作符。它们的功能是实现**内存的动态分配和释放**。

动态分配new的一般形式是：
- **指针变量=new 数据类型；**
- **指针变量=new 数据类型(初始值);**

```cpp
int *a， *b;
a=new int;
b=new int(10);
```

释放由new操作动态分配的内存时，用delete操作。

它的一般形式是：**delete 指针变量;**

```cpp
delete a;
delete b;
```

##### 例1.9 操作符new和delete的使用

```cpp
#include <iostream.h>
main()
{
    int *p; // 声明一个整型指针变量p
    p=new int; // 动态分配一个存放int型数据的内存空间，并将首地址赋给p
    *p=10;
    cout<<*p;
    delete p; // 释放指针变量p指向的内存空间
    return 0;
}
```

##### 例1.10 将new和delete用于结构类型

```cpp
#include<iostream.h>
#include<string.h>
struct person {
    char name[20];
    int age;
};
main()
{
    person *p;
    p=new person;
    strcpy(p->name， "Wang Fun");
    p->age=23;
    cout<<"\n"<<p->name<<" "<<endl<<p->age;
    delete p;
    return 0;
}
```

与C的内存动态分配和释放操作（malloc和free）相比，C++提供的动态分配有以下**优点**
- (1) new和delete 操作自动计算需要分配和释放类型的长度。这不但**省去了用sizeof计算长度的步骤**，更主要的是避免
了内存分配和释放时因长度出错带来的严重后果；
- (2) new操作自动返回需分配类型的指针， **无需使用强制类型转换**；
- (3) new操作**能初始化**所分配的类型变量。
- (4) new和delete都能**可以被重载**，允许建立自定义的内存管理法。

#### 对使用new和delete的几点说明：
- (1)用new分配的空间，使用结束后应该**用delete显示的释放**，否则这部分空间将不能回收而变成死空间。
- (2)使用new动态分配内存时，如果没有足够的内存满足分配要求， new将返回空指针(**NULL**)。因此通常要对内存的动态分配是否成功进行检查。

##### 例1.11 对内存的动态分配是否成功进行检查
```cpp
#include <iostream.h>
main()
{
    int * p;
    p=new int;
    if(!p){
        cout<<"allocation failure\n";
        return 1;
    }
    *p=20;
    cout<<*p;
    delete p;
    return 0;
}
```

- (3) 使用new可以为数组动态分配内存空间这是需要在类型后面缀上数组大小。其语法形式为：
**指针变量=new 类型名 [下标表达式];**

    - 例如： `int *pi=new int[10];`
    这时new为具有10个元素的整型数组分配了内存空间，并将首地址赋给了指针pi。
    - 使用new为多维数组分配空间时，必须提供所有维的大小，
        - 如： `int *pi=new int[2][3][4];`
        - 其中第一维的界值可以是任何合法的表达式，如：`int i=3; int *pi=new int[ i ][2][3];`
- (4) 释放动态分配的数组存储区时，可使用delete运算符，其语法形式为： **delete [ ]指针变量;**
    - 无须指出空间的大小，但老版本的Cpp要求在delete的方括号中标出数字，以告诉Cpp要释放多少个元素所占的空间。例如：`delete []pi; delete [10]pi;`
- (5) new可在为简单变量分配内存空间的**同时**，进行**初始化**。这时的语法形式为：**指针变量=new 类型名(初始值列表)**

##### 例 1.12 new为简单变量分配内存空间的同时，进行初始化
```cpp
#include <iostream.h>
int main()
{
    int *p;
    p=new int(99); // 动态分配内存，并将99作为初始值赋给它
    if (!p)
    {
        cout<<"allocation failure\n";
        return 1;
    }
    cout<<*p;
    delete p;
    return 0;
}
```
##### 例 1.13 给数组分配内存空间的例子。
```cpp
#include <iostream.h>
main()
{
    double *s;
    s=new double[10];
    if(!s){
        cout<<"alocation failure\n";
        return 1;
    }
    for(int i=0;i<10;i++)
        s[i]=100.00+2*i;
    for(int i=0;i<10;i++)
        cout<<s[i]<<" ";
    delete []s;
    return 0;
}
```

### 15. 引用

#### (1) 引用的概念

引用就是某一变量（目标）的一个**别名**，这样对引用的操作就是对目标的操作。

引用的声明方法： **类型标识符 &引用名=目标变量名;**

```cpp
int a;
int &ra=a; //定义引用ra,它是变量a的引用，即别名
```

##### 说明：
- （1） &在此不是求地址运算，而是起标识作用。
- （2） **类型**标识符是指目标变量的类型。
- （3）声明引用时，必须同时对其进行**初始化**。
- （4）引用声明完毕后，相当于目标变量名有**两个名称**。
- （5）声明一个引用，不是新定义了一个变量，系统**并不给引用分配存储单元**。

##### 例1.15 引用的使用

```cpp
#include <iostream.h>
void main()
{
    int i;
    int &j=i;
    i=30;
    cout<<"i="<<i<<"j="<<j<<"\n";
    j=80;
    cout<<"i="<<i<<"j="<<j<<"\n";
    cout<<"Address of i"<<&i<<"\n";
    cout <<"Address of j"<<&j<<"\n";
}
```

结果：
```
i=30 j=30
i=80 j=80
Address of oxfff4
Address of oxfff4
```

##### 例1.16 使用引用可以简化程序

```cpp
#include<iostream.h>
main()
{
    int i=15;
    int* iptr=&i;
    int & rptr=i;
    cout<<" i is "<<i<<endl;
    cout<<" *iptr is "<<*iptr<<endl;
    cout<<" rptr is "<<rptr<<endl;
    i=29;
    cout<<" After changing i to 29： "<<endl;
    cout<<" i is "<<i<<endl;
    cout<<" *iptr is "<<*iptr<<endl;
    cout<<" rptr is "<<rptr<<endl;
    return 0;
}
```

运行结果：
```
i is 15
*iptr is 15
rptr is 15
After changing i to 29：
i is 29
*iptr is 29
rptr is 29
```

#### (2) 引用的使用

- （1）引用名可以是任何合法的变量名。除了用作函数的参数或返回类型外，在声明时，必须立即对它进行初始化，不能声明完后再赋值。
```cpp
int i;
int &j;
j=i;
```

- （2）引用不能重新赋值，**不能再把该引用名作为其他变量名的别名**，任何对该**引用**的赋值就是该引用对应的**目标变量名**的赋值。对引用**求地址**，就是对目标变量求地址。
```cpp
int i=5;
int &j1=i; 
int &j2=j1; 
```
```cpp
int num=50;
int & ref=num;
int *p=&ref;
```

- （3）由于指针变量也是变量，所以，可以声明一个**指针变量的引用**。方法是： **类型标识符 \*&引用名=指针变量名;**
```cpp
#include <iostream.h>
void main()
{
    int *a; //定义指针变量a
    int *&p=a; //定义引用p，初始化为指针变量a，所以p是a的引用（别名）
    int b=10;
    p=&b; //等价于a=&b，即将变量b的地址赋给a。
    cout<<*a<<endl; //输出变量b的值
    cout<<*p<<endl; //等价于cout<<*a;
    cout<<a<<endl; //输出a和p的地址
    cout<<p<<endl;
}
```

- （4）引用是对某一变量或目标对象的引用，它本身不是一种数据类型，因此引用本身不占存储单元，这样，就**不能声明引用的引用**，也不能定义**引用的指针**。
```cpp
int a;
int & & ra=a; //错误
int &*p=&ra; //错误
```

- （5）不能建立数组的引用，因为数组是一个由若干个元素所组成的集合，所以就无法建立一个数组的别名。

- （6）不能建立空指针的引用
```cpp
int &rp=NULL; //错误
```

- （7）也不能建立空类型void的引用，因为尽管在C++语言中有void数据类型，但没有任何一个变量或常量属于void类型。
```cpp
void &ra=3; //错误
```

- (8) 尽管引用运算符与地址操作符使用相同的的符号，但时不一样的。引用仅在声明时带有引用运算符&，以后就像普通变量一样使用，不能再带&。其他场合使用的&都是地址操作符。
```cpp
int j=5;
int& i=j; // 声明引用i， "&"为引用运算符
i=123; // 使用引用i，不带引用运算符
int *pi=&i; // 在此， "&"为地址操作符
cout<<&pi; // 在此， "&"为地址操作符
```

#### (3) 用引用作为函数的参数

- 一个函数的参数也可定义成引用的形式
```cpp
void swap(int &p1, int &p2) //形参p1, p2都是引用
{
    int p;
    p=p1;
    p1=p2;
    p2=p;
}
```
在主调函数的调用点处，直接以**变量**作为**实参**进行调用即可，不需要实参变量有任何的特殊要求。
```cpp
swap(a,b); //直接以a和b作为实参调用swap函数
```

##### 例1.17 采用指针参数的例子
```cpp
#include<iostream.h>
void swap(int *m， int *n)
{
    int temp;
    temp=*m;
    *m= *n;
    *n=temp;
}
main()
{
    int a=5， b=10;
    cout<<"a="<<a<<" b="<<b<<endl;
    swap(&a， &b);
    cout<<"a="<<a<<" b="<<b<<endl;
    return 0;
}
```

运行结果：
```
a=5 b=10
a=10 b=5
```

##### 例1.18 采用“引用参数”传递函数参数
```cpp
#include <iostream.h>
void swap(int& m， int& n)
{
    int temp;
    temp=m;
    m=n;
    n=temp;
}
main()
{
    int a=5， b=10;
    cout<<"a="<<a<<" b="<<b<<endl;
    swap(a， b);
    cout<<"a="<<a<<" b="<<b<<endl;
    return 0;
}
```

运行结果：
```
a=5 b=10
a=10 b=5
```

#### (4) 用引用返回函数值

函数可以返回一个引用，将函数说明为返回一个引用的主要目的是：为了将函数用在赋值运算符的左边。

要以引用返回函数值，则函数定义时要按以下格式：

**类型标识符 &函数名（形参列表及类型说明）
{函数体}**

##### 说明

- 以引用返回函数值，定义函数时需要在函数名前加&
- 用引用返回一个函数值的最大好处是，在内存中不产生被返回值的副本。

##### 例1.19 返回引用的函数
```cpp
#include <iostream.h>
int a[]={1， 3， 5， 7， 9};
int& index(int); // 声明返回引用的函数
void main()
{
    cout<<index(2)<<endl;
    index(2)=25; // 将a[2]重新赋值为25
    cout<<index(2)<<endl;
}
int& index(int i)
{
    return a[i];
}
```

##### 例1.20 用引用返回函数的值
```cpp
#include<iostream.h>
int A[10];
int& array(int i);
void main()
{
    int i， number;
    A[0]=0;
    A[1]=1;
    cin>>number;
    for (i=2;i<number;i++)
    {
        array(i)=array(i-2)+array(i-1);
        cout<<"array("<<i<<")="<<array(i)<<endl;
    }
}
int& array(int i)
{
    return A[i];
}
```

运行结果：
```
array(2)=1
array(3)=2
array(4)=3
array(5)=5
array(6)=8
array(7)=13
array(8)=21
array(9)=34
```

- 在定义返回引用的函数时，注意不要返回该函数内的自动变量 (局部变量)的引用，由于自动变量的生存期仅限于函数内部，当函数返回时，自动变量就消失了。
```cpp
int& fun()
{
    int a;
    //...
    return a;
}
```

- 传递引用给函数与传递指针的效果是一样的，但使用更简练。
- 使用引用传递函数的参数，在内存中并没有产生实参的副本，它是直接对实参操作；
```cpp
void swap(int *p1, int *p2)
{
    int p;
    p=*p1; //必须用“*指针变量名”的形式操作目标变量
    p1=*p2;
    *p2=p;
}
main()
{
    int a,b;
    cin>>a>>b;
    swap(&a,&b); //必须以变量a和b的地址作为实参
    cout<<a<<b;
}
```

#### 如何使一个被调函数同时返回多个值

由于函数的返回值是通过函数体中的return语句完成的，但一个return语句只能返回一个值，为此，我们可以采用以下方法：
- （1）利用**全局变量**的方法：在函数中把所需数据保存在全局变量中。当被调函数执行完毕后在主调函数中直接读取全局变量的值即可。
- （2）使用**指针或数组**的方法：指针作为函数参数的情况下，可将主调函数的某些变量的地址传递给被调函数。
- （3）利用**引用**的方法：使用引用传递参数，可以在被调函数中改变主调函数中目标变量的值，这种方法实际上就是可以使被调函数返回多个值。

##### 例 使用引用使函数返回多个值

以下定义了可以同时返回10个数中的最大值和最小值的函数max_min。
```cpp
#include <iostream.h>
void max_min(int *p,int n,int &max,int &min);
//声明函数max_min
void main()
{
    int a[10];
    int ma,mi;
    int i;
    for(i=0;i<10;i++)
        cin>>a[i];
    max_min(a,10,ma,mi); //调用函数max_min
    cout<<ma<<mi;
}
void max_min(int *p,int n,int &max,int &min)
//形参max 和min定义成引用
{
    int i=0;
    max=*(p+i);
    min=*(p+i);
    for(i=1;i<n;i++) {
        if(max<*(p+i))
            max=*(p+i); //实质上就是对实参变量ma赋值
        if(min>*(p+i))
            min=*(p+i); //实质上就是对实参变量mi赋值
    }
}
```

##### 例 以下程序中定义了一个普通的函数fn1（它用返回值的方法返回函数值），另外一个函数fn2，它以引用的方法返回函数值。
```cpp
#include <iostream.h>
float temp; //定义全局变量temp
float fn1(float r); //声明函数fn1
float &fn2(float r); //声明函数fn2
float fn1(float r) //定义函数fn1，它以返回值的方法返回函数值
{
    temp=(float)(r*r*3.14);
    return temp;
}
float &fn2(float r) //定义函数fn2，它以引用方式返回函数值
{
    temp=(float)(r*r*3.14);
    return temp;
}
void main() //主函数
{
    float a=fn1(10.0);//第1种情况，系统生成要返回值的副本(即临时变量)
    float &b=fn1(10.0);//第2种情况，可能会出错(不同C++系统有不同规定)
    //不能从被调函数中返回一个临时变量或局部变量的引用
    float c=fn2(10.0); //第3种情况，系统不生成返回值的副本
    //可以从被调函数中返回一个全局变量的引用
    float &d=fn2(10.0); //第4种情况，系统不生成返回值的副本
    //可以从被调函数中返回一个全局变量的引用
    cout<<a<<c<<d;
}
```

一个返回引用的函数值**作为赋值表达式的左值**

一般情况下，赋值表达式的左边只能是变量名，即被赋
值的对象必须是变量，只有变量才能被赋值，常量或表达式不能被赋值，但如果一个函数的返回值是引用时，赋值号的左边可以是该函数的调用。

##### 例2-26 测试用返回引用的函数值作为赋值表达式的左值。
```cpp
#include <iostream.h>
int &put(int n);
int vals[10];
int error=-1;
void main()
{
    put(0)=10; //以put(0)函数值作为左值， 等价于vals[0]=10;
    put(9)=20; //以put(9)函数值作为左值， 等价于 vals[9]=10;
    cout<<vals[0];
    cout<<vals[9];
}
int &put(int n)
{
    if (n>=0 && n<=9 )
        return vals[n];
    else{
        cout<<”subscript error”;
        return error;
    }
}
```

#### 用const限定引用

声明方式： **const 类型标识符 &引用名=目标变量名;**

用这种方式声明的引用，**不能通过引用对目标变量的值进行修改**，从而使引用的目标成为const，达到了引用的安全性。

##### 例2-27
```cpp
#include “iostream.h”
double &fn(const double &pd)
{
    static double ad=32;
    ad+=pd;
    cout<<pd<<endl;
    return ad;
}
void main()
{
    double a=100.0;
    double &pa=fn(a);
    cout<<pa<<endl;
    a=200.0;
    pa=fn(a);
    cout<<pa<<endl;
}
```
程序运行的结果
```
100
132
200
332
```

#### 引用总结

- （1）在引用的使用中，单纯给某个变量取个别名是毫无意义的，引用的目的主要用于在函数参数传递中，解决大对象的传递效率和空间不如意的问题。
- （2）用引用传递函数的参数，能保证参数传递中不产生副本，提高传递的效率，且通过const的使用，保证了引用传递的安全性。
- （3）引用与指针的区别是，指针通过某个指针变量指向一个对象后，对它所指向的变量**间接操作**，程序中使用指针，程序的可读性差；而引用本身就是目标变量的别名，**对引用的操作就是对目标变量的操作**。

##### 课后练习题目
```cpp
#include<iostream.h>
int &max(int &num1,int &num2); // 返回一个较大值
int &min(int &num1,int &num2); // 返回一个较小值
main()
{
    int num1， num2;
    cout<<"Enter the first number: ";
    cin>>num1;
    cout<<"Enter the second number: ";
    cin>>num2;
    max(num1,num2)=0;
    cout<<"\nAfter putting zero in largest, the numbers are";
    cout<<"\n"<<num1<<" and "<<num2<<"\n";
    cout<<"\nNow， please enter two more numbers.\n";
    cout<<"Enter the first number :";
    cin>>num1;
    cout<<"Enter the second number:";
    cin>>num2;
    min(num1， num2)=0;
    cout<<"\nAfter putting zero in smallest the numbers are";
    cout<<"\n"<<num1<<" and "<<num2<<"\n";
    return 0;
}
int &max(int &num1,int &num2)
{
    return (num1>num2)?num1:num2;
}
int &min(int &num1,int &num2)
{
    return (num1<num2)?num1:num2;
}
```