/*
깊이우선탐색 DFS
깊이우선탐색에서는 스택이 사용됨
컴퓨터 자에가 스택프레임이기 때문에 재귀함수만 사용해도 가능하긴 함

1. 큐에 넣고 방문 처리
2. 방문하지 않은 인접노드 스택에 넣고 방문처리, 방문하지 않은 인접 노드가 없다면
스택에서 최상단 노드 pop
*/

#include <iostream>
#include <vector>

using namespace std;

int number = 7;
int check[8];
vector<int> a[8];

void dfs(int x) {
	if (check[x]) return;
	check[x] = true;
	cout << x << ' ';
	for (int i = 0; i < a[x].size(); i++) {
		int xx = a[x][i];
		dfs(xx);
	}
}

int main() {
	a[1].push_back(2);
	a[2].push_back(1);

	a[1].push_back(3);
	a[3].push_back(1);


	a[2].push_back(4);
	a[4].push_back(2);

	a[2].push_back(5);
	a[5].push_back(2);

	a[3].push_back(6);
	a[6].push_back(3);

	a[3].push_back(7);
	a[7].push_back(3);


	dfs(1);
	return 0;
}