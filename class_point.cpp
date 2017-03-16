/***************************************************
* Author: coolyr
* Mail: yunrong@pku.edu.cn
* Description:
***************************************************/

//C++ 中指向类的指针
//指向类的指针方式如同指向结构的指针。实际上，类可以看成是一个带有函数的结构。
//
//与所有的指针一样，您必须在使用指针之前，对指针进行初始化。

#include <iostream>
using namespace std;

class Box
{
    public:
        Box(double l=2.0, double b=2.0, double h=2.0)
        {
            cout << "constructor called." << endl;
            length = l;
            breadth = b;
            height = h;
        }

        double Volume()
        {
            return length * breadth * height;
        }

    private:
        double length;
        double breadth;
        double height;

};

int main(int argc, char** argv, char** envp){

    Box box1(3.3, 1.2, 1.5);
    Box box2(8.5, 6.0, 2.0);
    Box *ptrBox;

    ptrBox = &box1;
    cout << "Volume of box1: " << ptrBox->Volume() << endl;

    ptrBox = &box2;
    cout << "Volume of box2: " << ptrBox->Volume() << endl;

    return 0;    
}

