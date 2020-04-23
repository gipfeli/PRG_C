#include <stdio.h>
#include <stdlib.h>

#include "bitOperation.h"

void printBinary (unsigned int input, unsigned char nBitsToPrint);

int main (int argc, char *argv[]){
	unsigned char testRegister = 0;

	for (int i = 0; i < 8; i++)
	{
		/* code */
		SetBitNof8 (&testRegister, i);
		printBinary (testRegister, 8);
	}
	for (int i = 7; i >= 0; i--)
	{
		/* code */
		ClearBitNof8 (&testRegister,i);
		printBinary(testRegister, 8);
	}

	return EXIT_SUCCESS;
}

void printBinary (unsigned int input, unsigned char nBitsToPrint){
	unsigned int i = 0;

	printf("%u = \t 0b", (unsigned short)input);

	for (i = (1<<nBitsToPrint); i>0; i=(i>>1)){
		if (input & i){
			printf("1");
		} else {
			printf("0");
		}
	}
	printf("\n");
}