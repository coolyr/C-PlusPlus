/***************************************************
* Author: coolyr
* Mail: yunrong@pku.edu.cn
* Description:
***************************************************/

#include <iostream>
using namespace std;

#define LENGTH 10
void func(void);

static int count = 10;
int main(int argc, char** argv, char** envp){

    cout << "Hello C++\n";
    cout << "size of long int: " <<sizeof(long int) << endl;
    cout << "size of int: " << sizeof(int) << endl;
    enum color {red, green, blue} c;
    c = blue;
    cout << "color is:" << c << endl;
    cout << "LENGTH : " << LENGTH << endl;
    const int WIDTH = 5;
    cout << "WIDTH: " << WIDTH << endl;
    int count = 3;
    while(count--)
    {
        func();
    }

    return 0;    

}


void func(void)
{
    static int i = 5;
    i++;
    std::cout << "static i: " << i << endl;
    std::cout << "out static count: " << count << std::endl;
}

