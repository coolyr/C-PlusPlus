/***************************************************
* Author: coolyr
* Mail: yunrong@pku.edu.cn
* Description:
***************************************************/

#include <iostream>
using namespace std;


//构造函数 & 析构函数
//类的构造函数是一种特殊的函数，在创建一个新的对象时调用。
//类的析构函数也是一种特殊的函数，在删除所创建的对象时调用

//类的构造函数是类的一种特殊的成员函数，它会在每次创建类的新对象时执行
//构造函数的名称与类的名称是完全相同的，并且不会返回任何类型，也不会返回 void。
//构造函数可用于为某些成员变量设置初始值。


//类的析构函数是类的一种特殊的成员函数，它会在每次删除所创建的对象时执行。
//
//析构函数的名称与类的名称是完全相同的，只是在前面加了个波浪号（~）作为前缀
//它不会返回任何值，也不能带有任何参数。
//构函数有助于在跳出程序（比如关闭文件、释放内存等）前释放资源。
class Line
{
    public:
        void setLength(double len);
        double getLength(void);
        Line(); //构造函数 - 有参
        Line(double len);//构造函数 - 无参
        ~Line(); // 析构函数
    private:
        double length;
};

//成员函数定义，包括构造函数
Line::Line(void)
{
    cout << "Object is being created : 无参构造" << endl;
}

/*Line::Line(double len)
{
    cout << "Object is being created : 有参构造" << endl;
    length = len;
}
*/
//使用初始化列表来初始化字段
Line::Line(double len): length(len)
{
    cout << "Object is being created : 初始化列表构造" << endl;
}

//成员函数的定义：析构函数

Line::~Line(void)
{
    cout << "Object is being deleted" << endl;
}

void Line::setLength(double len)
{
    length = len;
}

double Line::getLength(void)
{
    return length;
}



int main(int argc, char** argv, char** envp){
    //Line line;
    Line line(10.0);

    cout << "Length of line: " << line.getLength() << endl;
    //设置长度
    line.setLength(6.0);
    cout << "Length of line: " << line.getLength() << endl;

    return 0;    
}

