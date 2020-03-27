/*
너비를 우선으로 하여 탐색하는 방법
BFS 맹목적인 탐색을 하고자 할때 사용
최단경로는 찾는다는 것에서 최단길이 찾을때 사용됨

1.방문처리
2. 큐에서 하나의 노드 꺼냅
3. 방문 하지 않은 노드 방문하고 다음 큐를 꺼냄
*/

#include <iostream>
#include <queue>
#include <vector>

using namespace std;

int number = 7;
int check[7];
vector<int> a[8]; //트리의 번호와 벡터의 번호 같게하기위해 8개 선언

void bfs(int start) {
	queue<int> q;
	q.push(start);
	check[start] = true;
	while (!q.empty()) {
		int x = q.front();
		q.pop();
		printf("%d ", x);
		for (int i = 0; i < a[x].size(); i++) {
			int y = a[x][i];
			if (!check[y]) {
				q.push(y);
				check[y] = true;
			}
		}
	}
}
int main() {
	a[1].push_back(2);
	a[2].push_back(1);

	a[1].push_back(3);
	a[3].push_back(1);

	a[2].push_back(3);
	a[3].push_back(2);

	a[2].push_back(4);
	a[4].push_back(2);

	a[2].push_back(5);
	a[5].push_back(2);

	a[3].push_back(6);
	a[6].push_back(3);

	a[3].push_back(7);
	a[7].push_back(3);

	a[4].push_back(5);
	a[5].push_back(4);

	a[6].push_back(7);
	a[7].push_back(6);

	bfs(1);
	return 0;
}

