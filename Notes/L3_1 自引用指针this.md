# 自引用指针this

##### 例 3.1 this指针的引例
```
#include<iostream.h>
class A{
public:
    A(int x1){ x=x1; }
    void disp(){ cout<<"x= "<<x<<endl;}
private:
    int x;
};
main()
{
    A a(1),b(2);
    cout<<" a: "; a.disp();
    cout<<" b: "; b.disp();
    return 0;
}
```

程序运行的结果:
```
a: x=1
b: x=2
```

### 理解this

- 每一个类的成员函数都有一个隐藏定义的**常量指针**，我们把它称为this指针。
- this指针的**类型**就是成员函数所属的**类的类型**。
- 每当调用成员函数时，它被初始化为被调函数所在类的**对象的地址**。也就是自动地将对象的指针传给它。不同的对象调用同一个成员函数时，编译器将根据成员函数的this指针所指向的对象来确定应该引用哪一个对象的数据成员。
- 在通常情况下，this指针在系统中是**隐含地存在**的。也可以将其**显式**地表示出来。
- `cout<<“x=”<<this->x<<endl;`

##### 例3.2 显示this指针的值。 （显式）
```cpp
#include<iostream.h>
class A{
public:
    A(int x1){ x=x1;}
    void disp(){cout<<"\nthis="<<this<<"when x="<<this->x;}
private:
    int x;
};
main()
{
    A a(1),b(2),c(3);
    a.disp();
    b.disp();
    c.disp();
    return 0;
}
```
```
this=0x0065FDF4 when x=1
this=0x0065FDF0 when x=2
this=0x0065FDEC when x=3
```

##### 【例3.3】 分析下列程序的运行结果,说明程序中this和*this的用法
```cpp
#include<iostream.h>
class Sample{
private:
    int x,y;
public:
    Sample(int i=0,int j=0)
    { x=i; y=j; }
    void copy(Sample& xy);
    void print()
    { cout<<x<<","<<y<<endl; }
};
void Sample::copy(Sample& xy)
{
    if (this==&xy) return;
    *this=xy;
}
void main()
{
    Sample p1,p2(5,6);
    p1.copy(p2);
    p1.print();
}
```
运行结果：
```
5,6
```

##### 例.一个使用this的类
```cpp
class Circle{
private:
    double radius;
public:
    Circle(double radius) // 参数与数据成员同名时
    {
        this->radius = radius; // 去掉 this 如何理解？
    } // P272.例9.5中形式参数为何取 nam ？
    double get_area()
    {
        return 3.14 * radius * radius;
    }
};
int main()
{
    Circle c = Circle(1);
    double a = c.get_area();
    cout << a << endl;
    return 0;
}
```

### 说明:

- this指针是一个const指针，不能在程序中修改它或给它赋值。
- this指针是一个局部数据，它的作用域仅在一个对象的内部。

#### （1） 隐式存在
this指针是隐式使用的，它是作为参数被传递给成员函数的。

#### （2）自动实现
是编译系统自动实现的，程序设计者不必人为地在形参中增加this指针，也不必将对象a的地址传给this指针。

#### （3） *this
表示对象当前对象本身
> 例如，计算Box体积的函数可以改写为`return((*this).height * (*this).width * (*this).length);`
