//ī�������� ����ؾ���
//�츮�� �Ϲ������� ����ϴ� ������ �ƴϰ�
//������ ����ŭ �迭 ī�����ؼ� ��Ÿ������

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