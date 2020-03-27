#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <algorithm>

bool compare(int a, int b) {
	return a > b;
}
int main() {
	int n, i = 0, on=1;
	int arr[10] = {};
	scanf("%d", &n);
	while (n/10) {
		arr[i] = n % 10;
		n /= 10;
		i++;
	}arr[i] = n;
	std::sort(arr, arr + i + 1, compare);
	for (int j = 0; j <= i; j++) printf("%d", arr[j]);
	return 0;
}