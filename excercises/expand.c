#include <stdio.h>
#include <stdlib.h>
char* expand(char* s1, char* s2);

void print_string(char* arr);

int main(int argc, char *argv[]) {

	if (argc != 2) {
        	printf("Usage: %s <input_string>\n", argv[0]);
        	return -1;
    	}

	char* s1 = argv[1];
	char* s2 = malloc(sizeof(int) * 1000);
	if (s2 == NULL) {
		return -1;
	}
	s2 = expand(s1, s2);
	print_string(s2);
	free(s2);
	s2 = NULL;
	return 0;

}

char* expand(char* s1, char* s2) {
	int i = 0;
	int j = 0;
	while (1) {
		if (s1[i + 1] == '\0') {
			s2[j++] = s1[i];
			break;
		}
		if (i == 0) {
			s2[j++] = s1[i++];
			continue;
		}
		if (s1[i] == '-') {
			printf("[%c, %c, %c]\n", s1[i-1], s1[i], s1[i + 1]);
			if (s1[i - 1] == s1[i + 1]) {
				s2[j++] = s1[i - 1];
				i++;
				continue;
			}	
			if (s1[i - 1] >= 65 && s1[i + 1] <= 90)  { // A-Z
				for (int k = s1[i - 1] + 1; k < s1[i + 1] - 1; k++) {
					s2[j++] = k;
				}
				i++;
				continue;
			}
			if (s1[i - 1] >= 97 && s1[i + 1] <= 122) { // a-z
				for (int k = s1[i - 1] + 1; k < s1[i + 1] - 1; k++) {
                                        s2[j++] = k;
                                }
                                i++;
                                continue;
			}
			if (s1[i - 1] >= 48 && s1[i + 1] <= 57) { // 0-9
				for (int k = s1[i - 1] + 1; k < s1[i + 1] - 1; k++) {
                                        s2[j++] = k;
                                }
                                i++;
                                continue;
			}	
		} else {
			s2[j++] = s1[i++];
		}
	}	
	s2[j] = '\0';
	return s2;
}

void print_string(char* arr) {
    int i = 0;
    while (arr[i] != '\0') {
        printf("%c", arr[i++]);
    }
    printf("\n");
}
