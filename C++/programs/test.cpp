#include <iostream>
#include <fstream>
using namespace std;

void replaceC (ifstream& inStream, ofstream& outStream);

int main(){
    ifstream fin;
    ofstream fout;
    cout << "Begin editing files.\n";

    fin.open("cad.dat");
    if (fin.fail()){
        cout << "Input file opening failed.\n";
        exit(1);
    }
    fout.open("cplusad.dat");
    if (fout.fail()){
        cout << "Output file opening failed.\n";
        exit(1);
    }

    replaceC (fin, fout);

    fin.close();
    fout.close();

    cout << "End of editing files.\n";
    return 0;
}

void replaceC (ifstream& inStream, ofstream& outStream){
    char c;
    inStream.get(c);
    while (!inStream.eof()){
        if (c == 'C')   outStream << "C++";
        else            outStream.put(c);
        inStream.get(c);
    }
}
