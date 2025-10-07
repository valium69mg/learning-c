#include <stdio.h>
#include <stdlib.h>

int power(int n, int e);

int main() {

	int n = 3;
	int e = 2;
	printf("result: %d\n", power(n, e));
	int n2 = 2;
	int e2 = 4;
	printf("result: %d\n", power(n2,e2));
	return 0;

}

int power(int n, int e) {
	int r = n;
	for (int i = 1; i < e; i++) {
		r = r * n;
	}

	return r;
}
