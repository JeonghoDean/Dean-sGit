#define _CRT_SECURE_NO_WARNINGS
#include<iostream>
#include<vector>
#include <cstring>
using namespace std;

int a[51][51];
int visit[51][51];
int worm;
int xsize, ysize;
vector<int> v;

void dfs(int y, int x) {
	if (visit[y][x]) return;
	visit[y][x] = true;
	if (a[y][x - 1] == 1 && x > 0 ) dfs(y, x - 1);
	if (a[y][x + 1] == 1 && x < xsize - 1)	dfs(y, x + 1);
	if (a[y - 1][x] == 1 && y > 0)	dfs(y - 1, x);
	if (a[y + 1][x] == 1 && y < ysize - 1)	dfs(y + 1, x);
}

int main() {
	int testCase, num;
	int xpos, ypos;
	scanf("%d", &testCase);
	for (int i = 0; i < testCase; i++) {
		memset(a, 0, sizeof(a));
		memset(visit, 0, sizeof(visit));
		worm = 0;
		scanf("%d %d %d", &xsize, &ysize, &num);
		for (int j = 0; j < num; j++) {
			scanf("%d %d", &xpos, &ypos);
			a[ypos][xpos]++;
		}
		for (int y = 0; y < ysize; y++) {
			for (int x = 0; x < xsize; x++) {
				if (a[y][x] == 1 && visit[y][x] == false) {
					dfs(y, x);
					worm++;
				}
			}
		}v.push_back(worm);
	}
	for (int i : v)
		printf("%d\n", i);
	return 0;
}