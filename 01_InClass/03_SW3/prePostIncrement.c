//unterschied zw i++ und ++i 
#include <stdio.h>

int main (void){
    int a = 0, b =0;
    printf("a: %d\n", ++a);
    printf("b: %d\n", b++);

    printf("b: %d\n", b);

    return(0);
}