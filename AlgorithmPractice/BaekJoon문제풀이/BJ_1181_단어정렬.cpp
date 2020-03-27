#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include<vector>
#include<algorithm>
using namespace std;


int main() {
	int n;
	char word[50];
	cin >> n;
	vector<string> v;
	while (n--) {
		cin >> word;
		v.push_back(word);
	}
	sort(v.begin(), v.end(), [](string a, string b) {
		if (a.length() == b.length())
			return a < b;
		else return a.length() < b.length();
	});
	v.erase(unique(v.begin(), v.end()), v.end());
	for (string s : v) {
		cout << s << '\n';
	}
	return 0;
}