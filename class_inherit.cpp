/***************************************************
* Author: coolyr
* Mail: yunrong@pku.edu.cn
* Description:
***************************************************/

//一个类可以派生自多个类，这意味着，它可以从多个基类继承数据和函数。
//定义一个派生类，我们使用一个类派生列表来指定基类。
//类派生列表以一个或多个基类命名，形式如下：
//class derived-class: access-specifier base-class
//
//访问修饰符 access-specifier 是 public、protected 或 private 其中的一个
//base-class 是之前定义过的某个类的名称
//如果未使用访问修饰符 access-specifier，则默认为 private

//一个派生类继承了所有的基类方法，但下列情况除外：
//<1> 基类的构造函数、析构函数和拷贝构造函数。
//<2> 基类的重载运算符。
//<3> 基类的友元函数。

//##继承类型
//我们几乎不使用 protected 或 private 继承，通常使用 public 继承。
//当使用不同类型的继承时，遵循以下几个规则：
//
//公有继承（public）：当一个类派生自公有基类时，基类的公有成员也是派生类的公有成员，基类的保护成员也是派生类的保护成员，基类的私有成员不能直接被派生类访问，但是可以通过调用基类的公有和保护成员来访问。
//
//保护继承（protected）： 当一个类派生自保护基类时，基类的公有和保护成员将成为派生类的保护成员。
//
//私有继承（private）：当一个类派生自私有基类时，基类的公有和保护成员将成为派生类的私有成员。
//
//

//###多继承
//多继承即一个子类可以有多个父类，它继承了多个父类的特性。
//C++ 类可以从多个类继承成员，语法如下：
//
//class <派生类名>:<继承方式1><基类名1>,<继承方式2><基类名2>,…

#include <iostream>
using namespace std;

class Shape
{
    public:
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

//基类 PaintCost
class PaintCost
{
    public:
        int getCost(int area)
        {
            return area * 70;
        }
};

//派生类
class Rectangle: public Shape, public PaintCost
{
    public:
        int getArea()
        {
            return (width * height);
        }
};


int main(int argc, char** argv, char** envp){

    Rectangle Rect;
    int area;

    Rect.setWidth(5);
    Rect.setHeight(7);

    area = Rect.getArea();
    //输出对象的面积
    cout << "Total area: " << Rect.getArea() << endl; 

    //输出总花费
    cout << "Total paint cost: " << Rect.getCost(area) << endl;
    return 0;    
}

