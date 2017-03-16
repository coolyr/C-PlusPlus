/***************************************************
* Author: coolyr
* Mail: yunrong@pku.edu.cn
* Description:
***************************************************/

//C++ 中的 this 指针
//每个对象都有一个特殊的指针 this，它指向对象本身.
//
//在 C++ 中，每一个对象都能通过 this 指针来访问自己的地址
//this 指针是所有成员函数的 <隐含参数>。
//因此，在成员函数内部，它可以用来指向调用对象。
//
//友元函数没有 this 指针，因为友元不是类的成员。只有成员函数才有 this 指针。
//

#include <iostream>
using namespace std;

class Box
{
    public:
        //构造函数定义
        Box(double l=2.0, double b=2.0, double h=2.0)
        {
            cout << "Constructor called." << endl;
            length = l;
            breadth = b;
            height = h;
        }
        
        double Volume()
        {
            return length * breadth * height;
        }

        int compare(Box box)
        {
            return this->Volume() > box.Volume();
        }

    private:
        double length;
        double breadth;
        double height;
    
};


int main(int argc, char** argv, char** envp){
    Box box1(3.3, 1.2, 1.5);
    Box box2(8.5, 6.0, 2.0);

    if(box1.compare(box2))
    {
       cout << "box2 is smaller than box1" << endl; 
    }
    else
    {
        cout << "box2 is equal to or larger than box1" << endl;
    }

    return 0;    
}

