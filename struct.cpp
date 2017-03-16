/***************************************************
* Author: coolyr
* Mail: yunrong@pku.edu.cn
* Description:
***************************************************/


#include <iostream>
#include <cstring>

using namespace std;
void printBook(struct Book book);
void printBook(struct Book *book);


struct Book
{
    char title[50];
    char author[50];
    char subject[100];
    int book_id;
};

typedef struct
{
    char title[50];
    char author[50];
    char subject[100];
    int book_id;
} Books;

int main(int argc, char** argv, char** envp){
    struct Book book1;  // 声明 Book1，类型为 Book
    struct Book book2;
    
    //book1
    strcpy(book1.title, "Learn C++ Programming");
    strcpy(book1.author, "Chand Miyan");
    strcpy(book1.subject, "C++ Programming");
    
    //book2
    strcpy( book2.title, "Telecom Billing");
    strcpy( book2.author, "Yakit Singha");
    strcpy( book2.subject, "Telecom");
    book2.book_id = 6495700;

    cout << "Book 1 titile: " <<  book1.title << endl;
    cout << "Book 1 author: " << book1.author << endl;
    cout << "Book 1 subject: " << book1.subject << endl;
    cout << "Book 1 id: " << book1.book_id << endl;

    cout << "Book 2 titile: " <<  book2.title << endl;
    cout << "Book 2 author: " << book2.author << endl;
    cout << "Book 2 subject: " << book2.subject << endl;
    cout << "Book 2 id: " << book2.book_id << endl;

    cout << "############" << endl;
    printBook(book1);

    cout << "############" << endl;
    printBook(&book2);

    Books Book1;
    //Book1.title = "hello World!";
    strcpy(Book1.title, "Hello world!");
    cout << " typedef Books: " << Book1.title << endl;
    



    return 0;    
}

void printBook(struct Book book)
{
    cout << "Book title: " << book.title << endl;
    cout << "book author: " << book.author << endl;
    cout << "Book subject: " << book.subject << endl;
    cout << "Book id: " << book.book_id << endl;
}

void printBook(struct Book *book)
{
    cout << "Book title: " << book->title << endl;
    cout << "Book author: " << book->author << endl;
    cout << "Book subject: " << book->subject << endl;
    cout << "Book id: " << book->book_id << endl;
}



