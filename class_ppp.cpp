/***************************************************
* Author: coolyr
* Mail: yunrong@pku.edu.cn
* Description:
***************************************************/
//类访问修饰符
//
//类成员可以被定义为 public、private 或 protected。默认情况下是定义为 private。
//类成员的访问限制是通过在类主体内部对各个区域标记 public、private、protected 来指定的。关键字 public、private、protected 称为访问说明符。
//
//一个类可以有多个 public、protected 或 private 标记区域。每个标记区域在下一个标记区域开始之前或者在遇到类主体结束右括号之前都是有效的。
//
//#######成员和类的默认访问修饰符是 private。

#include <iostream>
using namespace std;

class Line
{
    //公有成员在程序中类的外部是可访问的。您可以不使用任何成员函数来设置和获取公有变量的值
    public:
        double length;
        void setLength(double len);
        double getLength(void);
        void setWidth(double wid);
        double getWidth(void);
    //私有成员变量或函数在类的外部是不可访问的，甚至是不可查看的。
    //只有类和友元函数可以访问私有成员。
    //默认情况下，类的所有成员都是私有的。例如在下面的类中，width 是一个私有成员，
    //这意味着，如果您没有使用任何访问修饰符，类的成员将被假定为私有成员
    private:
        double width;

    //保护成员变量或函数与私有成员十分相似，但保护成员在派生类（即子类）中是可访问的
    protected:
        double color;

};


// 成员函数定义
double Line::getLength(void)
{
    return length;
}

void Line::setLength(double len)
{
    length = len;
}

double Line::getWidth(void)
{
    return width;
}
void Line::setWidth(double wid)
{
    width = wid;
}

class subLine:Line
{
    public:
        void setSubColor(double colo);
        double getSubColor(void);
};

//子类的成员函数
void subLine::setSubColor(double colo)
{
    color = colo;
}

double subLine::getSubColor(void)
{
    return color;
}

int main(int argc, char** argv, char** envp){

    Line line;
    cout << "************Public: " << endl;
    //设置长度
    line.setLength(6.0);
    cout << "Length of Line: " << line.getLength() << endl;

    //不使用成员函数设置长度
    line.length = 10.0; // OK: 因为 length 是公有的
    cout << "Length of Line: " << line.length << endl;

    cout << "***********Private: " << endl;
    line.setWidth(3.5);
    cout << "Width of Line: " << line.getWidth() << endl;

    cout << "***********Protected:" << endl;
    subLine subline;
    subline.setSubColor(10000.0);
    cout << "Color of Line: " << subline.getSubColor() << endl;


    return 0;    
}

