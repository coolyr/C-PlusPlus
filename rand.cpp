/***************************************************
* Author: coolyr
* Mail: yunrong@pku.edu.cn
* Description:
***************************************************/
//关于随机数生成器，有两个相关的函数。一个是 rand()，该函数只返回一个伪随机数。生成随机数之前必须先调用 srand() 函数。
//time() 函数来获取系统时间的秒数，通过调用 rand() 函数来生成随机数：

#include <iostream>
#include <ctime>
#include <cstdlib>
using namespace std;


int main(int argc, char** argv, char** envp){
    
    int i, j;

    //设置种子
    srand((unsigned)time(NULL)) ;

    for(i=0; i<10; i++)
    {
        j = rand();
        cout << "random number: " << j << endl;
    }


    return 0;    
}

