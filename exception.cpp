/***************************************************
* Author: coolyr
* Mail: yunrong@pku.edu.cn
* Description:
***************************************************/

//C++ 标准的异常
//
//C++ 提供了一系列标准的异常，定义在 <exception> 中，
//我们可以在程序中使用这些标准的异常。它们是以父子类层次结构组织起来的，如下所示：
//
//std::exception        该异常是所有标准 C++ 异常的父类。
//std::bad_alloc        该异常可以通过 new 抛出。
//std::bad_cast         该异常可以通过 dynamic_cast 抛出。
//std::bad_exception    这在处理 C++ 程序中无法预期的异常时非常有用。
//std::bad_typeid       该异常可以通过 typeid 抛出。
//std::logic_error      理论上可以通过读取代码来检测到的异常。
//std::domain_error     当使用了一个无效的数学域时，会抛出该异常。
//std::invalid_argument 当使用了无效的参数时，会抛出该异常。
//std::length_error     当创建了太长的 std::string 时，会抛出该异常。
//std::out_of_range     该异常可以通过方法抛出，例如 std::vector 和 std::bitset<>::operator[]()。
//std::runtime_error    理论上不可以通过读取代码来检测到的异常。
//std::overflow_error   当发生数学上溢时，会抛出该异常。
//std::range_error      当尝试存储超出范围的值时，会抛出该异常。
//std::underflow_error  当发生数学下溢时，会抛出该异常。

#include <iostream>
#include <exception>
using namespace std;

//定义新的异常
struct MyException : public exception
{
    //what() 是异常类提供的一个公共方法，它已被所有子异常类重载。
    //这将返回异常产生的原因。
    //const throw() -> 修饰函数体 
    // <1> const : 代表this指针式常量，不能被修改。 就是说这个函数不能修改自己的对象
    // <2> throw()  ?? 不懂
    const char* what() const throw()
    {
        return "c++ Exception.";
    }
};

double division(int a, int b)
{
    if(b == 0)
    {
        throw "Division by zero condition!";
    }
    return (a / b);
}
int main(int argc, char** argv, char** envp){

    /*
    int x = 50;
    int y = 0;
    double z = 0;

    try
    {
        z = division(x , y);
        cout << z << endl;
    }
    //由于我们抛出了一个类型为 const char* 的异常，
    //因此，当捕获该异常时，我们必须在 catch 块中使用 const char*。
    catch (const char* msg )
    {
        cerr << msg << endl;
    }
*/
    cout << "测试自定义异常：" << endl;

    try
    {
        throw MyException();
    }
    catch(MyException &e)
    {
        std::cout << "MyException caught" << std::endl;
        cout << e.what() << endl;
    }
    catch(std::exception &e)
    {
        cout << "Ohter exception!!";
    }


    return 0;    
}

