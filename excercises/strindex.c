#include <stdio.h>
#include <string.h>
int strindex(char s[], char t);

int main() {

	char s[] = "Hello world";
	char t = 'l';
	int index = strindex(s, t);
	printf("rightmost character %c in %s is at index %d\n", t, s, index);
	return 0;
}


int strindex(char s[], char t) {

	int index = -1;

	for (int i = 0; i <= strlen(s); i++) { 
		if (s[i] == t) {	
			index = i;
		}
	}

	return index;
}
