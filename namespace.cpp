/***************************************************
* Author: coolyr
* Mail: yunrong@pku.edu.cn
* Description:
***************************************************/

//命名空间
//作为附加信息来区分不同库中相同名称的函数、类、变量等。
//使用了命名空间即定义了上下文。本质上，命名空间就是定义了一个范围。

//using 指令
//<1>您可以使用 using namespace 指令，这样在使用命名空间时就可以不用在前面加上命名空间的名称。
//这个指令会告诉编译器，后续的代码将使用指定的命名空间中的名称。

//<2>using 指令也可以用来指定命名空间中的特定项目。
//例如，如果您只打算使用 std 命名空间中的 cout 部分，您可以使用如下的语句：
//using std::cout;

//<3>using 指令引入的名称遵循正常的范围规则。
//名称从使用 using 指令开始是可见的，直到该范围结束。
//此时，在范围以外定义的同名实体是隐藏的。


//<4>不连续的命名空间
//命名空间可以定义在几个不同的部分中，因此命名空间是由几个单独定义的部分组成的
//一个命名空间的各个组成部分可以分散在多个文件中。
//如果命名空间中的某个组成部分需要请求定义在另一个文件中的名称，则仍然需要声明该名称。
//下面的命名空间定义可以是 <定义一个新的命名空间>， 也可以是<为已有的命名空间增加新的元素>：
//namespace namespace_name {
//   // 代码声明
//   }


//<5>嵌套的命名空间
//命名空间可以嵌套，您可以在一个命名空间中定义另一个命名空间，如下所示：
//您可以通过使用 :: 运算符来访问嵌套的命名空间中的成员：
//
//
//
#include <iostream>
using namespace std;

//第一个命名空间
namespace first_space
{
    void func()
    {
        cout << "Inside first_space" << endl;
    }
    namespace third_space
    {
        void func()
        {
            cout << "In Inside third_sapce" << endl;
        }

        void func2()
        {
            cout << "Inside third_space" << endl;
        }
    }
}

namespace second_space
{
    void func()
    {
        cout << "Inside second_space" << endl;
    }
}

using namespace first_space::third_space;
//using namespace first_space;
int main(int argc, char** argv, char** envp){

    func();
    //func2(); //声明为first_space时，不能直接使用first_space中的third_space的func2()

    //调用第一个命名空间中的函数
    first_space::func();

    //调用第二个命名空间中的函数
    second_space::func();
    return 0;    
}




