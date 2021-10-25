#include <stdio.h>
printSomething(){
    printf(" hello,world\n");
    printf("\t\n");
    printf("\b\n");
    printf("\"\n");
    printf("\\\n");
}
// 练习1-2
main(){
    printSomething();
    printf("\c");
}