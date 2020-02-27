//scanf, printf test

#include <stdio.h>

int main (void)
{
    int readValue = 0;
    printf("Enter value: ");
    scanf("%d", &readValue);

    printf("The entered value is: %d\n", readValue);
}