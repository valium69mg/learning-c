#include <stdio.h>

unsigned invertbits(unsigned x, int n, int p);
void print_binary(unsigned int x);

int main() {

	int n = 3;
	int p = 4;
	unsigned char x = 0b10101010;
	invertbits(x, n , p);
	return 0;
}


unsigned invertbits(unsigned x, int n, int p) {
	print_binary(x);
	unsigned maskN = (1 << n) - 1;
	print_binary(maskN);
	unsigned bitsToInvert = (x >> (p + 1 - n)) & maskN;
	print_binary(bitsToInvert);
	unsigned bitsInverted = ~bitsToInvert & maskN;
	print_binary(bitsInverted);
	unsigned displacedMaskN = maskN << (p + 1 - n); 
	print_binary(displacedMaskN);
	unsigned bitsInvertedPlaced = bitsInverted << (p + 1 - n);
	print_binary(bitsInvertedPlaced);
	unsigned xWithUnsetBits = x & ~displacedMaskN;
	print_binary(xWithUnsetBits);
	unsigned result = xWithUnsetBits | bitsInvertedPlaced;
	print_binary(result);
	return result;
}

void print_binary(unsigned int x) {
    int bits = sizeof(x) * 8; // normalmente 32 bits
    for (int i = bits - 1; i >= 0; i--) {
        printf("%d", (x >> i) & 1);
        if (i % 4 == 0) printf(" "); // opcional: separa cada 4 bits para mejor lectura
    }
    printf("\n");
}
