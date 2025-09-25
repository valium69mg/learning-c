#include <stdio.h>
#include <stdlib.h>

int main () {
    int blank = 32;
    int c;
    int lastWasBlank = 0;
    while (((c = getchar()) != EOF)) {
        if (lastWasBlank == 0 || c != blank)  {
            putchar(c);
        }
        if (c == blank) {
            lastWasBlank = 1;
        } else {
            lastWasBlank = 0;
        }
    } 

    return 0;
}