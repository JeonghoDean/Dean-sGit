#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include<vector>
#include<algorithm>
using namespace std;

int getSum(string a) {
	int length = a.length(), sum = 0;
	for (int i = 0; i < length; i++) {
		if (a[i] - '0' >= 0 && a[i] - '0' <= 9) {
			sum += a[i] - '0';
		}
	}return sum;
}

int main() {
	int n;
	cin >> n;
	string input;
	vector<string> v;
	
	while (n--) {
		cin >> input;
		v.push_back(input);
	}
	sort(v.begin(), v.end(), [](string a, string b) {
		if (a.length() != b.length())
			return a.length() < b.length();
		else {
			int aSum = getSum(a);
			int bSum = getSum(b);
			if (aSum != bSum) {
				return aSum < bSum;
			}
			else {
				return a < b;
			}
		}
	});
	for (string a : v)
		cout << a << '\n';
	return 0;
}