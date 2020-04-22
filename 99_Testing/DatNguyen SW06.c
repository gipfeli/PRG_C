/**
 * @file    sw06.c
 * @brief   Solution to homework SW06.
 */

#include "board.h"
#include <stdio.h>
#include <stdbool.h>
#include <stdint.h>

int main(void) {

	init();

	uint32_t marker = msTicks;
	enum stufe{null, low = 100, medium = 10, high = 5};													/* Array to save the last 10 steps */
	int i;
	int sum = 0;

	enum intensity{A, B, C, D, E, F};
	enum intensity intensity_level;

	bool stateChange = 0;
	bool laststateChange = 0;
	int stateChangeCounter = 0;

	while (true) {
		while (msTicks < marker + 1000){							/* wait for 1 second */
			stateChange = getTilt();								/* get state of Tilt-sensor (boolean) */
			int *step=malloc(10 * sizeof(int));						/* Dynamically allocated array step, size 10 */

			for (i = 0; i < 10; i++){
				if (msTicks < high)	{										/* step high: 200 state changes per second => max. period of a tick is 5 ms */
					step[i] = 1000;
					printf("State: high. Time %d [ms]\n", msTicks);
				} else if (msTicks < medium && msTicks >= high) {			/* step medium: 100 ... 199 state changes per second => min. period of a tick is 10 ms */
					step[i] = 100;
					printf("State: medium. Time %d [ms]\n", msTicks);
				} else if (msTicks < low && msTicks >= medium) {			/* step low: 10 ... 99 state changes per second => min. period of a tick is 100 ms */
					step[i] = 10;
					printf("State: low. Time %d [ms]\n", msTicks);
				} else {
					step[i] = 0;
					printf("State: null. Time %d [ms]\n", msTicks);
				}
			}

			for (i = 0; i < 10; i++){
				sum = sum + step[i];								/* Sum up activity score in the last 10 seconds */
			}

			if (sum <= 30) {										/* Categorize activity intensity based on score. Logic here could be wrong somewhere */
				intensity_level = F;
			} else if (sum > 30 && sum <= 60) {
				intensity_level = E;
			} else if (sum > 60 && sum <= 300) {
				intensity_level = D;
			} else if (sum >= 300 && sum <= 600) {
				intensity_level = C;
			} else if (sum > 600 && sum <= 6000) {
				intensity_level = B;
			} else if (sum > 6000) {
				intensity_level = A;
			} else {
				printf("Logic fails\n");
			}

			switch (intensity_level){
				case 0:												// FRAGE: Kann man hier, enum Elemente(intensity) A, B, C statt 0, 1, 2, eingeben? 
					RGB_color(0, 0, 255);							// Blue = A
					break;
				case 1:
					RGB_color(64, 224, 208);						// Turquoise = B
					break;
				case 2:
					RGB_color(0, 255, 0);							// Green = C
					break;
				case 3:												
					RGB_color(255, 255, 0);							// Yellow = D
					break;
				case 4:
					RGB_color(255, 165, 0);							// Orange = E
					break;
				case 5:
					RGB_color(255, 0, 0);							// Red = F
					break;
			}

			free(step);												// Free array.
		}
		marker += 1000;
	}

	return 0;
}

void RGB_color(int red_value, int green_value, int blue_value){
	PWM_SetDutycycleRed(red_value);
	PWM_SetDutycycleGreen(green_value);
	PWM_SetDutycycleBlue(blue_value);
	delay();
	PWM_SetDutycycleRed(0);
	PWM_SetDutycycleGreen(0);
	PWM_SetDutycycleBlue(0);
	delay();
}

static void delay(void){
	volatile uint32_t i = 0U;
	for (i = 0U; i < 800000U; ++i)
	{
		__asm("NOP");										/* delay as Board test */
	}
}