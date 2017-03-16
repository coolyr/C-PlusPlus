/***************************************************
* Author: coolyr
* Mail: yunrong@pku.edu.cn
* Description:
***************************************************/

//数据封装
//据封装是一种把数据和操作数据的函数捆绑在一起的机制
//数据抽象是一种仅向用户暴露接口而把具体的实现细节隐藏起来的机制。
//
//设计策略
//通常情况下，我们都会设置类成员状态为私有（private），除非我们真的需要将其暴露，这样才能保证良好的封装性。
//这通常应用于数据成员，但它同样适用于所有成员，包括虚函数。

#include <iostream>
using namespace std;

class Adder{
   public:
      // 构造函数
      Adder(int i = 0)
      {
        total = i;
      }
      // 对外的接口
      void addNum(int number)
      {
          total += number;
      }
      // 对外的接口
      int getTotal()
      {
          return total;
      };
   private:
      // 对外隐藏的数据
      int total;
};

int main(int argc, char** argv, char** envp){

    Adder a;
   
    a.addNum(10);
    a.addNum(20);
    a.addNum(30);

    cout << "Total " << a.getTotal() <<endl;
    return 0;    
}

