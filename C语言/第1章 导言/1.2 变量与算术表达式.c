#include <stdio.h>
fahrToCelsius(){
    float fahr,celsius;
    float lower,upper,step;
    lower = 0;
    upper = 300;
    step = 20;
    fahr = lower;
    printf("华氏度 摄氏度\n");
    while(fahr<=upper){
        celsius = (5.0/9.0)*(fahr-32.0);
        printf(" %3.0f %6.1f\n",fahr,celsius);
        fahr+=step;
    }
}
// 练习1-4
celsiusToFahr(){
    float fahr,celsius;
    float lower,upper,step;
    lower = 0;
    upper = 100;
    step = 20;
    celsius = lower;
    printf("摄氏度 华氏度\n");
    while(celsius<=upper){
        fahr = 32.0+(celsius*(9.0/5.0));
        printf(" %3.0f %6.1f\n",celsius,fahr);
        celsius+=step;
    }
}
main(){
    celsiusToFahr();
}