/***************************************************
* Author: coolyr
* Mail: yunrong@pku.edu.cn
* Description:
***************************************************/

//预处理器
//预处理器是一些指令，指示编译器在实际编译之前所需完成的预处理。
//所有的预处理器指令都是以井号（#）开头，只有空格字符可以出现在预处理指令之前。
//预处理指令不是 C++ 语句，所以它们不会以分号（;）结尾
//
//#define 预处理
//#define 预处理指令用于创建符号常量。该符号常量通常称为宏，指令的一般形式是：
//#define macro-name replacement-text 
//函数宏
//可以使用 #define 来定义一个带有参数的宏
//#define MIN(a,b) (((a)<(b)) ? a : b)
//
//条件编译
//用来有选择地对部分程序源代码进行编译。
//#ifndef NULL
//   #define NULL 0
//#endif
//
//
//您可以只在调试时进行编译，调试开关可以使用一个宏来实现，如下所示：
//#ifdef DEBUG
//   cerr <<"Variable x = " << x << endl;
//#endif
//如果在指令 #ifdef DEBUG 之前已经定义了符号常量 DEBUG，则会对程序中的 cerr 语句进行编译
//
//您可以使用 #if 0 语句注释掉程序的一部分
//#if 0
//   不进行编译的代码
//#endif
//
//
//# 和 ## 运算符
//# 运算符会把 replacement-text 令牌转换为用引号引起来的字符串。
//## 运算符用于连接两个令牌。
//
//
//C++ 中的预定义宏
//__LINE__  这会在程序编译时包含当前行号。
//__FILE__  这会在程序编译时包含当前文件名。
//__DATE__  会包含一个形式为 month/day/year 的字符串，它表示把源文件转换为目标代码的日期。
//__TIME__  这会包含一个形式为 hour:minute:second 的字符串，它表示程序被编译的时间。
//

#include <iostream>
using namespace std;

#define DEBUG 

#define PI 3.14159
#define MIN(a, b) ((a)<(b) ? a : b) 

int main(int argc, char** argv, char** envp){

    cout << "Value of PI: " << PI << endl;

    int i, j;
    i = 100;
    j = 30;

#ifdef DEBUG
    cerr << "Trace: Inside main function";
#endif

#if 0
        /*这是注释部分*/
    cout << MKSTR(HELLO C++) << endl;
#endif

    cout << "The minimum is " << MIN(i, j) << endl;

#ifdef DEBUG
        cerr << "Trace: Coming cout of maiin function" << endl;
#endif

    cout << "Value of __LINE__ : " << __LINE__ << endl;
    cout << "Value of __FILE__ : " << __FILE__ << endl;
    cout << "Value of __DATE__ : " << __DATE__ << endl;
    cout << "Value of __TIME__ : " << __TIME__ << endl;

    return 0;    
}

