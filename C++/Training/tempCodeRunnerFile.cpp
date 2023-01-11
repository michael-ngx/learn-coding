#include <iostream>
#include <string>
#include <vector>
#include <cctype>

using namespace std;

// // 8 - 1
// string correctString (string input);

// int main(){
//     string input, output;
//     cout << "Enter the input string: ";
//     getline(cin, input, '.');
//     output = correctString(input);
//     cout << "The output string is: " << output << endl;
//     return 0;
// }

// string correctString (string input){
//     string output;
//     for (int i = 0; i < input.length(); i++){
//         if (i == 0){
//             output.push_back(toupper(input[0]));
//             continue;
//         }
//         char c = tolower(input[i]);
//         if (c == '\n') c = ' ';
//         if (isblank(c) && isblank(input[i+1])) continue;
//         output.push_back(c);
//     }
//     return output + ".";
// }

// // 8 - 2
// void countAndPrintWordsLetters (string input);

// int main(){
//     string input, output;
//     cout << "Enter the input string: ";
//     getline(cin, input);

//     countAndPrintWordsLetters (input);
    
//     return 0;
// }

// void countAndPrintWordsLetters (string input){
//     int wordCount;
//     vector <int> characters (26);
//     for (char c : input){
//         if (c == ' ' || c == '.') wordCount++;
//         c = tolower(c);
//         if (isalpha(c)){
//             int index = c - 'a';
//             characters[index]++;
//         }
//     }
//     cout << wordCount << ' ' << "words" << endl;
//     for (int index = 0; index < 26; index++)
//         if (characters[index] > 0) cout << characters[index] << ' ' << char(index + 'a') << endl;
// }

