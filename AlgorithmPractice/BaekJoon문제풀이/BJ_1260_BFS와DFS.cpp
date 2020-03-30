#include<iostream>
#include<vector>
#include<queue>
#include<algorithm>
using namespace std;

int check_bfs[1001];
int check_dfs[1001];
vector<int> node[1001];

void dfs(int x){
	if (check_dfs[x]) return;
	check_dfs[x] = true;
	cout << x << ' ';
	for (int i = 0; i < node[x].size(); i++) {
		int xx = node[x][i];
		dfs(xx);
	}
}

void bfs(int start) {
	queue<int> q;
	q.push(start);
	check_bfs[start] = true;
	while (!q.empty()) {
		int x = q.front();
		q.pop();
		cout << x << ' ';
		for (int i = 0; i < node[x].size(); i++) {
			int y = node[x][i];
			if (!check_bfs[y]) {
				q.push(y);
				check_bfs[y] = true;
			}
		}
	}
}

int main() {
	int n, m, start;
	cin >> n >> m >> start;
	int a, b;
	for (int i = 0; i < m; i++) {
		cin >> a >> b;
		node[a].push_back(b);
		node[b].push_back(a);
		sort(node[a].begin(), node[a].end());
		sort(node[b].begin(), node[b].end());
	}
	

	dfs(start); 
	cout << '\n';
	bfs(start);

	return 0;
}