#include <stdio.h>
#include <limits.h>

int main() {

	char c = 0;
	short s;
	int in;
	long l;
	
	unsigned char uc;
	unsigned short us;
	unsigned int uin;
	unsigned long ul;

	// char
	char charMinValue = c;
	char charMaxValue = c;
	for (int i = 0; i <= 100000; i++) {
		c += 1;

		if (c < charMinValue) {
			charMinValue = c;	
		}	
		if (c > charMaxValue) {
			charMaxValue = c;
		}
	}
	printf("Char max value %d\n", charMaxValue);
	printf("Char min value %d\n", charMinValue);

	// short
	short maxShortValue = s;
	short minShortValue = s;
	for (int i = 0; i <= 300000; i++) {
		s += 1;
		if (s > minShortValue) {
			minShortValue = s;
		}
		if (s < maxShortValue) {
			maxShortValue = s;
		}
	}
	printf("Short max value %d\n", maxShortValue);
	printf("Short min value %d\n", minShortValue);

	// int
	printf("int: %d to %d\n", INT_MIN, INT_MAX);	

}
