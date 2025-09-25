#include <stdio.h>
#include <stdlib.h>

#define IN 1
#define OUT 0

int main() {

    int state = OUT;
    int c;

    while ((c = getchar()) != EOF) {

        if (c != ' ') {
            printf("%c",c);
        } else {
            printf("\n");
        }
    
    }

    return 0;
}