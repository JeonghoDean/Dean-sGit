/* ������
��ǥ���� '���� ����' �˰������μ� ��� �ӵ��� O(N*logN)
Ÿ ���İ� ������ ��� �ſ� ����
Ư���� ��(�ǹ�)�� �������� ū���ڿ� ���� ���ڸ� ���� ��ȯ�� �ڿ� �迭�� ������ ����
*/


#include <iostream>

void quickSort(int *data, int start, int end) {
	if (start >= end)return;	//���� 1���� ��� ��
	int key = start;
	int i = start + 1;
	int j = end;
	int temp;

	while (i <= j) {		//������ ������ �ݺ�
		i = start + 1;
		j = end;
		while (data[i] <= data[key]) {	//Ű ������ ū ���� ã��������
			i++;
			if (data[start] == 10) printf("i = %d ", i);
		}
		while (data[j] >= data[key] && j > start) {	//Ű ������ ���� ���� ã��������
			j--;
		}
		if (i > j) {		//���� ������ ���¸� Ű ���� ��ü
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