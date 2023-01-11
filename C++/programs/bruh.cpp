#include <iostream>
using namespace std;

void printReverse (int* array, int start, int end)
{
    cout << array[end];
    if (start == end) {return;}
    printReverse(array, start, end-1);
}
// int bruh[] = {1, 2, 3, 4};
// printReverse(bruh, 0, 3);


class Base{
    protected:
        int a;
        int b;
    public:
        Base(int _a, int _b){
            a = _a;
            b = _b;
            cout << "Base class constructor" << endl;
        }
        Base(){ cout << "Default" << endl;}
        virtual void attack(){ cout << "This is base class attack" << endl;}
};

class Child1 : public Base{
    public:
        Child1(int _a, int _b) : Base(_a, _b){
            cout << "Children class constructor" << endl;
        }
        void bruh(){
            cout << a << " " << b << endl;
        }
        // void attack(){ cout << "This is derived class attack" << endl;}
};

int main(){
    Child1 bruh(12,30);
    bruh.bruh();
    bruh.attack();
}


class Animal{
    virtual void makeSound() { cout << "Animalll" << endl;}
    virtual void walk() {}
    void sleep() {}
};

class Cow : public Animal{ void makeSound() { cout << "Moooo" << endl;}};
class Pig : public Animal{ 
    void makeSound() { cout << "Oink" << endl;}
    void walk() { cout << "Pig walking" << endl;}
};
class Donkey : public Animal{ void makeSound() { cout << "Hee Haw" << endl;}};

