/***************************************************
* Author: coolyr
* Mail: yunrong@pku.edu.cn
* Description:
***************************************************/


#include <iostream>
using namespace std;


int main(int argc, char** argv, char** envp){

    cout << "变量的大小会根据编译器和所使用的电脑而有所不同" << endl;
    cout << "Size of char : " << sizeof(char) << endl;
    cout << "Size of int : " << sizeof(int) << endl;
    cout << "Size of short int : " << sizeof(short int) << endl;
    cout << "Size of long int : " << sizeof(long int) << endl;
    cout << "Size of float : " << sizeof(float) << endl;
    cout << "Size of double : " << sizeof(double) << endl;
    cout << "Size of wchar_t : " << sizeof(wchar_t) << endl;
    return 0;    
}

