#include <iostream>
using namespace std;

class Base{
    public:
        virtual ~Base(){
            cout << "Base -1" << endl;
        }
};

class Intr : public Base {
    public:
        virtual ~Intr(){
            cout << "Intr -1" << endl;
        }
};

class Derived : public Intr{
    public:
        virtual ~Derived(){
            cout << "Derived -1" << endl;
        }
};

int main(){
    Base* pb = new Intr;
    Base* pi = new Derived;
    delete pb;
    delete pi;
}

