// Testing IF ELSE condition
#include <stdio.h>

int main (void) {
	printf("Compare two values for kindergarden children: \n");
	int inputFirst, inputSecond;
	printf("First value: \n");
	scanf("%d", &inputFirst);
	printf("Second value: \n");
	scanf("%d", &inputSecond);

	char equal[5] = "equal";
	char larger[6] = "larger";
	char smaller[7] = "smaller";

	if (inputFirst < inputSecond){
		printf("First value is %s than second value.\n", smaller);
	} else if (inputFirst > inputSecond){
		printf("First value is %s than second value.\n", larger);
	} else {
		printf("First value is %s to second value.\n", equal);
	}

	return 0;
}
