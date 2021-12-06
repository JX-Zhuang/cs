#include <stdio.h>
int main(){
    int sum = 0,n = 2;
    while(n>0){
        if(n%2==1){
            sum+=n;
        }
        scanf("%d",&n);
    }
    printf("%d",sum);
    return 0;
}