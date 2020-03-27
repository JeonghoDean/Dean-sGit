/* 퀵정렬
대표적인 '분할 정복' 알고리즘으로서 평균 속도가 O(N*logN)
타 정렬과 비교했을 경우 매우 빠름
특정한 값(피벗)을 기준으로 큰숫자와 작은 숫자를 서로 교환한 뒤에 배열을 반으로 나눔
*/


#include <iostream>

void quickSort(int *data, int start, int end) {
	if (start >= end)return;	//원소 1개일 경우 끝
	int key = start;
	int i = start + 1;
	int j = end;
	int temp;

	while (i <= j) {		//엇갈리 때까지 반복
		i = start + 1;
		j = end;
		while (data[i] <= data[key]) {	//키 값보다 큰 값을 찾을때까지
			i++;
			if (data[start] == 10) printf("i = %d ", i);
		}
		while (data[j] >= data[key] && j > start) {	//키 값보다 작은 값을 찾을때까지
			j--;
		}
		if (i > j) {		//현재 엇갈린 상태면 키 값과 교체
			temp = data[key];
			data[key] = data[j];
			data[j] = temp;
		}
		else {
			temp = data[j];
			data[j] = data[i];
			data[i] = temp;
		}
		for (int k = start; k <= end; k++) printf("%d ", data[k]); printf("\n");
	}
	quickSort(data, start, j - 1);
	quickSort(data, j+1, end);
}
int main() {
	int array[10] = { 10,1,5,8,7,6,4,3,2,9 };
	quickSort(array, 0, 9);
	for (int i = 0; i < 10; i++) {
		printf("%d ", array[i]);
	}
}