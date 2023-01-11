#include <stdio.h>

int main ()
{
    char operator = 'a';
    int count = 1;
    while (operator != 'E'){
        
        while(operator != '+' && operator != '-' && operator != '*' && operator != '/' && operator != 'E' ){
            if (count != 1){
                printf("Invalid operation! Try again.\n");
            }
            count++;
            printf("Give an operation (+, -, *, /) E to stop: ");
            scanf(" %c", &operator);
        }
    
        if (operator == 'E'){
            printf("\n");
            return 0;
        }
    
        printf("Give values: ");
        int a,b,c,d,denominator,numerator;
        scanf ("%d %d %d %d",&a,&b,&c,&d);

        

        if (operator == '+'){
            denominator = b*d;
            numerator = a*d + b*c;
        }

        else if (operator == '-'){
            denominator = b*d;
            numerator = a*d - b*c;
        }

        else if (operator == '*'){
            denominator = b*d;
            numerator = a*c;
        }

        else{
            denominator = b*c;
            numerator = a*d;
        }

        //....Truong hop am, hoac la ket qua = int

        if (denominator == 0){
            printf("%d/%d %c %d/%d Invalid expression!\n",a,b,operator,c,d);
        }

        else{
            if (numerator%denominator == 0){
                printf("%d/%d %c %d/%d = %d\n",a,b,operator,c,d,numerator/denominator);
            }
            else{
                if ((numerator < 0 && denominator < 0) || (numerator > 0 && denominator < 0)){
                    numerator *= -1;
                    denominator *= -1;
                }
                printf("%d/%d %c %d/%d = %d/%d\n",a,b,operator,c,d,numerator,denominator);
            }
            

        }

        printf("Give an operation (+, -, *, /) E to stop: ");
        scanf(" %c", &operator);
        while(operator != '+' && operator != '-' && operator != '*' && operator != '/' && operator != 'E' ){
            printf("Invalid operation! Try again.\n");
            printf("Give an operation (+, -, *, /) E to stop: ");
            scanf(" %c", &operator);
        }
    }
    
    printf("\n");
    return 0;
}