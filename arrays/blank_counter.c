#include <stdio.h>
#include <stdlib.h>

int main() {

    int counter[1] = {0};
    int c;
    int blank = 32;
    while ((c = getchar()) != EOF) {

        if (c == blank) {
            counter[0]++;
        }
    }
    printf("Total blank spaces: %d\n", counter[0]);

    return 0;
}