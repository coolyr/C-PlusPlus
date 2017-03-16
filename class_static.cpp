/***************************************************
* Author: coolyr
* Mail: yunrong@pku.edu.cn
* Description:
***************************************************/

//C++ 类的静态成员
//类的数据成员和函数成员都可以被声明为静态的。
//
//我们可以使用 static 关键字来把类成员定义为静态的。
//当我们声明类的成员为静态时，这意味着无论创建多少个类的对象，静态成员都只有一个副本。
//静态成员在类的所有对象中是,<共享>的。
//如果不存在其他的初始化语句，<在创建第一个对象时，所有的静态数据都会被初始化为零>。

//我们不能把静态成员放置在类的定义中??????[没明白]，但是可以在类的外部通过使用 <<范围解析运算符 ::>>  来重新声明静态变量从而对它进行初始化
//  ## 经测试，静态成员必须在外面进行初始化！！！，上面说的如果不初始化，会在创建第一个对象的时候默认初始化为0的说法测试不可行！
//  因为既然初始化了，直接调用静态函数访问java中是可行的，但是c++中不可行。

//#######################################
//静态函数成员
//
//如果把函数成员声明为静态的，就可以把函数与类的任何特定对象独立开来。
//静态成员函数即使在类对象不存在的情况下也能被调用
//静态函数只要使用类名加范围解析运算符 :: 就可以访问。
//
//静态成员函数只能访问静态数据成员，不能访问其他静态成员函数和类外部的其他函数。???
//静态成员函数有一个类范围，他们不能访问类的 this 指针。##
//您可以使用静态成员函数来判断类的某些对象是否已被创建。
//

#include <iostream>
using namespace std;

class Box
{
    public:
        static int objectCount;
        //int count = 1;
        Box(double l=2.0, double b=2.0, double h=2.0)
        {
            cout << "Constructor called." << endl;
            length = l;
            breadth = b;
            height = h;

            // 每次创建对象时增加 1
            objectCount++;
        }
        double Volume()
        {
            return length * breadth * height;
        }
        static int getCount()
        {
            return objectCount;
        }

    private:
        double length;
        double breadth;
        double height;
};

//初始化类 Box 的静态成员
int Box::objectCount = 10;

int main(int argc, char** argv, char** envp){

    cout << "Inital stage count: " << Box::getCount() << endl;

    Box box1(3.3, 1.2, 1.5);
    Box box2(8.5, 6.0, 2.0);

    //输出对象的总数
    cout << "Total objects: " << Box::objectCount << endl;

    return 0;    
}

