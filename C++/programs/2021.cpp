#include <iostream>
using namespace std;

int main(){
    int* p = nullptr;
    int* q = nullptr;
    int* r = nullptr;
    int** t = &p;
    int** s = &q;
    r = p;
    p = new int;
    q = new int;
    *p = 5;
    *q = 2;
    **s = *p + **t;
    // This line should cout nothing
    cout << *r << endl;
}

class Base{
    public:
        int a = 0;
        Base& operator=(const Base& rhs){
            a = rhs.a;
            cout << "Here" << endl;
        }
};

class A : public Base{
};

class B : public Base{
};

int main(){
    A a;
    A b;
    a = b;
}


int func(int n){
    if (n == 0) return 0;
    int sum = 0;
    for (int j = 0; j < n; j++){
        sum++;
    }
    return func(n/2);
}
