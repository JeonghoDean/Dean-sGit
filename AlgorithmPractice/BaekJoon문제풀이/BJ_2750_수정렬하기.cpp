#define _CRT_SECURE_NO_WARNINGS
#include <iostream>

int main() {
	int n, i, j, index, min, temp;
	int array[1000] = {};

	scanf("%d", &n);
	for (i = 0; i < n; i++) {
		scanf("%d", &array[i]);
	}
	
	for (i = 0; i < n; i++) {
		min = 1001;
		for (j = i; j < n; j++) {
			if (min > array[j]) {
				min = array[j];
				index = j;
			}
		}
		temp = array[i];
		array[i] = array[index];
		array[index] = temp;
	}
	for (i = 0; i < n; i++) {
		printf("%d ", array[i]);
	}
}