/***************************************************
* Author: coolyr
* Mail: yunrong@pku.edu.cn
* Description:
***************************************************/

//C++ 输入/输出运算符重载
//C++ 能够使用流提取运算符 >> 和流插入运算符 << 来输入和输出内置的数据类型。
//您可以重载流提取运算符和流插入运算符来操作对象等用户自定义的数据类型。
//有一点很重要，需要把运算符重载函数声明为类的友元函数，这样我们就能不用创建对象而直接调用函数。

#include <iostream>
using namespace std;

class Distance
{
    private:
        int feet;
        int inches;
    public:
        Distance()
        {
            feet = 0;
            inches = 0;
        }

        Distance(int f, int i)
        {
            feet = f;
            inches = i;
        }

        friend ostream &operator<<(ostream &output, const Distance &D)
        {
           output << "F: " << D.feet << "\tI: " << D.inches;
           return output;
        }

        friend istream &operator>>(istream &input, Distance &D)
        {
            input >> D.feet >> D.inches;
            return input;
        }
};

int main(int argc, char** argv, char** envp){

    Distance D1(11, 10), D2(5, 11), D3;

    cout << "Enter the value of object: " << endl;
    cin >> D3;

    cout << "First Distance :\t" << D1 << endl;
    cout << "Second Distance :\t" << D2 << endl;
    cout << "Third Distance :\t" << D3 << endl;

    return 0;    
}

