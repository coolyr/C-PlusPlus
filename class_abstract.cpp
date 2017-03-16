/***************************************************
* Author: coolyr
* Mail: yunrong@pku.edu.cn
* Description:
***************************************************/

//数据抽象
//数据抽象是指，只向外界提供关键信息，隐藏其后台的实现细节，即只表现必要的信息而不呈现细节
//数据抽象是一种依赖于接口和实现分离的编程（设计）技术。
//
//设计策略
//抽象把代码分离为接口和实现。所以在设计组件时，必须保持接口独立于实现
//这样，如果改变底层实现，接口也将保持不变。
//这样，不管任何程序使用接口，接口都不会受到影响，只需要将最新的实现重新编译即可。

#include <iostream>
using namespace std;

class Adder
{
    public:
        //构造函数
        Adder(int i=0)
        {
            total = i;
        }
        //对外的接口
        void addNum(int number)
        {
            total += number;
        }
        //对外接口
        int getTotal()
        {
            return total;
        }

    private:
        //对外隐藏的数据
        int total;

};

int main(int argc, char** argv, char** envp){
    Adder a;

    a.addNum(10);
    a.addNum(20);
    a.addNum(30);

    cout << "Total :" << a.getTotal() << endl;

    return 0;    
}

