#include <iostream>
using namespace std;

// class Complex{
//     private:
//         int real;
//         int imaginary;
//     public:
//         Complex (){
//             real = 0;
//             imaginary = 0;
//         }
//         Complex (int r, int img){
//             real = r;
//             imaginary = img;
//         }
//         Complex (Complex& r){
//             real = r.real;
//             imaginary = r.imaginary;
//         }
//         Complex operator+ (Complex& r){
//             return Complex((real + r.real), (imaginary + r.imaginary));
//         }
//         Complex& operator= (const Complex& r){              // const here is mandatory
//             real = r.real;      
//             imaginary = r.imaginary;
//             return *this;
//         }
//         void print(){
//             cout << real << imaginary << endl;
//         }
// };

// int fib(int n){
//     if (n == 0) return 0;
//     if (n == 1) return 1;
//     return (fib(n-1) + fib(n-2));
// }

// class TreeNode{
//     private:
//         int value;
//         TreeNode* left;
//         TreeNode* right;
//     public:
//         TreeNode();
//         ~TreeNode();
// };

// class Tree{
//     private:
//         TreeNode* root;
//     public:
//         Tree();
//         ~Tree();
// };

// TreeNode::~TreeNode(){
// 	if (left != nullptr) delete left;
//     if (right != nullptr) delete right;
//     // delete this; // We don't need delete this, because this is already 
//                     //called by something else
// }

// Tree::~Tree(){
//     if (root != nullptr) delete root;
// }

class Parent{
    private:
        string name;
    protected:
        int age;
        void die(){ age = 0; }
        string getName(){ return name; }
    public:
        Parent(){ name="can't change me"; age = 14; }
};

class Children : public Parent{
    public:
        Children() : Parent(){/* Called parent constructor */} 
        void print(){cout << age << getName() << endl;} // 14can't change me
};

int main(){
    Children bruh;
    // bruh.die();
    bruh.print();
}

// Complex a;
// Complex b(3,4);
// Complex c;
// c = a + b;

// c.print();

// return 0;
// cout << fib(10) << endl;