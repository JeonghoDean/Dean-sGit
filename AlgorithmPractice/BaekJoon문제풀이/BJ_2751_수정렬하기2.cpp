#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include<algorithm>
int main() {
	int n;
	scanf("%d", &n);
	int* array = (int*)malloc(sizeof(int) * n);
	for (int i = 0; i < n; i++) {
		scanf("%d", &array[i]);
	}
	std::sort(array, array + n);
	for (int i = 0; i < n; i++) {
		printf("%d\n", array[i]);
	}
	return 0;
}