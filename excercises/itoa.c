#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void reverse_str(char s[]);
void itoa(int n, char s[]);

int main() {

	char str[12];
	int n = 123;
	itoa(n, str);
	printf("%s\n",str);
	return 0;
}

void itoa(int n, char s[])
   {
       int i, sign;
       if ((sign = n) < 0)  /* record sign */
           n = -n;          /* make n positive */
       i = 0;
       do {      /* generate digits in reverse order */
           s[i++] = n % 10 + '0';  /* get next digit */
       } while ((n /= 10) > 0);    /* delete it */
       if (sign < 0)
           s[i++] = '-';
       s[i] = '\0';
       reverse_str(s);
   }

void reverse_str(char s[]) {
	
	char* rs = malloc(sizeof(char) * strlen(s));
	if (!rs) return;
	int j = 0;
	for (int i = strlen(s); i >= 0; i--) {
		if (s[i] == '\0') {
			continue;
		}
		rs[j++] = s[i];
	}
	rs[j] = '\0';

	for (int i = 0; i <= strlen(rs); i++) {
		s[i] = rs[i];
	}

	free(rs);
}
