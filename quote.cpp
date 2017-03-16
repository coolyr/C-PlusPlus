/***************************************************
* Author: coolyr
* Mail: yunrong@pku.edu.cn
* Description:
***************************************************/
//引用变量是一个别名，也就是说，它是某个已存在变量的另一个名字。一旦把引用初始化为某个变量，
//就可以使用该引用名称或变量名称来指向变量.
//引用很容易与指针混淆，它们之间有三个主要的不同：
// <1>不存在空引用。引用必须连接到一块合法的内存。
// <2>一旦引用被初始化为一个对象，就不能被指向到另一个对象。指针可以在任何时候指向到另一个对象。
// <3>引用必须在创建时被初始化。指针可以在任何时间被初始化。

//  @@@试想变量名称是变量附属在内存位置中的标签，您可以把引用当成是变量附属在内存位置中的第二个标签。因此，您可以通过原始变量名称或引用来访问变量的内容
//

#include <iostream>
using namespace std;

void swap(int &x, int &y);

double vals[] = {10.1, 12.6, 33.1, 24.1, 50.0};

double& setValues(int i)
{
    return vals[i]; //返回第 i 个元素的引用
}

int main(int argc, char** argv, char** envp){

    //声明简单的变量
    int i;
    double d;

    //声明简单的变量
    int & r = i;
    double & s = d;

    i = 5;
    cout << "Value of i : " << i << endl;
    cout << "Value of reference : " << r << endl;

    d = 11.7;
    cout << "Value of d: " << d << endl;
    cout << "Value of d reference: " << s << endl;

    //引用通常用于函数参数列表和函数返回值。
    //
    //把引用作为参数
    //C++ 支持把引用作为参数传给函数，这比传一般的参数更安全。
    
    //局部变量声明
    int a=100;
    int b=200;

    cout << "交换前, a: " << a << endl;
    cout << "交换前，b: " << b << endl;

    swap(a, b);
    
    cout << "交换后, a: " << a << endl;
    cout << "交换后, b: " << b << endl;
    
    //把引用作为返回值
    //可以从 C++ 函数中返回引用，就像返回其他数据类型一样。

    //通过使用引用来替代指针，会使 C++ 程序更容易阅读和维护。
    //c++函数可以返回一个引用，方式与返回一个指针类似。
    //当函数返回一个引用时，则返回一个指向返回值的隐式指针。这样，函数就可以放在赋值语句的左边
    cout << "改变前的值:" << endl;
    for(int i=0; i<5; i++)
    {
        cout << "vals[" << i << "] = ";
        cout << vals[i] << endl;
    }


    setValues(1) = 20.23; // 改变第 2 个元素
    setValues(3) = 70.8; // 改变第 4 个元素

    cout << "改变后的值：" << endl;
    for(int i=0; i<5; i++)
    {
        cout << "Vals[" << i << "] = ";
        cout << vals[i] << endl;
    }


    //当返回一个引用时，要注意被引用的对象不能超出作用域。
    //所以返回一个对局部变量的引用是不合法的，但是，可以返回一个对静态变量的引用。

    return 0;    
}

//函数定义
void swap(int &x, int &y)
{
    int temp;
    temp = x;
    x = y;
    y = temp;
}

int& func()
{
    int q;
    //return q; //会在编译时候发生错误
    static int x;
    return x; //安全，x 在函数作用域外依然是有效的
}




