#include <iostream>
#include <cstring>
using namespace std;

class MyClass
{
public:
    string title;
    string obj;

    MyClass()
    {
        title = "Nada";
        obj = "NO";
    }

    MyClass(string aTitle, string aObj)
    {
        title = aTitle;
        obj = aObj;
    }
};

int main()
{
    int n;
    cout << "Hello world" << endl;
    cout << "suck my dick btw" << endl;
    do
    {
        cout << "Inserire un numero: ";
        cin >> n;
    } while (n < 0);

    if (n % 2 == 0)
    {
        cout << "Pari" << endl;
    }
    else
    {
        cout << "Dispari" << endl;
    }

    MyClass test;
    cout << test.title << endl;
    MyClass test1("Test", "Altro test");
    cout << test1.title << '\t' << test1.obj << endl;
    return 0;
}