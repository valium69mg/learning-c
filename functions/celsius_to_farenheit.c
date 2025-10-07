#include <stdio.h>
#include <stdlib.h>

float celsiusToFarenheit(int c);

int main(){

	int c = 32;
	printf("Celsius: %d, Farenheit: %.2f\n", c, celsiusToFarenheit(c));
	return 0;

}

float celsiusToFarenheit(int c) {
	return (c * (9.0/5.0)) + 32;
}
