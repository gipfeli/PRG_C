//Übung 02: Ein-mal-Eins
#include <stdio.h>
#include <stdlib.h>

int main (int argc, char* argv[]){
    int inputValue = atoi(argv[1]);
    int i,j,n;

    if(argc != 2 && inputValue < 0 || inputValue > 10){
        printf("Usage: multiTable wholeNumber\n wholeNumber: integer on the interval [1,10]\n");
    }
    for(i=1; i <= inputValue; i++){
        for(j=1; j <=inputValue; j++){
            printf("%d\t ",i*j); 
        }
        printf("\n");
    }
    
    return 0;
}