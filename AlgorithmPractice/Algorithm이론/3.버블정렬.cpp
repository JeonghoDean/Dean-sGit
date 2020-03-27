//버블정렬
//가장 효율성이 떨어짐
//바로 옆의 수와 자리 바꾸는 정렬방법
//시간복잡도 O(N^2) but 선택 정렬 보다도 작업량이 더 많음. 즉 가장 느림

#include <iostream>

int main() {
	int i, j, temp;
	int array[10] = { 1,10,5,8,7,6,4,3,2,9 };
	for (i = 0; i < 10; i++) {
		for (j = 0; j < 9 - i; j++) {
			if (array[j] > array[j + 1]) {
				temp = array[j];
				array[j] = array[j + 1];
				array[j + 1] = temp;
			}
		}
	}
	for (i = 0; i < 10; i++)
		printf("%d ", array[i]);
	return 0;
}