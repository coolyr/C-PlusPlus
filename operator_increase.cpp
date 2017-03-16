/***************************************************
* Author: coolyr
* Mail: yunrong@pku.edu.cn
* Description:
***************************************************/

//C++ ++ 和 -- 运算符重载
//递增运算符（ ++ ）和递减运算符（ -- ）是 C++ 语言中两个重要的一元运算符。
//

#include <iostream>
using namespace std;

class Time
{
    private:
        int hours;
        int minutes;
    public:
        Time()
        {
            hours = 0;
            minutes = 0;
        }

        Time(int h, int m)
        {
            hours = h;
            minutes = m;
        }
        //显示时间的方法
        void displayTime()
        {
            cout << "H: " << hours << "\tM: " << minutes << endl;
        }

        //重载前缀递增运算符（ ++ ）
        Time operator++()
        {
            ++minutes;
            if(minutes >= 60)
            {
                ++hours;
                minutes -= 60;
            }

            return Time(hours, minutes);
        }

        Time operator++(int)
        {
            //保存原始值
            Time T(hours, minutes);
            ++minutes;
            if(minutes >= 60)
            {
                ++hours;
                minutes -= 60;
            }

            //返回旧的原始值
            return T;
        }
};

int main(int argc, char** argv, char** envp){
    Time T1(11, 59), T2(10, 40);
    
    T1.displayTime();
    ++T1;
    T1.displayTime();
    ++T1;                    // T1 再加 1
    T1.displayTime();        // 显示 T1
 
    T2.displayTime();
    T2++;                    // T2 加 1
    T2.displayTime();        // 显示 T2
    T2++;                    // T2 再加 1
    T2.displayTime();        // 显示 T2turn 0;    
    return 0;
}
