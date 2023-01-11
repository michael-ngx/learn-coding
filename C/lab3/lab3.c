#include <stdio.h>

int factorial (int n){
    int result = 1;
    if (n == 0){
        return result;
    }
    for (int i = 1; i <= n ; i++){
        result *= i;
    }
    return result;
}

int choose(int n,int r){
    return factorial(n)/(factorial(r)*factorial(n-r));
}

void triangle (int num){
    int space = num*2-1;
    int init_space;
    for (int n = 0; n < num; n++){
        
        //add initial spaces
        init_space = num*(num-n-1);
        for (int j = 0; j < init_space; j++){
            printf(" ");
        }

        //calculate numbers to print
        for (int r = 0; r <= n; r++){
            int num_to_print = choose(n,r);
            printf("%d",num_to_print);
            
            //these if-elseif-else statements are used to calculate spaces after each number to print
            
            //if num to print has 2 digits --> minus 1 space after
            if (num_to_print >= 10){
                for (int t = 0; t < space-1; t++){
                printf(" ");
                }
            }

            //normally, between numbers
            else if (r != n){
                for (int t = 0; t < space; t++){
                printf(" ");
                }
            }

            //the spaces after the last number = init_space
            else{
                for (int k = 0; k < init_space; k++){
                printf(" ");
                }
            }
        }
        printf("\n");
    }
}

int main(){
    int num;
    printf("Enter the number of rows: ");
    scanf("%d",&num);
    triangle(num);
    return 0;
}