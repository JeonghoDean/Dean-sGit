/*
�������
�ð����⵵ O(N)
���� ������ ������ ������ ���� �� ������ ���Ĺ��
*/
#define _CRT_SECURE_NO_WARNINGS
#include <iostream>

int main() {
	int count[5] = {};
	int array[30] = {
		1,4,5,2,3,4,5,2,1,3,
		4,2,3,5,1,2,3,4,2,1,
		5,3,2,4,5,2,5,5,4,3
	};
	for (int i = 0; i < 30; i++) {
		count[array[i] - 1]++;
	}
	for (int i = 0; i < 5; i++)
		for (int j = 0; j < count[i]; j++)
			printf("%d", i+1);
	
	return 0;
}