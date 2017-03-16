/***************************************************
* Author: coolyr
* Mail: yunrong@pku.edu.cn
* Description:
***************************************************/

//两种类型的多任务处理 : 基于进程和基于线程。
//<1> 基于 [进程] 的多任务处理是 [程序] 的并发执行。
//<2> 基于 [线程] 的多任务处理是同一程序的 [片段] 的并发执行。

//多线程程序包含可以同时运行的两个或多个部分。
//这样的程序中的每个部分称为一个线程，每个线程定义了一个单独的执行路径。
//C++ 不包含多线程应用程序的任何内置支持。相反，它完全依赖于操作系统来提供此功能。
//我们要使用 POSIX 编写多线程 C++ 程序。POSIX Threads 或 Pthreads 提供的 API 可在多种类 Unix POSIX 系统上可用，比如 FreeBSD、NetBSD、GNU/Linux、Mac OS X 和 Solaris。
//
//<POSIX>POSIX表示可移植操作系统接口（Portable Operating System Interface ，缩写为 POSIX ），POSIX标准定义了操作系统应该为应用程序提供的接口标准，是IEEE为要在各种UNIX操作系统上运行的软件而定义的一系列API标准的总称，其正式称呼为IEEE 1003，而国际标准名称为ISO/IEC 9945。
//
//


#include <iostream>
#include <pthread.h>
using namespace std;

#define NUM_THREADS 5

//线程运行函数
void* say_Hello(void* args)
{
    cout << "Hello Runoob! " << endl;
    //pthread_exit(NULL);
}


int main(int argc, char** argv, char** envp){

    //定义线程的 id 变量，多个变量使用数组
    pthread_t tids[NUM_THREADS];
    for(int i=0; i<NUM_THREADS; ++i)
    {
        //参数依次是：创建的线程id，线程参数，调用的函数，传入的函数参数
        int ret = pthread_create(&tids[i], NULL, say_Hello, NULL);
        if(ret != 0)
        {
            cout << "pthread_create error: error_code= " << ret << endl;
        }
    }
    //等各个线程退出后，进程才结束，否则进程强制结束了，线程可能还没反应过来；
    pthread_exit(NULL);
    //pthread_exit 用于显式地退出一个线程。通常情况下，pthread_exit() 函数是在线程完成工作后无需继续存在时被调用。
    //如果 main() 是在它所创建的线程之前结束，并通过 pthread_exit() 退出，那么其他线程将继续执行。
    //否则，它们将在 main() 结束时自动被终止。
    return 0;    
}

