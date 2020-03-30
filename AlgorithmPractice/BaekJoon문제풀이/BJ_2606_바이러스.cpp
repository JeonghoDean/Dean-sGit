#include<iostream>
#include<vector>
#include<queue>
#include<algorithm>
using namespace std;

int check[1001];
vector<int> a[101];
int cnt;

void dfs(int x) {
	if (check[x]) return;
	check[x] = true;
	cnt++;
	for (int i = 0; i < a[x].size(); i++) {
		int xx = a[x][i];
		dfs(xx);
	}

}
int main() {
	int n, m;
	cin >> n >> m;
	int node1, node2;
	for (int i = 0; i < m; i++) {
		cin >> node1 >> node2;
		a[node1].push_back(node2);
		a[node2].push_back(node1);
	}
	dfs(1);
	cout << cnt-1;
	return 0;
}