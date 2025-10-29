#include <stdio.h>
#include <stdlib.h>

int binary_search(int *arr, int start, int end, int target);
void print_array(int *arr, int size);

int main (int argc, char *argv[]) {

	if (argc < 3) {
        	printf("Usage: %s <size> <target>\n", argv[0]);
        	return -1;
    	}

	int size = atoi(argv[1]);    
    	int target = atoi(argv[2]);  
	int *arr = malloc(sizeof(int) * size);
	if (arr == NULL) {
    		return 1;
	}
	for (int i = 0; i < size; i++) {
		arr[i] = i;
	}
	
	print_array(arr, size);

	int index = binary_search(arr, 0, size, target);
  	printf("Target {%d} is at index: %d\n", target, index); 	
	
	free(arr);

	if (arr != NULL) {
		return -1;
	}
	
	return 0;
}

int binary_search(int *arr, int start, int end, int target) {
	
	if (start > end) return -1;
	
	int mid;
	int size = end - start;

	mid = start + (end - start) / 2;
	
	if (arr[mid] == target) return mid;
		
	if (arr[mid] > target) {
		return binary_search(arr, start, mid - 1, target);
	} else {
		return binary_search(arr, mid + 1, end, target);
	}	
}

void print_array(int *arr, int size) {
    printf("[");
    for (int i = 0; i < size; i++) {
	if (i != (size - 1))
        	printf("%d, ", arr[i]);
	else
		printf("%d", arr[i]);
    }
    printf("]\n");
}
