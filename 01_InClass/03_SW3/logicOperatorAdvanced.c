// Take 3 positive int. If failed to do so, break
#include <stdio.h>
#include <stdlib.h>

int main (int argc, char* argv[]){

int smallest = 0, biggest = 0;

if(argc=4){
    int a = atoi(argv[1]);
    int b = atoi(argv[2]);
    int c = atoi(argv[3]);

    if(a>=0 && b>=0 && c>=0){
        // Find smollest
        if (a < b && a < c){
            smallest = a;
        } else if (b < c){
            smallest = b;
        } else{
            smallest = c;
        }
        // Find yugest
        if (a > b && a > c){
            biggest = a;
        } else if(b > c){
            biggest = b;
        } else {
            biggest = c;
        }
    printf("The smallest of the entered values is: %d\n", smallest);
    printf("The largest of the entered values is: %d\n", biggest);
    } else
    {
        printf("I can only process positive numbers. Please try again.");
    }
    
} else {
    printf("Too many/few arguments.");
}
    return 0;
}