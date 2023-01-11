#include <iostream>
using namespace std;

class treenode {
    public:
        int data;
        treenode *left;
        treenode *right;
};

treenode *Root;

void oddevenorder (treenode *rt){
    cout << rt->data << endl;
    if (rt->data % 2 == 1){
        if (rt->left != nullptr) oddevenorder(rt->left);
        if (rt->right != nullptr) oddevenorder(rt->right);
    }
    else{
        if (rt->right != nullptr) oddevenorder(rt->right);
        if (rt->left != nullptr) oddevenorder(rt->left);
    }
}