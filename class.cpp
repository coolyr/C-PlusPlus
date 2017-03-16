/***************************************************
* Author: coolyr
* Mail: yunrong@pku.edu.cn
* Description:
***************************************************/


#include <iostream>
using namespace std;


class Box
{
    public:
        double length;
        double breadth;
        double height;
        //成员函数声明
        double getVolume2(void);
        void setLength(double len);
        void setBreadth(double bre);
        void setHeight(double hei);

        //在类定义中定义的成员函数把函数声明为内联的，即便没有使用 inline 标识符
        double getVolume(void)
        {
            return length * breadth * height;
        }

}; //必须有';'

//成员函数定义
//在类的外部使用 <<范围解析运算符 :: >> 定义该函数
double Box::getVolume2(void)
{
    return length * breadth * height;
}

void Box::setLength(double len)
{
    length = len;
}

void Box::setBreadth(double bre)
{
    breadth = bre;
}

void Box::setHeight(double hei)
{
    height = hei;
}

int main(int argc, char** argv, char** envp)
{

    Box box1;
    Box box2;
    double volume = 0.0;

    box1.height = 5.0;
    box1.length = 6.0;
    box1.breadth = 7.0;

    box2.height = 10.0;
    box2.length = 12.0;
    box2.breadth = 13.0;

    volume = box1.height * box1.length * box1.breadth;
    cout << "box1 的体积: " << volume << endl;

    volume = box2.height * box2.length * box2.breadth;
    cout << "Box2 的体积: " << volume << endl;
    
    cout << "*************************" << endl;
    // box1
    box1.setLength(11.5);
    box1.setBreadth(7.0);
    box1.setHeight(5.0);

    box2.setLength(2.5);
    box2.setBreadth(13.0);
    box2.setHeight(8.5);
    
    volume = box1.height * box1.length * box1.breadth;
    cout << "box1 的体积: " << volume << endl;

    volume = box2.height * box2.length * box2.breadth;
    cout << "Box2 的体积: " << volume << endl;
    


    return 0;    
}

