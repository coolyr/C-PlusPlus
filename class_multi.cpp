/***************************************************
* Author: coolyr
* Mail: yunrong@pku.edu.cn
* Description:
***************************************************/

//<C++ 多态>
//多态按字面的意思就是多种形态。当类之间存在层次结构，并且类之间是通过继承关联时，就会用到多态。
//C++ 多态意味着调用成员函数时，会根据调用函数的对象的类型来执行不同的函数。

// <1>虚函数
//
//虚函数 是在基类中使用关键字 virtual 声明的函数。
//在派生类中重新定义基类中定义的虚函数时，会告诉编译器不要静态链接到该函数。
//
// <2>纯虚函数
//
//您可能想要在基类中定义虚函数，以便在派生类中重新定义该函数更好地适用于对象，
//但是您在基类中又不能对虚函数给出有意义的实现，这个时候就会用到纯虚函数。


#include <iostream>
using namespace std;

class Shape
{
    protected:
        int width, height;
    public:
        Shape(int a=0, int b=0)
        {
            width = a;
            height = b;
        }

        //编译器看的是指针的内容，而不是它的类型
        //int area()
        virtual int area()
        {
            cout << "Parent class area : " << endl;
            return 0;
        }
        
        // pure virtual function
        // = 0 [告诉编译器，函数没有主体，上面的虚函数是 <纯虚函数>。]
        //virtual int area() = 0;
};

class Rectangle: public Shape
{
    public:
        Rectangle(int a=0, int b=0): Shape(a, b) { }

        int area()
        {
            cout << "Rectangle class area:" << endl;
            return (width * height);
        }
};

class Triangle: public Shape
{
    public:
        Triangle(int a=0, int b=0): Shape(a, b) { }
 
        int area()
        {   
            cout << "Triangle class area : " << endl;
            return (width * height / 2);
        }
};


int main(int argc, char** argv, char** envp){
    Shape *shape;
    Rectangle rec(10, 7);
    Triangle tri(10, 5);

    //存储矩形的地址
    shape = &rec;
    // 调用矩形的求面积函数 area
    shape->area();

    //存储三角形的地址
    shape = &tri;
    //调用三角形的求面积函数 area
    shape->area();

    return 0;    
}

