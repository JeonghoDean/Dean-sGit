//포기포기포기포기포기


#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <vector>
using namespace std;

int main() {
	int arr[4001] = {};
	int narr[4001] = {};
	int N, num = 0;
	int sum = 0, avg = 0;;
	scanf("%d", &N);
	for (int i = 0; i < N; i++) {
		scanf("%d", &num);
		if (num < 0)
			narr[abs(num)];
		else
			arr[num]++;
		sum += num;
	}avg = (int)((float)sum / N + 0.5);
	printf("%d\n", avg);

	sum = 0;
	int cnt = 4000;
	while (cnt < 0 && sum < N / 2) {
		sum += narr[cnt];
		cnt--;
	}
	if (cnt < 0) {
		cnt = 0;
		while (cnt < 4001 && sum < N / 2) {
			sum += arr[cnt];
			cnt++;
		}
		printf("%d\n", arr[cnt - 1]);
	}
	else {
		printf("%d\n", narr[cnt + 1]);
	}

	vector<int> v;
	int max = 0, index;
	int sign = 0;	//0=양수 , 1=음수
	for (int i = 0; i < 4001; i++) {
		if (arr[i] > max) {
			max = arr[i];
			sign = 0;
		}
		if (narr[i] > max) {
			max = narr[i];
			sign = 1;
		}
	}

	for (int i = 0; i < 4001; i++) {
		
		if (arr[i] == max && sign == 0) {
			v.push_back(i);
		}
		else if (narr[i] == max && sign == 1) {
			v.push_back(i);
		}
	}
	if(sign==0) printf("%d\n", arr[v.at(1)]);
	else printf("%d\n", narr[v.at(v.size-2)]);
	
	int maxnum[2] = {};
	int minnum[2] = {};
	for (int i = 0; i < 4001; i++) {
		if (arr[i] > 0) {
			maxnum[0] = i;
		}
		if (arr[4000 - i] > 0) {
			minnum[0] = 4000 - i;
		}
		if (narr[i] > 0) {
			maxnum[1] = i;
		}
		if (narr[4000 - i] > 0) {
			minnum[1] = 4000 - i;
		}
	}
	if (maxnum[0] != 0) {
		if(minnum[1]!=0)
			printf("%d", maxnum[0] + minnum[1]);
		else
			printf("%d", maxnum[0] - minnum[0]);
	}
	else {
		if (minnum[1] != 0)
			printf("%d", minnum[0] + minnum[1]);
		else
			printf("%d", minnum[0] - minnum[0]);
	}

		return 0;
}