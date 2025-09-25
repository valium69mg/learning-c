#include <stdio.h>
#include <stdlib.h>

int main () {

    int blank = 32;
    int c;
    int *blankCount = malloc(sizeof(int));
    *blankCount = 0;
    while (((c = getchar()) != EOF)) {
        if (c == blank) {
            (*blankCount)++;
            printf("Blank count: %d\n", *blankCount);
        }
        
    } 

    free(blankCount);

    return 0;
}