// Our palindrome test will disregard all spaces and punctuations
// and will consider upper- and lowercase versions of a letter to be the same when deciding if something is a palindrome

#include <iostream>
#include <string>
#include <cctype>
using namespace std;

bool checkPalindrome(string input);
void newLine();

/* Note the use of the newLine() function, to solve the issue of REMAINING INPUT '\N' */

// int main(){
//     string cont = "yes";
//     do{
//         string input;
//         cout << "Enter any string to check for palindrome: ";
//         getline (cin, input);
//         if (checkPalindrome(input)) cout << "It is a palindrome!" << endl;
//         else cout << "Nonono" << endl;
//         cout << "Continue? (y/n): ";
//         getline (cin, cont);
//     }while (cont != "n" || cont != "no");
// }

int main(){
    char cont;
    do{
        string input;
        cout << "Enter any string to check for palindrome: ";
        getline (cin, input);
        if (checkPalindrome(input)) cout << "It is a palindrome!" << endl;
        else cout << "Nonono" << endl;
        cout << "Continue? (y/n): ";
        cin >> cont;
        newLine();
    }while (cont != 'n');
}

bool checkPalindrome(string input){
    string newString;
    for (int i = 0; i < input.length(); i++){
        if (isalnum(input[i])) newString += input[i];
    }
    for (int j = 0; j < newString.length()/2; j++){
        if (newString[j] != newString[newString.length() - j - 1]) return false;
    }
    return true;
}

void newLine(){
    char c;
    do{
        cin.get(c);
    }while (c != '\n');
}