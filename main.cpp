
#include <iostream>
#include "Classes/books.h"
#include "Classes/libraries.h"
#include <windows.h>
#include <conio.h>
using namespace std;

int main() {
    int x;
    libraries lib;
    allBooks all;
    while(true){
        system("cls");
        cout<<"Enter one of the below numbers:"<<endl;
        cout<<"1. Add Library"<<endl;
        cout<<"2. Add book to library"<<endl;
        cout<<"3. Add book"<<endl;
        cout<<"4. lend Book"<<endl;
        cout<<"5. Show books based on subject"<<endl;
        cout<<"6. Delete library"<<endl;
        cout<<"7. Show all books of library"<<endl;
        cout<<"8. Delete book"<<endl;
        cout<<"9. Find book"<<endl;
        cout<<"10. Exit"<<endl;
        cin>>x;
        if(x==10){
            return 0;
        }
        else if(x==1){
            cout<<"Enter library name"<<endl;
            string name;
            cin>>name;
            cout<<"Enter library Address (ten character at most)"<<endl;
            string address;
            cin>>address;
            lib.addLibrary(address,me);
        }
        else if(x==2){
            cout<<"Enter library address"<<endl;
            string address;
            cin>>address;
            cout<<"Enter Shabak code"<<endl;
            string shabak;
            cin>>shabak;
            cout<<"Enter book name"<<endl;
            string name;
            cin>>name;
            library * li=lib.findLibary(address);
            if(li==nullptr){
                cout<<"There is no library with this address";
                Sleep(2000);
                continue;
            }
            books* book=all.findBook(shabak);
            if(book== nullptr){
                cout<<"Sorry you should first Add book then add it to library";
                Sleep(2000);
                continue;
            }
            lib.addBookTolib(address,shabak);
        }
        else if(x==3){
            cout<<"Enter book Name(18 character at most): ";
            string bookname;
            cin>>bookname;
            cout<<"Enter shabak code(10 character at most):  ";
            string shabak;
            cin>>shabak;
            cout<<"Enter writer name:  ";
            string writer;
            cin>>writer;
            cout<<"Select one of the below subjects:"<<endl;
            cout<<"1. Romance"<<endl;
            cout<<"2. Comedy"<<endl;
            cout<<"3. Drama"<<endl;
            cout<<"4. SciFi"<<endl;
            cout<<"5. Horror"<<endl;
            cout<<"6. Poetry"<<endl;
            int y;
            cin>>y;
            y--;
            all.addBook(shabak,bookname,writer,bookSubjects(y));
        }
        else if(x==4){
            cout<<"Enter library address"<<endl;
            string address;
            cin>>address;
            cout<<"Enter Shabak code"<<endl;
            string shabak;
            cin>>shabak;
            lib.changeLendMode(address,shabak);
        }
        else if(x==5){
            cout<<"Enter library address"<<endl;
            string address;
            cin>>address;
            cout<<"Select one of the below subjects:"<<endl;
            cout<<"1. Romance"<<endl;
            cout<<"2. Comedy"<<endl;
            cout<<"3. Drama"<<endl;
            cout<<"4. SciFi"<<endl;
            cout<<"5. Horror"<<endl;
            cout<<"6. Poetry"<<endl;
            int y;
            cin>>y;
            y--;
            lib.showAllBooksBesedOnSubject(address,all,bookSubjects(y));
        }
        else if(x==6){
            cout<<"Enter library address"<<endl;
            string address;
            cin>>address;
            lib.deleteLibrary(address);
        }
        else if(x==7){
            cout<<"Enter library address"<<endl;
            string address;
            cin>>address;
            lib.showAllBooks(address, all);
        }
        else if(x==8){
            cout<<"Enter book shabak code to delete"<<endl;
            string shabak;
            cin>>shabak;
            all.removeBook(shabak);
        }
        else if(x==9){
            cout<<"Enter library address"<<endl;
            string address;
            cin>>address;
            cout<<"Enter Shabak code"<<endl;
            string shabak;
            cin>>shabak;
            library* temp=lib.findLibary(address);
            if(temp== nullptr){
                cout<<"There is no library with this address";
                Sleep(2000);
                continue;
            }
            if(temp->doesBookExist(shabak)){
                books * b=all.findBook(shabak);
                cout<<"Name  |  Writer  |  Shabak Code  |  Subject"<<endl;
                cout<<b->bookName<<"  |  "<<b->writer<<"  |  "<<b->shabak<<"  |  ";
                if(b->bookSubject==Romance){
                    cout<<"Romance";
                }
                else if(b->bookSubject==Comedy){
                    cout<<"Comedy";
                }
                else if(b->bookSubject==Drama){
                    cout<<"Drama";
                }
                else if(b->bookSubject==SciFi){
                    cout<<"SciFi";
                }
                else if(b->bookSubject==Horror){
                    cout<<"Horror";
                }
                else if(b->bookSubject==Poetry){
                    cout<<"Poetry";
                }
                cout<<endl;
                cout<<"Press any key to continue";
                getch();
            }
            else{
                cout<<"This book dose not exist";
                Sleep(2000);
            }
        }
        else{
            continue;
        }
    }
}