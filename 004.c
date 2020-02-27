// Test data types
#include <stdio.h>

int main (void){
	printf("The program will print out the size of various data types: \n");
	printf("Size of a char : %ld\n", sizeof(char));
	printf("Size of a short : %ld\n", sizeof(short));
	printf("Size of a int : %ld\n", sizeof(int));
	printf("Size of a long : %ld\n", sizeof(long));
	printf("Size of a long long : %ld\n", sizeof(long long));
	printf("Size of a float : %ld\n", sizeof(float));
	printf("Size of a double : %ld\n", sizeof(double));
	printf("Size of a long double : %ld\n", sizeof(long double));

	printf("Data types with *: \n");
	printf("Size of a char : %ld\n", sizeof(char*));
	printf("Size of a char : %ld\n", sizeof(short*));
	printf("Size of a char : %ld\n", sizeof(int*));
	printf("Size of a char : %ld\n", sizeof(long*));
	printf("Size of a char : %ld\n", sizeof(long long*));
	printf("Size of a char : %ld\n", sizeof(float*));
	printf("Size of a char : %ld\n", sizeof(double*));
	printf("Size of a char : %ld\n", sizeof(long double*));
}
