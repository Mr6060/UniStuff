#include <iostream>
#include <cstring>
using namespace std;

class MyClass{
public:
    //elements
    string title;
    string obj;

    //constructors
    MyClass(){
        title = "Nada";
        obj = "NO";
    }

    MyClass(string aTitle, string aObj){
        title = aTitle;
        obj = aObj;
    }
    //destructors
};

int main(){
    int n;
    cout << "Hello world" << endl;
    cout << "suck my dick btw" << endl;
    do{
        cout << "Inserire un numero: ";
        cin >> n;
    } while (n < 0);

    if (n % 2 == 0){
        cout << "Pari" << endl;
    }
    else{
        cout << "Dispari" << endl;
    }

    MyClass test;
    cout << test.title << endl;
    MyClass test1("Test", "Altro test");
    cout << test1.title << '\t' << test1.obj << endl;
    cout << test1.title << endl;
    return 0;
}