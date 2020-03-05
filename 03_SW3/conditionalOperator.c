// Conditional or ternary opeartor in C
// variable = Exp1 ? Exp2 : Exp3
#include <stdio.h>

int main (void){
    int x = 0, y = 0, z = 0, a = 1, b = 100;
    printf("Enter y = ");
    scanf("%d", &y);
    printf("With y = %d\n",y);
    x = y ? 1 : 100;
    printf("x = %d\n", x);

    z = (x > y) ? x : y;
    printf("z = %d\n", z);

    return 0;
}