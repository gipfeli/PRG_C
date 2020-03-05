// Take 3 positive int. If failed to do so, break
#include <stdio.h>

int main (void){
    int a = 0, b = 0, c = 0;
    int smallest = 0, biggest = 0;
    printf("Please enter three positive values:\n");
    while (a>=0 || b>=0 || c>=0){
        printf("a = \n");
        scanf("%d", &a);
        if(a<0){
            printf("Try again.\n");
            break;
        }
        printf("b = \n");
        scanf("%d", &b);
        if(b<0){
            printf("Try again.\n");
            break;
        }
        printf("c = \n");
        scanf("%d", &c);
        if(c<0){
            printf("Try again.\n");
            break;
        }
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

    return 0;
    }


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

    return 0;
}