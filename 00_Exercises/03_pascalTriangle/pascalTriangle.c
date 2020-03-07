//Übung 3: Pascal Dreieck
#include <stdio.h>
#include <stdlib.h>

int main (int argc, char* argv[]){
    int rows = atoi(argv[1]);
    int i,j,space;
    int coeff = 1;

    if(argc != 2 && rows < 0 || rows > 10){
        printf("Usage: multiTable wholeNumber\n wholeNumber: integer on the interval [1,10]\n");
    }

    for (i=0; i<rows; i++){                       // Display rows
        for (space=1; space <= rows-i; space++)
            printf("  ");                         // 2 spaces for better looking
        
        for (j=0; j <= i; j++){
            if (j==0 || i == 0){
                coeff = 1;
            }else{
                coeff = coeff*(i-j+1)/j;
            }
            printf("%4d", coeff);
        }
        printf("\n");
    }

    return 0;
}