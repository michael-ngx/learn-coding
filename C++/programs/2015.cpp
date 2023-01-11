#include <iostream>
using namespace std;

class B{
    public:
        void Foo() {cout << "Why don't you call me?" << endl;}
    public:
        void Boo() {Foo(); cout << "B::Boo()" << endl;}
        virtual void Hoo() {}
};

class D : public B{
    public:
        virtual void Foo() {cout << "D::Foo()" << endl;}
    public:
        void Boo() {Foo(); cout << "D::Boo()" << endl;}
        virtual void Hoo() = 0;
};

class E : public D{
    public:
        // void Foo() {cout << "E::Foo()" << endl;}
        void Boo() {cout << "E::Boo()" << endl;}
        void Hoo() {}
};
int main(){
    B bObj, *bPtr;
    E eObj, *ePtr;

    bPtr = &eObj;
    ePtr = &eObj;

    bPtr -> Boo();
    bPtr -> Hoo();

    eObj.Boo();
    eObj.Foo();
}
