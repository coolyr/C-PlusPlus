/***************************************************
* Author: coolyr
* Mail: yunrong@pku.edu.cn
* Description:
***************************************************/
//C++ 内联函数
//通过内联函数，编译器试图在调用函数的地方扩展函数体中的代码。
//C++ 内联函数是通常与类一起使用.
//如果一个函数是内联的，那在编译时，编译器会把该函数的代码副本放置在每个调用该函数的地方。
//
//##对内联函数进行任何修改，都需要重新编译函数的所有客户端，
//##因为编译器需要重新更换一次所有的代码，否则将会继续使用旧的函数。
//
//<1>内联函数，需要在函数名前面放置关键字 inline
//<2>在调用函数之前需要对函数进行定义
//<3>如果已定义的函数多于一行，编译器会忽略 inline 限定符??? [inline函数必须定义在一行]
//<4>在类定义中的定义的函数都是内联函数，即使没有使用 inline 说明符。
//



#include <iostream>
using namespace std;


inline int Max(int x, int y)
{
    return (x>y) ? x : y;
}

int main(int argc, char** argv, char** envp){
    
    cout << "Max (20,10): " << Max(20, 10) << endl;
    cout << "Max (0,200): " << Max(0,200) << endl;
    cout << "Max (100, 1010): " << Max(100, 1010) << endl;

    return 0;    
}


//内联函数：

//（1） 内联函数定义和作用：
//将一个函数声明为inline，那么函数就成为内联函数。内联函数通常就是它在程序中每个调用点上“内联地”展开。从定义上看，内联函数跟一般函数不一样，一般函数调用的时候是需要调用开销的（比如出栈入栈等操作），内联函数从定义上看更像是宏，但是跟宏不一样。
//内联函数的作用主要就是使用在一些短小而使用非常频繁的函数中，为了减少函数调用的开销，为了避免使用宏（在c++中，宏是不建议使用的）。比如内联函数inline int  func(int x){return x*x;} 在调用的时候cout<<func(x)<<endl，在编译时将被展开为：
//cout<<(x*x)<<endl;

//（2） 内联函数相对于宏的区别和优点：
//从上面的分析中，可以看出，内联函数在表现形式上与宏很类似。但是内联函数和宏之间的区别很明显。宏是在预处理时进行的机械替换，内联是在编译时进行的。内联函数是真正的函数，只是在调用时，没有调用开销，像宏一样进行展开。内联函数会进行参数匹配检查，相对于带参数的宏有很好的优点，避免了处理宏的一些问题。

//（3） 如何使用内联函数和禁止内联：
//要让一个函数称为内联函数，有两种方法：一种是把函数加上inline关键字；一种是在类的说明部分定义的函数，默认就是内联的。
//要禁止编译器进行内联，可以使用#pragma auto_inline编译指令或者改变编译参数。

//（4） 内联函数注意事项：
    //<1>      内联函数一定会内联展开吗？答案是否定的。对于内联函数，程序只是提供了一个“内联建议”，即建议编译器把函数用内联展开，但是真正是否内联，是由编译器决定的，对于函数体过大的函数，编译器一般不会内联，即使制定为内联函数。
    //<2>       在内联函数内部，不允许用循环语句和开关语句（if或switch）。内联函数内部有循环和开关，也不会出错，但是编译器会把它当做非内联函数的。
    //<3>       关键字inline必须与函数定义体放在一起才能使函数真正内联，仅把inline放在函数声明的前面不起任何作用。因为inline是一种用于实现的关键字，不是一种用于声明的关键字。内联函数的声明是不需要加inline关键字的，内联函数的定义是必须加inline的（除了类的定义部分的默认内联函数），尽管很多书声明定义都加了，要注意理解声明和定义的区别。
    //<4>       在一个文件中定义的内联函数不能在另一个文件中使用。它们通常放在头文件中共享。
    //<5>       内联函数的定义必须在第一次调用之前。注意，这里是定义之前，不仅仅是声明之前。对于普通函数，可以在调用之前声明，调用代码之后具体定义（实现函数），但是内联函数要实现内联，必须先定义再调用，否则编译器会把在定义之前调用的内联函数当做普通函数进行调用。
    //<6>       说明：上面这些inline的注意事项，在编程时要自己注意，因为上面的注意事项不遵守很多并不会引起编译错误，只是会导致写了inline的函数不是内联函数，从而与预期的目的不一样。所以很多没法用程序实例说明到底编译器是按照inline还是非inline调用的，或许分析汇编代码能看出，但是水平有限，就不多分析了。


