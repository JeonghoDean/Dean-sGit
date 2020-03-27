#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

int main() {
	ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
	int n;
	cin >> n;
	vector<pair<int, int>> v;
	int num1, num2;
	while(n--){
		cin >> num1 >> num2;
		v.push_back(pair<int, int>(num1, num2));
	}
	sort(v.begin(), v.end(), [](pair<int, int>a, pair<int, int> b) {
		if (a.second == b.second)
			return a.first < b.first;
		else
			return a.second < b.second;
		});
	for(pair<int, int> p : v){
		cout << p.first << ' ' << p.second << "\n";
	}
	return 0;
}