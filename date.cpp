/***************************************************
* Author: coolyr
* Mail: yunrong@pku.edu.cn
* Description:
***************************************************/

//C++ 标准库没有提供所谓的日期类型。C++ 继承了 C 语言用于日期和时间操作的结构和函数。为了使用日期和时间相关的函数和结构，需要在 C++ 程序中引用 <ctime> 头文件。
//有四个与时间相关的类型：clock_t、time_t、size_t 和 tm。类型 clock_t、size_t 和 time_t 能够把系统时间和日期表示为某种整数。
//结构类型 tm 把日期和时间以 C 结构的形式保存，tm 结构的定义如下：

/*
struct tm {
    int tm_sec;   // 秒，正常范围从 0 到 59，但允许至 61
    int tm_min;   // 分，范围从 0 到 59
    int tm_hour;  // 小时，范围从 0 到 23
    int tm_mday;  // 一月中的第几天，范围从 1 到 31
    int tm_mon;   // 月，范围从 0 到 11
    int tm_year;  // 自 1900 年起的年数
    int tm_wday;  // 一周中的第几天，范围从 0 到 6，从星期日算起
    int tm_yday;  // 一年中的第几天，范围从 0 到 365，从 1 月 1 日算起
    int tm_isdst; // 夏令时
}
 *
 */

#include <iostream>
#include <ctime>

using namespace std;


int main(int argc, char** argv, char** envp){
    //基于当前系统的当前日期/时间
    time_t now = time(0);

    //把 now 转换为字符串形式
    char* dt = ctime(&now);

    cout << "本地日期和时间：" << dt << endl;

    //把 now 转换为 tm 结构
    tm *gmtm = gmtime(&now);
    dt = asctime(gmtm);
    cout << "UTC 日期和时间: " << dt << endl;
    
    //使用结构 tm 格式化时间
    //tm 结构在 C/C++ 中处理日期和时间相关的操作时，显得尤为重要。tm 结构以 C 结构的形式保存日期和时间。大多数与时间相关的函数都使用了 tm 结构。下面的实例使用了 tm 结构和各种与日期和时间相关的函数。
    //

    cout << "Number of sec since January 1,1970:" << now << endl;
    tm *myTM = localtime(&now);
    // 输出 tm 结构的各个组成部分
    cout << "Year: "<< 1900 + myTM->tm_year << endl;
    cout << "Month: "<< 1 + myTM->tm_mon<< endl;
    cout << "Day: "<<  myTM->tm_mday << endl;
    cout << "Time: "<< 1 + myTM->tm_hour << ":";
    cout << 1 + myTM->tm_min << ":";
    cout << 1 + myTM->tm_sec << endl;
    
    return 0;    
}

