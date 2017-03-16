/***************************************************
* Author: coolyr
* Mail: yunrong@pku.edu.cn
* Description:
***************************************************/

//C++ 二元运算符重载
//
//二元运算符需要两个参数，下面是二元运算符的实例。
//我们平常使用的加运算符（ + ）、减运算符（ - ）、乘运算符（ * ）和除运算符（ / ）都属于二元运算符

#include <iostream>
using namespace std;

class Box
{
    double length;
    double breadth;
    double height;

    public:
        double getVolume(void)
        {
            return length * breadth * height;
        }

        void setLength(double len)
        {
            length = len;
        }
        void setBreadth(double bre)
        {
            breadth = bre;
        }
        void setHeight(double hei)
        {
            height = hei;
        }
        Box operator+(const Box &b)
        {
            Box box;
            box.length = this->length + b.length;
            box.breadth = this->breadth + b.breadth;
            box.height = this->height + b.height;

            return box;
        }
};

int main(int argc, char** argv, char** envp){
    Box box1;                // 声明 Box1，类型为 Box
    Box box2;                // 声明 Box2，类型为 Box
    Box box3;                // 声明 Box3，类型为 Box
    double volume = 0.0;     // 把体积存储在该变量中

    box1.setLength(6.0);
    box1.setBreadth(7.0);
    box1.setHeight(5.0);

    box2.setLength(12.0);
    box2.setBreadth(13.0);
    box2.setHeight(10.0);

    volume = box1.getVolume();
    cout << "volume of box1: " << volume << endl;

    volume = box2.getVolume();
    cout << "volue of box2: " << volume << endl;

    // 把两个对象相加，得到 Box3
    box3 = box1 + box2;
    volume = box3.getVolume();
    cout << "Volume of Box3: " << volume << endl;


    return 0;    
}

