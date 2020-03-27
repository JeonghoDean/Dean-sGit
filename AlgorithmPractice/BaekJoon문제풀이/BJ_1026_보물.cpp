#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

int main() {
	int n,num;
	scanf("%d", &n);

	int a[50] = {};
	vector<int> v;

	for (int i = 0; i < n; i++) {
		scanf("%d", &a[i]);
	}
	for (int i = 0; i < n; i++) {
		scanf("%d", &num);
		v.push_back(num);
	}
	std::sort(a, a + n);

	int max, index = 0;
	int pindex[50] = {};
	int sum = 0;
	for (int j = 0; j < n; j++) {
		max = 0;
		for (int i = 0; i < v.size(); i++) {
			if (v.at(i) >= max) {
				max = v.at(i);
				index = i;
			}
		}
		sum += v.at(index) * a[j];
		v.erase(v.begin()+index);
	}
	
	printf("%d", sum);
}