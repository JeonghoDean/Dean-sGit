/* 힙정렬
시간 복잡도 O(N*logN)
힙트리구조 이용하는 정렬방법
*/

#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
using namespace std;

int main() {
	int number = 9;
	int heap[9] = { 7, 6, 5, 8, 3, 5, 9, 1, 6 };

	for (int i = 1; i < number; i++) {
		int root;
		int node = i, temp;
		do {
			root = (node - 1) / 2;
			if (heap[root] < heap[node]) {
				temp = heap[root];
				heap[root] = heap[node];
				heap[node] = temp;
			}
			node = root;
		} while (node!=0);
	}
	for (int i = number - 1; i >= 0; i--) {
		int temp = heap[0];
		heap[0] = heap[i];
		heap[i] = temp;
		int root = 0;
		int node;
		do {
			node = root * 2 + 1;
			if (heap[node] < heap[node + 1] && node < i-1) {
				node++;
			}
			if (heap[node] > heap[root] && node < i) {
				temp = heap[node];
				heap[node] = heap[root];
				heap[root] = temp;
			}
			root=node;
		} while (node < i);
	}
	for (int i = 0; i < number;i++) printf("%d ", heap[i]);
	return 0;
}
