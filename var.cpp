/***************************************************
* Author: coolyr
* Mail: yunrong@pku.edu.cn
* Description:
***************************************************/

//<1>当局部变量被定义时，系统不会对其初始化，您必须自行对其初始化。定义全局变量时，系统会自动初始化为下列值：


#include <iostream>
using namespace std;
 
// 函数声明
int max(int num1, int num2);
// 变量声明
//extern int x = 10;
extern int x;

 
int main ()
{
   // 局部变量声明
   int a = 100;
   int b = 200;
   int ret;
   //变量定义
   int x;
   //变量初始化
   x = 5;

   cout << "变量声明和定义: " << x << endl;

 
   // 调用函数来获取最大值
   ret = max(a, b);
 
   cout << "Max value is : " << ret << endl;
 
   return 0;
}
 
// 函数返回两个数中较大的那个数
int max(int num1, int num2) 
{
   // 局部变量声明
   int result;
 
   if (num1 > num2)
      result = num1;
   else
      result = num2;
 
   return result; 
}
