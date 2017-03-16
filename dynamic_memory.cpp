/***************************************************
* Author: coolyr
* Mail: yunrong@pku.edu.cn
* Description:
***************************************************/

//栈：在函数内部声明的所有变量都将占用栈内存。
//堆：这是程序中未使用的内存，在程序运行时可用于动态分配内存。
//
//下面是使用 new 运算符来为任意的数据类型动态分配内存的通用语法：
//new data-type;
//在这里，data-type 可以是包括数组在内的任意内置的数据类型，也可以是包括类或结构在内的用户自定义的任何数据类型。让我们先来看下内置的数据类型。例如，我们可以定义一个指向 double 类型的指针，然后请求内存，该内存在执行时被分配。
//
//如果自由存储区已被用完，可能无法成功分配内存。所以建议检查 new 运算符是否返回 NULL 指针，并采取以下适当的操作：
//
//malloc() 函数在 C 语言中就出现了，在 C++ 中仍然存在，但建议尽量不要使用 malloc() 函数。new 与 malloc() 函数相比，其主要的优点是，new 不只是分配了内存，它还创建了对象。 [可以从最后对象的内存分配看出来：申请new Box[4]的时候，Box构造函数被执行了4次]
//
//在任何时候，当您觉得某个已经动态分配内存的变量不再需要使用时，您可以使用 delete 操作符释放它所占用的内存
//
//

#include <iostream>
using namespace std;

class Box
{
    public:
        Box()
        {
            cout << "调用构造函数！" << endl;
        }

        ~Box()
        {
            cout << "调析构函数！" << endl;
        }
};



int main(int argc, char** argv, char** envp){

    cout << "普通值的内存分配:" << endl;
    double *pValue = NULL;//初始化为 null 的指针
    pValue = new double;//为变量请求内存

    *pValue = 2949.33;//在分配的地址存储值
    cout << "Value of pValue: " << *pValue << endl;

    delete pValue;//释放内存

    cout << "一维数组的动态内存分配" << endl;
    //数组的动态内存分配
    //假设我们要为一个字符数组（一个有 20 个字符的字符串）分配内存，
    //我们可以使用上面实例中的语法来为数组动态地分配内存，如下所示：
    char* pvalue  = NULL;   // 初始化为 null 的指针
    pvalue  = new char[20]; // 为变量请求内存
    //要删除我们刚才创建的数组，语句如下：
    delete [] pvalue;        // 删除 pvalue 所指向的数组

    cout << "多维数组的动态内存分配" << endl;
    int ROW = 2;
    int COL = 3;

    double ** p = new double* [ROW]; // 为行分配内存

    //为列分配内存
    for(int i=0; i<ROW; i++)
    {
        p[i] = new double[COL];
    }

    for(int i=0; i<ROW; i++)
    {
        for(int j=0; j<COL; j++)
        {
            p[i][j] = i+j;
        }
    }

    for(int i=0; i<ROW; i++)
    {
        for(int j=0; j<COL; j++)
        {
            //cout << "P[" + i + "][" + j + "] = " << p[i][j] << endl;
            cout << p[i][j] << endl;
        }
    }

    //释放多维数组内存：
    for(int i=0; i<ROW; i++)
        delete[] p[i];

    delete[] p;

    cout << "对象的动态内存分配：" << endl;

    Box *myBoxArray = new Box[3];

    delete []myBoxArray; //Delete array


    return 0;    
}

