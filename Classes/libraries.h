//
// Created by Jarvis on 3/15/2019.
//

#ifndef LIBRARY_LIBRARIES_H
#define LIBRARY_LIBRARIES_H

#include <iostream>
#include "books.h"

using namespace std;


typedef struct Pair{
    string shabak;
    bool isLend;
    struct Pair * next;
}bookPair;

class library{
private:
    string libName;
    string libAddress;
    bookPair * headBook;
    library * next;
    friend class libraries;
public:
    library();
    ~library();
    library(string libName,string libAddress);
    bool isBookLend(string shabak);
    bool doesBookExist(string shabak);
    void addBook(string shabak);
    void addBook(bookPair book);
    void lendBook(string shabak);
    void returnBookToLib(string shabak);
    void deleteBook(string shabak);
    bookPair * findBookPair(string shabak);
    int getBookCount();

    string getLibName();
    string getLibAddress();
    library * getNext();

    void setNext(library * ptr);

};


class libraries {
private:
    library * headlibs;
public:
    libraries();
    void addLibrary(string libAddress,string libName);
    void addLibrary(library lib);
    void deleteLibrary(string libAddress);
    library * findLibary(string libAddress);
    ~libraries();

    void addBookTolib(string libAddress,string shabak);
    void changeLendMode(string libAddress,string shabak);
    void showAllBooks(string libAddress, allBooks &all);
    void showAllBooksBesedOnSubject(string libAddress,allBooks &all,bookSubjects sub);
};


#endif //LIBRARY_LIBRARIES_H
