//선택정렬
//다른 정렬 알고리즘과 비교해서 비효율적인 정렬방식 중 하나
//가장 작은 수를 앞으로 보내며 정렬하는 방법
//시간복잡도 O(N^2)

#include <stdio.h>

int main() {
	int i, j, min, index, temp;
	int array[10] = { 1, 10, 5, 8,7,6,4,3,2,9 };
	for (i = 0; i < 10; i++) {
		min = 9999;
		for (j = i; j < 10; j++) {
			if (min > array[j]) {
				min = array[j];
				index = j;
			}
		}
		temp = array[i];
		array[i] = array[index];
		array[index] = temp;
	}
	for (i = 0; i < 10; i++) {
		printf("%d ", array[i]);
	}
	return 0;
}