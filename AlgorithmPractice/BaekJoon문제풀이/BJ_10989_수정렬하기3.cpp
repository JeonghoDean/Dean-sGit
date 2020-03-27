//카운팅정렬 사용해야함
//우리가 일반적으로 사용하는 정렬이 아니고
//출현한 수만큼 배열 카운팅해서 나타내야함

#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <algorithm>

int main() {
	int n;
	int buffer = 0;
	int arr[10001] = {};
	
	scanf("%d", &n);

	for (int i = 0; i < n; i++) {
		scanf("%d", &buffer);
		arr[buffer]++;
	}
	for (int i = 0; i < 10001; i++) {
		for (int j = 0; j < arr[i]; j++) {
			printf("%d\n", i);
		}
	}
	return 0;
}