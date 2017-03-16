/***************************************************
* Author: coolyr
* Mail: yunrong@pku.edu.cn
* Description:
***************************************************/

//接口（抽象类）
//
//接口描述了类的行为和功能，而不需要完成类的特定实现。
//C++ 接口是使用抽象类来实现的，抽象类与数据抽象互不混淆，
//数据抽象是一个把实现细节与相关的数据分离开的概念。

//如果类中至少有一个函数被声明为 [纯虚函数]，则这个类就是抽象类。
//纯虚函数是通过在声明中使用 "= 0" 来指定的
//
//
//<设计策略>
//面向对象的系统可能会使用一个抽象基类为所有的外部应用程序提供一个适当的、通用的、标准化的接口。然后，派生类通过继承抽象基类，就把所有类似的操作都继承下来。
//外部应用程序提供的功能（即公有函数）在抽象基类中是以 [纯虚函数] 的形式存在的。这些纯虚函数在相应的派生类中被实现。
//这个架构也使得新的应用程序可以很容易地被添加到系统中，即使是在系统被定义之后依然可以如此。

#include <iostream>
using namespace std;

class Shape
{
    public:
        //纯虚函数 -> Shape可以看成是Interace 或者 abstract class
        virtual int getArea() = 0;
        void setWidth(int w)
        {
            width = w;
        }

        void setHeight(int h)
        {
            height = h;
        }

    protected:
        int width;
        int height;
};

class Rectangle: public Shape
{
    public:
        int getArea()
        {
            return (width * height);
        }
};

class Triangle: public Shape
{
    public:
        int getArea()
        {
            return (width * height) / 2;
        }
};

int main(int argc, char** argv, char** envp){
    Rectangle Rect;
    Triangle Tri;

    Rect.setWidth(5);
    Rect.setHeight(7);

    //输出对象的面积
    cout << "Total Rectangle area: " << Rect.getArea() << endl;

    Tri.setWidth(5);
    Tri.setHeight(7);

    //输出对象的面积
    cout << "Total Trianngle area: " << Tri.getArea() << endl;

    return 0;    
}

