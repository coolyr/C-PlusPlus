/***************************************************
* Author: coolyr
* Mail: yunrong@pku.edu.cn
* Description:
***************************************************/

//拷贝构造函数是一种特殊的构造函数，它在创建对象时，
//是使用同一类中之前创建的对象来初始化新创建的对象。
//拷贝构造函数通常用于
//
//<1> 通过使用另一个同类型的对象来初始化新创建的对象。
//<2> 复制对象把它作为参数传递给函数。
//<3> 复制对象，并从函数返回这个对象。
//
//如果在类中没有定义拷贝构造函数，编译器会自行定义一个。
//如果类带有指针变量，并有动态内存分配，则它必须有一个拷贝构造函数。
//
//
#include <iostream>
using namespace std;

class Line
{
    public:
        int getLength(void);
        Line(int len);// 简单的构造函数
        Line(const Line &obj); // 拷贝构造函数
        ~Line(); //析构函数

    private:
        int *ptr;
};

//成员函数定义，包括构造函数
Line::Line(int len)
{
    cout << "Normal constructor allocationg ptr" << endl;
    //为指针分配内存
    ptr = new int; // new 返回一个int【地址快】的地址，把地址赋值给ptr
    *ptr = len; //把len存储到new所申请的地址中
}

Line::Line(const Line &obj)
{
    cout << "Copy constructor allocating ptr." << endl;
    ptr = new int;
    *ptr = *obj.ptr; // copy the value
}

Line::~Line(void)
{
    cout << "Freeing Memory!" << endl;
    delete ptr;
}

int Line::getLength(void)
{
    return *ptr;
}

//全局函数
void display(Line obj)
{
    cout << "length of Line : " << obj.getLength() << endl;
}



int main(int argc, char** argv, char** envp){

    Line line(10); // normal
    
    Line line2 = line; //这里也调用了copy构造函数

    display(line); // copy -> display -> free
    display(line2);// copy -> display -> free

    // free line
    // free line2
    return 0;    
}

