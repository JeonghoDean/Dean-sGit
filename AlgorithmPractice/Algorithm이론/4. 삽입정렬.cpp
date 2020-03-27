//삽입정렬
//각 숫자를 적절한 위치에 삽입
//시간복잡도 O(N^2)
//선택,버블정렬보다는 빠름
//이미 거이 정렬되어있는 상태에서는 삽입정렬이 매우 빠르다. 연산량 매우 적음

#include <iostream>

int main() {
	int i, j, temp;
	int array[10] = {1, 10, 5, 8, 7, 6, 4, 3, 2, 9};
	for (i = 0; i < 9; i++) {
		j = i;
		while (array[j] > array[j + 1]) {
			temp = array[j];
			array[j] = array[j + 1];
			array[j + 1] = temp;
			j--;
		}
	}
	for (i = 0; i < 10; i++)
		printf("%d ", array[i]);
	return 0;
}




