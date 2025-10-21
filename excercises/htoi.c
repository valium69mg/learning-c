#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <math.h>
int htoi(char s[]);
char* cleanHex(char s[]);

int main() {

	char s[] = "0xFF";
	char* ps = cleanHex(s);
	int decimalTotal =  htoi(ps);	
	printf("%s = %d\n", s, decimalTotal);
	free(ps);
	return 0;
}

int htoi(char* ps) {	
		
	int size_ps = strlen(ps) - 1;
	int totalDecimal = 0;
	int index = 0;
	for (size_ps; 0 <= size_ps; size_ps--) {
		int hexValue = ps[index];
		if (hexValue == 'F' || hexValue == 'f') {
			hexValue = 15;
		} else if (hexValue == 'E' || hexValue == 'e') {
			hexValue = 14;
		} else if(hexValue == 'D' || hexValue == 'd') {
			hexValue = 13;
		} else if (hexValue == 'C' || hexValue == 'c') {
			hexValue = 12;
		} else if (hexValue == 'B' || hexValue == 'b') {
			hexValue = 11;
		} else if (hexValue == 'A' || hexValue == 'a') {
			hexValue = 10;
		} else if (hexValue >= '0' && hexValue <= '9') {
			hexValue -= '0';
		}
		int decimal = hexValue * pow(16,size_ps);
		printf("(%d x 16e%d)\n", hexValue, size_ps);
		totalDecimal += decimal;
		index++;
	}	
	return totalDecimal;

}

char* cleanHex(char s[]){
	int i = 0;
	int j = 0;
	if (s[i] == '0' && (s[i+1] == 'x' || s[i+1] == 'X')) {
		i = 2;
	}

	char *ps = malloc((strlen(s) + 1) - i);

	while (1) {
		if (s[i] == '\0') {
			ps[j] = '\0';
			break;
		}
		ps[j] = s[i]; 
		i++;
		j++;	
		
	}
	return ps;
}


