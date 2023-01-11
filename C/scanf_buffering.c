#include <stdio.h>

int main ()
{
    char loop='y';
    while(loop != 'n') {
        printf("loop? ");
        scanf(" %c", &loop);  //Note the space before " %c". The reason is that when we input a character into the program, we already pressed a newline character. Therefore, the second loop took the character "\n". 
        if(loop != 'y') {     //This is scanf bufferring, and including a space will ignore all spaces and newline characters being inputted.
            loop='n';
        }
    }
    return 0;
}

//https://eecs.wsu.edu/~cs150/reading/scanf.htm