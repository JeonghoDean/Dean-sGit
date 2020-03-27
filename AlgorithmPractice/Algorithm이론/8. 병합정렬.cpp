/*병합정렬
평균시간복잡도 O(N*longN)
'분할정보방법'채택
정확히 반절씩 나눔으로서 최악의 경우 피할 수 있음
*/
#include <iostream>

int sortedArr[8];	//전렬 배열은 반드시 전역 변수로 선언

void merge(int *data, int start, int middle, int end) {
	int i = start;
	int j = middle + 1;
	int k = start;

	while (i <= middle && j <= end) {
		if (data[i] <= data[j]) {
			sortedArr[k] = data[i];
			i++;
		}
		else {
			sortedArr[k] = data[j];
			j++;
		}
		k++;
	}
	if (i > middle) {
		while (j <= end) {
			sortedArr[k] = data[j];
			k++;
			j++;
		}
	}
	else {
		while (i <= middle) {
			sortedArr[k] = data[i];
			k++;
			i++;
		}
	} 
	for (int a = start; a <= end; a++)
		data[a] = sortedArr[a];
}

void mergeSort(int *data, int start, int end) {
	if (start < end) {
		int middle = (start + end) / 2;
		mergeSort(data, start, middle);
		mergeSort(data, middle + 1, end);
		merge(data, start, middle, end);
	}
	
}
int main() {
	int arr[8] = {7, 6, 5, 8, 3, 5, 9, 1 };
	mergeSort(arr, 0, 7);
	for (int i = 0; i < 8; i++)
		printf("%d ", arr[i]);
	return 0;
}
