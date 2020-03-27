/*��������
��սð����⵵ O(N*longN)
'�����������'ä��
��Ȯ�� ������ �������μ� �־��� ��� ���� �� ����
*/
#include <iostream>

int sortedArr[8];	//���� �迭�� �ݵ�� ���� ������ ����

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
