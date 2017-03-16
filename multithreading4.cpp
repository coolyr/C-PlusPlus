/***************************************************
* Author: coolyr
* Mail: yunrong@pku.edu.cn
* Description:
***************************************************/

//   pthread_create (thread, attr, start_routine, arg) 
//   pthread_exit (status) 
//连接和分离线程
//
//我们可以使用以下两个函数来连接或分离线程：
//pthread_join (threadid, status) 
//pthread_detach (threadid) 
//
//pthread_join() 子程序阻碍调用程序，直到指定的 threadid 线程终止为止。
//当创建一个线程时，它的某个属性会定义它是否是可连接的（joinable）或可分离的（detached）。
//只有创建时定义为可连接的线程才可以被连接。如果线程创建时被定义为可分离的，则它永远也不能被连接。
//使用 pthread_join() 函数来等待线程的完成。

#include <iostream>
#include <cstdlib>
#include <pthread.h>
#include <unistd.h>

using namespace std;
#define NUM_THREADS 5

void *wait(void *t)
{
    long tid;

    tid = (long)t;

    sleep(1);
    cout << "Sleeping in thread" << endl;
    cout << "Thread with id: " << tid << " ...eixting " << endl;
    pthread_exit(NULL);
}

int main(int argc, char** argv, char** envp){
    int rc;
    int i;
    pthread_t threads[NUM_THREADS];//生成线程的id
    pthread_attr_t attr;
    void * status;

    //初始化并设置线程为可连接的（joinable）
    pthread_attr_init(&attr);
    pthread_attr_setdetachstate(&attr, PTHREAD_CREATE_JOINABLE);

    for(i=0; i<NUM_THREADS; ++i)
    {
        cout << "main() : creating thread, " << i << endl;
        //rc = pthread_create(&threads[i], NULL, wait, (void*) i); //看不明白！！待查
        rc = pthread_create(&threads[i], &attr, wait, (void*) i);
        if(rc)
        {
            cout << "Error: unable to create thread, " << rc << endl;
            exit(-1);
        }
    }
    
    //删除属性，并等待其他线程
    pthread_attr_destroy(&attr);
    for(i=0; i<NUM_THREADS; i++)
    {
        rc = pthread_join(threads[i], &status);
        if(rc)
        {
            cout << "Error:unable to join, " << rc << endl;
            exit(-1);
        }
        cout << "Main: complete thread id : " << i;
        cout << "exiting with status :" << status << endl;
    }
    cout << "Main: program exiting." << endl;
    pthread_exit(NULL);

    return 0;    
}


