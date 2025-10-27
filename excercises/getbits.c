#include <stdio.h>
#include <stdlib.h>

unsigned getbits(unsigned x, int p, int n);

int main () {
	unsigned char value = 0b11010110;
	int p = 4;
	int n = 3;
	printf("getbits (x = %d, p = %d, n = %d) -> %d:\n", value, p, n, getbits(value, p, n));
	return 0;

}


unsigned getbits(unsigned x, int p, int n) {
	return ((x >> (p - n + 1)) & ~(~0 << n));
}
