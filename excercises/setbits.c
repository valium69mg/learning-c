#include <stdio.h>

unsigned setbits(unsigned char x, unsigned char y, int p, int n);
void print_binary(unsigned int x);

int main() {
    unsigned char x = 0b10101010;
    unsigned char y = 0b11110000;
    int p = 4;
    int n = 3;
    unsigned result = setbits(x, y, p, n);
    print_binary(result);     
    return 0;
}

unsigned setbits(unsigned char x, unsigned char y, int p, int n) {
    unsigned maskForN = (1 << n) - 1;  // 0b111 si n = 3
    unsigned displacedMaskForN = maskForN << (p + 1 - n);  // 0b111 << 2 = 0b11100
    unsigned xWithUnsetBits = x & ~displacedMaskForN;  // Borra los bits en x
    unsigned yBitsPlaced = (y & maskForN) << (p + 1 - n);  // Extrae bits de y y los coloca
    return xWithUnsetBits | yBitsPlaced;  // Inserta los bits en x
}


void print_binary(unsigned int x) {
    int bits = sizeof(x) * 8; // normalmente 32 bits
    for (int i = bits - 1; i >= 0; i--) {
        printf("%d", (x >> i) & 1);
        if (i % 4 == 0) printf(" "); // opcional: separa cada 4 bits para mejor lectura
    }
    printf("\n");
}

