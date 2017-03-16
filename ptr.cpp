/***************************************************
* Author: coolyr
* Mail: yunrong@pku.edu.cn
* Description:
***************************************************/


#include <iostream>
#include<ctime>


using namespace std;

const int MAX = 3;

double getAverage(int *arr, int size);

int* getRandom()
{
    static int r[10];

    srand((unsigned)time(NULL));
    for(int i=0; i<10; ++i)
    {
        r[i] = rand();
        cout << r[i] << endl;
    }
    return r;
}

int main(int argc, char** argv, char** envp){
    int var1;
    char var2[10];

    cout << "&var1 = " << &var1 << endl;
    cout << "&var2 <第一个元素var2[0]的地址的地址> = " << &var2 << endl;
    cout << "var2 <第一个元素var2[0]的地址> = " << var2 << endl;

    //C++ Null 指针 【C++ 支持空指针。NULL 指针是一个定义在标准库中的值为零的常量。】
    //cout << "NULL = " << NULL << endl;
    int *p = NULL;
    cout << "p = " << p << endl;

    //C++ 指针的算术运算 [可以对指针进行四种算术运算：++、--、+、-]
    int var[MAX] = {10, 100, 200};
    int *ptr;

    ptr = var;
    for(int i=0; i<MAX; i++)
    {
        cout << "Address of var[" << i << "] = ";
        cout << ptr << endl;

        cout << "Value of var[" << i << "] = " ;
        cout << *ptr << endl;

        ptr++;
    }
    
    ptr = &var[MAX - 1];
    for(int i=MAX; i>0; i--)
    {
        cout << "Adress of var[[" << i << "] = ";
        cout << ptr << endl;

        cout << "Value of var[" << i << "] =";
        cout << *ptr << endl;
        ptr--;
    }

    ptr = var;
    int i = 0;
    while(ptr <= &var[MAX - 1])
    {
        cout << "Adress of var[" << i << "] = ";
        cout << ptr << endl;

        cout << "Value of var [" << i << "] = ";
        cout << *ptr << endl;
        ptr++;
        i++;
    }
    
//C++ 指针 vs 数组 [ 指针和数组之间有着密切的关系。]
//指针和数组是密切相关的。事实上指针和数组在很多情况下是可以互换的。例如，一个指向数组开头的指针，可以通过使用指针的算术运算或数组索引来访问数组,数组名对应一个指针常量，只要不改变数组的值，仍然可以用指针形式的表达式.

    //C++ 指向指针的指针 [C++ 允许指向指针的指针。]
    int n;
    int **pp;

    n = 3000;
    p = &n;
    pp = &p;
    cout << "Value of var: " << n << endl;
    cout << "Value avaliable at *p: "<< *p << endl;
    cout << "Value avaliable at **pp: "<< **pp << endl;

    //C++ 传递指针给函数 [通过引用或地址传递参数，使传递的参数在调用函数中被改变。]
    int balance[5] = {1000, 2, 3, 17, 50};
    double avg;

    avg = getAverage(balance, 5);

    cout<< "Average value is: " << avg << endl;


    //C++ 从函数返回指针 [ C++ 允许函数返回指针到局部变量、静态变量和动态内存分配。]
    //C++ 不支持在函数外返回局部变量的地址，除非定义局部变量为 static 变量。
    
    int *t;
    t = getRandom();

    for(int i=0; i<10; i++)
    {
        cout << "*(p + " << i << ") : ";
        cout << *(t + i) << endl;
    }
    return 0;    
}

double getAverage(int *arr, int size)
{
    int i, sum=0;
    double avg;

    for(int i=0; i<size; i++)
    {
        sum += arr[i];
    }

    avg = double(sum) / size;
    return avg;
}


