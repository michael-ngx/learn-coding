#include <stdio.h>
#define TAX 1.13
int main(){
    double monthly_rate, duration, swipe_fee, mastercard, apple_rate, apple, iBill, total;
    printf("Enter the monthly rate: ");
    scanf("%lf",&monthly_rate);
    printf("Enter the service duration (in months): ");
    scanf("%lf",&duration);
    printf("Enter the swipe fee rate (in percentage): ");
    scanf("%lf",&swipe_fee);
    printf("Enter the Apple Pay rate (in percentage): ");
    scanf("%lf",&apple_rate);
    int free_month = (int) (duration/4);
    iBill = monthly_rate*(duration - free_month)*TAX;
    mastercard = iBill*swipe_fee/100;
    apple = mastercard*apple_rate/100;
    total = iBill + mastercard + apple;

    printf("Your total free months(s) using iBell's service is: %d\nThe iBill charge including taxes is: %.2lf\nThe swipe fee paid to Mastercard is: %.2lf\nThe fee paid to use Apple Pay is: %.2lf\nThe total charge is: %.2lf",free_month,iBill,mastercard,apple,total);
}

/*
#include<stdio.h>

int main(){
    int code,first,second,third;
    printf("Enter an encrypted 3-digit code: ");
    scanf("%d",&code);
    third = code%10;
    second = code/10%10;
    first = code/100;
    printf("The real 3-digit code is: %d%d%d",third,(9-second),first);
}
*/