//
// Created by Ahmadreza on 3/16/2019.
//

#ifndef LIBRARY_BOOKS_H
#define LIBRARY_BOOKS_H


#include <iostream>


using namespace std;

enum bookSubjects{Romance = 0, Comedy = 1, Drama = 2, SciFi = 3, Horror = 4, Poetry = 5};

class books {
private:
    string shabak;
    string bookName;
    string writer;
    enum bookSubjects bookSubject;
    books* next;
    friend class allBooks;
    friend class libraries;
public:
       friend int main();
       string getBookName();
       void setBookName(string name);
       string getBookWriter();
       void setBookWriter(string writer);


};

class allBooks{
private:
    books* headBook = nullptr;
public:
    allBooks();
    ~allBooks();
    void addBook(string, string, string, bookSubjects);
    books *findBook(string);
    void removeBook(string);
};


#endif //LIBRARY_BOOKS_H
