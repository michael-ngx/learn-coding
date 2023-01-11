#include <stdio.h>

int main(){
    int total;
    printf("Please give an amount in cents less than 100: ");
    scanf("%d",&total);
        
    while (total >= 1 && total <= 99){
        int quarter,dime,nickel,cent,temp = total;

        quarter = temp/25;
        temp = temp - quarter*25;
        dime = temp/10;
        temp = temp - dime*10;
        nickel = temp/5;
        temp = temp - nickel*5;
        cent = temp/1;

        printf("%d cents: ",total);

//quarter
        if(quarter != 0 && dime == 0 && nickel == 0 && cent == 0){
            if (quarter == 1){
                printf("1 quarter.\n");
            }  
            else if (quarter > 1){
                printf("%d quarters.\n",quarter);
            }    
        }
        else if (quarter != 0){
            if(quarter == 1){
                printf("1 quarter, ");
            }
            else{
                printf("%d quarters, ",quarter);
            }
        }

//dime
        if(dime != 0 && nickel == 0 && cent == 0){
            if (dime == 1){
                printf("1 dime.\n");
            }  
            else if (dime > 1){
                printf("%d dimes.\n",dime);
            }    
        }
        else if (dime != 0){
            if(dime == 1){
                printf("1 dime, ");
            }
            else{
                printf("%d dimes, ",dime);
            }
        }

//nickel
        if(nickel != 0 && cent == 0){
            if (nickel == 1){
                printf("1 nickel.\n");
            }  
            else if (nickel > 1){
                printf("%d nickels.\n",nickel);
            }    
        }
        else if (nickel != 0){
            if(nickel == 1){
                printf("1 nickel, ");
            }
            else{
                printf("%d nickels, ",nickel);
            }
        }

//cent
        if (cent != 0){
            if(cent == 1){
                printf("1 cent.\n");
            }
            else{
                printf("%d cents.\n",cent);
            }
        }
    
        
        
        printf("Please give an amount in cents less than 100: ");
        scanf("%d",&total);
    }
    
    printf("Goodbye.\n");
    
    return 0;
}