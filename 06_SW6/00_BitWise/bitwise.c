#include <stdio.h>
#include <stdlib.h>

void printBinary (int input);

int main (int argc, char *argv[]){
	int a = 12, b = 25;
	printBinary(a);
	printBinary(b);
	printBinary(~a);

	printBinary(a&b);
	printBinary(a|b);
	printBinary(a^b);

	printBinary(a<<1);
	printBinary(a>>1);

	unsigned char c 	= 0b000001100;
	unsigned char mask 	= 0b001000000;

	printf("\n *** set bit 5 ***\n");
	printBinary(c);
	unsigned d = c;
	printBinary(c|mask);
	mask = 1; // 0b00000001
	printBinary(c | mask << 5);

	return EXIT_SUCCESS;
}

void printBinary (int input){
	unsigned int i = 0;

	printf("%d = \t 0b", input);

	for (i = (1<<31); i>0; i=(i>>1)){
		if (input&i){
			printf("1");
		} else {
			printf("0");
		}
	}
	printf("\n");
}

