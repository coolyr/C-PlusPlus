/***************************************************
* Author: coolyr
* Mail: yunrong@pku.edu.cn
* Description:
***************************************************/


#include <iostream>
#include <cstring>
#include<string>
using namespace std;


int main(int argc, char** argv, char** envp){

    char greeting[6] = {'H', 'e', 'l', 'l', 'o'};
    char greetString[] = "Hello";

    cout << "Greeting message: ";
    cout << greeting << endl;
    cout << "greedString: " << greetString << endl;

    char str1[10] = "Hello";
    char str2[10] = "World";
    char str3[10];
    int len;

    string s1 = "Hello";
    string s2 = "world";
    string s3;
    int size;


    strcpy(str3, str1);
    cout << "strcpy(str3, str1) : " << str1 << endl;
    s3 = s1;
    cout << "s3 = s1 : " << s3 << endl<<endl;
    
    strcat(str1, str2);
    cout << "strcat(str1, str2) : " << str1 << endl;
    s3 = s1 + s2;
    cout << "s1 : " << s3 << endl << endl;

    len = strlen(str1);
    size = s3.size();
    cout << "strlen(str1) : " << len << endl;
    cout << "s3.size() : " << size << endl << endl;


    return 0;    
}

