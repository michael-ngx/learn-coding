// 2. Write a program to compute numeric grades for a course. The course records are in a file that will serve as the input file. The input file is in exactly the following format: Each line contains a student’s last name, then one space, then the student’s first name, then one space, then ten quiz scores all on one line. The quiz scores are whole numbers and are separated by one space. Your program will take its input from this file and send its output to a second file. The data in the output file will be the same as the data in the input file except that there will be one additional number (of type double) at the end of each line. This number will be the average of the student’s ten quiz scores. If this is being done as a class assignment, obtain the file names from your instructor. Use at least one function that has file streams as all or some of its arguments.
// Last_name First_name space score score score...

#include <iostream>
#include <fstream>
#include <cctype>
using namespace std;

void calculateAverage(ifstream& fin, ofstream& fout);

int main(){
    ifstream fin;
    ofstream fout;
    
    fin.open("scores.dat");
    if (fin.fail()){
        cout << "Input file failed to open";
        exit(1);
    }
    fout.open("average.dat");
    if (fout.fail()){
        cout << "Output file failed to open";
        exit(1);
    }

    calculateAverage(fin, fout);

    fin.close();
    fout.close();
    return 0;
}

void calculateAverage(ifstream& fin, ofstream& fout){
    int sum = 0;
    char next;              // How do we differentiate numbers and char input? Overload function for types int and char?
    int n;
    while (fin >> next){
        if (next == '\n'){
            fout << sum/10;
            sum = 0;
        }
        else{
            if (!isalpha(next)) sum += next;
        }
        fout << next;
    }
}