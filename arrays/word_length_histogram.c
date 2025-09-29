#include <stdio.h>
#include <stdlib.h>


int main() {

    int isInWord = 0;
    int c;
    int letterCounter = 0;
    int histogram[12] = {0,0,0,0,0,0,0,0,0,0,0,0}; // more than 10 letter word are considered on 11 category

    while ((c = getchar()) != EOF) {

        if (isInWord == 0) { 
            if ((c != ' ' && c != '\n' && c != '\t')) { // new word
                isInWord = 1;
                letterCounter++;
            } else {
                // do nothing
            }
        } else {
            if ((c != ' ' && c != '\n' && c != '\t')) { // still in word
                letterCounter++;
            } else { // word finished
                // update histogram
                if (letterCounter > 10) {
                    histogram[10]++;
                } else {
                    histogram[letterCounter - 1]++;
                }
                // reset
                letterCounter = 0;
                isInWord = 0;
            }
        }
    }

    if (isInWord && letterCounter > 0) {
        if (letterCounter > 10) {
            histogram[10]++;
        } else {
            histogram[letterCounter - 1]++;
    }
    }


    // print histogram 
    for (int i = 0; i <= 10; i++) {
        printf("%2d: ", i + 1);
        for (int j = 0; j < histogram[i]; j++) {
            printf("*");
        }
        printf("\n");
    }
    printf("11+: ");
    for (int j = 0; j < histogram[11]; j++) {
        printf("*");
    }
    printf("\n");


    return 0;
}