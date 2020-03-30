#define _CRT_SECURE_NO_WARNINGS
#include<iostream>
#include<algorithm>
#include<vector>
using namespace std;

int check[30][30];
int a[30][30];
vector<int> unitcnt;
int cnt;

void dfs(int y, int x, int size) {
	if (check[y][x])
		return;
	check[y][x] = true;
	cnt++;
	if (a[y][x - 1] == 1 && x > 0) dfs(y, x - 1, size);
	if (a[y][x + 1] == 1 && x < size - 1) dfs(y, x + 1, size);
	if (a[y + 1][x] == 1 && y < size - 1) dfs(y + 1, x, size);
	if (a[y - 1][x] == 1 && y > 0) dfs(y - 1, x, size);
}
int main() {
	int n;
	int unit = 0;
	cin >> n;
	int number;
	for (int y = 0; y < n; y++) {
		for (int x = 0; x < n; x++) {
			scanf("%1d", &a[y][x]);
		}
	}
	for (int y = 0; y < n; y++) {
		for (int x = 0; x < n; x++) {
			if (a[y][x] == 1 && check[y][x] == false) {
				cnt = 0;
				dfs(y, x, n);
				unit++;
				unitcnt.push_back(cnt);
				
			}
		}
	}
	sort(unitcnt.begin(), unitcnt.end());
	cout << unit << '\n';
	for (int i = 0; i < unitcnt.size(); i++) {
		cout << unitcnt[i] << '\n';
	}
	return 0;
}