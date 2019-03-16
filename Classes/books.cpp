//
// Created by Ahmadreza on 3/16/2019.
//

#include "books.h"
#include <iostream>
#include <stdio.h>
#include <fstream>

using namespace std;

void allBooks::addBook(string shabak, string bookName, string writer, bookSubjects bookSubject) {
    if (headBook == nullptr){
        auto *temp = new books;
        temp->shabak = shabak;
        temp->bookName = bookName;
        temp->writer = writer;
        temp->bookSubject = bookSubject;
        temp->next = nullptr;
        headBook = temp;
        return;
    }
    books * temp = headBook;
    while(temp->next != nullptr && temp->next->bookName != ""){
        temp = temp->next;
    }
    auto * newTemp = new books;
    newTemp->shabak = shabak;
    newTemp->bookSubject = bookSubject;
    newTemp->bookName = bookName;
    newTemp->writer = writer;
    newTemp->next = nullptr;
    temp->next = newTemp;
}



string books::getBookName() {
    return bookName;
}

void books::setBookName(string name) {
    bookName=name;
}

string books::getBookWriter() {
    return writer;
}

void books::setBookWriter(string writer) {
    this->writer=writer;
}

allBooks::allBooks() {

    ifstream inFile;
    inFile.open("books.txt");
    if (inFile.is_open()){
        while (!inFile.eof()){
            string codeshabak;
            string bookName;
            string writer;
            bookSubjects bookSubject = Romance;
            int subject;
            inFile >> codeshabak;
            if(codeshabak==""){
                break;
            }
            inFile >> bookName >> subject >> writer;
            bookSubject = bookSubjects(subject);
            addBook(codeshabak, bookName, writer, bookSubject);
        }
    }
    inFile.close();
}

allBooks::~allBooks(){
    books * temp = headBook;
    ofstream outFile;
    outFile.open("books.txt");
    while (temp != nullptr){
        if (temp->bookName == "")
            break;
        outFile << temp->shabak << " " << temp->bookName << " " << temp->bookSubject << " " << temp->writer << endl;
        temp = temp->next;
    }
    outFile.close();
}


books* allBooks::findBook(string shabak) {
    books * temp = headBook;
    while (temp != nullptr){
        if (temp->shabak == shabak){
            return temp;
        }
        temp = temp->next;
    }
    return nullptr;
}

void allBooks::removeBook(string shabak) {
    books* temp = headBook;
    books* backtemp = nullptr;
    if (temp->shabak == shabak) {
        headBook = temp->next;
        return;
    }
    while (temp != nullptr){
        if (temp->shabak == shabak){
            backtemp->next = temp->next;
            temp->next = nullptr;
            delete(temp);
            return;
        }
        backtemp = temp;
        temp = temp->next;
    }
}

