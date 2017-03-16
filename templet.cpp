/***************************************************
* Author: coolyr
* Mail: yunrong@pku.edu.cn
* Description:
***************************************************/

//模板是泛型编程的基础，泛型编程即以一种独立于任何特定类型的方式编写代码。
//模板是创建泛型类或函数的蓝图或公式。
//库容器，比如迭代器和算法，都是泛型编程的例子，它们都使用了模板的概念。
//每个容器都有一个单一的定义，比如 向量，我们可以定义许多不同类型的向量，
//比如 vector <int> 或 vector <string>。
//
//
#include <iostream>
#include <vector>
#include <cstdlib>
#include <string>
#include<stdexcept>
using namespace std;

//函数模板
template <typename T>
inline T const& Max(T const& a, T const& b)
{
    return a < b ? b : a;
}

//类模板
template <class T>
class Stack
{
    private:
        vector<T> elems;  //元素

    public:
        void push(T const&); 
        void pop();
        T top() const;
        bool empty() const
        {
            return elems.empty();
        }
};


template <class T>
void Stack<T>::push(T const& elem)
{
    //追加传入元素的副本
    elems.push_back(elem);
}

template <class T>
void Stack<T>::pop()
{
    if(elems.empty())
    {
        throw out_of_range("Stack<>::pop: empty stack");
    }
    // 删除最后一个元素
    elems.pop_back();
}

template <class T>
T Stack<T>::top() const
{
    if(elems.empty())
    {
        throw out_of_range("Stack<>::top: empty stack");
    }
    //返回最后一个元素的副本
    return elems.back();
}

int main(int argc, char** argv, char** envp){
    int i = 39;
    int j = 20;
    cout << "Max(i, j): " << Max(i, j) << endl;

    double f1 = 13.5;
    double f2 = 20.7;
    cout << "Max(f1, f2): " << Max(f1, f2) << endl;

    string s1 = "Hello";
    string s2 = "World";
    cout << "Max(s1, s2): " << Max(s1, s2) << endl;

    cout << "类模板：" << endl;
    try
    {
        Stack<int> intStack; //int 类型的栈
        Stack<string> stringStack; //string 类型的栈 
        //操作 int 类型的栈 
        intStack.push(7);
        cout << intStack.top() << endl;

        //操作 int 类型的栈 
        stringStack.push("Hello");
        cout << stringStack.top() << std::endl;
        stringStack.pop();
        stringStack.pop();
    }
    catch (exception const& ex)
    {
        cerr << "Exception const& ex -> " << ex.what() << endl;
    }
    return 0;    
}

