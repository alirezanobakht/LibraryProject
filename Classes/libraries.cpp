//
// Created by Jarvis on 3/15/2019.
//
#include "libraries.h"
#include <iostream>
#include <fstream>
#include <vector>
#include <conio.h>
using namespace std;

vector<books> sortBooks(vector<books> vec,int x){
    if(x==1){
        for(int i=vec.size()-1;i>0;i--){
            for(int j=0;j<i;j++){
                if(vec[j].getBookName()>vec[j+1].getBookName()){
                    string temp=vec[j].getBookName();
                    vec[j].setBookName(vec[j+1].getBookName());
                    vec[j+1].setBookName(temp);
                }
            }
        }
    }
    else{
        for(int i=vec.size()-1;i>0;i--){
            for(int j=0;j<i;j++){
                if(vec[j].getBookWriter()>vec[j+1].getBookWriter()){
                    string temp=vec[j].getBookWriter();
                    vec[j].setBookWriter(vec[j+1].getBookWriter());
                    vec[j+1].setBookWriter(temp);
                }
            }
        }
    }
    return vec;
}

library::library(string libName, string libAddress) {
    this->libName=libName;
    this->libAddress=libAddress;
    this->headBook= nullptr;
    this->next= nullptr;
}

bool library::isBookLend(string shabak) {
    bookPair * temp=findBookPair(shabak);
    if(temp== nullptr){
        return true;
    }
    return temp->isLend;
}

bool library::doesBookExist(string shabak) {
    bookPair * temp=findBookPair(shabak);
    if(temp== nullptr){
        return false;
    }
    return true;
}

void library::addBook(string shabak) {
    if(headBook== nullptr){
        headBook=new bookPair;
        headBook->shabak=shabak;
        headBook->isLend=false;
        headBook->next= nullptr;
    }
    else if(doesBookExist(shabak)==true){
        return;
    }
    else{
        bookPair * temp=headBook;
        while(temp->next!= nullptr){
            temp=temp->next;
        }
        bookPair * temp2=new bookPair;
        temp2->shabak=shabak;
        temp2->isLend=false;
        temp2->next= nullptr;
        temp->next=temp2;
    }
}

void library::addBook(bookPair book) {
    if(headBook== nullptr){
        headBook=new bookPair;
        headBook->shabak=book.shabak;
        headBook->isLend=book.isLend;
        headBook->next= nullptr;
    }
    else if(doesBookExist(book.shabak)==true){
        return;
    }
    else{
        bookPair * temp=headBook;
        while(temp->next!= nullptr){
            temp=temp->next;
        }
        bookPair * temp2=new bookPair;
        temp2->shabak=book.shabak;
        temp2->isLend=book.isLend;
        temp2->next= nullptr;
        temp->next=temp2;
    }
}

void library::lendBook(string shabak) {
    bookPair * temp=findBookPair(shabak);
    if(temp!=nullptr)
        temp->isLend=true;
}

void library::returnBookToLib(string shabak) {
    bookPair * temp=findBookPair(shabak);
    if(temp!= nullptr){
        temp->isLend=false;
    }
}

void library::deleteBook(string shabak) {
    if(headBook->shabak==shabak){
        bookPair * temp=headBook;
        headBook=headBook->next;
        delete temp;
        return;
    }
    else{
        bookPair * temp=headBook;
        while(temp->next!= nullptr && temp->next->shabak!=shabak){
            temp=temp->next;
        }
        if(temp->next==nullptr){
            return;
        }
        bookPair * temp2=temp->next;
        bookPair * temp3=temp2->next;
        delete temp2;
        temp->next=temp3;
    }
}

bookPair *library::findBookPair(string shabak) {
    bookPair * temp=headBook;
    while(temp!= nullptr){
        if(temp->shabak==shabak){
            return temp;
        }
        temp=temp->next;
    }
    return nullptr;
}

string library::getLibAddress() {
    return libAddress;
}

string library::getLibName() {
    return libName;
}

library *library::getNext() {
    return next;
}

void library::setNext(library *ptr) {
    next=ptr;
}

int library::getBookCount() {
    bookPair* temp=headBook;
    int x=0;
    while(temp!=nullptr){
        temp=temp->next;
        x++;
    }
    return x;
}

library::library() {
    next= nullptr;
    headBook= nullptr;
}

library::~library() {

}


//Libraries method
libraries::libraries() {
    headlibs= nullptr;
    ifstream input;
    input.open("Libraries.txt");
    if(input.is_open()){
        while(!input.eof()){
            library lib;
            lib.next= nullptr;
            input>>lib.libName;

            if(lib.libName=="")
                break;

            input>>lib.libAddress;
            int x=0;
            input>>x;
            for(int i=0;i<x;i++){
                bookPair book;
                input>>book.shabak;
                input>>book.isLend;
                lib.addBook(book);
            }
            addLibrary(lib);
        }
    }
    input.close();
}

void libraries::addLibrary(string libAddress, string libName) {

    library * fake=findLibary(libAddress);
    if(fake!=nullptr)
        return;

    if(headlibs==nullptr){
        headlibs=new library;
        headlibs->next=nullptr;
        headlibs->headBook=nullptr;
        headlibs->libAddress=libAddress;
        headlibs->libName=libName;
        return;
    }
    library * temp=headlibs;
    while(temp->next!=nullptr){
        temp=temp->next;
    }
    library * temp2=new library;
    temp2->next=nullptr;
    temp2->libName=libName;
    temp2->libAddress=libAddress;
    temp2->headBook=nullptr;
    temp->next=temp2;
}

void libraries::addLibrary(library lib) {

    library * fake=findLibary(lib.libAddress);
    if(fake!=nullptr)
        return;

    if(headlibs==nullptr){
        headlibs=new library;
        headlibs->next=nullptr;
        headlibs->headBook=lib.headBook;
        headlibs->libAddress=lib.libAddress;
        headlibs->libName=lib.libName;
        return;
    }
    library * temp=headlibs;
    while(temp->next!=nullptr){
        temp=temp->next;
    }
    library * temp2=new library;
    temp2->next=nullptr;
    temp2->libName=lib.libName;
    temp2->libAddress=lib.libAddress;
    temp2->headBook=lib.headBook;
    temp->next=temp2;

}

void libraries::deleteLibrary(string libAddress) {
    if(headlibs->libAddress==libAddress){
        library * temp=headlibs;
        headlibs=headlibs->next;
        delete temp;
        return;
    }
    else{
        library * temp=headlibs;
        while(temp->next!=nullptr && temp->next->libAddress==libAddress){
            temp=temp->next;
        }
        if(temp->next==nullptr){
            return;
        }
        library * temp2=temp->next;
        library * temp3=temp2->next;
        temp->next=temp3;
        delete temp2;
    }
}

library *libraries::findLibary(string libAddress) {
    library * temp=headlibs;
    while(temp!= nullptr){
        if(temp->getLibAddress()==libAddress){
            return temp;
        }
        temp=temp->next;
    }
    return nullptr;
}

libraries::~libraries() {
    library * temp=headlibs;
    ofstream output;
    output.open("Libraries.txt");
    while(temp!=nullptr){
        output<<temp->libName<<" "<<temp->libAddress<<" "<<temp->getBookCount()<<" ";
        bookPair * tempbook=temp->headBook;
        while(tempbook!=nullptr){
            output<<tempbook->shabak<<" "<<tempbook->isLend<<" ";
            tempbook=tempbook->next;
        }
        temp=temp->next;
    }
    output.close();
}

void libraries::addBookTolib(string libAddress, string shabak) {
    library * lib=findLibary(libAddress);
    lib->addBook(shabak);
}

void libraries::changeLendMode(string libAddress, string shabak) {
    library * temp=findLibary(libAddress);
    if(temp== nullptr)
        return;
    if(temp->isBookLend(shabak)){
        temp->returnBookToLib(shabak);
    }
    else{
        temp->lendBook(shabak);
    }
}

void libraries::showAllBooks(string libAddress, allBooks &all) {
    library * lbrr=findLibary(libAddress);
    if(lbrr==nullptr){
        cout<<"There is no library with this Address";
        return;
    }
    vector<books> vec;
    bookPair * bp=lbrr->headBook;
    while(bp!=nullptr){
        books * bptr=all.findBook(bp->shabak);
        books book=*bptr;
        vec.push_back(book);
        bp=bp->next;
    }
    vec=sortBooks(vec,1);
    cout<<"Name  |  Writer  |  Shabak Code  |  Subject"<<endl;
    for(int i=0;i<vec.size();i++){
        cout<<vec[i].bookName<<"  |  "<<vec[i].writer<<"  |  "<<vec[i].shabak<<"  |  ";
        if(vec[i].bookSubject==Romance){
            cout<<"Romance";
        }
        else if(vec[i].bookSubject==Comedy){
            cout<<"Comedy";
        }
        else if(vec[i].bookSubject==Drama){
            cout<<"Drama";
        }
        else if(vec[i].bookSubject==SciFi){
            cout<<"SciFi";
        }
        else if(vec[i].bookSubject==Horror){
            cout<<"Horror";
        }
        else if(vec[i].bookSubject==Poetry){
            cout<<"Poetry";
        }
        cout<<endl;
    }
    cout<<"Press any key to continue";
    getch();
}

void libraries::showAllBooksBesedOnSubject(string libAddress, allBooks &all, bookSubjects sub) {
    library * lbrr=findLibary(libAddress);
    if(lbrr==nullptr){
        cout<<"There is no library with this Address";
        return;
    }
    vector<books> vectemp;
    bookPair * bp=lbrr->headBook;
    while(bp!=nullptr){
        books * bptr=all.findBook(bp->shabak);
        books book=*bptr;
        vectemp.push_back(book);
        bp=bp->next;
    }
    vectemp=sortBooks(vectemp,2);
    vector<books> vec;
    for(int i=0;i<vectemp.size();i++){
        if(vectemp[i].bookSubject==sub){
            vec.push_back(vectemp[i]);
        }
    }
    cout<<"Name  |  Writer  |  Shabak Code  |  Subject"<<endl;
    for(int i=0;i<vec.size();i++){
        cout<<vec[i].bookName<<"  |  "<<vec[i].writer<<"  |  "<<vec[i].shabak<<"  |  ";
        if(vec[i].bookSubject==Romance){
            cout<<"Romance";
        }
        else if(vec[i].bookSubject==Comedy){
            cout<<"Comedy";
        }
        else if(vec[i].bookSubject==Drama){
            cout<<"Drama";
        }
        else if(vec[i].bookSubject==SciFi){
            cout<<"SciFi";
        }
        else if(vec[i].bookSubject==Horror){
            cout<<"Horror";
        }
        else if(vec[i].bookSubject==Poetry){
            cout<<"Poetry";
        }
        cout<<endl;
    }
    cout<<"Press any key to continue";
    getch();

}



