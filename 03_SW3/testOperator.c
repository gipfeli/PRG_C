// Zuwesung von verschiedene Werte zu Variablen
#include <stdio.h>
#include <math.h>

int main (void){
    short largeShort = 32760;
    printf("largeShort: %d\n", largeShort);
    largeShort = largeShort + 12345;
    printf("New largeShort: %d\n", largeShort);

    printf("\n");
    int numerator = 19;
    int denominator = 5;
    int result = numerator/denominator;
    printf("Numerator: %d; Denominator: %d\n", numerator, denominator);
    printf("Result: %d\n", result);

    printf("\n");
    float e = 2.718281828f;
    e++;
    printf("e = %f\n", e);
    e--;
    printf("e = %f\n", e);

    double dblNumerator = 12.8;
    // For modulo operation, an int-typed data is required. Or use fmod (math.h)
    int modDblNumerator = (int)(dblNumerator);
    int result1 = modDblNumerator % 3;
    printf("%lf mod 3 = %d\n", dblNumerator, result1);

    return(0);
}

