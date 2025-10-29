#include <stdio.h>

void print_binary(unsigned int x);
unsigned rotatebits(unsigned x, int n);

int main() {
	unsigned char x = 0b10100110;
	int n = 3;
	rotatebits(x, 3);
	return 0;
}

unsigned rotatebits(unsigned x, int n) {
	print_binary(x);
	unsigned maskN = (1 << n) - 1;
	print_binary(maskN);
	unsigned bitsToRotate = x & maskN;
	print_binary(bitsToRotate);
	unsigned displacedMaskN = maskN << (8 - n);
	print_binary(displacedMaskN);
	unsigned xUnsettedBits = x >> n;
	print_binary(xUnsettedBits);
	unsigned bitsToRotateDisplaced = bitsToRotate << (8 - n);
	print_binary(bitsToRotateDisplaced);
	unsigned result = xUnsettedBits | bitsToRotateDisplaced;
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
