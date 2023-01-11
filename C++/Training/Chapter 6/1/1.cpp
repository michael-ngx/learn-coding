// 1. Write a program to generate personalized junk mail. The program takes input both from an input file and from the keyboard. The input file contains the text of a letter, except that the name of the recipient is indicated by the three characters #N#. The program asks the user for a name and then writes the letter to a second file but with the three letters #N# replaced by the name. The three-letter string #N# will occur exactly once in the letter.

#include <iostream>
#include <fstream>
using namespace std;

void askName (ofstream& fout);

int main(){
    ifstream fin;
    ofstream fout;
    
    fin.open("infile.dat");
    if (fin.fail()){
        cout << "Input file failed to open";
        exit(1);
    }
    fout.open("outfile.dat");
    if (fout.fail()){
        cout << "Output file failed to open";
        exit(1);
    }

    char c;
    fin.get(c);
    while (!fin.eof()){
        char c1, c2;
        if (c == '#' && fin >> c1){
            if (c1 == 'N' && fin >> c2){
                if (c2 == '#'){
                    askName(fout);
                }
                else fout << c << c1 << c2;
            }
            else fout << c << c1;
        }
        else fout << c;

        fin.get(c);
    }
    fin.close();
    fout.close();
    return 0;
}

void askName (ofstream& fout){
    cout << "Enter your name: ";
    char character;
    do{
        cin.get(character);
        fout.put(character);
    } while (character != '\n');
}
