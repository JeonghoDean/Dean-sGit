#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <algorithm>

int main() {
	int n;
	scanf("%d", &n);
	
	int a[50] = {};
	int c[50] = {};
	int b[50] = {};
	for (int i = 0; i < n; i++) {
		scanf("%d", &a[i]);
	}
	for (int i = 0; i < n; i++) {
		scanf("%d", &b[i]);
	}
	std::sort(a, a + n);
	for (int i = 0; i < n; i++) {
	}

	int max, max2=100, temp, index=101, pindex=0;
	for (int j = 0; j < n; j++) {
		max = 0;
		for (int i = 0; i < n; i++) {
			if (b[i] <= max2 && b[i] >= max && i != pindex) {
				max = b[i];
				index = i;
			}
		}
		c[index] = a[j];
		max2 = max;
		pindex = index;
	}
	int sum = 0;
	for (int i = 0; i < n; i++) {
		sum += b[i] * c[i];
	}
	printf("%d", sum);
}