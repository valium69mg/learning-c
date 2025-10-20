#include <stdio.h>

int strlencarlos(char s[]);

int main() {

	char str[] = "Hello world";

	printf("String length is %d\n", strlencarlos(str));
	return 0;
}

int strlencarlos(char s[]){
	int i = 0;
	while (s[i] != '\0') {
		i += 1;
	}
	return i + 1;
}
