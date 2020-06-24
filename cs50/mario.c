#include <stdio.h>

//print the array
//dir=0 means print forward direction, dir=1 means print backwards direction
void printArr(char* arr, int dir, int size) {
	if (dir == 0) {
		for (int i = 0; i < size; i++) {
			printf("%c", arr[i]);
		}
	} else if (dir == 1) {
		for (int i = (size - 1); i >= 0; i--) {
			printf("%c", arr[i]);
		}
	}
}

int main(void) {
	int n = 0;
	while (n < 1 || n > 8) {
		//print the prompt and get the user input
		printf("Height: ");
		scanf("%d", &n);
	}

	//allocate the array to store the pyramid
	char* arr;
	arr = malloc(n); 
	memset(arr, ' ', n);

	//loop while printing the pyramid
	for (int i = 0; i < n; i++) {
		arr[i] = '#';
		printArr(arr, 1, n);
		printf("  ");
		printArr(arr, 0, n);
		printf("\n");
	}
	return 0;
}

