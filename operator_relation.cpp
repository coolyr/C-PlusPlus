/***************************************************
* Author: coolyr
* Mail: yunrong@pku.edu.cn
* Description:
***************************************************/
//C++ 语言支持各种关系运算符（ < 、 > 、 <= 、 >= 、 == 等等），它们可用于比较 C++ 内置的数据类型。
//您可以重载任何一个关系运算符，重载后的关系运算符可用于比较类的对象。


#include <iostream>
using namespace std;

class Distance
{
   private:
      int feet;             // 0 到无穷
      int inches;           // 0 到 12
   public:
      // 所需的构造函数
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
      
      // 显示距离的方法
      void displayDistance()
      {
         cout << "F: " << feet << "\tI:" << inches <<endl;
      }
      
      // 重载负运算符（ - ）
      Distance operator- ()  
      {
         feet = -feet;
         inches = -inches;
         return Distance(feet, inches);
      }
      
      // 重载小于运算符（ < ）
      bool operator <(const Distance& d)
      {
         if(feet < d.feet)
         {
            return true;
         }
         if(feet == d.feet && inches < d.inches)
         {
            return true;
         }
         return false;
      }
};



int main(int argc, char** argv, char** envp){

    Distance D1(11, 10), D2(5, 11);
 
    if( D1 < D2 )
    {
       cout << "D1 is less than D2 " << endl;
    }
    else
    {
       cout << "D2 is less than D1 " << endl;
    }
    return 0;
}

