#include <stdio.h>


int main() {
	int c;
	while (c = getchar()) {

		if (c == '\t') {
			c = ' ';
		}
		printf("%c",c);
	}
}
