#include <stdio.h>
#include <stdbool.h>

bool readstring(int*result,int len){
    
    if (len <= 0){
        return false;
    }

    printf("Enter %d characters (one of 12345) as a search string: ",len);
    for (int i = 0; i < len; i++){
        scanf("%1d",&result[i]);
        if (result[i] < 1 || result[i] > 5){
            printf("Erroneous character input '%d' exiting\n",result[i]);
            return false;
        }
    }
    return true;
}

void searchstring(int*string, int*DNA, int len){
    for (int i = 0; DNA[i] != 0; i++){
        int start = 0;
        int temp = i;
        while (start < len && (DNA[temp] == string[start] || string[start] == 5)){
            temp++;
            start++;
        }
        if (start == len){
            printf("Match of search string found at element %d\n",i);
        }
    }
}

int main(){

    int DNA[] = {1, 2, 4, 2, 2, 2, 1, 4, 4, 2, 3, 4, 4, 4, 2, 1, 4, 1, 3, 3, 2, 1, 3, 2, 1, 1, 2, 2, 2, 3, 4, 1, 3, 1, 2, 1, 4, 4, 4, 1, 1, 3, 1, 4, 2, 4, 4, 1, 4, 4, 1, 4, 4, 4, 4, 1, 1, 2, 3, 3, 3, 3, 4, 4, 3, 2, 3, 2, 3, 4, 3, 3, 4, 4, 1, 3, 3, 2, 1, 2, 3, 1, 2, 1, 3, 3,2, 1, 4, 1, 4, 3, 4, 4, 4, 1, 2, 1, 3, 2, 0}; 
    
    bool check;

    do{
        int len;
        printf("Enter length of DNA string to match: ");
        scanf("%d",&len);
        
        int string[len];
        check = readstring(string,len);

        if (check){
        searchstring(string,DNA,len);
        }

    }while(check);
    printf("Goodbye");
    return 0;
}