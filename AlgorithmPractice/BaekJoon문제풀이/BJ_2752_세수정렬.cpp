#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include<algorithm>
int main() {
	int array[3] = {};
	scanf("%d %d %d", &array[0], &array[1], &array[2]);
	std::sort(array, array + 3);
	printf("%d %d %d", array[0], array[1], array[2]);
	return 0;
}