#include <iostream>
#include <fstream>
using namespace std;

int main(){
    int a;
    ifstream inFile ("text.txt");
    while (1){
        inFile >> a;
        if (inFile.fail()){
            cout << "failed.." << endl;
            string b;
            inFile >> b;
            cout << "First " << b << endl;
            inFile.clear();
            inFile >> b;
            cout << "Second " << b << endl;
            inFile.ignore(100, '\n');
            break;
        }
        // break;
    }
}
